/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

long long solve(long long e, long long x, long long n, long long h) {
    if (e <= 0) {
        return h;
    }
    return solve(e - (n * x), x + 100, n, h + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long e, x, n;
    if (cin >> e >> x >> n) {
        long long hours = solve(e, x, n, 0);
        cout << "Precisamos de " << hours << " horas para conseguirmos imprimir " << e << " euros." << endl;
    }

    return 0;
}