/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    int min_val = numeric_limits<int>::max();
    int min_pos = -1;

    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val < min_val) {
            min_val = val;
            min_pos = i;
        }
    }

    cout << "Menor valor: " << min_val << "\n";
    cout << "Posicao: " << min_pos << "\n";

    return 0;
}