/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    
    string s = to_string(n);
    if (s.size() != 4) {
        cout << "Nao pode";
        return 0;
    }
    
    vector<int> digits;
    for (char c : s) {
        if (!isdigit(static_cast<unsigned char>(c))) {
            cout << "Nao pode";
            return 0;
        }
        digits.push_back(c - '0');
    }
    
    for (int d : digits) {
        if (d == 0) {
            cout << "Nao pode";
            return 0;
        }
    }
    
    set<int> st(digits.begin(), digits.end());
    if ((int)st.size() == 4) cout << "Pode";
    else cout << "Nao pode";
    
    return 0;
}