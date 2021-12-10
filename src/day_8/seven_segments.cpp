#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <cmath>

#define TASK_2

size_t fun() {
    std::fstream file("input");
    size_t count = 0;
    size_t uniq_nums[10] = {0, 0, 1, 7, 4, 0, 0, 8, 0, 0};
#if defined TASK_2
    //      0(6)
    //  5(4)   1(4)
    //      6(5)
    //  4(3)   2(5)
    //      3(6)
    std::string digits[10];
    char signal_val[7];
    for (std::string line; std::getline(file, line); ) {
        size_t letters_count[7]{0};

        std::istringstream ss(line);
        std::string num;
        for (size_t i = 0; i < 10; ++i) {
            ss >> num;
            if (uniq_nums[num.size()]) {
                digits[uniq_nums[num.size()]] = num;
            } else {
                for (size_t j = 0; j < num.size(); ++j) {
                    letters_count[num[j] - 'a']++;
                }
            }
        }
        
        // 0
        signal_val[0] = digits[7][0] + digits[7][1] + digits[7][2] - digits[1][0] - digits[1][1];
        // 1, 2
        signal_val[1] = letters_count[digits[1][0] - 'a'] == 4 ? digits[1][0] : digits[1][1];
        signal_val[2] = digits[1][0] + digits[1][1] - signal_val[1];
        // other
        for (size_t i = 0; i < 7; ++i) {
            char l = 'a' + i;
            if (letters_count[i] == 3) {
                signal_val[4] = l;
            } else if (letters_count[i] == 4 && signal_val[1] != l) {
                signal_val[5] = l;
            } else if (letters_count[i] == 5 && signal_val[2] != l) {
                signal_val[6] = l;
            } else if (letters_count[i] == 6 && signal_val[0] != l) {
                signal_val[3] = l;
            }
        }
        
        // numbers
        
        ss.ignore(3);
        size_t res_num = 0;
        for (size_t i = 0; i < 4; ++i) {
            ss >> num;
            if (uniq_nums[num.size()]) {
                res_num = res_num * 10 + uniq_nums[num.size()];
            } else {
                if (num.size() == 5) {
                    if (num.find(signal_val[2]) == std::string::npos) {
                        res_num = res_num * 10 + 2;
                    } else if (num.find(signal_val[5]) == std::string::npos) {
                        res_num = res_num * 10 + 3;
                    } else {
                        res_num = res_num * 10 + 5;
                    }
                } else {
                    if (num.find(signal_val[6]) == std::string::npos) {
                        res_num = res_num * 10;
                    } else if (num.find(signal_val[1]) == std::string::npos) {
                        res_num = res_num * 10 + 6;
                    } else {
                        res_num = res_num * 10 + 9;
                    }
                }
            }
        }
        std::cout << res_num << std::endl;
        count += res_num;
    }
#else
    for (std::string line; std::getline(file, line); ) {
        std::istringstream ss(line);
        std::string digit;
        do {
            ss >> digit;
        } while (digit != "|");
        for (size_t i = 0; i < 4; ++i) {
            ss >> digit;
            count += uniq_nums[digit.size()] ? 1 : 0;
        }
    }
#endif
    return count;
}

int main() {
    std::cout << fun() << std::endl;
    return 0;
}
