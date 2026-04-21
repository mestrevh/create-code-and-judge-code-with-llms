/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numbers[4];
    for (int i = 0; i < 4; ++i) {
        if (!(cin >> numbers[i])) break;
    }

    sort(numbers, numbers + 4, greater<int>());

    for (int i = 0; i < 4; ++i) {
        cout << numbers[i] << (i == 3 ? "" : " ");
    }
    cout << "\n";

    return 0;
}