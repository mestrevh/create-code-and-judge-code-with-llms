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

    string word;
    bool first = true;
    while (cin >> word) {
        if (!first) {
            cout << " ";
        }
        cout << word;
        first = false;
    }
    cout << endl;

    return 0;
}