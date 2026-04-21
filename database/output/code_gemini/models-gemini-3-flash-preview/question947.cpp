/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<uint32_t, bool> memo;

bool solve(uint32_t mask, int len) {
    if (len == 0) return true;
    uint32_t state = (mask << 5) | (uint32_t)len;
    auto it = memo.find(state);
    if (it != memo.end()) return it->second;

    bool possible = false;
    int i = 0;
    while (i < len) {
        int j = i;
        int bit_i = (mask >> i) & 1;
        while (j < len && ((mask >> j) & 1) == bit_i) j++;
        
        int g_len = j - i;
        if (g_len >= 2) {
            uint32_t prefix = (i == 0) ? 0 : (mask & ((1u << i) - 1));
            uint32_t suffix = (j == len) ? 0 : (mask >> j);
            uint32_t next_mask = prefix | (suffix << i);
            if (solve(next_mask, len - g_len)) {
                possible = true;
                break;
            }
        }
        i = j;
    }
    return memo[state] = possible;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        string s;
        if (!(cin >> s)) break;
        int n = s.length();
        uint32_t mask = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') mask |= (1u << i);
        }
        cout << (solve(mask, n) ? 1 : 0) << "\n";
    }
    return 0;
}