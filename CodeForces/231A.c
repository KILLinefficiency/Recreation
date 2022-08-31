#include <stdio.h>

int main() {
    int probs = 0;
    int n;
    scanf("%d", &n);

    for(int t = 0; t < n; t++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int count = a + b + c;
        if(count > 1) {
            probs++;
        }
    }

    printf("%d\n", probs);
    return 0;
}
