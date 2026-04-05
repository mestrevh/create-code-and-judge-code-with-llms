/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

string par_ou_impar(long long n) {
    if (n % 2 == 0) {
        return "Par";
    } else {
        return "Ímpar";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (cin >> n) {
        cout << par_ou_impar(n) << endl;
    }

    return 0;
}