/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef vector<int> BigInt;

BigInt factorialInBase(int n, int b) {
    BigInt res;
    res.push_back(1);
    for (int i = 2; i <= n; ++i) {
        long long carry = 0;
        for (int &digit : res) {
            carry += (long long)digit * i;
            digit = (int)(carry % b);
            carry /= b;
        }
        while (carry) {
            res.push_back((int)(carry % b));
            carry /= b;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int countTotalZeros(const BigInt& res) {
    int z = 0;
    for (int d : res) {
        if (d == 0) z++;
    }
    return z;
}

string formatBase(const BigInt& res) {
    string s = "";
    for (int d : res) {
        if (d < 10) s += (char)('0' + d);
        else s += (char)('A' + (d - 10));
    }
    return s;
}

bool checkFim(string s) {
    if (s.length() != 3) return false;
    for (char &c : s) c = (char)toupper(c);
    return s == "FIM";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while (cin >> s) {
        if (checkFim(s)) break;
        int b;
        if (!(cin >> b)) break;
        
        int n = 0;
        bool is_neg = false;
        try {
            n = stoi(s);
            if (n < 0) is_neg = true;
        } catch (...) {
            if (!s.empty() && s[0] == '-') is_neg = true;
            else n = 10000;
        }

        if (is_neg) {
            cout << "Numero negativo" << endl;
        } else if (b <= 1 || b > 16) {
            cout << "Base invalida" << endl;
        } else {
            BigInt f10 = factorialInBase(n, 10);
            BigInt fB = factorialInBase(n, b);
            cout << formatBase(f10) << " " << formatBase(fB) << " " << countTotalZeros(fB) << " " << (int)fB.size() << endl;
        }
    }
    return 0;
}