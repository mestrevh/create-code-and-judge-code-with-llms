/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    cout << (num % 10) * 100 + (num / 10 % 10) * 10 + (num / 100) << endl;
    return 0;
}
