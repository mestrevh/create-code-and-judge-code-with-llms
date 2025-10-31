/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int maior = a;
    if (b > maior) maior = b;
    if (c > maior) maior = c;
    int menor = a;
    if (b < menor) menor = b;
    if (c < menor) menor = c;
    cout << a + b + c - maior - menor << endl;
    return 0;
}
