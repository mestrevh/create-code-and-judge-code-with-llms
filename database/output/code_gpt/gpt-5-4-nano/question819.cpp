/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    if (!(cin >> A >> B)) return 0;

    map<string,int> d = {{"norte",0},{"leste",1},{"sul",2},{"oeste",3}};
    int a = d[A], b = d[B];
    int diff = abs(a - b);
    diff = min(diff, 4 - diff);
    cout << diff * 90 << "\n";
    return 0;
}