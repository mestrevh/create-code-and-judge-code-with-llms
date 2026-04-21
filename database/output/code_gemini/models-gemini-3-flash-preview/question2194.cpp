/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, s;
    if (cin >> a >> b >> s) {
        long long abs_a = (a < 0) ? -a : a;
        long long abs_b = (b < 0) ? -b : b;
        long long min_dist = abs_a + abs_b;

        if (s >= min_dist && (s - min_dist) % 2 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}