#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <cmath>

#define TASK1
#define TASK2

const size_t N = 1000;
enum Point { empty = 0, lined = 1, overlaped = 2};

size_t hydrothermal_venture_1() {
    std::fstream file ("input");
    
    size_t overlapted_count = 0;
    int x1, y1, x2, y2;
    size_t matrix[N][N];
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            matrix[i][j] = Point::empty;
        }
    }
    
    for (std::string line; std::getline(file, line); ) {
        sscanf(line.c_str(), "%d,%d -> %d,%d", &x1, &y1, &x2, &y2);
        if (x1 == x2) {
            size_t min = std::min(y1, y2);
            size_t max = std::max(y1, y2);
            for (size_t y = min; y <= max; ++y) {
                if (matrix[x1][y] == Point::empty) {
                    matrix[x1][y] = Point::lined;
                } else if (matrix[x1][y] == Point::lined) {
                    matrix[x1][y] = Point::overlaped;
                    overlapted_count++;
                }
            }
        } else if (y1 == y2) {
            size_t min = std::min(x1, x2);
            size_t max = std::max(x1, x2);
            for (size_t x = min; x <= max; ++x) {
                if (matrix[x][y1] == Point::empty) {
                    matrix[x][y1] = Point::lined;
                } else if (matrix[x][y1] == Point::lined) {
                    matrix[x][y1] = Point::overlaped;
                    overlapted_count++;
                }
            }
        }
#ifdef TASK2
        else if (std::abs(x2 - x1) == std::abs(y2 - y1)) {
            size_t minX = std::min(x1, x2);
            size_t maxX = std::max(x1, x2);
            size_t y = minX == x1 ? y1 : y2;
            size_t adj;
            if (y == y1) {
                adj = y1 > y2 ? -1 : 1;
            } else {
                adj = y1 > y2 ? 1 : -1;
            }
            for (size_t x = minX; x <= maxX; ++x) {
                if (matrix[x][y] == Point::empty) {
                    matrix[x][y] = Point::lined;
                } else if (matrix[x][y] == Point::lined) {
                    matrix[x][y] = Point::overlaped;
                    overlapted_count++;
                }
                y += adj;
            }
        }
#endif
    }
    
    for (size_t x = 0; x < 10; ++x) {
        for (size_t y = 0; y < 10; ++y) {
            std::cout << matrix[y][x];
        }
        std::cout << std::endl;
    }
    
    return overlapted_count;
}

int main() {
#ifdef TASK1
    std::cout << hydrothermal_venture_1() << std::endl;
#endif
    return 0;
}
