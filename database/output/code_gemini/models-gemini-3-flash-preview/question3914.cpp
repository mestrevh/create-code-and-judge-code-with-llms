/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long M;
    int x, y, z;
    if (!(cin >> M >> x >> y >> z)) return 0;

    int A, B, C;
    int profit = 0;
    bool case1_possible = false;

    if ((M * x) % 100 == 0 && (M * y) % 100 == 0 && (M * z) % 100 == 0) {
        A = (M * x) / 100;
        B = (M * y) / 100;
        C = (M * z) / 100;
        profit = M - (A + B + C);
        case1_possible = true;
        cout << "Cada homem ficou com " << A << ", " << B << " e " << C << " reais, respectivamente" << "\n";
    }

    bool possible = case1_possible;

    if (!case1_possible) {
        for (int i = 1; i <= 3; ++i) {
            long long Mt = M + i;
            if ((Mt * x) % 100 == 0 && (Mt * y) % 100 == 0 && (Mt * z) % 100 == 0) {
                int nA = (Mt * x) / 100;
                int nB = (Mt * y) / 100;
                int nC = (Mt * z) / 100;
                int rem = Mt - (nA + nB + nC);
                if (rem >= i + 1) {
                    A = nA; B = nB; C = nC;
                    profit = rem - i;
                    possible = true;
                    cout << "Cada homem ficou com " << A << ", " << B << " e " << C << " reais, respectivamente" << "\n";
                    
                    if (i == 2) {
                        char c1, c2, c3;
                        cin >> c1 >> c2 >> c3;
                        int sum = (c1 - 'a' + 1) + (c2 - 'a' + 1) + (c3 - 'a' + 1);
                        cout << sum << "\n";
                    } else if (i == 3) {
                        int a1, a2, a3;
                        cin >> a1 >> a2 >> a3;
                        if (a1 % 3 == 0 || a2 % 3 == 0 || a3 % 3 == 0) {
                            int parcelas = (a1 / 3) + (a2 / 3) + (a3 / 3);
                            cout << parcelas << "\n";
                        }
                    }
                    break;
                }
            }
        }
    }

    if (!possible) {
        cout << "Nao foi dessa vez que Rebeka pode ajudar..." << "\n";
    }

    if (possible && (3 + profit >= 7)) {
        cout << "Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!" << "\n";
    } else {
        cout << "E parece que Rebeka vai ter que voltar andando..." << "\n";
    }

    return 0;
}