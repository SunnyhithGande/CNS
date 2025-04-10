#include <stdio.h>

int main() {
    int a = 10;  // Example input
    int b = 5;   // Example input

    printf("a = %d, b = %d\n\n", a, b);

    // Bitwise AND
    printf("a & b = %d\n", a & b);

    // Bitwise OR
    printf("a | b = %d\n", a | b);

    // Bitwise XOR
    printf("a ^ b = %d\n", a ^ b);

    // Bitwise NOT
    printf("~a = %d\n", ~a);
    printf("~b = %d\n", ~b);

    // Left Shift
    printf("a << 1 = %d\n", a << 1);
    printf("b << 1 = %d\n", b << 1);

    // Right Shift
    printf("a >> 1 = %d\n", a >> 1);
    printf("b >> 1 = %d\n", b >> 1);

    return 0;
}
