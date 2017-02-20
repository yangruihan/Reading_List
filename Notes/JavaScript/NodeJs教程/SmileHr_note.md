# 《NodeJs教程》

>NodeJs概述
>>Node.jsisaplatformbuiltonChrome'sJavaScriptruntimeforeasilybuildingfast,scalablenetworkapplications.Node.jsusesanevent-driven,non-blockingI/Omodelthatmakesitlightweightandefficient,perfectfordata-intensivereal-timeapplicationsthatrunacrossdistributeddevices


##章节目录
*第一章：NodeJs入门
*第二章：Node.Js NPM
*第三章：Node事件编程
*第四章：Node文件操作
*第五章：Node模块

#### 第一章 NodeJS入门
- nodejs安装略，附安装包下载地址：https://nodejs.org/en/download/
>Node的两种运行方式
>1.交互模式
>>在命令行中输入node，即进入node的编写环境。如输入：console.log("hello world") 回车即可看到运行结果：hello world
>2.文件模式
>>新建一个test.js文件，编辑填入consloe.log("hello world")，保存后进入命令行，在文件的当前目录下输入node test.js，
>>同样可以看到运行结果：hello world 
>3.console对象
>>console是Node.js提供的控制台对象，其中包含了向标准输出(stdout)的函数log，向标准错误(stderr)输出的函数error。功能类似于c中的printf
>>console也有一些内置方法，在命令行中输入console.log(console)即可查看方法名

#### 第二章 NodeJs NPM