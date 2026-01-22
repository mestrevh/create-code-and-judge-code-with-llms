/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, R;
        cin >> N >> R;
        set<int> rows, cols;
        int totalPins = 0;

        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= 2 * i - 1; ++j)
                if (i % 2 == 1 && j <= i * 2 - 1)
                    totalPins++;

        while (R--) {
            int Ti, Pi;
            cin >> Ti >> Pi;

            if (Ti == 0) {
                rows.insert(Pi);
            } else {
                cols.insert(Pi);
            }
        }

        int remainingPins = totalPins - rows.size() * (N + 1) - cols.size() * (N + 1) + rows.size() * cols.size();
        cout << remainingPins << '\n';
    }
    return 0;
}
