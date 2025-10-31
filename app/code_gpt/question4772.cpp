/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N;
    char C;
    cin >> N >> C;

    if (N < 2) {
        cout << "Fica muito feio, meu senhor." << endl;
        return 0;
    }

    int mid = (N % 2 == 0) ? 2 : 1;
    int legs = N / 2;

    for (int i = 0; i < N; i++) {
        if (i < N / 2) {
            for (int j = 0; j < N; j++) {
                if (j == i || j == N - 1 - i)
                    cout << C;
                else
                    cout << ' ';
            }
        } else {
            for (int j = 0; j < N; j++) {
                if (j == N - 1 - i || (N % 2 == 0 && j == N / 2 - 1) || (N % 2 != 0 && j == N / 2))
                    cout << C;
                else
                    cout << ' ';
            }
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < N; i++) {
        if (i < N / 2) {
            for (int j = 0; j < N; j++) {
                if (j == i || j == N - 1 - i)
                    cout << C;
                else
                    cout << ' ';
            }
        } else {
            for (int j = 0; j < N; j++) {
                if (j == N / 2 || (N % 2 == 0 && (i - N / 2) < legs))
                    cout << C;
                else
                    cout << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}
