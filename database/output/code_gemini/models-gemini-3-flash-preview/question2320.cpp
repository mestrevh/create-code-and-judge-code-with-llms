/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct BigInt {
    vector<int> d;
    BigInt(long long v = 0) {
        if (v == 0) d.push_back(0);
        while (v > 0) {
            d.push_back(v % 10);
            v /= 10;
        }
    }
    void multiply(int n) {
        if (n == 0) {
            d.assign(1, 0);
            return;
        }
        long long carry = 0;
        for (size_t i = 0; i < d.size() || carry; ++i) {
            if (i == d.size()) d.push_back(0);
            long long cur = carry + (long long)d[i] * n;
            d[i] = (int)(cur % 10);
            carry = cur / 10;
        }
        while (d.size() > 1 && d.back() == 0) d.pop_back();
    }
    bool lessThan50() {
        if (d.size() > 2) return false;
        int val = 0;
        if (d.size() == 2) val = d[1] * 10 + d[0];
        else if (!d.empty()) val = d[0];
        return val < 50;
    }
    void print() {
        for (int i = (int)d.size() - 1; i >= 0; --i) cout << d[i];
        cout << "\n";
    }
};

BigInt factorial(int n) {
    if (n <= 1) return BigInt(1);
    BigInt res = factorial(n - 1);
    res.multiply(n);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int y;
    long long total_sum = 0;
    while (cin >> y) {
        total_sum += y;
        BigInt res = factorial(y);
        if (res.lessThan50()) {
            res.multiply(2);
        }
        res.print();
    }
    if (total_sum > 100) {
        cout << "WildCats, get the head in the game!" << endl;
    }
    return 0;
}