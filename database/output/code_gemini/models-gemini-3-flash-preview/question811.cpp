/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int testCount = 1;

    while (cin >> N && N != 0) {
        int winner = 0;
        for (int i = 1; i <= N; ++i) {
            int ticket;
            cin >> ticket;
            if (ticket == i) {
                winner = ticket;
            }
        }

        cout << "Teste " << testCount++ << "\n";
        cout << winner << "\n\n";
    }

    return 0;
}