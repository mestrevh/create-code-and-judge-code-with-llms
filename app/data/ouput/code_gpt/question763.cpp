/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    
    string s = input;
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    string reversed = s;
    reverse(reversed.begin(), reversed.end());

    bool isPalindrome = (s == reversed);

    if (isPalindrome) {
        int maxLen = 0;
        for (size_t len = 1; len <= s.size() / 2; ++len) {
            if (s.substr(0, len) == s.substr(len, len)) {
                maxLen = len;
            }
        }
        cout << "SIM\n" << maxLen << endl;
    } else {
        cout << "NAO" << endl;
    }

    return 0;
}
