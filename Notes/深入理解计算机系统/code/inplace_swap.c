#include <stdio.h>

void inplace_swap(int *x, int *y) {
    *y = *x ^ *y; 
    *x = *x ^ *y; // *x = *x ^ *x ^ *y = *y
    *y = *x ^ *y; // *y = *y ^ *x ^ *y = *x
}

void reverse_array(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt - 1; first < last; first++, last--) {
        inplace_swap(&a[first], &a[last]);
    }
}

int main() {
    int a, b;

    a = 2;
    b = 5;

    printf("before swap %d %d\n", a, b);
    inplace_swap(&a, &b);
    printf("after swap %d %d\n", a, b);

    int a1[] = { 1, 2, 3, 4 };
    reverse_array(a1, 4);
    for (int i = 0; i < 4; i++) {
        printf("%d ", a1[i]);
    }
    printf("\n");

    int a2[] = { 1, 2, 3, 4, 5 };
    reverse_array(a2, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", a2[i]);
    }
    printf("\n");

    return 0;
}
