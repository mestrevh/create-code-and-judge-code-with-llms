/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

void simulate_clock(std::string& s) {
    if (s.empty()) {
        return;
    }

    bool cascade = (s[0] == 'O');
    s[0] = (s[0] == 'O' ? 'X' : 'O');

    if (cascade) {
        for (size_t i = 1; i < s.length(); ++i) {
            if (s[i] == 'O') {
                s[i] = 'X';
            } else {
                s[i] = 'O';
                break;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int R;
    std::cin >> R;

    std::vector<std::string> results;
    if (R > 0) {
        results.reserve(R);
    }

    for (int i = 0; i < R; ++i) {
        std::string s;
        long long f;
        std::cin >> s >> f;
        for (long long j = 0; j < f; ++j) {
            simulate_clock(s);
        }
        std::cout << s << "\n";
        results.push_back(s);
    }

    if (R > 0) {
        std::string final_str = results[0];
        for (size_t i = 1; i < results.size(); ++i) {
            if (final_str.length() % 2 == 0) {
                if (final_str.back() == results[i].front()) {
                    final_str += '@';
                } else {
                    final_str += '$';
                }
            } else {
                if (final_str.back() == results[i].front()) {
                    final_str += '#';
                } else {
                    final_str += '%';
                }
            }
            final_str += results[i];
        }
        std::cout << final_str << "\n";
    }

    return 0;
}
