/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<unsigned long long> nums;
    unsigned long long x;
    while (cin >> x) nums.push_back(x);

    unordered_map<unsigned long long, long long> freq;
    freq.reserve(nums.size() * 2 + 1);

    unsigned long long bestVal = 0;
    long long bestFreq = -1;

    for (auto v : nums) {
        long long f = ++freq[v];
        if (f > bestFreq) {
            bestFreq = f;
            bestVal = v;
        }
    }

    cout << "Moda = " << bestVal << "\n";
    return 0;
}