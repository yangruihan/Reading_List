# 《Spring MVC 学习指南》

####  【美】 Paul Deck 著
####   林仪明 崔毅 译

>Spring MVC概述
>>Spring MVC是Spring框架中用于Web应用快速开发的一个模块。Spring MVC的MVC是Model-View-Controller的缩写
>它是一个广泛应用在图形化用户交互开发中的设计模式【注意区别于三层架构，和MVC是完全不同是两个概念】，
>不仅常见于Web开发，还广泛应用于桌面开发，如Java Swing。

## 章节目录
* 第一章：Spring框架，介绍了最流行的开源框架
* 第二章：模型2和MVC模式，讨论了Spring MVC实现的设计模式
* 第三章：Spring MVC介绍，本书编写了第一个Spring MVC应用
* 第四章：基于注解的的控制器，讨论了MVC模式中最重要的一个对象-----控制器。本章，我们将学习如何编写基于注解的控制器
* 第五章：数据绑定和表单标签库，讨论Spring MVC最强大的一个特性，并利用它来展示表单数据
* 第六章：转换器和格式化，讨论了数据绑定的辅助对象类型
* 第七章：验证器，展示如何通过验证器来验证用户输入数据
* 第八章：表达式语言
* 第九章：JSTL
* 第十章：国际化
* 第十一章：上传文件
* 第十二章：下载文件
* 附录A：Tomcat
* 附录B：Servlet
* 附录C：JSP
* 附录D：部署描述符


## 读书笔记记录

>2017-1-18
>>页码：0~34

1. 除了通过类的构造器方式，Spring还同样支持通过调用一个工厂的方法来初始化类。下面的bean定义展示了通过工厂方法来
实例化java.util.Calendar。
    ```
    <bean id="Calendar" class="java.util.Calendar" factory-method="getInstance"/>
    ```

2. 除了通过名称传递参数外，Spring还支持通过指数方式传递参数，具体如下：
    ```
    <bean name="featureProduct" class="app.bean.Product">
        <constructor-arg index="0" value="Ultimate Olive Oil"/>
        <constructor-arg index="1' value="9.85">
    </bean>
    ```
3. Servlet和Filter都可以充当控制器。几乎所有现代Web框架都是模型2（MVC）的实现。Spring MVC和Struts1使用一个
Servlet作为控制器，而Struts2则使用一个Filter作为控制器。

4. Dispatcher Servlet的功能【Spring MVC是一个包含 Dispatcher Servlet的框架，无需我们开发Dispatcher Servlet】
    1. 根据URI调用相应的action
    2. 实例化正确的控制器类
    3. 根据请求参数值来构造表单bean
    4. 调用控制器对象的相应方法
    5. 转向到一个视图（JSP页面）


#### 每天小结
* 初看目录，感觉这本书内容不是很多，全书不到300页，感觉不出意外一个星期不用就可以看完了。
* 书本的内容也比较浅显，希望有新的收获。


>2017-1-19
>>页码：35~68

1. SpringMVC中的视图解析器负责解析视图。可以通过配置文件定义一个ViewResolver（如下）来配置视图解析器
```
<bean class="org.springframework.web.servlet.view.InternalResourceViewResolver">
        <property name="prefix" value="/WEB-INF/pages/"/>
        <property name="suffix" value=".jsp"/>
</bean>
```
>如上视图解析器配置有前缀和后缀两个属性。这样一来，view路径将缩短。例如，仅需提供”myPage“，而不必再设置
视图路径为/WEB-INF/jsp/myPage.jsp，视图解析器将会自动增加前缀后缀。

2. 可以通过实现Controller接口来编写我们的控制器，但是Spring2.5引入了一种新方式：通过注解实现我们的控制器
（事实证明，这种方式更加简单高效，代码的耦合性更低）。下面是一个简单的注解实现Controller的例子。
```
@Controller
public class UserController{
        //其他代码
}
```

3. Spring使用扫描机制来找到应用中所有的基于注解的控制器类。为了保证Spring能找到你的控制器，需要完成两件事情。
    *   首先，需要在SpringMVC的配置文件中声明Spring-Context，如下。
        ```
        <beans
            - - -
            xmls:context-"http://www.springframework.org/schema/context"
            - - -
        >
        ```
    *   然后需要应用<conponent-scan/>元素，如下所示：
        ```
        <context:component-scan base-package="basePackagePath"/>
        ```
        >basePackagePath即要扫描的类所在的包名。请确保所有控制类都在基本包下，并且不要指定一个太广泛的基本包
        （如指定com.example，而非com.example.controller），因为这样会使得SpringMVC扫描了无关的包。

4. RequestMapping注解类型的作用如同其名字所暗示的；映射一个请求和一种方法。可以使用@RequestMapping注解注释一种方法或类。
一个采用@RequestMapping注解的方法将成为一个请求处理方法，并由调度程序在接收到URL请求时调用。
    ```
    @Controller
    @RequestMapping(value="/user")
    public class UserController{

        @RequestMapping(value="/userLsit")
        public String getUserAll(){
            //代码段
        }
    }
    ```
   >这样一来可以使用如下URL访问getUserAll方法：http://域名:端口/应用名称/user/userList

5. RequestMapping除了有value属性外还有其它属性，如method属性用来指定该方法只用来处理哪些HTTP协议
这为我们构建REST风格的系统提供了便利。
    ```
    @Controller
    @RequestMapping(value="/user")
    public class UserController{

        @RequestMapping(value="/userLsit",method=RequestMethod.GET)
        public String getUserAll(){
            //代码段
        }
    }
    ```
    >指定该方法只对GET请求生效

5. 重定向的一个不便的地方是：无法轻松地传递值给目标页面。而采用转发，则可以简单地将属性添加到Model，使得目标视图可以轻松访问。
由于重定向经过客户端，所以Model中的一切都在重定向时丢失。幸运的是，Spring3.1版本以及更高版本通过Flash属性提供了一种供重定向传值的方法。
要使用Flash属性：
    * Spring MVC配置文件中有一个<annotation-driven/>元素。
    * 还必须在方法上添加一个新的参数类型org.springframework.web.servlet.support.RedirectAttribute。

    ```
    @Controller
    @RequestMapping(value="/user")
    public class UserController{

        @RequestMapping(value="/userLsit",method=RequestMethod.GET)
        public String getUserAll(RedirectAttributes redirectAttributes){
            //代码段
            redirectAttributes.addFlashAttribute("name","value");
            return "redirect:/user_view";
        }
    }
    ```


#### 每天小结
* 主要看了第三章和第四章。
* 第三章介绍了SpringMVC中核心的几个元素：DispatcherServlet、Controller、ViewResolver。但是介绍得很浅，可能只是为了跑通那个小例子吧。
终之感觉讲得不够透彻，没有结合SpringMVC工作流程介绍每个部件在运行时所处的地位。这么重要的东西没用多少笔墨就简单的描述了下。
这章没几页，但是大部分篇幅都是在撸那个小例子。感觉一个具体的小例子并没有把知识点完全涵盖到。该讲的地方没有深入。
* 第四章讲基于注解的控制器、怎么编写请求处理方法、请求参数和路径变量。这里比较重要的一点是重定向和Flash属性，这是Spring3.1一个重要的新特性。
提供了一种方便的重定向值传递的方法。
