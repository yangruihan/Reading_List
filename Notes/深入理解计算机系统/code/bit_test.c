#include <stdio.h>

int main() {
    long x = 0x87654321;
    printf("x=%#010lx\n", x);
    long x1 = x & 0xff;
    printf("x1=%#010lx\n", x1);
    return 0;
}
