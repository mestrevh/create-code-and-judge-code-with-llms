/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long s;
    if (!(cin >> s)) return 0;

    long long days = s / 86400;
    s %= 86400;
    long long hours = s / 3600;
    s %= 3600;
    long long minutes = s / 60;
    long long seconds = s % 60;

    cout << days << "\n" << hours << "\n" << minutes << "\n" << seconds;
    return 0;
}