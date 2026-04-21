/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double width, length, height;
    if (cin >> width >> length >> height) {
        if (width <= 45.0 && length <= 56.0 && height <= 25.0) {
            cout << "PERMITIDA" << endl;
        } else {
            cout << "PROIBIDA" << endl;
        }
    }

    return 0;
}