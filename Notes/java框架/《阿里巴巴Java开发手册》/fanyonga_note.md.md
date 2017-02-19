## java编程规范笔记

> 《阿里巴巴Java开发手册》 
> 2017-02-19

### 命名规范

* **严禁中文** ，对于国际通用的名称可视为英文，如“alibaba”，“youku”，“souhu”等；
* 抽象类命名使用Abstract开头，异常类命名使用Exception结尾，测试类使用需要测试的类开头，以Test结尾；
* 包名统一使用单数形式
* 如果使用到了设计模式，应在类的命名中体现出来，如“OrderFactory”，“ResourceObserver”
* 各层命名规范
* Service/DAO层命名规范
* 获得单个对象的方法使用get作为开头
  * 获得多个对象的方法使用list作为开头
  * 获得统计值的方法使用count作为开头
  * 插入的方法使用**save（推荐）**和insert作为开头
  * 删除的方法使用**remove（推荐）**和delete作为开头
  * 修改方法使用update作为开头
* 领域模型命名规约
* 数据对象： xxxDO,xxx即为数据表名。
  * 数据传输对象：xxxDTO，xxx即为业务领域相关名称
  * 展示对象：xxxVO，xxx一般为网页名称
  * POJO是DO/DTO/BO/VO的统称，禁止命名为xxxPOJO

### 常量定义

* 不允许出现任何魔法值（即未定义的常量）直接出现在代码当中
* 不要使用一个常量类维护所有的常量，应该安昌亮功能进行分类，分开维护
* 缓存相关的常量放在类：CacheConsts下
* 系统配置相关的常量放在类：ConfigConsts下
* 常量的复用层次有五层：
* 跨应用共享常量：放在二方库中，通常是client.jar中的const目录下
* 应用内共享常量，放置在一方库的moudules中的const目录下
* 子工程内部共享常量：当前子工程的const目录下
* 包内共享常量：当前包下单独的const目录下
* 类内共享常量：直接在类内部private statis final定义

### OOP规约

* 关于基本数据类型与包装数据类型的使用标准如下
* 1）所有的POJO类属性必须使用包装数据类型
* 2）RPC（Remote Procedure Call）方法的参数和返回值必须使用包装类型
* 3）所得的局部变量推荐使用基本数据类型
* 定义DO/DTO/VO等POJO类时，不要设定任何默认值。
* 构造方法里面禁止加入任何业务逻辑，如果有初始化逻辑，请将它放在init方法中
* 使用String的sqlit方法得到的数组时，需做最后一个分隔符后面有无内容的检验，否则可能抛出IndexOutOfBoundsException的风险

### 集合处理

* Map/Set的key为自定义对象时，必须重写hashCode和equals方法
* 集合转数组方法必须使用集合的toArray（T[] array）方法，传入的是类型完全一样的数组，其大小就是list.size()
* 使用 Iterator方式而不是foreach 的循环内进行元素的remove/add操作

### 并发处理

* 获得单例对象要线程安全，单例对象内部操作也要线程安全

### SQL规约

* 当某一列的值全为NULL时，count（col）的结果为0，而**sum（col）的结果为NULL**
* 使用ISNULL来判断是否为 NULL，注意：NULL与任何值的直接比较都为NULL，而不是布尔值
* 不得使用外键和级联（外键影响数据库的插入速度，级联更新时存在 更新风暴的危险），一切外键概念必须在应用层解决。
* 禁止使用存储过程，存储过程难以调试和扩展，更没有移植性。
* in操作尽可能避免，如果避免不了，要控制in后面的集合元素个数小于1000

### ORM规约

* POJO类的boolean属性不能加is，而数据库字段必须加is，要求在resultMap中进行字段与属性之间的映射。