/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (cin >> n) {
        int tens = n / 10;
        int units = n % 10;
        int reversed = units * 10 + tens;
        cout << reversed << "\n";
    }
    
    return 0;
}