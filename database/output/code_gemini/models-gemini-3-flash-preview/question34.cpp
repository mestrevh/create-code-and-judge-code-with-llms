/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    long long n50 = n / 50;
    n %= 50;
    long long n20 = n / 20;
    n %= 20;
    long long n10 = n / 10;
    n %= 10;
    long long n5 = n / 5;
    n %= 5;
    long long n1 = n;

    cout << "Notas de 50: " << n50 << "\n";
    cout << "Notas de 20: " << n20 << "\n";
    cout << "Notas de 10: " << n10 << "\n";
    cout << "Notas de 5: " << n5 << "\n";
    cout << "Notas de 1: " << n1 << endl;

    return 0;
}