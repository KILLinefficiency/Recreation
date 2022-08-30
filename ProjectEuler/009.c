#include <stdio.h>

int main() {
    int prod = 0;
    for(int x = 1; x < 1001; x++) {
        for(int y = x; y < 1001; y++) {
            for(int z = y; z < 1001; z++) {
                if(x + y + z == 1000) {
                    if(((x * x) + (y * y)) == z * z) {
                        prod = x * y * z;
                    }
                }
            }
        }
    }
    printf("%d\n", prod);
    return 0;
}
