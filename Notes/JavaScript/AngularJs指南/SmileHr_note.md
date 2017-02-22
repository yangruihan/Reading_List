# 《AngularJs》

>AngularJs概述
>>AngularJS 是一个 JavaScript 框架。
>>AngularJS 通过 指令 扩展了 HTML，且通过 表达式 绑定数据到 HTML
>>AngularJS 把应用程序数据绑定到 HTML 元素。
>>AngularJS 可以克隆和重复 HTML 元素。
>>AngularJS 可以隐藏和显示 HTML 元素。
>>AngularJS 可以在 HTML 元素"背后"添加代码。
>>AngularJS 支持输入验证。
>>各版本下载地址： https://github.com/angular/angular.js/releases

##章节目录
* 第一章：AngularJs简介
* 第二章：AngularJS表达式
* 第三章：AngularJS开发
* 第四章：分析一个AngularJS应用程序
* 第五章：与服务器通信
* 第六章：指令
* 第七章：其他关注点

####第一章 AngularJs简介
-略
####第二章 AngularJs表达式
-格式：{{expression}}
######1.Anguler数字
    <div ng-app="" ng-init="quantity=1;cost=5">
        <p>总价： {{ quantity * cost }}</p>
    </div>
######2.Angular 字符串
    <div ng-app="" ng-init="firstName='John';lastName='Doe'">
        <p>姓名： {{ firstName + " " + lastName }}</p>
    </div>
######3.Angular 对象
    <div ng-app="" ng-init="person={firstName:'John',lastName:'Doe'}">
        <p>姓氏： {{ person.lastName }}</p> 
    </div>
######4.Angular 数组
    <div ng-app="" ng-init="points=[1,15,19,2,40]">
        <p>第三个值为 {{ points[2] }}</p>
    </div>
>小结：Angular表达式与JavaScript表达式异同点
>>类似于 JavaScript 表达式，AngularJS 表达式可以包含字母，操作符，变量。
>>与 JavaScript 表达式不同，AngularJS 表达式可以写在 HTML 中。
>>与 JavaScript 表达式不同，AngularJS 表达式不支持条件判断，循环及异常。
>>与 JavaScript 表达式不同，AngularJS 表达式支持过滤器