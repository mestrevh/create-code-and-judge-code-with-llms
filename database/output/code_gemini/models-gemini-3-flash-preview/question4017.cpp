/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Y;
    if (!(cin >> Y)) return 0;

    int countY = 0;
    double sumAvg = 0;
    int countAvg = 0;
    int num;

    for (int i = 0; i < 20; ++i) {
        if (!(cin >> num) || num == -1) break;
        
        if (num == Y) {
            countY++;
        }
        
        if (num > 0 && (num < 15 || num > 20)) {
            sumAvg += num;
            countAvg++;
        }
    }

    cout << "O número " << Y << " apareceu " << countY << " vez(es)" << endl;
    
    if (countAvg > 0) {
        cout << fixed << setprecision(2) << "A média dos números foi de: " << (sumAvg / countAvg) << endl;
    } else {
        cout << "Sem valores para calcular a média" << endl;
    }

    return 0;
}