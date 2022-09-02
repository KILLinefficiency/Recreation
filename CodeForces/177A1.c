#include <stdio.h>

int main() {
    int n, sum = 0;
    scanf("%d", &n);

    int mat[n][n];
    int pos = (n - 1) / 2;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    for(int pdx = 0; pdx < n; pdx++) {
        for(int pdy = 0; pdy < n; pdy++) {
            if((pdx == pdy) && (mat[pdx][pdy] != 101)) {
                sum += mat[pdx][pdy];
                mat[pdx][pdy] = 101;
            }
        }
    }

    for(int pdx = 0; pdx < n; pdx++) {
        for(int pdy = n - 1; pdy >= 0; pdy--) {
            if((pdx + pdy == n - 1) && (mat[pdx][pdy] != 101)) {
                sum += mat[pdx][pdy];
                mat[pdx][pdy] = 101;
            }
        }
    }

    for(int itr = 0; itr < n; itr++) {
        if(mat[itr][pos] != 101) {
            sum += mat[itr][pos];
            mat[itr][pos] = 101;
        }
        if(mat[pos][itr] != 101) {
            sum += mat[pos][itr];
            mat[pos][itr] = 101;
        }
    }

    printf("%d\n", sum);
    return 0;
}
