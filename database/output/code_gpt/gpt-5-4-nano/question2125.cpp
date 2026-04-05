/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static double solveChance(int H, int isPM, double S) {
    int hour24 = (H % 12) + (isPM ? 12 : 0);
    int start = 5;
    int end = hour24;

    auto step = [&](double prev, bool even, int modBase) -> double {
        if (even) return prev + S / 2.0;
        return prev + fmod(prev, 7.0);
    };

    auto stepPMtoAm = [&](double prev, bool even, int modBase) -> double {
        if (even) return prev + S;
        return prev + fmod(prev, 10.0);
    };

    double chance = 0.0;

    int cur = start;
    while (cur != end) {
        bool even = (cur % 2 == 0);
        if (cur >= 16 || cur < 5) {
            chance = stepPMtoAm(chance, even, 10);
        } else {
            if (cur >= 6 && cur <= 15) {
                chance = step(chance, even, 7);
            } else {
                if (cur == 5) chance = S / 0.0;
            }
        }
        cur = (cur + 1) % 24;
    }

    return chance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string timeStr;
    if (!(cin >> timeStr)) return 0;
    int H;
    string ampm;
    {
        string s = timeStr;
        H = stoi(s);
        cin >> ampm;
    }
    double S;
    cin >> S;

    if (S < 0) {
        cout << "Dados Invalidos.";
        return 0;
    }

    if (!(ampm == "am" || ampm == "pm")) {
        cout << "Dados Invalidos.";
        return 0;
    }

    int isPM = (ampm == "pm");

    if (H < 1 || H > 12) {
        cout << "Dados Invalidos.";
        return 0;
    }

    int hour24 = (H % 12) + (isPM ? 12 : 0);
    int startHour = 5;
    if (hour24 == 5) {
        double x = 5.0;
        cout << fixed << setprecision(1)
             << "A chance de aparecimento de Demogorgon e de " << x << "%.";
        if (x >= 100.0) cout << "\nOu seja, nao olhe para tras.";
        return 0;
    }

    function<double(int, double)> rec = [&](int curHour, double prev) -> double {
        int next = (curHour + 1) % 24;
        if (next == hour24) return prev;
        bool even = (curHour % 2 == 0);
        if (curHour >= 16 || curHour < 5) {
            if (even) prev = prev + S;
            else prev = prev + fmod(prev, 10.0);
        } else {
            if (curHour >= 6 && curHour <= 15) {
                if (even) prev = prev + S / 2.0;
                else prev = prev + fmod(prev, 7.0);
            }
        }
        return rec(next, prev);
    };

    double chance = 0.0;

    int curHour = startHour;
    bool even = (curHour % 2 == 0);
    chance = 5.0;

    function<double(int, double)> go = [&](int h, double prev) -> double {
        if (h == hour24) return prev;
        bool ev = (h % 2 == 0);
        if (h >= 16 || h < 5) {
            if (ev) prev = prev + S;
            else prev = prev + fmod(prev, 10.0);
        } else {
            if (h >= 6 && h <= 15) {
                if (ev) prev = prev + S / 2.0;
                else prev = prev + fmod(prev, 7.0);
            } else {
                if (h == 5) prev = prev + 0;
            }
        }
        int nh = (h + 1) % 24;
        return go(nh, prev);
    };

    double result = go(startHour, chance);

    if (!(hour24 >= 0 && hour24 <= 23)) {
        cout << "Dados Invalidos.";
        return 0;
    }

    cout << fixed << setprecision(1)
         << "A chance de aparecimento de Demogorgon e de " << result << "%.";
    if (result >= 100.0) cout << "\nOu seja, nao olhe para tras.";
    return 0;
}