/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string addStrings(string num1, string num2) {
    string result = "";
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        result += (char)(sum % 10 + '0');
        carry = sum / 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

string multiplyStrings(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    int n = num1.size();
    int m = num2.size();
    vector<int> res(n + m, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int p1 = i + j;
            int p2 = i + j + 1;
            int sum = (num1[i] - '0') * (num2[j] - '0') + res[p2];
            res[p2] = sum % 10;
            res[p1] += sum / 10;
        }
    }
    string result = "";
    for (int p : res) {
        if (!(result.empty() && p == 0)) {
            result += (char)(p + '0');
        }
    }
    return result.empty() ? "0" : result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    if (!(cin >> s1 >> s2)) return 0;

    cout << addStrings(s1, s2) << "\n";
    cout << multiplyStrings(s1, s2) << endl;

    return 0;
}