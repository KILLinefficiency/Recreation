#include <stdio.h>

int main() {
    int p[4];
    int req = 0;

    for(int i = 0; i < 4; i++)
        scanf("%d", &p[i]);
    
    for(int y = 0; y < 4; y++) {
        for(int x = 0; x < 3; x++) {
            if(p[x + 1] < p[x]) {
                int temp = p[x + 1];
                p[x + 1] = p[x];
                p[x] = temp;
            }
        }
    }

    for(int a = 0; a < 3; a++) {
        if(p[a] == p[a + 1])
            req++;
    }
    
    printf("%d\n", req);
    return 0;
}
