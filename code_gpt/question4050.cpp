/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    if (N >= 18) cout << "adulto";
    else if (N >= 10) cout << "adolescente";
    else cout << "crianca";
    return 0;
}
