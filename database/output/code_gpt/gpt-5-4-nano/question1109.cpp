/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<long long> prog(7), lines(7);
    for (int i = 0; i < 7; i++) {
        if (!(cin >> prog[i])) return 0;
        if (!(cin >> lines[i])) return 0;
    }

    const long long needProg = 5;
    const long long needLines = 100;

    vector<string> days = {"DOMINGO","SEGUNDA","TERCA","QUARTA","QUINTA","SEXTA","SABADO"};

    int daysProg = 0, daysLines = 0;
    for (int i = 0; i < 7; i++) {
        if (prog[i] >= needProg) daysProg++;
        if (lines[i] >= needLines) daysLines++;
    }

    int bestDay = 0;
    for (int i = 1; i < 7; i++) {
        if (lines[i] >= lines[bestDay]) bestDay = i;
    }

    cout << "QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE PROGRAMAS: " << daysProg << "\n";
    cout << "QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE LINHAS: " << daysLines << "\n";
    cout << "DIA QUE MAIS PRODUZIU: " << days[bestDay] << "\n";
    return 0;
}