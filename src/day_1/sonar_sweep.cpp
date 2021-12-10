#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//#define TASK1
#define TASK2

size_t sonar_sweep_1(std::string filepath) {
    std::fstream f(filepath);

    size_t increases = 0;
    size_t prev;
    f >> prev;
    for (size_t val; f >> val;) {
        if (prev < val) {
            ++increases;
        }
        prev = val;
    }
    return increases;
}

size_t sonar_sweep_2(std::string filepath) {
    std::fstream f1(filepath);
    std::fstream f2(filepath);
    f2.ignore(sizeof(int) * 3);

    size_t increases = 0;
    for (size_t first, second; f2 >> second; ) {
        f1 >> first;
        if (second > first) {
            ++increases;
        }
    }
    return increases;
}

int main() {
#ifdef TASK1
    std::cout << sonar_sweep_1("input.txt") << std::endl;
#endif
#ifdef TASK2
    std::cout << sonar_sweep_2("input.txt") << std::endl;
#endif
    return 0;
}
