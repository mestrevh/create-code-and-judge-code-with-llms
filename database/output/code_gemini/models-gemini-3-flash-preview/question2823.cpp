/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Digite a soma dos dados em cada rodada separados por ENTER:" << endl;

    int s[3];
    bool has_invalid = false;
    for (int i = 0; i < 3; i++) {
        if (!(cin >> s[i])) break;
        if (s[i] < 2 || s[i] > 12) {
            has_invalid = true;
        }
    }

    if (has_invalid) {
        cout << "Valor invalido" << endl;
        return 0;
    }

    bool cond_extremes = false; // >= 10 or <= 4
    bool cond_even = false;     // any number is even
    bool has_two = false;       // automatic loss if 2 is rolled

    for (int i = 0; i < 3; i++) {
        if (s[i] == 2) {
            has_two = true;
        }
        if (s[i] >= 10 || s[i] <= 4) {
            cond_extremes = true;
        }
        if (s[i] % 2 == 0) {
            cond_even = true;
        }
    }

    if (!has_two && cond_extremes && cond_even) {
        cout << "Biu ganhou" << endl;
    } else {
        cout << "Biu perdeu" << endl;
    }

    return 0;
}