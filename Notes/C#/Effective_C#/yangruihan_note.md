# Effective C#

## Use Properties Instead of Accessible Data Members

1. 需要对属性做约束和额外处理时，无需在类中寻找到底哪些位置对属性进行了修改，只需要修改 Properties set && get 方法即可

2. 对多线程赋\取值支持简单:

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

## Prefer `readonly` to `const`

1. 编译期常量和运行时常量区别：

    |-|编译期|运行时|
    |:---|:---:|:---:|
    |关键字|`const`|`readonly`|
    |适用范围|`class`、`struct`、`method`|`class`、`struct`|
    |行为|编译期替换|运行时引用|
    |类型限制|基础类型、枚举、字符串|任何类型|

2. 由于编译期常量（`const`）在编译时将内容直接替换为常量值，这会导致一旦更新常量值，需要将所有用到该常量值的程序集都重新编译一遍，使其更新到最新值，而运行时常量（`readonly`）在运行时才通过引用确认其值，只需要更新包含该常量的程序集即可

