/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> V(n);
    vector<long long> W(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
    }
    
    for (int i = 0; i < n; ++i) {
        W[i] = factorial(V[i]);
    }
    
    for (int i = 0; i < n; ++i) {
        cout << V[i] << (i < n - 1 ? " " : "\n");
    }
    
    for (int i = 0; i < n; ++i) {
        cout << W[i] << (i < n - 1 ? " " : "\n");
    }
    
    return 0;
}
