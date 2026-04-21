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

    int n;
    if (!(cin >> n)) return 0;

    long long par_score = 0;
    long long odd_score = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            string word;
            if (!(cin >> word)) break;
            if ((i + j) % 2 == 0) {
                // Time Par: coordinate sum is even, sum chars at even indices (0, 2, 4...)
                for (int k = 0; k < (int)word.length(); k += 2) {
                    par_score += (unsigned char)word[k];
                }
            } else {
                // Time Odd: coordinate sum is odd, sum chars at odd indices (1, 3, 5...)
                for (int k = 1; k < (int)word.length(); k += 2) {
                    odd_score += (unsigned char)word[k];
                }
            }
        }
    }

    if (odd_score > par_score) {
        cout << "Os impares venceram com " << odd_score << " pontos!" << endl;
    } else if (par_score > odd_score) {
        cout << "Os pares venceram com " << par_score << " pontos!" << endl;
    } else {
        cout << "Tivemos um empate em " << par_score << " pontos!" << endl;
    }

    return 0;
}