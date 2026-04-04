/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p;
    while (cin >> p && p != 0) {
        int n10 = p / 10;
        int rem = p % 10;
        int n5 = rem / 5;
        int n1 = rem % 5;
        int total = n10 + n5 + n1;
        
        cout << total << "\n";
        cout << n1 << " " << n5 << " " << n10 << "\n";
    }

    return 0;
}