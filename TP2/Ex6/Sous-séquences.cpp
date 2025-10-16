#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> lis_sequence(const std::vector<int>& A) {
    if (A.empty()) return {};

    int n = static_cast<int>(A.size());
    std::vector<int> tail;
    std::vector<int> indices;
    std::vector<int> prev(n, -1);

    for (int i = 0; i < n; ++i) {
        auto it = std::lower_bound(tail.begin(), tail.end(), A[i]);

        if (it == tail.end()) {
            if (!tail.empty()) {
                prev[i] = indices.back();
            }
            tail.push_back(A[i]);
            indices.push_back(i);
        } else {
            int pos = it - tail.begin();
            tail[pos] = A[i];
            indices[pos] = i;
            if (pos > 0) {
                prev[i] = indices[pos - 1];
            }
        }
    }

    std::vector<int> lis;
    for (int k = indices.back(); k != -1; k = prev[k]) {
        lis.push_back(A[k]);
    }
    std::reverse(lis.begin(), lis.end());

    return lis;
}

int main() {
    std::vector<int> seq = {1, 2, 3, 4, 9, 10, 5, 6, 7};
    std::vector<int> lis = lis_sequence(seq);

    std::cout << "Longueur de la Liste: " << lis.size() << std::endl;
    std::cout << "Séquence Liste: ";
    for (size_t i = 0; i < lis.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << lis[i];
    }
    std::cout << std::endl;

    return 0;
}