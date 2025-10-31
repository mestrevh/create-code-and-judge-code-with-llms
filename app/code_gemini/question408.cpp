/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

const bool segments[10][7] = {
    // 0, 1, 2, 3, 4, 5, 6
    {true, true, true, true, true, true, false},   // 0
    {false, true, true, false, false, false, false}, // 1
    {true, true, false, true, true, false, true},    // 2
    {true, true, true, true, false, false, true},    // 3
    {false, true, true, false, false, true, true},   // 4
    {true, false, true, true, false, true, true},    // 5
    {true, false, true, true, true, true, true},     // 6
    {true, true, true, false, false, false, false},  // 7
    {true, true, true, true, true, true, true},      // 8
    {true, true, true, true, false, true, true}      // 9
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int s;
    std::string n;

    while (std::cin >> s >> n && (s != 0 || n != "0")) {
        
        // Top horizontal (segment 0)
        for (size_t i = 0; i < n.length(); ++i) {
            if (i > 0) std::cout << " ";
            int digit = n[i] - '0';
            std::cout << " ";
            char c = segments[digit][0] ? '-' : ' ';
            for (int j = 0; j < s; ++j) {
                std::cout << c;
            }
            std::cout << " ";
        }
        std::cout << "\n";

        // Top vertical (segments 5 & 1)
        for (int k = 0; k < s; ++k) {
            for (size_t i = 0; i < n.length(); ++i) {
                if (i > 0) std::cout << " ";
                int digit = n[i] - '0';
                char c_left = segments[digit][5] ? '|' : ' ';
                char c_right = segments[digit][1] ? '|' : ' ';
                std::cout << c_left;
                for (int j = 0; j < s; ++j) {
                    std::cout << " ";
                }
                std::cout << c_right;
            }
            std::cout << "\n";
        }

        // Middle horizontal (segment 6)
        for (size_t i = 0; i < n.length(); ++i) {
            if (i > 0) std::cout << " ";
            int digit = n[i] - '0';
            std::cout << " ";
            char c = segments[digit][6] ? '-' : ' ';
            for (int j = 0; j < s; ++j) {
                std::cout << c;
            }
            std::cout << " ";
        }
        std::cout << "\n";

        // Bottom vertical (segments 4 & 2)
        for (int k = 0; k < s; ++k) {
            for (size_t i = 0; i < n.length(); ++i) {
                if (i > 0) std::cout << " ";
                int digit = n[i] - '0';
                char c_left = segments[digit][4] ? '|' : ' ';
                char c_right = segments[digit][2] ? '|' : ' ';
                std::cout << c_left;
                for (int j = 0; j < s; ++j) {
                    std::cout << " ";
                }
                std::cout << c_right;
            }
            std::cout << "\n";
        }

        // Bottom horizontal (segment 3)
        for (size_t i = 0; i < n.length(); ++i) {
            if (i > 0) std::cout << " ";
            int digit = n[i] - '0';
            std::cout << " ";
            char c = segments[digit][3] ? '-' : ' ';
            for (int j = 0; j < s; ++j) {
                std::cout << c;
            }
            std::cout << " ";
        }
        std::cout << "\n";
        
        std::cout << "\n";
    }

    return 0;
}
