#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <deque>

#define TASK_2

size_t char_to_score(char c) {
    switch (c) {
        case ']': return 57;
        case ')': return 3;
        case '}': return 1197;
        case '>': return 25137;
    }
    return 0;
}
size_t char_to_score_2(char c) {
    switch (c) {
        case '(': return 1;
        case '[': return 2;
        case '{': return 3;
        case '<': return 4;
    }
    return 0;
}
const std::string closing(")]}>");
const std::string pairs("()[]{}<>");

size_t fun() {
    std::fstream file("input");
    size_t result = 0;
    std::vector<size_t> ress;

    for (std::string line; std::getline(file, line); ) {
        std::deque<char> s;
        bool flag = false;
        s.push_back('0');
        for (size_t i = 0; i < line.size(); ++i) {
            if (closing.find(line[i]) == std::string::npos) {
                s.push_back(line[i]);
            } else {
                std::string str;
                str += s.back();
                str += line[i];
                if (pairs.find(str) == std::string::npos) {
                    result += char_to_score(line[i]);
                    flag = true;
                    break;
                }
                s.pop_back();
            }
        }
#if defined TASK_2
        if (flag) {
            continue;
        }
        
        s.pop_front();
        size_t score = 0;
        while (!s.empty()) {
            score = score * 5 + char_to_score_2(s.back());
            s.pop_back();
        }
        ress.push_back(score);
    }
    std::sort(ress.begin(), ress.end());
    result = ress[ress.size()/2];
#endif
    return result;
}

int main() {
    std::cout << fun() << std::endl;
    return 0;
}
