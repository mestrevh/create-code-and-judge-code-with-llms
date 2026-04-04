/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    if (n <= 0) return 0;

    long long max_val;
    int max_pos = 0;

    for (int i = 0; i < n; ++i) {
        long long current;
        if (!(cin >> current)) break;
        if (i == 0 || current > max_val) {
            max_val = current;
            max_pos = i;
        }
    }

    cout << "o maior numero eh " << max_val << ", e foi lido na posicao " << max_pos << endl;

    return 0;
}