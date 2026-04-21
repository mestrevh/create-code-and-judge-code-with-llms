/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c1, c2;
    if (cin >> c1 >> c2) {
        int v1 = c1 - 'a';
        int v2 = c2 - 'a';
        
        if (v1 > v2) swap(v1, v2);
        
        int sum = v1 + v2;
        
        if (sum % 2 == 0) {
            cout << (char)(sum / 2 + 'a') << "\n";
        } else {
            cout << (char)(sum / 2 + 'a') << "\n";
            cout << (char)(sum / 2 + 1 + 'a') << "\n";
        }
    }

    return 0;
}