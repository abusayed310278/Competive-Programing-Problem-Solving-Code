#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<bool> present(n + 1, false);
    
    for (int i = 0; i < n - 1; ++i) {
        int num;
        std::cin >> num;
        present[num] = true;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (!present[i]) {
            std::cout << i << std::endl;
            break;
        }
    }
    
    return 0;
}
