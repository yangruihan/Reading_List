# C++ Primer（英文第五版）笔记
- 创建人 C.y.(yangruihan)
- 创建时间 2017/1/19

## Chapter1 Getting Started
### About `std::cout` and `std::endl`
Writing `endl` has the effect of ending the current line and flushing the ***buffer*** associated with that device. Programmers often add print statements during debugging. Such statements should *always* flush the stream. Otherwise, if the program crashes, output may be left in the buffer, leading to incorrect inferences about where the program crashed.

## Chapter2 Variables and basic Types
### Minimum sizes of arithmetic types
The standard guarantees minimum sizes as following:

|Type|Meaning|Minimum Size|
|:---|:---|:---|
|bool|boolean|NA|
|char|character|8 bits|
|wchar\_t|wide character|16 bits|
|char16\_t|Unicode character|16 bits|
|char32\_t|Unicode character|32 bits|
|short|short integer|16 bits|
|int|integer|16 bits|
|long|long integer|32 bits|
|long long|long integer|64 bits|
|float|single-precision floating-point|6 significant digits|
|double|double-precision floating-point|10 significant digits|
|long double|extended-precision floating-point|10 significant digits|

**However, compilers are allowed to use larger sizes for these type. Because the number of bits varies, the largest(or smallest) value that a type can represent also varies.**

### A few rules of thumb can be useful in deciding which type to use
- Use an unsigned type when you know that the values cannot be negative.
- Use `int` for integer arithmetic. `short` is usually too small and, in practice, `long` often has the same size as `int`. If your data values are larger than the minimum guaranteed size of an `int`, then use `long long`.
- Do not use plain `char` or `bool` in arithmetic expressions. Use them *only* to hold characters or truth values. Computations using `char` are especially problematic because `char` is signed on some machines and `unsigned` on others. If you need a tiny integer, explicitly specify either `signed char` or `unsigned char`.
- Use `double` for floating-point computations; `float` usually does not have enough precision, and the cost of double-precision calculations versus single-precision is negligible. In fact, on some machines, double-precision operations are faster than single. The precision offered by `long double` usually is unnecessary and often entails considerable run-time cost.

### Type conversions
- When we assign one of the non`bool` arithmetic types to a `bool` object, the result is `false` if the value is `0` and `true` otherwise.
- When we assign a `bool` to one of the other arithmetic types, the resulting value is `1` if the `bool` is true and `0` if the `bool` is false.
- When we assign a floating-point value to an object of integral types, the value is truncated. The value that is stored is the part before the decimal point.
- When we assign an integral value to an object of floating-point type, the fractional part is zero. Precision may be lost if the integer has more bits than the floating-point object can accommodate.
- If we assign an out-of-range value to an object of unsigned type, the result is the remainder of the value modulo the number of values the target type can hold. For example, an 8-bit `unsigned char` can hold values from `0` through `255`, inclusive. If we assign a value outside this range, the compiler assigns the remainder of that value modulo 256. Therefore, assigning `-1` to an 8-bit `unsigned char` gives that object the value `255`.
- If we assign an out-of-range value to an object of signed type, the result is **undefined**. The program might appear to work, it might crash, or it might produce garbage values.

### Escape sequence
|name|escape sequence|
|:---:|:---:|
|newline|`\n`|
|horizontal tab|`\t`|
|alert(bell)|`\a`|
|vertical tab|`\v`|
|backspace|`\b`|
|double quote|`\"`|
|backslash|`\\`|
|question mark|`\?`|
|single quote|`\'`|
|carriage return|`\r`|
|formfeed|`\f`|

### Specifying the type of a literal
#### Character and Character String Literals
|Prefix|Meaning|Type|
|:---|:---|:---|
|u|Unicode 16 character|char16\_t|
|U|Unicode 32 character|char32\_t|
|L|wide character|wchar_t|
|u8|utf-8(string literals only)|char|

#### Integer Literals
|Suffix|Minimum Type|
|:---|:---|
|u or U|unsigned|
|l or L|long|
|ll or LL|long long|

#### Floating-Point Literals
|Suffix|Type|
|:---|:---|
|f of F|float|
|l or L|long double|
