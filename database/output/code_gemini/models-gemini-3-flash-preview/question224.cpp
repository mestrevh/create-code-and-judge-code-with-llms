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

    int num;
    int max_val = 0;

    while (cin >> num && num != 0) {
        if (num > max_val) {
            max_val = num;
        }
    }

    cout << max_val << endl;

    return 0;
}