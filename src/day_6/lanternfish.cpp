#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <cmath>

#define TASK1
#define TASK2

const size_t BIG_LOOP_SIZE = 7;
const size_t LITTLE_LOOP_SIZE = 2;
#ifdef TASK2
const size_t DAYS = 256;
#elif defined TASK1
const size_t DAYS = 80;
#endif

size_t lanternfish() {
    std::fstream file("input");
    
    size_t big_loop[BIG_LOOP_SIZE]{0};
    size_t little_loop[LITTLE_LOOP_SIZE]{0};
    size_t i_big = 0, i_little = 0;
    
    size_t res = 0;
    std::string number_as_string;
    while (std::getline(file, number_as_string, ',')) {
        big_loop[std::stoi(number_as_string)]++;
        res++;
    }
    
    for (size_t i = 0; i < DAYS; ++i) {
        size_t new_fish = big_loop[i_big];
        res += new_fish;
        big_loop[i_big] += little_loop[i_little];
        little_loop[i_little] = new_fish;
        
        i_big = (i_big + 1) % BIG_LOOP_SIZE;
        i_little = (i_little + 1) % LITTLE_LOOP_SIZE;
    }
    
    return res;
}

int main() {
    std::cout << lanternfish() << std::endl;
    return 0;
}
