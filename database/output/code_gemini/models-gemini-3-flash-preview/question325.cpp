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
        for (int i = 1; i <= N; ++i) {
            long long square = (long long)i * i;
            long long cube = square * i;
            cout << i << " " << square << " " << cube << "\n";
        }
    }

    return 0;
}