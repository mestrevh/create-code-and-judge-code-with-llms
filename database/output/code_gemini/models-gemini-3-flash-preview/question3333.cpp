/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char target;
    if (!(cin >> target)) return 0;

    int n = target - 'A';

    for (int i = 0; i <= n; ++i) {
        int dots = n - i;
        
        for (int j = 0; j < dots; ++j) {
            cout << '.';
        }
        
        for (int j = 0; j <= i; ++j) {
            cout << (char)('A' + j);
        }
        
        for (int j = i - 1; j >= 0; --j) {
            cout << (char)('A' + j);
        }
        
        for (int j = 0; j < dots; ++j) {
            cout << '.';
        }
        
        cout << '\n';
    }

    return 0;
}