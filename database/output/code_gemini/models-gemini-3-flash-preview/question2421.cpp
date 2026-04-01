/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long p;
    if (!(cin >> p)) return 0;

    int denominations[] = {500, 100, 50, 10, 5, 1};

    for (int i = 0; i < 6; ++i) {
        long long count = p / denominations[i];
        p %= denominations[i];
        cout << count << " moedas de " << denominations[i] << "." << "\n";
    }

    return 0;
}