/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cpfs(n), notas(n);
    
    for (int i = 0; i < n; i++) {
        cin >> cpfs[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> notas[i];
    }
    
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int cpf;
        cin >> cpf;
        auto it = lower_bound(cpfs.begin(), cpfs.end(), cpf);
        if (it != cpfs.end() && *it == cpf) {
            cout << notas[it - cpfs.begin()] << endl;
        } else {
            cout << "NAO SE APRESENTOU" << endl;
        }
    }
    return 0;
}
