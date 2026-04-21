/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

string add(string a, string b) {
    string res = "";
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int val1 = (i >= 0) ? (a[i--] - '0') : 0;
        int val2 = (j >= 0) ? (b[j--] - '0') : 0;
        int sum = val1 + val2 + carry;
        res += (char)((sum % 10) + '0');
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

string normalize(string s) {
    size_t first = s.find_first_not_of('0');
    if (first == string::npos) return "0";
    return s.substr(first);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    map<char, long long> counts;
    set<char> distinct;
    string totalSum = "0";

    while (cin >> s) {
        string digits = "";
        for (char c : s) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                distinct.insert(c);
                counts[c]++;
            } else if (c >= '0' && c <= '9') {
                digits += c;
            }
        }
        if (!digits.empty()) {
            totalSum = add(totalSum, digits);
        }
    }

    if (distinct.size() != 3) {
        cout << "eh... parece que Rebeka continua pobre e atras das grades" << endl;
    } else {
        vector<char> L(distinct.begin(), distinct.end());
        string password = "";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    char c[3] = {L[i], L[j], L[k]};
                    map<char, int> need;
                    need[c[0]]++;
                    need[c[1]]++;
                    need[c[2]]++;
                    
                    bool ok = true;
                    for (auto const& [ch, req] : need) {
                        if (counts[ch] < req) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        password += c[0];
                        password += c[1];
                        password += c[2];
                    }
                }
            }
        }
        cout << password << endl;
        cout << "Rebeka agora esta livre! A senha da cela eh " << normalize(totalSum) << endl;
    }

    return 0;
}