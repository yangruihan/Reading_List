# C++ Primer（英文第五版）笔记
- 创建人 C.y.(yangruihan)
- 创建时间 2017/1/19

## Chapter1 Getting Started
### About `std::cout` and `std::endl`
Writing `endl` has the effect of ending the current line and flushing the ***buffer*** associated with that device. Programmers often add print statements during debugging. Such statements should *always* flush the stream. Otherwise, if the program crashes, output may be left in the buffer, leading to incorrect inferences about where the program crashed.
