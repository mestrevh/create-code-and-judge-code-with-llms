/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, test = 1;
    while (true) {
        cin >> n;
        if (n == 0) break;

        vector<int> tickets(n);
        for (int i = 0; i < n; i++) {
            cin >> tickets[i];
        }

        int winner = -1;
        for (int i = 0; i < n; i++) {
            if (tickets[i] == i + 1) {
                winner = tickets[i];
                break;
            }
        }

        cout << "Teste " << test++ << endl;
        cout << winner << endl << endl;
    }
    return 0;
}
