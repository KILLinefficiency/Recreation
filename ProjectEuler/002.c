#include <stdio.h>

int main() {
    unsigned long first = 1;
    unsigned long second = 2;
    unsigned long sum_even = 0;

    while(second < 4000000) {
        if(second % 2 == 0) {
            sum_even += second;
        }

        unsigned long temp = second;
        second = second + first;
        first = temp;
    }

    printf("%ld\n", sum_even);
    return 0;
}
