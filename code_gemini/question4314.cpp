/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string simulate(string s, int f) {
    int n = s.length();
    for (int i = 0; i < f; ++i) {
        char prev = s[0];
        s[0] = (s[0] == 'X' ? 'O' : 'X');
        for (int j = 1; j < n; ++j) {
            if (prev == 'X') {
                prev = s[j];
                s[j] = (s[j] == 'X' ? 'O' : 'X');
            } else {
                prev = s[j];
            }
        }
    }
    return s;
}

int main() {
    int r;
    cin >> r;
    string final_string = "";
    for (int i = 0; i < r; ++i) {
        string s;
        int f;
        cin >> s >> f;
        string result = simulate(s, f);
        cout << result << endl;
        if (final_string.length() > 0) {
            char last = final_string.back();
            char first = result.front();
            if (final_string.length() % 2 == 0) {
                if (last == first) {
                    final_string += "@";
                } else {
                    final_string += "$";
                }
            } else {
                if (last == first) {
                    final_string += "#";
                } else {
                    final_string += "%";
                }
            }
        }
        final_string += result;
    }
    cout << final_string << endl;
    return 0;
}
