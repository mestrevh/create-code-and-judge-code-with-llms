/*
Código criado pelo gpt-4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, testCase = 1;
    while (cin >> n, n) {
        vector<int> goalsFor(n + 1, 0);
        vector<int> goalsAgainst(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int x, y;
            cin >> x >> y;
            goalsFor[i] = x;
            goalsAgainst[i] = y;
        }
        
        int maxSaldo = -1, maxA = 0, maxB = 0;
        
        for (int A = 1; A <= n; ++A) {
            int totalFor = 0, totalAgainst = 0;
            for (int B = A; B <= n; ++B) {
                totalFor += goalsFor[B];
                totalAgainst += goalsAgainst[B];
                int saldo = totalFor - totalAgainst;
                if (saldo > maxSaldo || (saldo == maxSaldo && (B - A > maxB - maxA))) {
                    maxSaldo = saldo;
                    maxA = A;
                    maxB = B;
                }
            }
        }
        
        cout << "Teste " << testCase++ << endl;
        if (maxSaldo > 0) {
            cout << maxA << " " << maxB << endl;
        } else {
            cout << "nenhum" << endl;
        }
        cout << endl;
    }
    return 0;
}