/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 4 == 0 && n % 7 == 0 && n % 5 != 0) {
        cout << "sim" << endl;
    } else {
        cout << "nao" << endl;
    }
    return 0;
}
