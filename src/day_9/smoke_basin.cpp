#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <queue>
#include <utility>

#define TASK_2
const size_t N = 100;
const size_t M = 100;
using point = std::pair<size_t, size_t>;

size_t fun() {
    std::fstream file("input");
    size_t count = 0;
    std::vector<std::vector<size_t>> arr(N + 2, std::vector<size_t>(M + 2, 9));
    std::vector<point> low_points;
    for (size_t i = 1; i < N + 1; ++i) {
        for (size_t j = 1; j < M + 1; ++j) {
            char c;
            file >> c;
            arr[i][j] = c - '0';
        }
    }
    for (size_t i = 1; i < N + 1; ++i) {
        for (size_t j = 1; j < M + 1; ++j) {
            if (arr[i][j] < arr[i][j-1] && arr[i][j] < arr[i][j+1] && arr[i][j] < arr[i+1][j] && arr[i][j] < arr[i-1][j]) {
                low_points.push_back({i, j});
            }
        }
    }
#if defined TASK_2
    std::vector<size_t> sums;
    for (point lp : low_points) {
        std::queue<point> q;
        q.push(lp);
        std::vector<std::vector<bool>> visited(N + 2, std::vector<bool>(M + 2, false));
        visited[lp.first][lp.second] = true;
        size_t sum = 0;
        while(!q.empty()) {
            point p = q.front();
            q.pop();
            sum++;
            
            if (arr[p.first + 1][p.second] < 9 && !visited[p.first + 1][p.second]) {
                q.push({p.first + 1, p.second});
                visited[p.first + 1][p.second] = true;
            }
            if (arr[p.first - 1][p.second] < 9 && !visited[p.first - 1][p.second]) {
                q.push({p.first - 1, p.second});
                visited[p.first - 1][p.second] = true;
            }
            if (arr[p.first][p.second + 1] < 9 && !visited[p.first][p.second + 1]) {
                q.push({p.first, p.second + 1});
                visited[p.first][p.second + 1] = true;
            }
            if (arr[p.first][p.second - 1] < 9 && !visited[p.first][p.second - 1]) {
                q.push({p.first, p.second - 1});
                visited[p.first][p.second - 1] = true;
            }
        }
        sums.push_back(sum);
    }
    std::sort(sums.begin(), sums.end(), std::greater<size_t>());
    count = sums[0] * sums[1] * sums[2];
#else
    for (point p : low_points) {
        count += 1 + arr[p.first][p.second];
    }
#endif
    return count;
}

int main() {
    std::cout << fun() << std::endl;
    return 0;
}
