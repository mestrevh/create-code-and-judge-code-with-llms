/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double dollar;
    while (cin >> dollar) {
        cout << fixed << setprecision(2) << (dollar * 3.55) << "\n";
    }
    
    return 0;
}