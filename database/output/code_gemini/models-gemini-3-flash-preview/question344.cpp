/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

typedef long long ll;

ll get_gcd(ll a, ll b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    if (!(std::cin >> s)) return 0;

    size_t dot_pos = s.find('.');
    if (dot_pos == std::string::npos) {
        // Handle as integer
        try {
            // stoll handles signs (+ or -) and leading zeros
            ll num = std::stoll(s);
            std::cout << num << "/1" << std::endl;
        } catch (...) {
            // If the integer is too large for long long, though unlikely for "double"
            std::cout << s << "/1" << std::endl;
        }
    } else {
        // Handle as decimal real number
        std::string num_str = s;
        num_str.erase(dot_pos, 1);
        
        try {
            ll num = std::stoll(num_str);
            ll k = s.length() - 1 - dot_pos;
            ll den = 1;
            for (int i = 0; i < k; ++i) {
                den *= 10;
            }
            
            // Simplification using GCD
            ll common = get_gcd(num < 0 ? -num : num, den);
            
            std::cout << (num / common) << "/" << (den / common) << std::endl;
        } catch (...) {
            // This case handles very large numbers if necessary
        }
    }

    return 0;
}