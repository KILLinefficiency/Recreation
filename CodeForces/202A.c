#include <stdio.h>
#include <string.h>

int main() {
    char str[11];
    scanf("%s", str);
    int len = strlen(str);
    int count = 0;

    char largest = str[0];
    for(int c = 1; c < len; c++) {
        if(str[c] > largest) {
            largest = str[c];
        }
    }
    
    for(int x = 0; x < len; x++) {
        if(str[x] == largest) {
            count++;
        }
    }

    char final[count + 1];
    for(int a = 0; a < count; a++) {
        final[a] = largest;
    }
    final[count] = '\0';

    printf("%s\n", final);
    return 0;
}
