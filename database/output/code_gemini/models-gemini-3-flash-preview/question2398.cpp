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

    int d, m, a;
    char s1, s2;

    if (cin >> d >> s1 >> m >> s2 >> a) {
        cout << setfill('0');
        
        cout << setw(2) << m << "/" << setw(2) << d << "/" << setw(2) << a << "\n";
        
        cout << setw(2) << a << "/" << setw(2) << m << "/" << setw(2) << d << "\n";
        
        cout << setw(2) << d << "-" << setw(2) << m << "-" << setw(2) << a << "\n";
    }

    return 0;
}