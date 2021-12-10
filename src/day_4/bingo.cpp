#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

//#define TASK1
#define TASK2
const size_t BINGO_SIZE = 5;

size_t bingo_1() {
    std::fstream file("input");
    
    std::string nums_str;
    std::getline(file, nums_str);
    std::vector<size_t> nums;
    std::stringstream ss(nums_str);
    for (int i; ss >> i;) {
        nums.push_back(i);
        ss.ignore();
    }
    
#ifdef TASK1
    size_t win_num_index = nums.size() + 1;
#elif defined TASK2
    size_t win_num_index = 0;
#endif
    size_t win_res = 0;
    
    std::vector<size_t> matrix(BINGO_SIZE * BINGO_SIZE);
    std::vector<size_t> h_sum(BINGO_SIZE);
    std::vector<size_t> v_sum(BINGO_SIZE);

    while (!file.eof()) {
        
        // clean old data
        std::fill(h_sum.begin(), h_sum.end(), 0);
        std::fill(v_sum.begin(), v_sum.end(), 0);
        bool bingo = false;
        
        // read new data
        for (size_t h = 0; h < BINGO_SIZE; ++h) {
            for (size_t v = 0; v < BINGO_SIZE; ++v) {
                size_t num;
                file >> num;
                matrix[h * BINGO_SIZE + v] = num;
                h_sum[h] += num;
                v_sum[v] += num;
            }
        }
        
        // find bingo num index
        for (size_t num_index = 0; num_index < nums.size(); ++num_index) {
            size_t num = nums[num_index];
            for (size_t h = 0; h < BINGO_SIZE; ++h) {
                for (size_t v = 0; v < BINGO_SIZE; ++v) {
                    if (matrix[h * BINGO_SIZE + v] == num) {
                        h_sum[h] -= num;
                        v_sum[v] -= num;
                        if (h_sum[h] == 0 || v_sum[v] == 0) {
                            bingo = true;
                        }
                    }
                }
            }
            
            if (bingo) {
#ifdef TASK1
                if (num_index < win_num_index) {
#elif defined TASK2
                if (num_index > win_num_index) {
#endif
                    win_num_index = num_index;
                    win_res = 0;
                    for (size_t h : v_sum) {
                        win_res += h;
                    }
                    win_res *= num;
                }
                break;
            }
        }
    }
    return win_res;
}

int main() {
    std::cout << bingo_1() << std::endl;
    return 0;
}
