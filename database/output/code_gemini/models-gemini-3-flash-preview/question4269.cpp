/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double value;
    int count = 0;
    while (count < 3 && cin >> value) {
        cout << value * 5.08 << "\n";
        count++;
    }

    return 0;
}