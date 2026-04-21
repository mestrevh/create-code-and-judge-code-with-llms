/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 0;
    double original, discounted;
    for (int i = 0; i < 5; ++i) {
        if (cin >> original >> discounted) {
            if (discounted <= (original * 0.8) + 1e-9) {
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}