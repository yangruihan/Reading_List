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


>2017-1-20
>>页码：69~102

1. Spring也拥有自己的表单标签库，表单标签库中包含了可以用在JSP页面中渲染HTML元素的标签。为了使用这些标签，必须在JSP页面中的开头声明这个taglib指令
```
<%tablib prefix="form" uri="http://www.springframework.org/tags/form"/>
```

2. Spring中的转换器和格式化：Converter和Formatter两者均可以用于将一种对象类型转换成另外一种对象类型。Converter是通用元件，
可以在应用程序的任意层中使用，而Formatter则是专门为Web层设计的。

    >**1. 使用Converter**
    >>* 编写一个实现```org.springframework.core.convert.converter.Converter```接口的Java类，实现其converter方法。
    >>```public interface Converter<S,T>``` ```T convert(S source);```   S:原始类型，T：转化后的类型。
    >>* 在SpringMVC配置文件中编写一个conversionService bean，Bean的类名称必须为 ```org.springframework.context.support.ConversionServiceFactoryBean```。
    >>这个bean必须包含一个converters属性，它将列出要在应用程序中使用的所有定制Converter。

        <bean id="conversionService" class="org.springframework.context.support.ConversionServiceFactoryBean">
            <property name="converters">
                <list>
                    <bean class="MyConverter">
                        <constructor-arg type="java.lang.String" value="MM-dd-yyyy"/>
                    </bean>
                </list>
            </property>
        </bean>

    >>* 最后要给annotation-driven元素的conversion-service属性赋bean名称

        <mvc:annotation-driven conversion-service="conversionService"/>

    >**2. 使用Formatter**
    >>* 编写一个实现```org.springframework.format.Formatter```接口的Java类，实现parse和print两个方法
    >>```public interface Formatter<T>``` ```T parse(String text,java.util.Locale locale)``` ```String print(T object,java.util.Locale locale)```。
    >>parse方法利用指定的Locale将一个String解析成目标类型。print方法与之相反，它是返回目标对象的字符串表示法。
    >>* 在SpringMVC配置文件中利用conversionService bean对它进行注册。bean的类名称必须为```org.springframework.format.support.FormattingConversionServiceFactoryBean```
    >>这个bean必须包含一个formatters属性，它将列出要在应用程序中使用的所有定制Formatter。

        <bean id="conversionService" class="org.springframework.format.support.FormattingConversionServiceFactoryBean">
            <property name="formatters">
                <set>
                    <bean class="MyFormatter">
                        <constructor-arg type="java.lang.String" value="MM-dd-yyyy"/>
                    </bean>
                </set>
            </property>
        </bean>

    >>* 最后要给annotation-driven元素的conversion-service属性赋bean名称
    >>注意：还需要给这个Formatter添加一个component-scan元素。

3. Converter是一般工具，可以将一种类型转换成另一种类型。例如，将String转换成Date，或者将Long转换成Date。Converter既可以用在Web层，也可以用在其他层中。
Formatter只能将String转换成另一种Java类型。例如，将String转换成Date，但它不能将Long转换成Date。因此，Formatter适用于web层。为此，在SpringMVC应用程序中，
选择Formatter比选择Converter更合适。

4.  SpringMVC中，有两种方式可以验证输入，即利用Spring自带的验证框架，或者利用JSR303实现。本章将详细介绍这两种输入验证方法。

#### 每天小结
* 主要看了表单标签和转化器两个部分的内容
* 表单标签没什么好说的，书上就是罗列了标签，然后一个个的介绍是干什么的，有哪些属性。感觉有点像学HTML。。。。。。后面结合一个例子讲解了数据绑定，代码很全，
就是这个占的篇幅有点多，其实点到就可以了。内容确实比较基础。
* 格式化讲解了Converter和Formatter两种，比较了两者的不同以及各自的适用场景。不过这个10页的内容单独成章是不是略显单薄了。可以试着多扩展一下。

>2017-1-21
>>页码：103~160

1. JSR 303“Bean Validation”（发布于2009年11月）和JSR 349“Bean Validation 1.1”（发布于2013年5月）指定了一整套的API，通过标注给对象添加约束。
当然，JSR只是一个规范文档，本身用处不大，除非编写了它的实现。对于JSR bean validation，目前有两个实现。第一个实现是Hibernate Validation，目前版本为5，
JSR 303和JSR 349两种它都实现了。第二个实现是Apache BVal，它只实现了JSR 303。

2. 实现免脚本的JSP页面。将一个应用程序中所有JSP页面中的脚本都关闭
```
<jsp-config>
    <jsp-property-group>
        <url-pattern>.jsp</url-pattern>
        <scripting-invalid>true</scripting-invalid>
    </jsp-property-group>
</jsp-config>
```

3. 禁用EL计算。目前有两种方式可以禁用JSP中的EL计算

    * 第一种，可以将page指令中的isELIgnored属性设为True。```<%@ page isELIgnored="true" %>```。isELIgnored属性默认值为False。
    如果想在一个或几个JSP页面中禁用EL表达式，建议使用isELIgnored属性。
    * 第二种，可以在部署描述符中使用jsp-property-group元素。
    ```
    <jsp-config>
        <jsp-property-group>
            <url-pattern>/noEl.jsp</url-pattern>
            <el-ingored>true</el-ingored>
        </jsp-property-group>
    </jsp-config>
    ```

#### 每天小结
* 今天看的很快，不是因为只是简单的翻了翻，而是因为这部分内容的问题。看了三章（第7~9章。
* 第七章讲的验证器，和第六章有点联系。讲解了基于注解的验证器。验证器的功能很强大同时也很重要就不多说了。
* 第八章和第九章要好好吐槽一下。延续了前面讲Spring标签的风格。总之就是有过之而无不及。通篇大讲特讲EL表达式和JSTL。
篇幅达到45页之多（整本书除去附录也才200页多点）。重要的不是这个，重要的是这本书名叫SpringMVC学习指南。怎么把EL表达式
和JSTL这种不属于SpringMVC的知识点放这么多进去呢？应该突出SpringMVC的重点和特点才是啊。抛开框架不谈，不管是学SpringMVC还是学Struts2，
EL表达式和JSTL都是和JSP以及Servlet一同学习的前驱知识点吧。眼看本书内容已经过半，但书上对SpringMVC的讲解还不特别深入，故对本书持保留态度。

>2017-1-22
>>页码：161~196

1. 在SpringMVC中处理文件上传有两种方法
    * 使用Apache Commons FileUpload元件。
    * 利用Servlet3.0及其更高版本的内置支持。
2. 使用Apache Commons FileUpload元件上传文件。只有实现了Servlet3.0及其更高版本规范的Servlet容器，才支持文件上传。对版本低于Servlet3.0的容器，
则需要Apache Commons FileUpload元件。这是一个开源的项目，因此是免费的，它还提供了源码。为了让Commons FileUpload成功的工作，还需要另外一个Apache
Commons元件：Apache Commons IO。此外还需要在SpringMVC配置文件中定义multipartResolver bean：
    ```
    <bean id="multipartResolver"
          class="org.springframework.web.multipart.commons.CommonsMultipartResolver">
        <property name="maxUploadSize" value="209715200" /><!--最大上传文件大小-->
        <property name="defaultEncoding" value="UTF-8" /><!--默认编码格式-->
        <property name="resolveLazily" value="true" /><!--懒加载-->
        <property name="uploadTempDir" value="fileUpload/tmp"/> <!--上传文件临时目录-->
        <property name="maxInMemorySize" value="10240000"/><!--最大缓存大小-->
    </bean>
    ```
3. 使用Servlet3上传文件就不需要Commons FileUpload和Commons IO元件了。在Servlet3以及其以上版本的容器中进行服务器端文件上传的编程，
是围绕着标注类型MultipartConfig和javax.servlet.http.Part接口进行的。处理已上传文件的Servlets必须以@MultipartConfig进行标注。
SpringMVC的DispatcherServlet处理大部分或者所以请求。令人遗憾的是，如果不修改源代码，将无法对Servlet进行标注。但值得庆幸的是，
Servlet3中有一种比较容易的方法，能使一个Servlet变成一个MultipartConfig Servlet，即给部署描述符（web.xml）中的Servlet声明赋值。
以下代码与用@MultipartConfig给DispatcherServlet进行标注的效果一样：
    ```
    <servlet>
        <servlet-name>springmvc</servlet-name>
        <servlet-class>org.springframework.web.servlet.DispatcherServlet</servlet-class>
        <init-param>
            <param-name>contextConfigLocation</param-name>
            <param-value>classpath:springmvc-servlet.xml</param-value>
        </init-param>
        <multipart-config>
            <max-file-size>20848820</max-file-size>
            <max-request-size>418018841</max-request-size>
            <file-size-threshold>1048576</file-size-threshold>
        </multipart-config>
    </servlet>
    ```

    此外还需要在SpringMVC配置文件中使用一个不同的多部分解析器：
    ```
    <bean id="multipartResolver"
          class="org.springframework.web.multipart.support.StandardServletMultipartResolver">
    </bean>
    ```
4. 在实现上传文件进度功能的时候，我们关注的是HTML5 input元素的change事件，当input元素的值发生改变时，它就会触发。
同时我们还关注HTML5在XMLHttpRequest对象中添加progress事件。当异步使用XMLHttpRequest对象上传文件时，就会持续的触发progress事件。
直到上传进度完成或者取消，或者直到上传进度因为出错而中断。通过监听progress事件，可以轻松地检测文件上传操作的进度。

#### 每天小结
* 今天主要看了SpringMVC中的文件上传部分。
* 在SpringMVC中处理文件上传有两种方法：1.使用Apache Commons FileUpload元件，2.利用Servlet3.0及其更高版本的内置支持
* 文件上传部分的特色是多文件上传以及增加了文件上传中报告上传进度功能的扩展。