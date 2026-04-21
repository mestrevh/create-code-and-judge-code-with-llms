/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if (!(cin >> N)) return 0;
    
    char concept;
    if (N >= 90) concept = 'A';
    else if (N >= 80) concept = 'B';
    else if (N >= 70) concept = 'C';
    else if (N >= 60) concept = 'D';
    else concept = 'E';
    
    cout << concept << "\n";
    return 0;
}