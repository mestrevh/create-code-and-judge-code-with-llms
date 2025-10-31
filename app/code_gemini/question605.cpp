/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

void computeLPSArray(const std::string& pat, int M, std::vector<int>& lps) {
    int length = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s, p;
    std::cin >> s >> p;

    int n = s.length();
    int m = p.length();

    if (m == 0 || m > n) {
        std::cout << -1 << "\n";
        return 0;
    }

    std::vector<int> lps(m);
    computeLPSArray(p, m, lps);

    std::vector<int> result_indices;
    int i = 0;
    int j = 0;
    while (i < n) {
        if (p[j] == s[i]) {
            i++;
            j++;
        }
        if (j == m) {
            result_indices.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && p[j] != s[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    if (result_indices.empty()) {
        std::cout << -1 << "\n";
    } else {
        for (int index : result_indices) {
            std::cout << index << "\n";
        }
    }

    return 0;
}
