/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

long long fatorial(int n) {
    long long f = 1;
    for (int i = 1; i <= n; ++i) {
        f *= i;
    }
    return f;
}

int main() {
    int n;
    cin >> n;
    vector<int> valores(n);
    long long total = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> valores[i];
        total += valores[i];
    }
    
    int f = 0;
    while (fatorial(f) < total) {
        f++;
    }
    
    cout << "Bia arrecadou " << f << "! dinheiros e pode jogar tenis!" << endl;
    return 0;
}
