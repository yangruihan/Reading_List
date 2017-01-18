#读书笔记目录

##书名：[git权威指南](http://www.worldhello.net/gotgit)

>2017-01-18

### 1.使用diff和patch 命令来进行版本控制

```sh
#比较差异
diff A B>diff.txt #比较原文件A和目标文件B的差异，并输出差异文件diff.txt

#恢复原文件A
cp B A # 覆盖原文件A
patch -R A < diff.txt # 使用差异文件diff.txt和目标文件B恢复原文件A

#恢复目标文件B
cp A B #覆盖目标文件B
patch B < diff.txt # 使用差异文件diff.txt和原文件B恢复目标文件A
```

### 2.CVS的工作原理
采用**C/S**架构，版本库位于服务端，实质是**RCS**文件容器。每个**RCS**文件的文件名以",v"结尾，用于存储对应文件的历次变更历史。详细结构如下图所示：

![图1：CVS版本控制系统示意图](/Notes/git/git权威指南/img/cvs-arch.png)

### 3.SVN的工作原理

SVN的每一次提交，都会在服务器端的db/revs和db/revprops目录下各自创建一个以#+顺序数字命名的文件，用以记录此次更新的内容。（M--修改，A--添加，D--删除）

![图2：CVS版本控制系统示意图](/Notes/git/git权威指南/img/svn-arch.png)

###  本日小结 2017-01-18

看完了第一章，主要熟悉了版本控制的发展历史，基本了解了CVS和SVN用来做版本控制的原理。
从CVS到SVN的转换，主要是由BDB（简单的关系型数据库）到FSFS（文件型数据库）的转换，而从SVN到git的转换，主要是由集中式版本控制到分布式版本控制。剩下的部分简要地提了部分git的好处。git安装，大致浏览一遍。