/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int soma = 0;
    for (int i = 0; i < n-1; ++i) soma += abs(v[i+1] - v[i]);
    soma += n+1;
    cout << soma << endl;
    return 0;
}
