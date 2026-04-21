/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a;
    int n;
    if (!(cin >> a >> n)) return 0;

    long long limit = (long long)n * 60;
    long long elapsed = 0;
    long long current_a = a;

    while (elapsed < limit) {
        if (current_a % 13 == 0) {
            long long target = current_a - 60;
            if (target > 0 && target % 60 == 0) {
                current_a += 30;
            } else {
                current_a = target;
            }
        }

        if (current_a == 0) {
            cout << elapsed << "\n";
            return 0;
        }

        current_a++;
        elapsed++;
    }

    cout << "fui pedir comida mesmo" << "\n";

    return 0;
}