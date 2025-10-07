/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> figuras;
    int joao = 0, maria = 0;
    int somaJoao = 0, somaMaria = 0;
    
    for (int i = 0; i < n; ++i) {
        int serie;
        cin >> serie;
        figuras.insert(serie);
        if (serie % 2 == 0) {
            joao++;
            somaJoao += serie;
        } else {
            maria++;
            somaMaria += serie;
        }
    }
    
    int bonus = (somaJoao > somaMaria) ? somaJoao + 10 : somaMaria;
    cout << joao << endl;
    cout << maria << endl;
    cout << (somaJoao > somaMaria ? somaJoao : somaMaria) << endl;
    
    return 0;
}
