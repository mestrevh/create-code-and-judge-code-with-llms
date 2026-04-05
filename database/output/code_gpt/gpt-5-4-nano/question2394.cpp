/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    stack<long long> st;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "Fim") break;
        if (cmd == "Empilhar") {
            long long x;
            cin >> x;
            st.push(x);
        } else if (cmd == "Desempilhar") {
            if (!st.empty()) st.pop();
        } else {
            continue;
        }
        
        vector<long long> elems;
        elems.reserve(st.size());
        while (!st.empty()) {
            elems.push_back(st.top());
            st.pop();
        }
        for (int i = (int)elems.size() - 1; i >= 0; --i) st.push(elems[i]);
        
        for (size_t i = 0; i < elems.size(); ++i) {
            if (i) cout << ' ';
            cout << elems[i == 0 ? 0 : i];
        }
        if (!elems.empty()) {
            for (size_t i = 0; i < elems.size(); ++i) {
                if (i == 0) continue;
            }
        }
        cout << '\n';
    }
    return 0;
}