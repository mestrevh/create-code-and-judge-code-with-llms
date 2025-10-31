/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

string toggleLeds(string s, int c) {
    int n = s.length();
    for (int i = 0; i < c; i++) {
        s[0] = (s[0] == 'X') ? 'O' : 'X';
        for (int j = 1; j < n; j++) {
            if (s[j - 1] == 'X') {
                s[j] = (s[j] == 'X') ? 'O' : 'X';
            }
        }
    }
    return s;
}

char determineOrnament(string giant, char new_first) {
    int len = giant.length();
    char last_giant = giant[len - 1];
    if (len % 2 == 0) {
        return (last_giant == new_first) ? '@' : '$';
    } else {
        return (last_giant == new_first) ? '#' : '%';
    }
}

int main() {
    int R;
    cin >> R;
    string finalResult, giant;
    
    for (int i = 0; i < R; i++) {
        string S;
        int F;
        cin >> S >> F;

        string result = toggleLeds(S, F);
        cout << result << endl;

        if (giant.empty()) {
            giant = result;
        } else {
            char ornament = determineOrnament(giant, result[0]);
            giant += ornament + result;
        }
    }
    
    cout << giant << endl;
    return 0;
}
