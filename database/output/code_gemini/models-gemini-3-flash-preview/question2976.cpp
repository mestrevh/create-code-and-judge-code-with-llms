/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    uint64_t n;
    if (!(cin >> n)) return 0;

    uint64_t sum = 0;
    while (n != 1) {
        sum += n;
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }
    sum += 1;

    cout << sum << endl;

    return 0;
}