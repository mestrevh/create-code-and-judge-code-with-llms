/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

void drawLine(int i, int N, char C) {
    int j = (N + 1) - i;
    for (int s = 0; s < i; ++s) {
        cout << ' ';
    }
    cout << C;
    if (j > i) {
        for (int s = 0; s < j - i - 1; ++s) {
            cout << ' ';
        }
        cout << C;
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;
    if (N < 2) {
        cout << "Fica muito feio, meu senhor." << endl;
        return 0;
    }
    char C;
    cin >> C;

    int mid = (N + 1) / 2;

    for (int i = 0; i <= mid; ++i) {
        drawLine(i, N, C);
    }
    for (int i = mid - 1; i >= 0; --i) {
        drawLine(i, N, C);
    }

    cout << '\n';

    for (int i = 0; i <= mid; ++i) {
        drawLine(i, N, C);
    }
    int legCount = N / 2;
    for (int k = 0; k < legCount; ++k) {
        drawLine(mid, N, C);
    }

    return 0;
}