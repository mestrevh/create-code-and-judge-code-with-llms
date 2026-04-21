/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<array<double,4>,3> qty;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(!(cin >> qty[i][j])) return 0;
        }
    }
    array<double,4> price;
    for(int j=0;j<4;j++) cin >> price[j];

    cout.setf(std::ios::fixed);
    cout << setprecision(2);
    for(int i=0;i<3;i++){
        double cost = 0.0;
        for(int j=0;j<4;j++) cost += qty[i][j] * price[j];
        cout << cost << "\n";
    }
    return 0;
}