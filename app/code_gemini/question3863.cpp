/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::string final_string = "";
    for (int i = 0; i < n; ++i) {
        char d;
        std::string s;
        std::cin >> d >> s;

        if (d == 'd') {
            final_string += s.substr(0, 6);
        } else {
            std::string right_half = s.substr(6, 6);
            std::reverse(right_half.begin(), right_half.end());
            final_string += right_half;
        }
    }

    std::string p;
    std::cin >> p;

    int count = 0;
    int l_h = final_string.length();
    int l_p = p.length();

    if (l_p > 0 && l_h >= l_p) {
        std::string doubled_haystack = final_string + final_string;
        
        for (int i = 0; i < l_h; ++i) {
            if (doubled_haystack.substr(i, l_p) == p) {
                count++;
            }
        }

        std::string p_rev = p;
        std::reverse(p_rev.begin(), p_rev.end());

        if (p != p_rev) {
            for (int i = 0; i < l_h; ++i) {
                if (doubled_haystack.substr(i, l_p) == p_rev) {
                    count++;
                }
            }
        }
    }
    
    std::cout << p << count << std::endl;

    return 0;
}
