/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int bolos_farinhas = A / 2;
    int bolos_ovos = B / 3;
    int bolos_leite = C / 5;

    int max_bolos = min({bolos_farinhas, bolos_ovos, bolos_leite});
    cout << max_bolos << endl;

    return 0;
}
