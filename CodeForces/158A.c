#include <stdio.h>

int main() {
    int n, k, advancers = 0;
    scanf("%d %d", &n, &k);

    int e[n];
    for(int a = 0; a < n; a++)
        scanf("%d", &e[a]);

    int kth = e[k - 1];

    for(int x = 0; x < n; x++) {
        if(e[x] >= kth && e[x] > 0) {
            advancers++;
        }
    }

    printf("%d\n", advancers);
    return 0;
}
