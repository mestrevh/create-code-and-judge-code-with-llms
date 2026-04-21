/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string toUpperStr(string s){
    for(char &c: s) c = (char)toupper((unsigned char)c);
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 11;
    int cntSexta = 0, cntDomingo = 0;
    int cntBar = 0, cntPraia = 0;

    for(int i = 0; i < n; i++){
        string dia, local;
        if(!(cin >> dia >> local)) return 0;
        dia = toUpperStr(dia);
        local = toUpperStr(local);

        if(dia == "SEXTA") cntSexta++;
        else if(dia == "DOMINGO") cntDomingo++;

        if(local == "BAR") cntBar++;
        else if(local == "PRAIA") cntPraia++;
    }

    string resDia = (cntSexta > cntDomingo) ? "SEXTA" : "DOMINGO";
    string resLocal = (cntBar > cntPraia) ? "BAR" : "PRAIA";

    cout << resDia << "\n" << resLocal << "\n";
    return 0;
}