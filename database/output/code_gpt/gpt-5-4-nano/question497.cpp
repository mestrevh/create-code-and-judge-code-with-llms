/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double s[5];
    for (int i = 0; i < 5; i++) {
        if (!(cin >> s[i])) return 0;
    }

    int days[5] = {0,1,2,3,4}; 
    int typeOfDay[5] = {0,2,1,0,2}; 
    string names[3] = {"NOVELA","FUTEBOL","FILME"};

    double sum = 0.0;
    for (int i = 0; i < 5; i++) sum += s[i];
    double avg = sum / 5.0;

    double best = s[0];
    int bestType = typeOfDay[0];
    for (int i = 1; i < 5; i++) {
        if (s[i] > best) {
            best = s[i];
            bestType = typeOfDay[i];
        }
    }

    cout << fixed << setprecision(2) << avg << "\n" << names[bestType] << "\n";
    return 0;
}