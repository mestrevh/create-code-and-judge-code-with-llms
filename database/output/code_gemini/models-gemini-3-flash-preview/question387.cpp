/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v[5];
    for (int i = 0; i < 5; ++i) {
        cin >> v[i];
    }

    bool increasing = true;
    bool decreasing = true;

    for (int i = 0; i < 4; ++i) {
        if (v[i] < v[i + 1]) {
            decreasing = false;
        } else if (v[i] > v[i + 1]) {
            increasing = false;
        }
    }

    if (increasing) {
        cout << 'C';
    } else if (decreasing) {
        cout << 'D';
    } else {
        cout << 'N';
    }

    return 0;
}