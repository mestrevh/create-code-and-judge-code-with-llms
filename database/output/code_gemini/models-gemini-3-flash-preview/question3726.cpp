/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!getline(cin, s)) return 0;

    vector<long long> v;
    int n = (int)s.size();
    for (int i = 0; i < n; ++i) {
        if (isdigit(s[i]) || (s[i] == '-' && i + 1 < n && isdigit(s[i + 1]))) {
            long long val = 0;
            int sign = 1;
            if (s[i] == '-') {
                sign = -1;
                i++;
            }
            while (i < n && isdigit(s[i])) {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            v.push_back(val * sign);
            i--; 
        }
    }

    bool sorted = true;
    if (v.size() > 1) {
        for (size_t i = 1; i < v.size(); ++i) {
            if (v[i] < v[i - 1]) {
                sorted = false;
                break;
            }
        }
    }

    if (sorted) {
        cout << "Ordenado" << endl;
    } else {
        cout << "Nao ordenado" << endl;
    }

    return 0;
}