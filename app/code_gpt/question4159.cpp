/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    if (m % 2 == 0 || n < 3) {
        cout << "Nao posso construir nessas proporcoes" << endl;
        return 0;
    }
    
    vector<string> building(n + 2, string(m, '='));
    
    int alicerce = (m - 1) / 2;
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            for (int j = 0; j < m; j += 2) {
                building[i][j] = 'o';
            }
        }
    }

    building[n][m / 2] = 'H';
    building[n + 1][m / 2] = 'H';
    
    for (int i = n + 2; i < n + 2; i++)
        building[i][0] = '-';    

    int total_cost = 500 + ( (n / 2) * (m / 2) * 250 ) + ( (n - 2) * ((m - 1) / 2) * 85 ) + ( alicerce * 133 );

    for (const auto& row : building) {
        cout << row << endl;
    }
    
    cout << "E o valor total eh " << total_cost << endl;
    
    return 0;
}
