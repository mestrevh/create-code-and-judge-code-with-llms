/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double arr[10];
    
    for (int i = 0; i < 10; ++i) {
        cout << "Digite um numero:" << endl;
        cin >> arr[i];
    }

    for (int i = 9; i >= 0; --i) {
        cout << arr[i] << endl;
    }

    return 0;
}
