/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    int oldest = -1;

    long long totalPeople = 0;
    long long countWomenEligible = 0;

    while (true) {
        int age;
        if (!(cin >> age)) return 0;
        if (age == -1) break;

        string sex, hair, eyes;
        cin >> sex >> hair >> eyes;

        totalPeople++;
        oldest = max(oldest, age);

        if (sex == "f" && hair == "l" && eyes == "v" && age >= 18 && age <= 35) {
            countWomenEligible++;
        }
    }

    double percent = 0.0;
    if (totalPeople > 0) percent = 100.0 * (double)countWomenEligible / (double)totalPeople;

    cout << "Mais velho: " << oldest << "\n";
    cout << "Mulheres com olhos verdes, loiras com 18 a 35 anos: " << fixed << setprecision(2) << percent << "%";
    return 0;
}