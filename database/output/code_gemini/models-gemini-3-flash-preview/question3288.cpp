/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

long long soma_tres(long long a, long long b, long long c) {
    return a + b + c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n1, n2, n3;
    if (cin >> n1 >> n2 >> n3) {
        cout << soma_tres(n1, n2, n3) << "\n";
    }

    return 0;
}