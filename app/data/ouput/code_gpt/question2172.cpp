/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int calcularTempo(int pos, int n, vector<int>& seq, bool encontrouChave) {
    if (pos >= n) return 0;
    int tempo = 1 + calcularTempo(pos + 1, n, seq, encontrouChave);
    
    if (seq[pos] == -1) {
        encontrouChave = true;
    }
    
    return encontrouChave ? tempo + 1 : tempo;
}

int main() {
    int n;
    cin >> n;
    vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }
    int resultado = calcularTempo(0, n, seq, false);
    cout << resultado << endl;
    return 0;
}
