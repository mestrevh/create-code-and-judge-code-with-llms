/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

unsigned long long digitSum(unsigned long long n) {
    if (n < 10) return n;
    return n % 10 + digitSum(n / 10);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long n;
    if (!(cin >> n)) return 0;
    cout << digitSum(n) << "\n";
    return 0;
}