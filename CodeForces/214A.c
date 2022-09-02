#include <stdio.h>

int main() {
    int n, m, req;
    scanf("%d %d", &n, &m);

    int max = n;
    if(m > n)
        max = m;
    
    for(int a = 0; a <= 1000; a++)
        for(int b = 0; b <= 1000; b++)
            if((a * a) + b == n && a + (b * b) == m)
                req++;

    printf("%d\n", req);
    return 0;
}
