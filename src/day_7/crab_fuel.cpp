#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <cmath>

#define TASK1
//#define TASK2

size_t crab_fuel() {
    std::fstream file("input");
    std::vector<int> positions;
    size_t pos_sum = 0;
    
    for (int num_; file >> num_; ) {
        pos_sum += num_;
        positions.push_back(num_);
        file.ignore();
    }
    const size_t pos_count = positions.size();
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
#if defined TASK2
    int best_pos_1 =  pos_sum / pos_count;
    int best_pos_2 =  pos_sum / pos_count + 1;

    size_t sum_res_1 = 0;
    size_t sum_res_2 = 0;
    for (size_t i = 0; i < pos_count; ++i) {
        sum_res_1 += ((std::abs(best_pos_1 - positions[i]) + 1) * std::abs(best_pos_1 - positions[i])) / 2;
        sum_res_2 += ((std::abs(best_pos_2 - positions[i]) + 1) * std::abs(best_pos_2 - positions[i])) / 2;
    }
    int sum_res = std::min(sum_res_1,sum_res_2);
    
#elif defined TASK1
    std::sort(positions.begin(), positions.end());
    std::cout << "p = " << positions[positions.size() / 2] << std::endl;
    size_t sum_res = pos_sum;
    for (size_t i = 0; i < pos_count / 2; ++i) {
        sum_res -= 2 * positions[i];
    }
#endif
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    // 0.00000000715473 sec = 715473 ns
    
    return sum_res;
}

int main() {
    std::cout << crab_fuel() << std::endl;
    return 0;
}
