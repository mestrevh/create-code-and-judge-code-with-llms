/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Problem: Generate all valid stack sequences ('i' for push, 'o' for pop) 
 * that transform source string s1 into target string s2.
 * 
 * Logic:
 * Use a backtracking Depth-First Search (DFS).
 * To maintain alphabetical order of sequences, we branch 'i' before 'o'
 * because 'i' (ASCII 105) < 'o' (ASCII 111).
 * 
 * Optimization:
 * 1. Pruning: Check if s1 and s2 have the same character counts.
 * 2. Pruning: A pop operation is only valid if the top of the stack
 *    matches the next required character in the target string.
 */

string s1, s2;
size_t n;
char res_ops[2005];
vector<char> st;

void dfs(size_t s_idx, size_t t_idx, int ops_idx) {
    // Base Case: successfully formed the target word
    if (t_idx == n) {
        for (int i = 0; i < ops_idx; ++i) {
            cout << res_ops[i] << (i == ops_idx - 1 ? "" : " ");
        }
        cout << "\n";
        return;
    }

    // Branch 1: Try 'i' (Push)
    // Lexicographically first since 'i' < 'o'
    if (s_idx < n) {
        st.push_back(s1[s_idx]);
        res_ops[ops_idx] = 'i';
        dfs(s_idx + 1, t_idx, ops_idx + 1);
        st.pop_back(); // Backtrack
    }

    // Branch 2: Try 'o' (Pop)
    // Only possible if stack not empty and top matches the target's current char
    if (!st.empty() && st.back() == s2[t_idx]) {
        char top = st.back();
        st.pop_back();
        res_ops[ops_idx] = 'o';
        dfs(s_idx, t_idx + 1, ops_idx + 1);
        st.push_back(top); // Backtrack
    }
}

bool is_possible() {
    if (s1.length() != s2.length()) return false;
    int cnt[256] = {0};
    for (char c : s1) cnt[(unsigned char)c]++;
    for (char c : s2) cnt[(unsigned char)c]--;
    for (int i = 0; i < 256; ++i) {
        if (cnt[i] != 0) return false;
    }
    return true;
}

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> s1 >> s2) {
        n = s1.length();
        cout << "[\n";
        
        // Initial quick check for character set equality
        if (is_possible()) {
            st.clear();
            st.reserve(n);
            dfs(0, 0, 0);
        }
        
        cout << "]\n";
    }

    return 0;
}