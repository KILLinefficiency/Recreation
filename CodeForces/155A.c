#include <stdio.h>

int main() {
    int n, amazing = 0;
    scanf("%d", &n);

    int r[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &r[i]);

    int best = r[0];
    int worst = r[0];

    for(int x = 0; x < n - 1; x++) {
        if(r[x] > r[x + 1] && r[x + 1] < worst) {
            amazing++;
            worst = r[x + 1];
        }
        if(r[x] < r[x + 1] && r[x + 1] > best) {
            amazing++;
            best = r[x + 1];
        }
    }

    printf("%d\n", amazing);
    return 0;
}
