/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int age;
    int gratuitos = 0;
    while (cin >> age) {
        if (age == 111) break;
        char sex;
        cin >> sex;
        sex = toupper(sex);

        bool free = false;
        if (age <= 10) free = true;
        if (age > 60) free = true;
        if (sex == 'M' && age > 25 && age < 35) free = true;

        if (free) gratuitos++;
    }

    cout << gratuitos << "\n";
    return 0;
}