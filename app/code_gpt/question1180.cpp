/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    string period = (A < 12) ? "am" : "pm";
    int hour = (A % 12 == 0) ? 12 : A % 12;

    cout << setw(2) << setfill('0') << hour << endl;
    cout << setw(2) << setfill('0') << B << endl;
    cout << period << endl;

    return 0;
}
