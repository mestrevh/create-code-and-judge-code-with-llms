/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long long n;
    if (!(cin >> n)) return 0;

    int k = 0;
    unsigned long long temp = n;
    while (temp >= 3) {
        temp /= 3;
        k++;
    }

    unsigned long long res = 1;
    for (int i = 2; i <= k; ++i) {
        res *= i;
    }

    cout << res << endl;

    return 0;
}