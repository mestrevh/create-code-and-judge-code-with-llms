/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

struct NameInfo {
    std::string name;
    int d_free;
    int r_free;
};

bool compareNames(const NameInfo& a, const NameInfo& b) {
    return std::min(a.d_free, b.r_free) > std::min(b.d_free, a.r_free);
}

void solve() {
    int f;
    while (std::cin >> f) {
        std::vector<NameInfo> names(f);
        for (int i = 0; i < f; ++i) {
            std::cin >> names[i].name;

            int d_pending = 0;
            int r_unmatched = 0;
            for (char c : names[i].name) {
                if (c == 'D') {
                    d_pending++;
                } else if (c == 'R') {
                    if (d_pending > 0) {
                        d_pending--;
                    } else {
                        r_unmatched++;
                    }
                }
            }
            names[i].d_free = d_pending;
            names[i].r_free = r_unmatched;
        }

        std::sort(names.begin(), names.end(), compareNames);

        std::string big_string = "";
        for (const auto& info : names) {
            big_string += info.name;
        }

        int pairs = 0;
        char looking_for = 'D';
        for (char c : big_string) {
            if (c == 'D' && looking_for == 'D') {
                looking_for = 'R';
            } else if (c == 'R' && looking_for == 'R') {
                looking_for = 'D';
                pairs++;
            }
        }
        std::cout << pairs << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
