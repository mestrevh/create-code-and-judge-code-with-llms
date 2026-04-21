/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long v;
    int n;
    if (!(cin >> v >> n)) return 0;

    vector<long long> st;
    st.reserve(n);
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        st.push_back(x);
    }

    for (long long x : st) cout << x << ' ';
    cout << "\n";

    reverse(st.begin(), st.end());

    for (auto &x : st) {
        if (x % 2 == 0) x = -x;
    }

    while (st.size() >= 2) {
        long long top = st.back();
        long long next = st[st.size() - 2];
        if (top == next) {
            st.pop_back();
            st.pop_back();
        } else {
            break;
        }
    }

    for (long long x : st) cout << x << ' ';
    cout << "\n";

    long long sum = 0;
    for (auto x : st) sum += x;

    if (sum >= v)
        cout << "Atravessou o Mundo Invertido com " << sum << " pontos. Vecna foi derrotado!\n";
    else
        cout << "Atravessou o Mundo Invertido com " << sum << " pontos. Hawkins esta condenada...\n";

    return 0;
}