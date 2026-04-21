/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int power;
    int max_power = 0;

    while (cin >> power && power != 0) {
        if (power > max_power) {
            max_power = power;
        }
    }

    cout << max_power << endl;

    return 0;
}