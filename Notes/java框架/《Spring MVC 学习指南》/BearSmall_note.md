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

1. 除了通过类的构造器方式，Spring还同样支持通过调用一个工厂的方法来初始化类。下面的bean定义展示了通过工厂方法来
实例化java.util.Calendar。
    ```
    <bean id="Calendar" class="java.util.Calendar" factory-method="getInstance/>
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