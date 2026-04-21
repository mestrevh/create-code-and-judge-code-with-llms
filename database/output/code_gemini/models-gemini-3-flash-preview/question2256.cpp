/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int contarOcorrencias(long long n, int x) {
    int count = 0;
    do {
        if (n % 10 == x) {
            count++;
        }
        n /= 10;
    } while (n > 0);
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    int x;
    if (cin >> n >> x) {
        cout << contarOcorrencias(n, x) << endl;
    }

    return 0;
}