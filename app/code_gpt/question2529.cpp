/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    
    if (A > B) {
        cout << "A eh maior" << endl;
    } else if (B > A) {
        cout << "B eh maior" << endl;
    } else {
        cout << "iguais" << endl;
    }
    
    return 0;
}
