/*
Código criado pelo gpt-5.4
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, teste = 1;
    while (cin >> N && N) {
        long long sum = 0, minPref = 0, best = LLONG_MIN;
        int minPos = 0, bestL = 1, bestR = 1;

        for (int i = 1; i <= N; ++i) {
            int X, Y;
            cin >> X >> Y;
            sum += (X - Y);

            long long cur = sum - minPref;
            int curL = minPos + 1;
            int curR = i;

            if (cur > best || (cur == best && (curR - curL > bestR - bestL))) {
                best = cur;
                bestL = curL;
                bestR = curR;
            }

            if (sum < minPref) {
                minPref = sum;
                minPos = i;
            }
        }

        cout << "Teste " << teste++ << "\n";
        if (best <= 0) {
            cout << "nenhum\n\n";
        } else {
            cout << bestL << " " << bestR << "\n\n";
        }
    }

    return 0;
}