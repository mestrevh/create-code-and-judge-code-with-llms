/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    int a = num / 100;
    int b = (num / 10) % 10;
    int c = num % 10;
    cout << c << b << a << endl;
    return 0;
}
