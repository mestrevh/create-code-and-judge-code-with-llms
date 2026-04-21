/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    cout << n << "\n";

    int denominations[] = {100, 50, 20, 10, 5, 2, 1};

    for (int i = 0; i < 7; ++i) {
        int count = n / denominations[i];
        cout << count << " nota(s) de R$ " << denominations[i] << ",00\n";
        n %= denominations[i];
    }

    return 0;
}