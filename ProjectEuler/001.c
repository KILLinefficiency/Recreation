#include <stdio.h>

int main() {
    int sum = 0;
    for(int count = 1; count < 1000; count++) {
        if(count % 3 == 0 || count % 5 == 0) {
            sum += count;
        }
    }
    printf("%d\n", sum);
    return 0;
}
