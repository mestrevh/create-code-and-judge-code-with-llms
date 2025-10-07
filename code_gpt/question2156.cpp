/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int volume, n;
    
    do {
        cin >> volume;
    } while (volume < 0 || volume > 100);
    
    do {
        cin >> n;
    } while (n < 0 || n > 10);
    
    vector<int> trocas(n);
    for (int i = 0; i < n; i++) {
        cin >> trocas[i];
    }
    
    for (int i = 0; i < n; i++) {
        volume += trocas[i];
        volume = max(0, min(100, volume));
    }
    
    cout << volume << endl;
    return 0;
}
