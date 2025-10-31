/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n1, n2;
    cin >> n1;
    if (n1 < 1) {
        cout << "Erro - A lista deve ter pelo menos 1 elemento." << endl;
        return 0;
    }
    
    vector<int> lista1(n1);
    for (int &val : lista1) {
        cin >> val;
    }

    cin >> n2;
    if (n2 < 1) {
        cout << "Erro - A lista deve ter pelo menos 1 elemento." << endl;
        return 0;
    }

    vector<int> lista2(n2);
    for (int &val : lista2) {
        cin >> val;
    }

    set<int> uniao(lista1.begin(), lista1.end());
    uniao.insert(lista2.begin(), lista2.end());

    for (const int &val : uniao) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
