/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int F, I;
    if (!(cin >> F >> I)) return 0;

    int count = 0;

    if (F >= 150 && I >= 12) count++;
    if (F >= 140 && I >= 14) count++;
    if (F >= 170 || I >= 16) count++;

    cout << count << "\n";
    return 0;
}