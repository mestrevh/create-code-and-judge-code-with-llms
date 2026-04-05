/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int periodo(long long ano, bool dC){
    long long y;
    if(!dC) y = -ano;
    else y = ano;

    long long marco1 = -3999; 
    long long marco2 = 476;   
    long long marco3 = 1789;  

    if(y <= marco1) return 1;
    if(y <= marco2 - 1) return 2; 
    if(y <= marco3) return 3;
    return 4;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ano;
    string era;

    int bestPeriodo = -1;
    long long bestValor = LLONG_MIN;

    for(int i = 0; i < 3; i++){
        cin >> ano >> era;
        bool dC = (era == "dC" || era == "DC" || era == "dc");
        long long y = dC ? ano : -ano;
        if(y > bestValor){
            bestValor = y;
            bestPeriodo = periodo(ano, dC);
        }
    }

    cout << bestPeriodo << "\n";
    return 0;
}