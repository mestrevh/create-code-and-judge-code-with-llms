/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

long long calculateHeight(long long n, long long k) {
    if (n <= 1 || k <= 1) {
        return 0;
    }
    return 1 + calculateHeight(n, k / n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    if (cin >> n >> k) {
        cout << calculateHeight(n, k) << endl;
    }

    return 0;
}