/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A,B,C,D,E,F,G,H;
    if(!(cin >> A >> B >> C >> D >> E >> F >> G >> H)) return 0;

    bool ok = true;

    auto sameTeam = [&](int x, int y){ return x == y; };

    if(!( !sameTeam(A,B) || true )) {}

    if(ok){
        if(! (sameTeam(A, G) || sameTeam(A, F) || sameTeam(A, H) || sameTeam(A, D) || sameTeam(A, B) )) {
            ok = false;
        }
    }

    if(ok){
        if(sameTeam(A, B) || sameTeam(A, D)) {
        } 
    }

    auto violate = [&](){
        ok = false;
    };

    if(ok){
        if(sameTeam(A, A)) {}
    }

    if(ok){
        if(!sameTeam(A,B) && !sameTeam(A,D) && !sameTeam(A,F) && !sameTeam(A,H)) {
            ok = false;
        }
    }

    if(ok){
        if(sameTeam(B,A) || sameTeam(B,D)) ok = false;
    }

    if(ok){
        if(sameTeam(G,H)) {
            if(!sameTeam(D,C)) ok = false;
        }
    }

    if(ok){
        if(sameTeam(H,G) || sameTeam(H,F)) {
        } else {
            ok = false;
        }
        if(sameTeam(H,A) || sameTeam(H,B) || sameTeam(H,C) || sameTeam(H,D) || sameTeam(H,E)) {
            ok = false;
        }
    }

    if(ok){
        if(sameTeam(C,E)) {
            if(!sameTeam(F,A)) ok = false;
        } else {
            if(sameTeam(F,A)) ok = false;
        }
    }

    cout << (ok ? "Conseguimos times suficientes!\n" : "Alguem nao esta satisfeito...\n");
    return 0;
}