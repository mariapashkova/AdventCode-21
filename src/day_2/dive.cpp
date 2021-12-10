#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#define TASK1
#define TASK2

size_t dive_1() {
    size_t x = 0, y = 0;
    std::fstream f("input.txt");
    std::string comand;
    size_t val;
    while (f >> comand >> val) {
        if (comand == "up") {
            y -= val;
        } else if (comand == "down") {
            y += val;
        } else {
            x += val;
        }
    }
    return x * y;
}

size_t dive_2() {
    size_t x = 0, y = 0, aim = 0;
    std::fstream f("input.txt");
    std::string comand;
    size_t val;
    while (f >> comand >> val) {
        if (comand == "up") {
            aim -= val;
        } else if (comand == "down") {
            aim += val;
        } else {
            x += val;
            y += (aim * val);
        }
    }
    return x * y;
}

int main() {
#ifdef TASK1
    std::cout << dive_1() << std::endl;
#endif
#ifdef TASK2
    std::cout << dive_2() << std::endl;
#endif
    return 0;
}
