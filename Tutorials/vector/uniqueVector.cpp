#include <iostream>
#include <vector>
#include <algorithm>

bool vectorCompare(const std::vector<int>& a, const std::vector<int>& b) {
    return a < b;
}

int main() {
    std::vector<std::vector<int>> vec = {{1, 2, 3}, {2, 3, 4}, {1, 2, 3}, {5, 6, 7}, {1, 2, 3}};

    std::sort(vec.begin(), vec.end(), vectorCompare);
    auto last = std::unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());

    for (const auto& v : vec) {
        for (const auto& i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
