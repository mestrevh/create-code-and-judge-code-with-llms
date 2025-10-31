/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

bool is_palindrome(const std::string& s) {
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());
    return s == reversed_s;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::string> board(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> board[i];
    }

    int k;
    std::cin >> k;

    int winners = 0;

    for (int i = 0; i < k; ++i) {
        int t;
        std::string s;
        std::cin >> t >> s;

        if (is_palindrome(s)) {
            winners++;
            continue;
        }

        int r = 0, c = 0;
        bool safe = true;
        std::vector<std::pair<int, int>> path;

        if (board[r][c] != 'o' && board[r][c] != 'x') {
            safe = false;
        } else {
            path.push_back({r, c});
        }
        
        if (safe) {
            for (char move : s) {
                if (move == 'C') r--;
                else if (move == 'B') r++;
                else if (move == 'D') c++;
                else if (move == 'E') c--;

                if (r < 0 || r >= n || c < 0 || c >= n) {
                    safe = false;
                    break;
                }

                if (board[r][c] != 'o' && board[r][c] != 'x') {
                    safe = false;
                    break;
                }
                
                path.push_back({r, c});
            }
        }

        if (safe) {
            winners++;
            for (const auto& pos : path) {
                if (board[pos.first][pos.second] == 'x') {
                    board[pos.first][pos.second] = 'h';
                }
            }
        }
    }

    std::cout << winners << std::endl;

    return 0;
}
