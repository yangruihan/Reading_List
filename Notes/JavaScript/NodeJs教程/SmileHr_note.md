# 《NodeJs教程》

> NodeJs概述
>> Node.js is a platform built on Chrome's JavaScript runtime for easily building fast,scalable network applications.Node.js uses an event-driven,non-blocking I/O model that makes it lightweight and efficient,perfect for data-intensive real-time applications that run across distributed devices


##章节目录
* 第一章：NodeJs入门
* 第二章：Node.Js NPM
* 第三章：Node事件编程

#### 第一章 NodeJS入门
##### 1.Node 安装
>> nodejs安装略，附安装包下载地址：https://nodejs.org/en/download/>
##### 2.Node的两种运行方式
###### 1）.交互模式
>> 在命令行中输入node，即进入node的编写环境。如输入：console.log("hello world") 回车即可看到运行结果：hello world
###### 2）.文件模式
>> 新建一个test.js文件，编辑填入consloe.log("hello world")，保存后进入命令行，在文件的当前目录下输入node test.js，同样可以看到运行结果：hello world 
##### 3.console对象
- 1）console是Node.js提供的控制台对象，其中包含了向标准输出(stdout)的函数log，向标准错误(stderr)输出的函数error。功能类似于c中的printf
- 2）console也有一些内置方法，在命令行中输入console.log(console)即可查看方法名

#### 第二章 NodeJs NPM
>什么是NPM
>>NPM即Node Package Manager；它的功能就是 Install, Update, and Uninstall
Packages。
##### 1.NPM安装包
>>npm install -g packagename //表示全局加载安装包
##### 2.NPM更新包
>>npm update packgename
##### 3.NPM卸载包
>>npm uninstall packgename
##### 4.NPM搜索包
>>npm find packagename
##### 5.NodeJs中的包依赖
######1）package.json文件
>>-node中使用package.json解决包依赖问题
>>-package.json是一个JSON格式的文本文件，它包含一些属性用于描述包的功能。不管你是否要把自己开发的包通过npmpublish进行发布还是作为私有的，你都应该在你的包的根目录下创建这个文件
>>-package.json文件中关键属性：
-name：模块名
-description：模块描述
-version：当前模块的版本号
-author：模块作者信息
-contributors：贡献者人员信息
-dependencies：依赖的模块，NPM就是通过这个属性来解决模块之间的依赖问题的
devDependencies：同上，不过这里的依赖的模块要多些keywords：模块关键字，方便你使用npmsearch查找到它
-repository：模块文件保存地址，那些贡献者们就能下载到它的源码了
-main：模块接口，表示Node.js在调用某个模块的时候，将寻找main指向的路径作为模块的接口
-bin：模块的可执行文件路径
-scripts：这个不清楚作什么用？
-dist：模块的指纹，可用来验证模块的完全性
######2）NodeJs模块加载机制
>>-模块类型：核心模块和文件模块
>>-调用require即可：module.exports = require('./lib/express');
>>-加载方式：
>>>-按路径加载：如果require的参数以“/”开头，那么就以绝对路径的方式来查找模块名；反之如果require的参数以“./”或者“../”开头，则以相对路径的方式来查找
>>>-通过node_modules目录来加载:1）使用情况：如果require加载的模块不是核心模块（比如,fs,http,event,sys等）并且require的参数不是上面两种中的一种。2）当require加载的模块不是核心模块时或者不以路径为参数，它就会以你脚本所在的路径为当前路径并试图寻找此路径下是否有一个叫做node_modules的目录，如果没有这个目录（node_modules），则往此目录的父目录中寻找。反复执行这一过程，直到你的根目录，如果还没有就报错了。
######3）创建自己的模块
>-只需要将自己的模块名当做require的参数即可
>-要创建自己的模块，只要使用exports或者module.exports导入你的公有方法即可
#### 第三章 NodeJs 事件编程 --核心
##### 1.回调函数
> 回调函数就是一个通过函数指针调用的函数。如果你把函数的指针（地址）作为参数传递给另一个函数，当这个指针被用为调用它所指向的函数时，我们就说这是回调函数。
##### 2.EventEmitter类
######1）初步了解EventEmitter类
>API:
>>(1)addListener(event,listener)：为指定事件(event)注册一个或者多个监听器(listener)。我们可以使用on来代替addListener
>>(2)once(event,listener)：为指定事件单次注册一个监听器，即事件触发后就立即删除该监听器，意味着这个事件的监听器最多只触发一次
>>(3)removeListener(event,listener)：移除指定事件的某一个监听器，当然这个监听器是通过on或者addListener注册过的
>>(4)removeAllListeners([event])：移除所有事件上的所有监听器，如果你指定了某个event，则只移除那个event上的所有监听器
>>(5)setMaxListeners(n)：设置某个事件的最大监听器数，默认为10，通过设置为0来禁用这个特性
>>(6)listeners(event)：返回指定事件上的监听器数组
>>(7)emit(event,[arg1],[arg2],[...])：触发指定事件，这里可选的参数(arg1,arg2)被传递到事件监听器当作它的参数表
######2）运用EventEmitter类
>eg:创建emitter.js文件，然后添加如下内容：
    var events=require('events');
    var emitter=newevents.EventEmitter();
    emitter.on('buyTicket',function(from,to){
        console.log('Buyticket:'+'From'+from+'To'+to);
    });
    emitter.on('error',function(err){
        console.log('Error:'+err);
    });
    emitter.emit('buyTicket','Shenzhen','Changsha');
>ps:从上面的例子中，emitter对象通过on注册了’buyTicket’事件，并为这个事件设置了一个匿名监听器，然后通过emit触发了这个’buyTicket’事件。还为emitter对象绑定了一个error事件的监听器，你不妨去手动触发这个error看看。一般来说,你应该总是监听错误事件并正确地处理它们。其他的api都可以类似的运用 
>
> 多个监听器陷阱：
>>正如可以给同一个标签绑定多个事件一样，我们也可以给一个事件绑定多个监听器：
    emitter.on('buyTicket1',function(from,to){
        console.log('Buyticket:'+'From'+from+'To'+to);
    });
    emitter.on('buyTicket2',function(from,to){
        console.log('Buyticket:'+'From'+from+'To'+to);
    });
>>它们被触发的时候，按照绑定时的顺序依次触发，然而有个意外：对上面这个例子来说，如果事件’buyTicket1′throwsanerror，即抛出一个错误，那么事件’buyTicket2′将不会被触发
######3）继承EventEmitter类
>javascript中一个util工具类其中的inherits(constructor,superConstructor专为继承
而生
    var util=require("util");//导入util模块
    var events=require("events");//导入events模块
    functionMyStream(){
        events.EventEmitter.call(this);
        //call方法使得MyStream对象继承了EventEmitter对象上的方法
    }
    util.inherits(MyStream,events.EventEmitter);//使用inherits方法
    MyStream.prototype.write=function(data){
        //MyStream对象扩展了一个write方法，它可以使用emit触发事件
        this.emit("data",data);
    }
    var stream=newMyStream();//构建一个stream对象
    console.log(streaminstanceofevents.EventEmitter);
    //判断stream对象是不是EventEmitter对象的实例，这里为true
    console.log(MyStream.super_===events.EventEmitter);
    //MyStream的父类是不是EventEmitter，这里为true
    stream.on("data",function(data){
        //stream调用了继承过来的on方法，定义了一个'data'事件并安装了一个监听器
        console.log('Receiveddata:"'+data+'"');
    })
    stream.write("Itworks!");//调用stream对象的write方法，
    结果：Receiveddata:"Itworks!"

