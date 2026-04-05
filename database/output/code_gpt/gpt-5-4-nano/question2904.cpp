/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double C;
    if (!(cin >> C)) return 0;
    int N;
    cin >> N;

    vector<long double> X(N + 1);
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        X[i] = stold(s);
    }

    long double best = 0.0L;

    vector<int> st;
    st.reserve(N);

    for (int r = 1; r <= N; r++) {
        while (!st.empty() && X[st.back()] >= X[r]) st.pop_back();
        int l = st.empty() ? 1 : st.back() + 1;
        long double mn = X[r];

        long double gain = C * (r - l) * (mn / 100.0L);
        if (gain > best) best = gain;

        st.push_back(r);
    }

    cout << fixed << setprecision(2) << (double)best << "\n";
    return 0;
}