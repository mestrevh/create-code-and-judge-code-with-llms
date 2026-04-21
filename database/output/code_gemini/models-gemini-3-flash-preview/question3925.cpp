/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    if (!(cin >> s)) return 0;
    
    if (s.length() < 4) return 0;
    
    int a = s[0] - '0';
    int b = s[3] - '0';
    string suffix = s.substr(3);
    
    bool found = false;
    for (int i = 0; i <= 99; ++i) {
        if (is_prime(i / a) && is_prime(i / b)) {
            found = true;
            cout << s[0];
            if (i < 10) cout << '0';
            cout << i << suffix << "\n";
        }
    }
    
    if (!found) {
        cout << "Marquinhos esta louco!\n";
    }
    
    return 0;
}