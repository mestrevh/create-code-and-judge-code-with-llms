/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int current_pos = 0;
    int die_value = 1;
    int moves = 0;

    while (current_pos != n - 1) {
        current_pos = (current_pos + die_value) % n;
        moves++;
        die_value++;
        if (die_value > 6) {
            die_value = 1;
        }
    }

    cout << moves << endl;

    return 0;
}