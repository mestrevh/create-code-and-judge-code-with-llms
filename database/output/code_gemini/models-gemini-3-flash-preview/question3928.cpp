/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string addStrings(string a, string b) {
    string res = "";
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry + (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0);
        res += (sum % 10) + '0';
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool compareNumericStrings(const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> sequence(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> sequence[i];
    }
    sort(sequence.begin(), sequence.end(), compareNumericStrings);

    vector<string> fib(n + 1);
    if (n >= 1) fib[1] = "1";
    if (n >= 2) fib[2] = "1";
    for (int i = 3; i <= n; ++i) {
        fib[i] = addStrings(fib[i - 1], fib[i - 2]);
    }

    int p = 0;
    for (int i = 1; i <= n; ++i) {
        if (p < (int)sequence.size() && fib[i] == sequence[p]) {
            p++;
        } else {
            cout << "Sherliro achou o termo " << fib[i] << " que deveria estar na posicao " << i << endl;
            break;
        }
    }

    return 0;
}