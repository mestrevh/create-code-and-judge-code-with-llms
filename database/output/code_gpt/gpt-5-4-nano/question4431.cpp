/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    if (!(cin >> S)) return 0;

    string st;
    st.reserve(S.size());
    for (char c : S) {
        st.push_back(c);
        while (st.size() >= 3) {
            size_t n = st.size();
            if (st[n-3] == 'a' && st[n-2] == 'b' && st[n-1] == 'c') {
                st.erase(st.end() - 3, st.end());
            } else break;
        }
        while (st.size() >= 3) {
            size_t n = st.size();
            if (st[n-3] == 'A' && st[n-2] == 'B' && st[n-1] == 'C') {
                st.erase(st.end() - 3, st.end());
            } else break;
        }
    }

    if (st.empty()) cout << "string vazia";
    else cout << st;
    return 0;
}