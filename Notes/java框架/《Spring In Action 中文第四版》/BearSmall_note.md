# Spring In Action
### ----------------Fouth Edition
#### 【美】 Craig Walls 著
#### 张卫滨 译

>Spring In Action
>* 毫无疑问 In Action系列图书是经典、畅销的代名词。同样，这本Spring In Action也是学习Spring框架必备的经典书籍。
>* 我想，除了Spring官网上一千多页的Spring参考手册以及Spring源码，这本Spring In Action也是很值得我们去细细品读的。

## 目录

### 第一部分 Spring核心

1.  第一章：Spring之旅
2.  第二章：装配Bean
3.  第三章：高级装配
4.  第四章：面向切面的Spring

### 第二部分 Web中的Spring

5.  第五章：构建Spring Web应用
6.  第六章：渲染Web视图
7.  第七章：Spring MVC的高级技术
8.  第八章：使用Spring Web Flow
9.  第九章：保护Web应用

### 第三部分 后端中的Spring

10. 第十章： 通过Spring和JDBC征服数据库
11. 第十一章：使用对象-关系映射持久化数据
12. 第十二章：使用NoSQL数据库
13. 第十三章：缓存数据
14. 第十四章：保护方法应用

### 第四部分 Spring集成

15. 第十五章：使用远程服务
16. 第十六章：使用Spring MVC创建REST API
17. 第十七章：Spring消息
18. 第十八章：使用WebSocket和STOMP实现消息功能
19. 第十九章：使用Spring发送Email
20. 第二十章：使用JMX管理
21. 第二十一章：借助Spring Boot简化Spring开发

## 读书笔记记录

>2017-1-18
>>页码：0~66

1. Spring的目标是致力于全方位的简化Java开发。为了降低Java开发的复杂性，Spring采取了以下四种关键策略
    * 基于POJO的轻量级和最小侵入性编程
    * 通过依赖注入和面向接口实现松耦合
    * 基于切面和惯例进行声明式编程
    * 通过切面和模板减少样板式代码

2. Spring容器并不是只有一个，Spring自带了多个容器实现，可以归纳为两种不同的类型。Bean工厂
    （org.springframework.beans.factory.BeanFactory接口定义）是最简单的容器，提供基本的DI支持。
    应用上下文（由org.springframework.context.ApplicationContext接口定义）基于BeanFactory构建，
    并提供应用框架级的服务，例如从属性文件解析文本信息以及发布应用事件给感兴趣的监听者。

3. Spring自带多种类型的应用上下文，包括并不仅限于以下几种
    * **AnnotationConfigApplicationContext**：从一个或多个基于Java的配置类中加载Spring应用上下文。
    * **AnnotationConfigWebApplicationContext**：从一个或多个基于Java的配置类中加载Spring Web应用上下文。
    * **ClassPathXMLApplicationContext**：从类路径下的一个或多个XML配置文件中加载上下文定义，把应用上下文的定义文件作为类资源。
    * **FileSystemXMLApplicationContext**：从系统下的一个或多个XML配置文件中加载上下文定义。
    * **XMLWebApplicationContext**：从Web应用下的一个或多个XML配置文件中加载上下文定义。

4. Spring框架由六个定义良好的模块分类组成
    * 数据访问与集成模块：【JDBC】【Transaction】，【ORM】，【OXM】，【Messaging】，【JMS】
    * Web与远程调用模块：【Web】，【Web Servlet】，【Web Portlet】，【WebSocket】
    * 面向切面编程模块：【AOP】，【Aspects】
    * Instrumentation模块：【Instrument】，【Instrument Tomcat】
    * Spring核心容器模块：【Beans】，【Core】，【Context】，【Expression】，【Context support】
    * 测试模块：【Test】

5. Spring新功能
    1. Spring3.1新特性
        * 引入环境profile功能。借助于profile，就能根据应用部署在什么环境之中选择不同的数据源bean；
        * 在Spring3.0基于Java的配置之上，Spring3.1添加了多个enable注解，这样就能使用这个注解启用Spring的特定功能
        * 添加Spring对声明式缓存的支持，和声明式事务很类似。
        * 新增用于构造器注入的c命名空间。
        * Spring开始支持Servlet3.0。
        * 改善Spring对JPA的支持，使得它能够在Spring中完整地配置JPA。
        * 对Spring MVC的增强：自动绑定路径变量到模型属性中。
        * 对Spring MVC的增强：提供了@RequestMappingproduces和consumes属性，用于配置Servlet容器。
                                                                                                                                                * Spring3.2还包含了基于RestTemplate的客户端的测试支持，不需请求中的Accept和Content-Type头部信息。
        提供了@RequestPart注解，用于将multipart请求中的某些部分绑定到处理器的方法参数中。
        * 对Spring MVC的增强：支持flash属性（在redirect请求之后依然能够存活的属性）以及用于在请求间存放flash属性的RedirectAttributes类型。

       > 同等重要的是为了支持原生的EntityManager，Spring的JpaTemplate和JpaDaoSupport类被废弃掉了。

   2. Spring3.2新特性
        * Spring3.2的控制器（Controller）可以使用Servlet3.0的异步请求，允许在一个独立的线程中处理请求，从而将Servlet线程解放出来处理更多的请求。
        * Spring3.2引入了Spring MVC测试框架，在使用的过程中不需要要往真正的REST端点上发送请求。
        * @ControllerAdvice注解能够将通过@ExceptionHandler、@InitBinder和@ModelAttribute方法收集到一个类中，并应用到所有的控制器上。
        * 太多了、略。
   3. Spring4.0新特性
        * 提供了对WebSocket编程的支持，包括支持JSR-356---------Java API for WebSocket
        * 鉴于WebSocket仅仅提供了一种低层次的API，急需高层次的抽象，因此Spring4.0在WebSocket之上提供了一个高层次的面向消息的编程模型，该模型基于SockJS，并且包含了对STOMP协议的支持。
        * 新的消息（messaging）模块，很多的类型来源于Spring Integration项目。这个消息模块支持Spring的SockJS/STOMP功能，同时提供基于模板的方式发布消息。
        * Spring是第一批支持Java8特性的Java框架，比如它支持lambda表达式。这能让使用特定回调接口更加简洁，代码更加易读。
        * 与Java8同时得到支持的是JSR-310---Date与Time API，在处理日期和时间时，它为开发者提供了比Java.util.Date或者java.util.Calendar更丰富的API
        * 为Groovy开发的应用程序提供了更加顺畅的编程体验。
        * 添加了条件化创建bean的功能，在这里只有开发人员定义的条件满足的时候，才会创建所声明的bean。
        * Spring4.0包含了Spring的RestTemplate的一个新的异步实现，它会立即返回并且允许在操作完成后执行回调。
        * 添加了多项对JEE规范的支持，包括JMS2.0、JPA2.1、和bean validation 1.1。

#### 每天小结

* 书的内容比较全面，涉及到了Spring框架的各个方面，知识点也很多，比较适合当工具书使用。
* 第四版是以Spring4为基础编写的，Spring3.1，Spring3.2，Spring4.0这几个版本都增加了很多让人眼前一亮的新特性。
* 正好这本书里面包含Spring的Web模块，里面也讲到了Spring MVC的内容，和我在看的另外一本书知识点有些重复。打算先看Web这部分，对比两本书，去粗取精。


>2017-1-19
>>页码：136~166

1. **Spring MVC 架构图**

    >

    ![Spring MVC 架构图](images/SpringMVC-architect.png)
    >
    *  1、	用户发送请求至前端控制器DispatcherServlet。
    *  2、	DispatcherServlet收到请求调用HandlerMapping处理器映射器。
    *  3、	处理器映射器根据请求url找到具体的处理器，生成处理器对象及处理器拦截器(如果有则生成)一并返回给DispatcherServlet。
    *  4、	DispatcherServlet通过HandlerAdapter处理器适配器调用处理器。
    *  5、	执行处理器(Controller，也叫后端控制器)。
    *  6、	Controller执行完成返回ModelAndView。
    *  7、	HandlerAdapter将controller执行结果ModelAndView返回给DispatcherServlet。
    *  8、	DispatcherServlet将ModelAndView传给ViewReslover视图解析器。
    *  9、	ViewReslover解析后返回具体View。
    *  10、	DispatcherServlet对View进行渲染视图（即将模型数据填充至视图中）。
    *  11、	DispatcherServlet响应用户。


2. 需要注意的是，除了“redirect:”，InternalResourceViewResolver还能识别“forward:”前缀。当它发现视图格式中的“forward:”作为前缀的时候，
请求将会前往（forward）指定的URL路径，而不再是重定向。

#### 每天小结

* 今天最重要的是理解上面那张图【图片根据书籍中内容以及互联网上相关资料绘制】，这是SpringMVC的核心。也是本书详细讲解到的地方。

>2017-1-25
>>页码：167~180

1. Spring自带了十三个视图解析器，能够将逻辑视图名称转换为物理实现。

|视图解析器|   描述|
|:-------:|:----:|
|BeanNameviewResolver|将视图解析为Spring应用上下文中的bean，其中bean的ID与视图的名字相同
|ContentNegotiatingViewResolver|通过考虑客户端需要的内容类型来解析视图，委托给另外一个能够产生对应内容类型的视图解析器|
|FreeMarkerviewResolver|将视图解析为FreeMarker模板|
|InternalResourceviewResolver|将视图解析为Web应用的内部资源(一般为JSP)|
|JasperReportsviewResolver|将视图解析为JasperReports定义|
|ResourceBundleviewResolver|将视图解析为资源bundle(一般为属性文件)|
|TilesviewResolver|将视图解析为Apache Tile定义，其中tile ID与视图名称相同。注意有两个不同的Tilesv上ewResolver实现，分别对应于Tiles 2.0和Tiles 3.0
|UrlBasedviewResolver|直接根据视图的名称解析视图，视图的名称会匹配一个物理视图的定义|
|VelocityLayoutviewResolver|将视图解析为Velocity布局，从不同的Velocity模板中组合页面|
|VelocityviewResolver|将视图解析为Velocity模板|
|xmlv1ewResolver|将视图解析为特定XML文件中的bean定义。类似于Bean NameViewResolver|
|XsltviewResolver|将视图解析为XSLT转换后的结果|
>最后还有一个是对Thymeleaf支持的视图解析器

2.使用Spring通用的标签库
```
<%@taglib uri="http://www.springframework.org/tag" prefix="s" %>
```

#### 每天小结
* Spring对渲染视图的支持
* Spring支持多种视图解析器，要视具体引用场景而定。
* Spring的通用标签库


>2017-1-26
>>页码：181-190

1. 使用Apache Tiles 定义视图
    * 配置Apache Tiles视图解析器

#### 每天小结
* 使用Apache Tiles 定义视图
* 配置Apache Tiles视图解析器
