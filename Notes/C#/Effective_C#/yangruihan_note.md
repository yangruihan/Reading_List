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

    | -        | 编译期                      | 运行时            |
    | :------- | :-------------------------: | :---------------: |
    | 关键字   | `const`                     | `readonly`        |
    | 适用范围 | `class`、`struct`、`method` | `class`、`struct` |
    | 行为     | 编译期替换                  | 运行时引用        |
    | 类型限制 | 基础类型、枚举、字符串      | 任何类型          |

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

## 5. Always Provide `ToString()`

1. `System.Object` 有一个默认的 `ToString()`方法，返回当前调用实例的类型，通常没有任何意义，需重写`ToString()`方法

2. 可以通过实现`IFormattable`接口中的`ToString(string format, IFormatProvider formatProvider)`方法来实现更为灵活的显示

3. 在极少数情况下，当您的类型需要提供更复杂的输出时，您应该利用实现`IFormattable`接口，同时可以通过实现`IFormatProvider`来从外部对某些对象提供期望的输出：

    ```c#
    public class CustomFormatter : IFormatProvider {

        public object GetFormat(Type formatType) {
            if (formatType == typeof(ICustomFormatter))
                return new CustomerFormatProvider();
            return null;
        }

        private class CustomerFormatProvider : ICustomFormatter {

            public string Format(string format, object arg, IFormatProvider formatProvider) {
                Customer c = arg as Customer;
                if (c == null)
                    return arg.ToString();
                return string.Format("{0,50}, {1,15}, {2,10:C}", c.Name, c.ContactPhone, c.Revenue);
            }
        }
    }
    ```

## 6. Understand the Relationship Among the Many Different Concepts of Equality

1. C# 提供了 4 种方法来判断两个不同的实例是否”相等“：

    1. `public static bool ReferenceEquals (object left, object right);`，比较值类型时永远为 False
    2. `public static bool Equals (object left, object right);`
    3. `public virtual bool Equals(object right);`
    4. `public static bool operator ==(MyClass left, MyClass right);`

2. 前两种方法应该永远不被修改，它们已经做到期望做到的事情

3. 编写自己的`Equals`方法时需要考虑数学中相等的三个特性：

    1. 自反性（reﬂexive）：表明无论任何类型，其自身等于自身永远成立。即`a==a`永远为 True
    2. 对称性（symmetric）：表明无论任何类型，有`a==b`，则一定有`b==a`
    3. 传递性（transitive）：表明无论任何类型，有`a==b`和`b==c`，则一定有`a==c`

4. 何时编写自己的`Equals`方法：

    1. 对于值类型来说，默认方法性能会出现问题，可以考虑自己编写一个效率更高的方法
    2. 对于引用类型来说，如果在判断相等的时候需要表达值语义，而不是引用语义，即希望其内容相等就表示相等，而不是地址相同才相等，则需要自己编写一个方法

5. 无论何时创建值类型，都应该重新定义运算符`==()`。 原因与实例`Equals()`函数完全相同。默认版本使用反射来比较两种值类型的内容，效率很低

6. 基本模板：

    ```c#
    public class Foo : IEquatable<Foo> {

        public override bool Equals(object right) {
            // check null
            // this pointer is never null in c# methods.
            if (object.ReferenceEquals(right, null))
                return false;

            if (object.ReferenceEquals(this, right))
                return true;

            if (this.GetType() != right.GetType())
                return false;

            return this.Equals(right as Foo);
        }

        public bool Equals(Foo other) {
            return true;
        }
    }
    ```
