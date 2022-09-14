// Work in Progress!

#include <iostream>
#include <vector>

int abs(int num) {
    if(num < 0) {
        num = -num;
    }
    return num;
}

int main() {
    int t, n;
    std::cin >> t;
    std::vector<std::string> res;
    for(int r = 0; r < t; r++) {
        std::cin >> n;
        std::vector<int> a(n);
        for(int l = 0; l < n; l++) {
            std::cin >> a[l];
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i] == -1 || a[j] == -1) {
                    continue;
                }
                if(abs(a[i] - a[j]) <= 1 && i != j) {
                    int min = a[i];
                    int min_index = i;
                    if(a[j] < a[i]) {
                        min = a[j];
                        min_index = j;
                    }
                    a[min_index] = -1;
                }
            }
        }

        int count = 0;
        for(int x : a) {
            if(x > 0) {
                count++;
            }
        }
        if(count == 1) {
            res.push_back("YES");
        }
        else {
            res.push_back("NO");
        }
    }
    
    for(std::string ans : res) {
        std::cout << ans << std::endl;
    }
    return 0;
}
