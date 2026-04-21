/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    if (getline(cin, a)) {
        if (!a.empty() && a.back() == '\r') a.pop_back();
        if (getline(cin, b)) {
            if (!b.empty() && b.back() == '\r') b.pop_back();
            
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            
            cout << b << " " << a << endl;
        }
    }

    return 0;
}