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
    
    for (int i = 0; i < N; i++) {
        int spaces = N - 1 - i;
        int stars = 2 * i + 1;
        for (int s = 0; s < spaces; s++) cout << '.';
        for (int k = 0; k < stars; k++) cout << '*';
        cout << "\n";
    }
    for (int i = 0; i < N; i++) {
        int spaces = i;
        int stars = 2 * (N - 1 - i) + 1;
        for (int s = 0; s < spaces; s++) cout << '.';
        for (int k = 0; k < stars; k++) cout << '*';
        cout << "\n";
    }
    return 0;
}