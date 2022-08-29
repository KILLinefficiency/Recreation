#include <stdio.h>

int main() {
    unsigned long sum_square = (100 * (100 + 1) * ((2 * 100) + 1)) / 6;
    unsigned long square_sum = ((100 * (100 + 1)) / 2) * ((100 * (100 + 1)) / 2);
    unsigned long diff = square_sum - sum_square;
    printf("%ld\n", diff);
    return 0;
}
