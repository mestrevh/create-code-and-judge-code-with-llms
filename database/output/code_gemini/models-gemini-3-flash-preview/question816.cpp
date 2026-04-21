/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string line;
    getline(cin, line); // Consome o restante da linha após o número N

    int balance = 0;
    bool ok = true;

    for (int i = 0; i < n; ++i) {
        if (!getline(cin, line)) break;
        for (char c : line) {
            if (c == '{') {
                balance++;
            } else if (c == '}') {
                balance--;
                if (balance < 0) {
                    ok = false;
                }
            }
        }
    }

    if (balance != 0) {
        ok = false;
    }

    if (ok) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}