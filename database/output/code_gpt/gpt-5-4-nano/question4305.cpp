/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string xs, ys, letter;
    long long N;

    if (!(cin >> xs >> ys >> letter >> N)) return 0;

    auto parseTimeToMinutes = [](const string& s) -> long long {
        bool neg = false;
        string t = s;
        if (!t.empty() && t[0] == '-') { neg = true; t = t.substr(1); }
        size_t pos = t.find('.');
        long long minutes = 0;
        if (pos == string::npos) {
            minutes = stoll(t) * 60;
        } else {
            string a = t.substr(0, pos);
            string b = t.substr(pos + 1);
            long long hour = a.empty() ? 0 : stoll(a);
            minutes = hour * 60;
            long long frac = 0;
            for (int i = 0; i < (int)b.size(); i++) {
                if (!isdigit((unsigned char)b[i])) break;
                frac = frac * 10 + (b[i] - '0');
            }
            long long denomPow10 = 1;
            for (int i = 0; i < (int)b.size(); i++) denomPow10 *= 10;
            if (frac != 0) minutes += (frac * 60 + denomPow10 / 2) / denomPow10;
        }
        return neg ? -minutes : minutes;
    };

    long long X = parseTimeToMinutes(xs);
    long long Y = parseTimeToMinutes(ys);

    bool valid = true;

    auto isValidLetter = [&]() -> bool {
        if (letter.size() != 1) return false;
        return letter[0] == 'A' || letter[0] == 'B';
    };

    if (X < 0 || X >= 24 * 60) valid = false;
    if (Y < 0 || Y >= 24 * 60) valid = false;
    if (X >= Y) valid = false;
    if (!isValidLetter()) valid = false;
    if (N <= 0) valid = false;

    long long diff = Y - X;

    if (valid) {
        if (letter[0] == 'A') {
            if (diff <= 60) valid = false;
        } else if (letter[0] == 'B') {
            if (diff <= 45) valid = false;
        }
    }

    if (valid) {
        long long thresholdExtra = (diff * 50 + 99) / 100;
        long long baseCap = 5;
        long long cap = baseCap;
        if (diff >= (thresholdExtra)) {
            cap = 9;
        }
        if (N > cap) valid = false;
    }

    if (!valid) {
        bool validInput = true;
        if (X < 0 || X >= 24 * 60) validInput = false;
        if (Y < 0 || Y >= 24 * 60) validInput = false;
        if (X >= Y) validInput = false;
        if (!isValidLetter()) validInput = false;
        if (N <= 0) validInput = false;

        if (!validInput) {
            cout << "Entrada Invalida\n";
        } else {
            cout << "Infelizmente o uninho nao tanka, rodamos!\n";
        }
    } else {
        cout << "O uninho faz a boa, obrigado querida mae line\n";
    }

    return 0;
}