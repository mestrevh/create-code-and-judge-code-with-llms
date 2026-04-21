/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N;
    if (!(cin >> N)) return 0;

    if (N <= 0) {
        cout << -1 << "\n";
        return 0;
    }

    int cnt[10] = {0};
    long long x = N;

    auto factorCount = [&](long long p, int d) {
        while (x % p == 0) {
            cnt[d]++;
            x /= p;
        }
    };

    factorCount(2, 2);
    factorCount(3, 3);
    factorCount(5, 5);
    factorCount(7, 7);

    if (x != 1) {
        cout << -1 << "\n";
        return 0;
    }

    string ans;
    for (int d : {8,6,9,4,2,5,3,7}) {
        while (cnt[d] > 0) {
            if (d == 2) { if (cnt[2] == 0) break; }
            if (d == 3) { if (cnt[3] == 0) break; }
            if (d == 5) { if (cnt[5] == 0) break; }
            if (d == 7) { if (cnt[7] == 0) break; }
            if (d == 4) { if (cnt[4] == 0) break; }
            if (d == 6) { if (cnt[6] == 0) break; }
            if (d == 8) { if (cnt[8] == 0) break; }
            if (d == 9) { if (cnt[9] == 0) break; }

            break;
        }
    }

    auto combine = [&]() {
        auto use = [&](int d, int k) {
            ans.append(k, char('0' + d));
            cnt[d] -= k;
        };

        int c2 = cnt[2], c3 = cnt[3], c5 = cnt[5], c7 = cnt[7];
        int c4 = 0, c6 = 0, c8 = 0, c9 = 0;

        c9 = c3 / 2;
        c3 %= 2;

        c8 = c2 / 3;
        c2 %= 3;

        c6 = min(c2, c3);
        c2 -= c6;
        c3 -= c6;

        c4 = c2 / 2;
        c2 %= 2;

        int c2final = c2;
        int c3final = c3;
        int c5final = c5;
        int c7final = c7;

        ans.clear();
        ans.append(c2final, '2');
        ans.append(c3final, '3');
        ans.append(c5final, '5');
        ans.append(c7final, '7');
        ans.append(c4, '4');
        ans.append(c6, '6');
        ans.append(c8, '8');
        ans.append(c9, '9');

        ans = string();
        vector<pair<char,int>> digits;
        digits.push_back({'2', c2final});
        digits.push_back({'3', c3final});
        digits.push_back({'4', c4});
        digits.push_back({'5', c5final});
        digits.push_back({'6', c6});
        digits.push_back({'7', c7final});
        digits.push_back({'8', c8});
        digits.push_back({'9', c9});
        for (auto &p : digits) ans.append(p.second, p.first);

        sort(ans.begin(), ans.end());
    };

    int c2 = cnt[2], c3 = cnt[3], c5 = cnt[5], c7 = cnt[7];

    int bestLen = INT_MAX;
    string best;

    int bestD2=0,bestD3=0,bestD4=0,bestD6=0,bestD8=0,bestD9=0,bestD5=0,bestD7=0;

    for (int d9 = 0; d9 <= c3/2; d9++) {
        int rem3 = c3 - 2*d9;
        for (int d8 = 0; d8 <= c2/3; d8++) {
            int rem2a = c2 - 3*d8;
            for (int d6 = 0; d6 <= min(rem2a, rem3); d6++) {
                int rem2b = rem2a - d6;
                int rem3b = rem3 - d6;
                int d4 = rem2b/2;
                int rem2c = rem2b%2;

                int len = d9 + d8 + d6 + d4 + rem2c + rem3b + c5 + c7;
                if (len < bestLen) {
                    bestLen = len;
                    bestD2 = rem2c;
                    bestD3 = rem3b;
                    bestD4 = d4;
                    bestD5 = c5;
                    bestD6 = d6;
                    bestD7 = c7;
                    bestD8 = d8;
                    bestD9 = d9;

                    string s;
                    s.append(bestD2, '2');
                    s.append(bestD3, '3');
                    s.append(bestD4, '4');
                    s.append(bestD5, '5');
                    s.append(bestD6, '6');
                    s.append(bestD7, '7');
                    s.append(bestD8, '8');
                    s.append(bestD9, '9');
                    sort(s.begin(), s.end());
                    best = s;
                } else if (len == bestLen && bestLen != INT_MAX) {
                    string s;
                    s.append(rem2c, '2');
                    s.append(rem3b, '3');
                    s.append(d4, '4');
                    s.append(c5, '5');
                    s.append(d6, '6');
                    s.append(c7, '7');
                    s.append(d8, '8');
                    s.append(d9, '9');
                    sort(s.begin(), s.end());
                    if (!best.empty() && s < best) best = s;
                    else if (best.empty()) best = s;
                }
            }
        }
    }

    if (bestLen == INT_MAX || best.empty()) cout << -1 << "\n";
    else cout << best << "\n";
    return 0;
}