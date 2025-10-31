/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N >= 90 && N <= 100) {
        cout << "A" << endl;
    } else if (N >= 75) {
        cout << "B" << endl;
    } else if (N >= 60) {
        cout << "C" << endl;
    } else if (N >= 40) {
        cout << "D" << endl;
    } else {
        cout << "E" << endl;
    }

    return 0;
}
