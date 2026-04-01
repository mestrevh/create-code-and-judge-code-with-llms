/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x;
    while (cin >> x && x != 0) {
        long long sum = 0;
        long long temp_x = x;
        for (long long i = 2; i * i <= temp_x; ++i) {
            while (temp_x % i == 0) {
                sum += i;
                temp_x /= i;
            }
        }
        if (temp_x > 1) {
            sum += temp_x;
        }
        cout << sum << "\n";
    }

    return 0;
}