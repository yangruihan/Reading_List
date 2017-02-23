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
* 1：AngularJs简介
* 2：AngularJS表达式
* 3：AngularJS指令
* 4：AngularJs模型

#### AngularJs简介
AngularJs应用一般包含三个部分:View(视图), 即 HTML。
Model(模型), 当前视图中可用的数据。Controller(控制器), 即 JavaScript 函数，可以添加或修改属性。

    <div ng-app="myApp" ng-controller="myCtrl">
        <input ng-model="name">
        <h1>{{greeting}}</h1>
        <button ng-click='sayHello()'>点我</button>    
    </div>
    <script>
        var app=angular.module('myApp',[]);
        app.controller('myCtrl',function($scope) {
            $scope.name = "Runoob";
            $scope.sayHello = function() {
                $scope.greeting = 'Hello ' + $scope.name + '!';
            };
        });
    </script>

#### AngularJs表达式
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
#### AngularJs 指令
######1.什么是指令
>AngularJS 指令是扩展的 HTML 属性，带有前缀 ng-
######2.作用
>(1)通过指令的新属性来扩展 HTML
>(2)通过内置的指令来为应用添加功能
######3.类型
>1)ng-app：初始化一个AngularJS应用程序，通常放在body标签上,定义了AngularJs应用程序的<b>根元素</b>。会在网页加载完毕时自动引导（自动初始化应用程序）
    
    <body ng-app=""></body>
>2)ng-init：初始化应用程序数据，但一般不推荐使用
>3)ng-model：把元素值（比如输入域的值）绑定到应用程序，也可以为应用程序数据提供类型验证（number、email、required）以及状态（invalid、dirty、touched、error）；还可以为HTML元素提供css类，并绑定其到HTML表单
>4)ng-repeat：主要用于循环数组，重复元素，对于集合中（数组中）的每个项会 克隆一次 HTML 元素   
    
    <div ng-app="" ng-init="names=['Jani','Hege','Kai']">   
        <p>使用 ng-repeat 来循环数组</p> 
        <ul>
            <li ng-repeat="x in names">{{ x }}</li>
        </ul>
    </div>
######4.创建自己的指令
第一种写法：
>使用 .directive 函数来添加自定义的指令
>使用驼峰法来命名一个指令， myDirective, 但在使用它时需要以-分割, my-directive
    
    <body ng-app="myApp">
        <my-directive></my-directive>
        <script>
            var app = angular.module("myApp", []);
            app.directive("myDirective", function() {
                return {
                    template : "<h1>自定义指令!</h1>"
                };
            });
        </script>
    </body>
第二种写法：

    angular.module('MyApp',[])
    .directive('zl1',zl1)
    .controller('con1',['$scope',func1]);
    function zl1(){
        var directive={ 
            restrict:'AEC',
            template:'this is the it-first directive',
        };
        return directive;
    };
    function func1($scope){
        $scope.name="alice";
    }

######5.调用自己定义的指令
>1）元素名：``   <my-directive></my-directive> ``
>2）属性：``    <div my-directive></div> ``
>3）类名：``<div class="my-directive"></div>``
>4）注释：``<!-- directive: my-directive -->``
ps:注释调用的时候，在定义指令时，return中需：
(1)添加 replace 属性， 否则评论是不可见的
(2)必须设置 restrict 的值为 "M" 才能通过注释来调用指令
(3)restrict为限制指令使用方式的参数，值为E(元素名)A(属性)C(类名)M(注释).可以多个值一起使用，默认值为EA

    app.directive("runoobDirective", function() {
        return {
            restrict : "M",
            replace : true,
            template : "<h1>自定义指令!</h1>"
        };
    });
####Angular模型 -- model指令
>双向绑定数据：
    
    <div ng-app="myApp" ng-controller="myCtrl">
        名字: <input ng-model="name">
        <h1>你输入了: {{name}}</h1>
    </div>
    <script>
        var app = angular.module('myApp', []);
        app.controller('myCtrl', function($scope) {
            $scope.name = "John Doe";
        });
    </script>
####Angular作用域 -- Scope
- Scope(作用域) 是应用在 HTML (视图) 和 JavaScript (控制器)之间的纽带。
- Scope 是一个对象，有可用的方法和属性
- Scope 可应用在视图和控制器上。
###### 1.使用Scope
当你在 AngularJS 创建控制器时，你可以将 $scope 对象当作一个参数传递:eg:

    <div ng-app="myApp" ng-controller="myCtrl">
        <h1>{{carname}}</h1>
    </div>
    <script>
        var app = angular.module('myApp', []);
        app.controller('myCtrl', function($scope) {
            $scope.carname = "Volvo";
        });
    </script>
    ps:当在控制器中添加 ``$scope 对象时，视图 (HTML) 可以获取了这些属性。
    视图中，你不需要添加 $scope 前缀, 只需要添加属性名即可，如： {{carname}}。

