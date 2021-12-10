#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

const size_t N = 12;
//#define TASK1
#define TASK2

size_t diagnostics_1() {
    std::fstream f("input.txt");
    size_t line_count = 0;
    size_t counter_arr[N]{0};
    for (std::string line; getline(f, line); ++line_count) {
        for (size_t i = 0; i < N; ++i) {
            counter_arr[i] += line[i] == '1';
        }
    }
    size_t a = 0, b = 0;
    for (size_t i = 0; i < N; ++i) {
        size_t common = counter_arr[i] * 2 >= line_count;
        a = a << 1 | common;
        size_t uncommon = counter_arr[i] * 2 > line_count;
        b = b << 1 | uncommon;
    }
    return a * b;
}

size_t diagnostics_2() {
    std::fstream f("input.txt");
    std::string a_condition, b_condition;
    bool a_finished = false, b_finished = false;
    for (size_t i = 0; !(a_finished && b_finished) && i < N; ++i) {
        f.clear();
        f.seekg(0);
        size_t a_condition_count = 0, b_condition_count = 0;
        size_t a_common_1 = 0, b_common_1 = 0;
        for (std::string line; getline(f, line); ) {
            if (!a_finished && a_condition == line.substr(0, i)) {
                    a_condition_count++;
                    a_common_1 += line[i] == '1';
            }
            
            if (!b_finished && b_condition == line.substr(0, i)) {
                    b_condition_count++;
                    b_common_1 += line[i] == '1';
            }
        }
        
        if (!a_finished) {
            a_condition += a_common_1 * 2 >= a_condition_count ? '1' : '0';
            if (a_condition_count == 2) {
                a_finished = true;
            }
        }
        
        if (!b_finished) {
            b_condition += b_common_1 * 2 >= b_condition_count ? '0' : '1';
            if (b_condition_count - b_common_1 == 1 || b_common_1 == 1) {
                b_finished = true;
            }
        }
    }
    
    std::string a_res_str, b_res_str;
    f.clear();
    f.seekg(0);
    for (std::string line; getline(f, line); ) {
        if (a_res_str.empty() && std::equal(a_condition.begin(), a_condition.end(), line.begin())) {
            a_res_str = line;
        }
        if (b_res_str.empty() && std::equal(b_condition.begin(), b_condition.end(), line.begin())) {
            b_res_str = line;
        }
    }
    
    size_t a_res = 0, b_res = 0;
    for (size_t i = 0; i < a_res_str.size(); ++i) {
        a_res = a_res << 1 | (a_res_str[i] == '1');
    }
    for (size_t i = 0; i < b_res_str.size(); ++i) {
        b_res = b_res << 1 | (b_res_str[i] == '1');
    }
    return a_res * b_res;
}

int main() {
#ifdef TASK1
    std::cout << diagnostics_1() << std::endl;
#endif
#ifdef TASK2
    std::cout << diagnostics_2() << std::endl;
#endif
    return 0;
}

