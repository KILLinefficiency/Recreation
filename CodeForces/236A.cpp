#include <iostream>
#include <unordered_map>

int main() {
    std::string name;
    std::getline(std::cin, name);
    int len = name.size();
    int distinct = 0;
    std::unordered_map<char, int> chrs;

    for(int i = 0; i < len; i++) {
        chrs[name[i]]++;
    }

    std::unordered_map<char, int>::iterator itr;
    for(itr = chrs.begin(); itr != chrs.end(); itr++) {
        if(itr->second >= 1) {
            distinct++;
        }
    }

    if(distinct % 2 == 0) {
        std::cout << "CHAT WITH HER!" << std::endl;
    }
    else {
        std::cout << "IGNORE HIM!" << std::endl;
    }

    return 0;
}
