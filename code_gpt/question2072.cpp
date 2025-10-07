/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, moedas = 0, x = 0, y = 0;
    cin >> N;
    vector<char> movimentos(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> movimentos[i];
    }
    
    for (char movimento : movimentos) {
        if (movimento == 'D') {
            x++;
        } else {
            y++;
        }
        
        if (y > x && (movimento == 'C' || movimento == 'D')) {
            if (y - x == 1) {
                moedas++;
            }
        }
    }
    
    cout << moedas << endl;
    return 0;
}
