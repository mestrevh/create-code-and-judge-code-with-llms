/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    char letra;
    cin >> letra;
    int n = letra - 'A' + 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) 
            cout << ".";
        for (int j = 0; j <= i; j++) 
            cout << static_cast<char>('A' + j);
        for (int j = i - 1; j >= 0; j--) 
            cout << static_cast<char>('A' + j);
        cout << endl;
    }
    return 0;
}
