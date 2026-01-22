/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore();
    string base;
    getline(cin, base);
    
    if (n <= 0 || m <= 0) {
        cout << "TAMANHO INVALIDO" << endl;
        return 0;
    }
    
    string prefix = base.substr(0, n);
    string suffix = base.substr(base.size() - m, m);
    
    cout << prefix << " :" << endl;
    for (int i = 0; i < 2; i++) {
        string secondary;
        getline(cin, secondary);
        cout << prefix + secondary << endl;
    }
    
    cout << suffix << " :" << endl;
    for (int i = 0; i < 2; i++) {
        string secondary;
        getline(cin, secondary);
        cout << secondary + suffix << endl;
    }
    
    return 0;
}
