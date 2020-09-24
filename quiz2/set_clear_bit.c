#include <stdio.h>
#include <stdbool.h>
void binary(unsigned int n) {
    for (int i = 256; i > 0; i /= 2) {
        if (n & i) 
            printf(" 1");
        else
            printf(" 0");
    }
    printf("\n");
}

bool getBit(int n, int index) {
    return ((n & (1 << index)) > 0);
}

int setBit(int n, int index, bool b) {
    if (b)
        return (n | (1 << index));	
    int mask = ~(1 << index);
    return n & mask;
}

int main() {
    int num = 16, index;

    printf("Input\n");
    for (int i = 7; i >= 0; i--) 
        printf("%d ", getBit(num,i));
    printf("\n");

    /* set bit */
    index = 6;
    printf("# Setting %d-th bit\n", index);
    num = setBit(num, index, true);
    for (int i = 7; i >= 0; i--) 
        printf("%d ", getBit(num,i));
    printf("\n");

    /* unset (clear) bit */
    index = 4;
    printf("# Unsetting (Clearing) %d-th bit\n", index);
    num = setBit(num, index, false);
    for (int i = 7; i >= 0; i--) 
        printf("%d ", getBit(num,i));
    printf("\n");

    return 0;
}