# Effective C#

## 1. Use Properties Instead of Accessible Data Members

1. 需要对属性做约束和额外处理时，无需在类中寻找到底哪些位置对属性进行了修改，只需要修改 Properties set && get 方法即可

2. 对多线程赋、取值支持简单:

   ```c#
   public class Test
   {
        private object syncHandle = new object();

        private string name;
        public string Name
        {
                get { lock(syncHandle) return name; }
                set { lock(syncHandle) name = value; }
        }
   }
   ```

3. Properties 具有所有方法的特性，可以是`vritual`、`abstract`，可以定义在`interface`中

4. Properties 中 set && get 是两个独立的方法，可以分别设置访问权限

5. 可以通过 Properties 来简化索引访问实现：

   - 一维：

   ```c#
   public int this[int index]
   {
        get { return theValues[index]; }
        set { thevalues[index] = value; }
   }
   ```

   - 二维：

   ```c#
   public int this[int x, int y]
   {
        get { return work(x, y); }
   }

   public int this[int index, string name]
   {
        get { return work(index, name); }
   }
   ```

6. Properties 和成员数据访问性能对比，JIT Compiler 会将 Properties 设置成 `inline` 方法，因此性能与直接访问成员数据没有什么差别，即使没有设置成 `inline` 方法，也只是多了一个函数调用的性能消耗，除非某些特定场景，否则可以忽略不计

7. 在实现 Properties set && get 时，应将其当成成员数据，即 get 方法不存在明显的副作用，且不能有耗时操作，set 方法改变类的状态，且用户可见

## 2. Prefer `readonly` to `const`

1. 编译期常量和运行时常量区别：

    |-|编译期|运行时|
    |:---|:---:|:---:|
    |关键字|`const`|`readonly`|
    |适用范围|`class`、`struct`、`method`|`class`、`struct`|
    |行为|编译期替换|运行时引用|
    |类型限制|基础类型、枚举、字符串|任何类型|

2. 由于编译期常量（`const`）在编译时将内容直接替换为常量值，这会导致一旦更新常量值，需要将所有用到该常量值的程序集都重新编译一遍，使其更新到最新值，而运行时常量（`readonly`）在运行时才通过引用确认其值，只需要更新包含该常量的程序集即可

## 3. Prefer the `is` or `as` Operators to Casts

1. 尽可能地使用`as`操作符，因为它比直接类型转换安全，且在运行时更高效

2. `as`和`is`操作不会做任何用户定义的转换，只有当运行时类型和目标类型匹配时才会转换成功

3. 用户定义的转换运算符只能在对象的编译时类型上运行，而不能在运行时类型上运行

4. `as`操作符不能用在值类型上（使用装箱与拆箱，同时可以使用`is`操作符进行判断）

5. 有时需要通过强制类型转换来规避基本类型或用户定义类型之间的差异，如`foreach`循环

## 4. Use Conditional Attributes Instead of `#if`

1. Conditional Attributes 作用于方法

2. 添加了 Conditional Attributes 的方法，在环境变量不满足的情况下，还是会被编译到程序集中，但是调用它的入口都会被删掉，即只占硬盘空间不占内存空间（没有调用不会被加载到内存中）和调用资源

3. Conditional Attributes 可以同时添加多个条件，他们之间的关系是 OR

    ```c#
    [Conditional("Debug"),
     Conditional("TRACE")]
    private void CheckState() { ... }
    ```
4. 如果想使用 AND 关系组织多个条件，可以使用原始方法`#if/#define`

    ```c#
    #if ( VAR1 && VAR2 )
    #define BOTH_VAR1_VAR2
    #endif

    private void CheckState()
    {
    #if BOTH_VAR1_VAR2
    ...
    #endif
    }
    ```

5. 添加 Conditional Attributes 的方法返回值必须为`void`，且不能产生任何边际效应，否则会导致代码在不同构建版本出现逻辑不一致的情况
