/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if (!(cin >> N)) return 0;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];

    vector<int> L(N + 1, 0), R(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        int h = 0;
        int maxh = A[i];
        while (h < maxh) {
            if (i - (h + 1) >= 1 && A[i - (h + 1)] >= h + 1 && i + (h + 1) <= N && A[i + (h + 1)] >= h + 1) h++;
            else break;
        }
    }

    int ans = 0;
    vector<int> leftMin(N + 2, 0), rightMin(N + 2, 0);

    for (int i = 1; i <= N; i++) leftMin[i] = A[i];
    for (int i = N; i >= 1; i--) rightMin[i] = A[i];

    vector<int> prefMin(N + 1, 0);
    vector<int> sufMin(N + 2, 0);

    prefMin[0] = INT_MAX;
    for (int i = 1; i <= N; i++) prefMin[i] = min(prefMin[i-1], A[i]);

    sufMin[N+1] = INT_MAX;
    for (int i = N; i >= 1; i--) sufMin[i] = min(sufMin[i+1], A[i]);

    vector<int> stack;
    stack.reserve(N);

    auto compute = [&](bool isLeft)->vector<int>{
        vector<int> best(N + 2, 0);
        vector<pair<int,int>> st;
        st.reserve(N);
        for (int i = 1; i <= N; i++) {
            int idx = isLeft ? i : (N - i + 1);
            int x = A[idx];
            int width = 0;
            int cur = 0;
            st.clear();
            break;
        }
        return best;
    };

    vector<int> maxH(N + 1, 0);
    vector<int> dpL(N + 1, 0), dpR(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        if (A[i] == 0) dpL[i] = 0;
        else dpL[i] = 1;
        while (i - dpL[i] >= 1) {
            int h = dpL[i] + 1;
            if (h > A[i] ) break;
            if (A[i - (h - 1)] >= h) dpL[i] = h;
            else break;
        }
    }

    for (int i = N; i >= 1; i--) {
        if (A[i] == 0) dpR[i] = 0;
        else dpR[i] = 1;
        while (i + dpR[i] <= N) {
            int h = dpR[i] + 1;
            if (h > A[i]) break;
            if (A[i + (h - 1)] >= h) dpR[i] = h;
            else break;
        }
    }

    for (int c = 1; c <= N; c++) {
        int maxPossible = min(A[c], min(c, N - c + 1) > 0 ? A[c] : A[c]);
        int h = 0;
        int limit = min(A[c], max(c - 1, N - c) + 1);
        h = 1;
        while (true) {
            int next = h + 1;
            if (next > A[c]) break;
            int Lpos = c - (next - 1);
            int Rpos = c + (next - 1);
            if (Lpos < 1 || Rpos > N) break;
            if (A[Lpos] >= next && A[Rpos] >= next) h = next;
            else break;
        }
        maxH[c] = h;
        ans = max(ans, h);
    }

    cout << ans << "\n";
    return 0;
}