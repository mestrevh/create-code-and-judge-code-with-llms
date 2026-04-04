/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool first = true;
    for (int i = 1500; i <= 2700; ++i) {
        if (i % 7 == 0 && i % 5 == 0) {
            if (!first) {
                cout << ",";
            }
            cout << i;
            first = false;
        }
    }
    cout << endl;

    return 0;
}