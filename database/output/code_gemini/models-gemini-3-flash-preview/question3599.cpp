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

    int count = 0;
    int last_selected = -1;

    for (int i = 0; i < n; ++i) {
        int current;
        cin >> current;
        if (current != last_selected) {
            count++;
            last_selected = current;
        }
    }

    cout << count << "\n";

    return 0;
}