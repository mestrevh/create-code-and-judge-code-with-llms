/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (cin >> N) {
        while (N--) {
            long long K;
            if (cin >> K) {
                long long sum = (K * (K * K + 1)) / 2;
                cout << sum << "\n";
            }
        }
    }

    return 0;
}