/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    long long product = 1;
    int number;

    while (cin >> number) {
        product *= number;
    }
    
    cout << "Prod = " << product << endl;

    return 0;
}
