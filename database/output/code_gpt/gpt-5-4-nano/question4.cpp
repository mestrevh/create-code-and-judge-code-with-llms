/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    int J = 0, M = 0;
    long long S = 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    unordered_set<int> seen;
    seen.reserve(n * 2);

    long long evenSumUnique = 0, oddSumUnique = 0;

    for (int x : nums) {
        if (seen.insert(x).second) {
            if (x % 2 == 0) evenSumUnique += x;
            else oddSumUnique += x;
        }
        if (x % 2 == 0) J++;
        else M++;
    }

    S = max(evenSumUnique, oddSumUnique);

    cout << J << "\n" << M << "\n" << S << "\n";
    return 0;
}