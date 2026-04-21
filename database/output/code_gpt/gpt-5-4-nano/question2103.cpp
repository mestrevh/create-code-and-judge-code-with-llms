/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool validMatrix(const array<array<int,3>,3>& m) {
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i!=j && i+j!=2){
                if(m[i][j]!=0) return false;
            } else {
                if(m[i][j]!=1) return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long lukeHP, vaderHP;
    if(!(cin >> lukeHP >> vaderHP)) return 0;

    array<array<int,3>,3> m1, m2;
    long long lukeDamage = 0, vaderDamage = 0;
    bool anyRound = false;

    while(true){
        bool ok1 = true, ok2 = true;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int x;
                if(!(cin >> x)){ ok1 = false; break; }
                m1[i][j]=x;
            }
            if(!ok1) break;
        }
        if(!ok1) break;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int x;
                if(!(cin >> x)){ ok2 = false; break; }
                m2[i][j]=x;
            }
            if(!ok2) break;
        }
        if(!ok2) break;

        anyRound = true;
        bool v1 = validMatrix(m1);
        bool v2 = validMatrix(m2);

        if(v1 && v2){
            bool sameDiag = true;
            for(int i=0;i<3;i++){
                if(m1[i][i] != m2[i][i]) { sameDiag = false; break; }
            }
            if(sameDiag){
                for(int i=0;i<3;i++){
                    int j = 2 - i;
                    if(m1[i][j] != m2[i][j]) { sameDiag = false; break; }
                }
            }
            if(sameDiag){
                lukeDamage += 15;
                vaderDamage += 15;
            } else {
                bool diff = false;
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(m1[i][j] != m2[i][j]) { diff = true; break; }
                    }
                    if(diff) break;
                }
                if(!diff){
                    lukeDamage += 0;
                    vaderDamage += 0;
                } else {
                    lukeDamage += 0;
                    vaderDamage += 0;
                }
            }
        } else if(v1){
            vaderDamage += 15;
        } else if(v2){
            lukeDamage += 15;
        }
    }

    long long lukeFinal = lukeHP - lukeDamage;
    long long vaderFinal = vaderHP - vaderDamage;

    if(lukeFinal > vaderFinal) cout << "Luke Skywalker venceu.";
    else if(vaderFinal > lukeFinal) cout << "Darth Vader venceu.";
    else cout << "Houve empate.";

    return 0;
}