/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int calcularC(const vector<int>& digits) {
    int somaPar = 0, somaImpar = 0;
    int n = (int)digits.size();
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) somaPar += digits[i];
        else somaImpar += digits[i];
    }
    int C = (somaPar * 3 + somaImpar) % 10;
    return C;
}

int calcularR(const vector<int>& digits) {
    int n = (int)digits.size();
    int best = 1, cur = 1;
    for (int i = 1; i < n; i++) {
        if (digits[i] == digits[i - 1]) cur++;
        else cur = 1;
        best = max(best, cur);
    }
    return best;
}

string gerarBase(string palavra) {
    string base;
    for (char ch : palavra) {
        char c = (char)tolower((unsigned char)ch);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') continue;
        base.push_back((char)toupper((unsigned char)ch));
    }
    if (base.empty()) base = "VOID";
    return base;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    string sDigits;
    cin >> sDigits;

    vector<int> digits(N);
    for (int i = 0; i < N; i++) digits[i] = sDigits[i] - '0';

    string palavra;
    cin >> palavra;

    int C = calcularC(digits);
    int R = calcularR(digits);
    string base = gerarBase(palavra);

    cout << C << " " << R << "\n";
    cout << "codigo: " << base << C << R << "\n";
    return 0;
}