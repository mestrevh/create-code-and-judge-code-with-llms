/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long year;
    if (!(cin >> year)) return 0;

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << "BISSEXTO" << endl;
    } else {
        cout << "NAOBISSEXTO" << endl;
    }

    return 0;
}