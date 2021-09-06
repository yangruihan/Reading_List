#include <stdio.h>
#include <stdint.h>

#define EXE_LABEL(number) \
    printf("--------------------------------------\n"); \
    printf("----- e %s  ------\n", number); \
    printf("--------------------------------------\n");

int bis(int x, int m) {
    return x | m;
}

int bic(int x, int m) {
    return x & (~m);
}

int bool_or(int x, int y) {
    return bis(x, y);
}

int bool_xor(int x, int y) {
    return bic(y, x);
}

int main() {
    EXE_LABEL("2.12");
    uint32_t x = 0x87654321;
    printf("x=%#010X\n", x);
    uint32_t x1 = x & 0xff;
    printf("x1=%#010X\n", x1);
    uint32_t x2 = (~x & (~0xff)) | (x & 0xff);
    printf("x2=%#010X\n", x2);
    uint32_t x3 = x | 0xff;
    printf("x3=%#010X\n", x3);

    EXE_LABEL("2.13");
    uint8_t a1 = 0b00110010;
    uint8_t a2 = 0b10010001;
    printf("a1=%0x\n", bool_or(a1, a2));
    printf("a2=%0x\n", bool_xor(a1, a2));

    return 0;
}
