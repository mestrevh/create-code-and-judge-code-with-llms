/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    if (cin >> n >> k) {
        long long total_sum = 0;
        while (n > 0) {
            total_sum += n;
            n -= k;
        }
        cout << total_sum << endl;
    }

    return 0;
}