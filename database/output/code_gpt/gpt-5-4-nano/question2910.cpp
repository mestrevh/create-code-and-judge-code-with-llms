/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X, Y, Z;
    if (!(cin >> N)) return 0;
    cin >> X >> Y >> Z;

    vector<int> a = {X, Y, Z};
    sort(a.begin(), a.end());

    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        if (sum + a[i] <= N) {
            sum += a[i];
            cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}