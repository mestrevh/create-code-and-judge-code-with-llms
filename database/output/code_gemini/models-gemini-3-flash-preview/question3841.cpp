/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X;
    if (!(cin >> X)) return 0;

    long long letters_count = 0;
    long long digits_count = 0;

    for (long long i = 0; i < X; ++i) {
        string s;
        if (!(cin >> s)) break;
        if (s.empty()) continue;
        char c = s[0];
        if (c >= '0' && c <= '9') {
            digits_count++;
        } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            letters_count++;
        }
    }

    long long K;
    if (!(cin >> K)) return 0;

    vector<bool> is_p;
    if (K >= 0) {
        is_p.assign(K + 1, true);
        is_p[0] = false;
        if (K >= 1) is_p[1] = false;
        for (long long p = 2; p * p <= K; p++) {
            if (is_p[p]) {
                for (long long j = p * p; j <= K; j += p)
                    is_p[j] = false;
            }
        }
    }

    for (long long i = 1; i <= K; ++i) {
        long long res_seq = 0;
        long long res_num = 0;

        if (is_p[i]) {
            // Se o tamanho i for um número primo, ele só quer escrever números
            if (digits_count == 0) {
                res_num = 0;
            } else {
                res_num = 1;
                for (long long j = 0; j < i; ++j) {
                    res_num *= digits_count;
                }
            }
            res_seq = 0;
        } else {
            // Se o tamanho i NÃO for um número primo, ele só quer escrever sequências
            if (letters_count == 0) {
                res_seq = 0;
            } else {
                res_seq = 1;
                for (long long j = 0; j < i; ++j) {
                    res_seq *= letters_count;
                }
            }
            res_num = 0;
        }

        cout << "Tamanho " << i << ":\n";
        cout << "Sequencias: " << res_seq << ", Numeros: " << res_num << "\n";
    }

    return 0;
}