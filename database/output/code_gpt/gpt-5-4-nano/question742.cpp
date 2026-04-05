/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string reverseString(const string& s) {
    string t = s;
    reverse(t.begin(), t.end());
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string A, B;
    if (!getline(cin, A)) return 0;
    getline(cin, B);
    
    A = reverseString(A);
    B = reverseString(B);
    
    cout << B << " " << A;
    return 0;
}