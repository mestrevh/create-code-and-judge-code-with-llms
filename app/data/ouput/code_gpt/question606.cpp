/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isValid(const string& s) {
    int count[10] = {0};
    for (char c : s) {
        count[c - '0']++;
        if (count[c - '0'] > 2) return false;
    }
    return true;
}

string adjust(string s, int pos) {
    while (pos >= 0) {
        if (s[pos] == '0') {
            s[pos] = '9';
            pos--;
            while (pos >= 0 && s[pos] == '0') {
                s[pos] = '9';
                pos--;
            }
            if (pos >= 0) s[pos]--;
        } else {
            s[pos]--;
            break;
        }
    }
    for (int i = pos + 1; i < s.size(); i++) {
        s[i] = '9';
    }
    return s;
}

string findLargestValid(int u) {
    string s = to_string(u);
    
    if (isValid(s)) return s;

    for (int i = s.size() - 1; i >= 0; i--) {
        if (i > 0 && s[i] > '0' && s[i] < '9') {
            string t = adjust(s, i);
            if (isValid(t)) return t;
        }
    }
    return "0";
}

int main() {
    long long u;
    cin >> u;
    cout << findLargestValid(u) << endl;
    return 0;
}
