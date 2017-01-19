# _500lines_

_500lines_准确来说不是一本书，而是github上的一个项目。不过有一本书也是基于这个项目的 : *500 lines or less* ,考虑到英文书籍的价格以及购买的麻烦性，还是看原项目更适合笔者。

[_500lines_]( [https://github.com/aosabook/500lines](https://github.com/aosabook/500lines))项目的目的在于给阅读者更广的视野，让阅读者理解软件设计者的想法。

这个项目里的每个文件夹基本都是一个独立的项目。试图用500行左右或者更少的代码完成某种特定的需求。在阅读时不应该过分关注某种语言的特性或某个算法的细节，而应该揣摩软件架构师们在设计软件时如何决定和权衡。

## Template engine

**项目简介**：一个用纯python实现的简单的模板引擎

```html
<p>Welcome, {{user_name}}!</p>
<p>Products:</p>
<ul>
{% for product in product_list %}
    <li>{{ product.name }}:
        {{ product.price|format_price }}</li>
{% endfor %}
</ul>
```

简单来说就是用来解析上面这样的`html`或者其他的代码，被大括号`{`包括的部分为动态内容，其他部分是静态文本

如果传入的参数是

```python
context = {'user_name': 'addliu', 'product_list': [{'name': 'iPhone', 'price': 6666}, {'name': 'Xiaomi', 'price': 899}, 'format_price': lambda price: '￥' + str(price)]
```

那么解析出来的文本如下

```html
<p>Welcome, addliu!</p>
<p>Products:</p>
<ul>
    <li>iPhone: ￥6666</li>
  	<li>Xiaomi: ￥899</li>
</ul>
```

**核心思想**：将模板解析成一个字符串`code`，字符串内容是一个python的**函数** (函数名为：`_render_function`) ，然后用`exec(code, namespace)`执行该函数的定义并返回`namespace`，最终由外层类调用`namespace`下的`_render_function`得到最终的静态文本。

> `code`字符串里面的函数定义如下：
>
> ```python
> def render_function(context, do_dots):
>     c_user_name = context['user_name']
>     c_product_list = context['product_list']
>     c_format_price = context['format_price']
>
>     result = []
>     append_result = result.append
>     extend_result = result.extend
>     to_str = str
>
>     extend_result([
>         '<p>Welcome, ',
>         to_str(c_user_name),
>         '!</p>\n<p>Products:</p>\n<ul>\n'
>     ])
>     for c_product in c_product_list:
>         extend_result([
>             '\n    <li>',
>             to_str(do_dots(c_product, 'name')),
>             ':\n        ',
>             to_str(c_format_price(do_dots(c_product, 'price'))),
>             '</li>\n'
>         ])
>     append_result('\n</ul>\n')
>     return ''.join(result)
> ```
>
> 外层传入参数，调用该函数就能获取解析后的静态字符串。
>
> 注：该**模板**解析的字符串并不局限于`html`文本