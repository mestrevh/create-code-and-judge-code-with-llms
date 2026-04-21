/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int par[5];
    int impar[5];
    int p_cnt = 0;
    int i_cnt = 0;
    int num;

    for (int i = 0; i < 15; ++i) {
        if (!(cin >> num)) break;
        if (num % 2 == 0) {
            par[p_cnt] = num;
            p_cnt++;
            if (p_cnt == 5) {
                for (int j = 0; j < 5; ++j) {
                    cout << "par[" << j << "] = " << par[j] << "\n";
                }
                p_cnt = 0;
            }
        } else {
            impar[i_cnt] = num;
            i_cnt++;
            if (i_cnt == 5) {
                for (int j = 0; j < 5; ++j) {
                    cout << "impar[" << j << "] = " << impar[j] << "\n";
                }
                i_cnt = 0;
            }
        }
    }

    for (int i = 0; i < i_cnt; ++i) {
        cout << "impar[" << i << "] = " << impar[i] << "\n";
    }

    for (int i = 0; i < p_cnt; ++i) {
        cout << "par[" << i << "] = " << par[i] << "\n";
    }

    return 0;
}