/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, test = 1;
    while (cin >> N && N != 0) {
        vector<int> deg(7, 0);
        int X, Y;
        for (int i = 0; i < N; ++i) {
            cin >> X >> Y;
            deg[X]++;
            deg[Y]++;
        }
        int odd = 0;
        for (int i = 0; i <= 6; ++i) {
            if (deg[i] % 2) odd++;
        }
        cout << "Teste " << test++ << "\n";
        if (odd == 0 || odd == 2)
            cout << "sim\n";
        else
            cout << "nao\n";
        cout << "\n";
    }
    return 0;
}
