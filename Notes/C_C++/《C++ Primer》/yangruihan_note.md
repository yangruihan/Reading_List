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
