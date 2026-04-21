/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int total = 0;

    double maxVale = 0.0;

    int starkLancers = 0;

    int minWildlingArcherAge = 999;

    char nightHighestSwordSex = 'X';
    double nightHighestSwordHeight = -1.0;

    char house;
    while (cin >> house) {
        if (!(house=='S' || house=='P' || house=='C' || house=='O')) break;

        char sex;
        int age;
        double height;
        char ability;

        cin >> sex >> age >> height >> ability;

        total++;

        if (house=='C') {
            maxVale = max(maxVale, height);
        }

        if (house=='S' && ability=='l') {
            starkLancers++;
        }

        if (house=='O' && ability=='a') {
            minWildlingArcherAge = min(minWildlingArcherAge, age);
        }

        if (house=='P' && ability=='e') {
            if (height > nightHighestSwordHeight) {
                nightHighestSwordHeight = height;
                nightHighestSwordSex = sex;
            }
        }
    }

    cout << total << "\n";
    cout << fixed << setprecision(2) << maxVale << "\n";
    cout << starkLancers << "\n";
    if (total == 0 || minWildlingArcherAge == 999) cout << 999 << "\n";
    else cout << minWildlingArcherAge << "\n";
    if (total == 0 || nightHighestSwordSex == 'X') cout << 'X' << "\n";
    else cout << nightHighestSwordSex << "\n";

    return 0;
}