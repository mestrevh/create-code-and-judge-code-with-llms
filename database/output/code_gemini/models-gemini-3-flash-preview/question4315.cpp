/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    string dummy;
    getline(cin, dummy);

    vector<string> strings(n);
    for (int i = 0; i < n; ++i) {
        if (!getline(cin, strings[i])) {
            break;
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        cout << strings[i];
    }
    cout << "\n";

    return 0;
}