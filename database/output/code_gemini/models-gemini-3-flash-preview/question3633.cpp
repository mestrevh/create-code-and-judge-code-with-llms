/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int kyara_total_wins = 0;
    int vinicius_total_wins = 0;

    for (int i = 0; i < n; ++i) {
        string s1, s2;
        if (!(cin >> s1 >> s2)) break;

        for (auto &c : s1) c = (char)tolower((unsigned char)c);
        for (auto &c : s2) c = (char)tolower((unsigned char)c);

        bool s1_valid = (s1 == "pedra" || s1 == "papel" || s1 == "tesoura");
        bool s2_valid = (s2 == "pedra" || s2 == "papel" || s2 == "tesoura");

        if (!s1_valid || !s2_valid) continue;

        if (s1 == s2) {
            continue;
        } else if ((s1 == "pedra" && s2 == "tesoura") ||
                   (s1 == "papel" && s2 == "pedra") ||
                   (s1 == "tesoura" && s2 == "papel")) {
            kyara_total_wins++;
        } else {
            vinicius_total_wins++;
        }
    }

    if (kyara_total_wins > vinicius_total_wins) {
        cout << "VINICIUS VAI LAVAR A LOUÇA!" << endl;
    } else if (vinicius_total_wins > kyara_total_wins) {
        cout << "KYARA VAI LAVAR A LOUÇA!" << endl;
    } else {
        cout << "OS DOIS VÃO LAVAR A LOUÇA JUNTOS!" << endl;
    }

    return 0;
}