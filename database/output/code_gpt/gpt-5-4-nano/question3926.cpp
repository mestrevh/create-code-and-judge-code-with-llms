/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isPrime(int x){
    if(x < 2) return false;
    if(x == 2 || x == 3) return true;
    if(x % 2 == 0) return false;
    for(int i = 3; 1LL*i*i <= x; i += 2) if(x % i == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long Dis;
    int Tam;
    if(!(cin >> Dis >> Tam)) return 0;

    vector<int> primeVisited;
    long long xp = 0;
    long long vale = 0;

    long long steps = 0;
    long long pos = 0;

    while(steps < Dis){
        if(isPrime((int)pos)) {
            primeVisited.push_back((int)pos);
            xp += pos;
        }
        if(pos == 7) vale++;
        pos = (pos + 1) % Tam;
        steps++;
    }

    long long coinsFromCircle = 1;
    if(vale > 0){
        coinsFromCircle = 1;
        for(long long i = 1; i <= vale; i++){
            coinsFromCircle *= i;
        }
    } else {
        coinsFromCircle = 0;
    }

    if(vale == 0){
        cout << "Experiencia = " << xp << " Moedas = " << coinsFromCircle << "\n";
        cout << "Ja que nao achei moedas, vou na Torre\n";

        long long torreCoins = 0;
        long long floors = 0;

        if(xp > 0){
            long long floorCount = xp;
            floors = floorCount;
            long long blocks = floorCount / 7;
            torreCoins += blocks * 30;
        }

        vector<long long> towerFloors;
        for(int k = 1; ; k++){
            long long f = 7LL * k;
            if(f > xp) break;
            towerFloors.push_back(f);
        }

        for(size_t i = 0; i < towerFloors.size(); i++){
            cout << towerFloors[i];
            if(i + 1 < towerFloors.size()) cout << " ";
            else cout << "\n";
        }
        if(towerFloors.empty()){
            cout << "\n";
        }

        if(xp == 0) cout << "Desisto.\n";
        else cout << "Consegui " << torreCoins << " moedas na Torre\n";
    } else {
        cout << "Experiencia = " << xp << " Moedas = " << coinsFromCircle << "\n";
    }

    if(!primeVisited.empty()){
        for(size_t i = 0; i < primeVisited.size(); i++){
            cout << primeVisited[i] << (i + 1 < primeVisited.size() ? ' ' : '\n');
        }
    } else {
        cout << "\n";
    }

    if(vale != 0){
        return 0;
    }

    return 0;
}