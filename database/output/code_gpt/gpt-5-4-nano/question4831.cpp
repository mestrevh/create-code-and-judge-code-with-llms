/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static long long absll(long long x){ return x<0?-x:x; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if(!(cin >> t)) return 0;

    for(int tc = 1; tc <= t; tc++) {
        vector<long long> st;
        long long n;
        while (cin >> n) {
            if(n == 0) break;
            long long cur = n;
            while(!st.empty() && ((st.back() & 1LL) == (cur & 1LL))) {
                cur = absll(cur - st.back());
                st.pop_back();
            }
            st.push_back(cur);
        }

        long long top = st.empty() ? -1 : st.back();
        cout << "Pilha " << tc << ": " << st.size() << " " << top << "\n";
    }
    return 0;
}