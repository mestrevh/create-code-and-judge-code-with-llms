/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a;
    if (cin >> a) {
        int diff = a - 1986;
        int k = (diff / 76) + 1;
        int next_year = 1986 + (k * 76);
        cout << next_year << endl;
    }

    return 0;
}