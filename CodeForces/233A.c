#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if((n % 2) != 0) {
        printf("%d\n", -1);
        return 0;
    }

    int p[n];
    for(int x = 0; x < n; x++)
        p[x] = x + 1;

    for(int i = 0; i < n - 1; i++) {
        if((i % 2 == 0) && ((i + 1) % 2 != 0)) {
            int next = p[i + 1];
            p[i + 1] = p[i];
            p[i] = next;
        }
    }

    for(int y = 0; y < n; y++)
        printf("%d ", p[y]);

    printf("\n");
    return 0;
}
