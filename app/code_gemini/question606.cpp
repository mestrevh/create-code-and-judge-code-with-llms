/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string S;
int N;
vector<int> counts;
string ans;

string largest_valid(int k) {
    if (k <= 0) {
        return "";
    }
    string res = "";
    int digit = 9;
    int count = 0;
    for (int i = 0; i < k; ++i) {
        res += to_string(digit);
        count++;
        if (count == 2) {
            digit--;
            count = 0;
        }
    }
    return res;
}

bool solve(int index, bool tight) {
    if (index == N) {
        return true;
    }

    int limit = tight ? (S[index] - '0') : 9;

    for (int d = limit; d >= 0; --d) {
        if (N > 1 && index == 0 && d == 0) {
            continue;
        }
        
        if (counts[d] < 2) {
            counts[d]++;
            ans += to_string(d);

            bool new_tight = tight && (d == limit);

            if (solve(index + 1, new_tight)) {
                return true;
            }

            ans.pop_back();
            counts[d]--;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S;
    N = S.length();
    counts.assign(10, 0);

    if (solve(0, true)) {
        cout << ans << endl;
    } else {
        cout << largest_valid(N - 1) << endl;
    }

    return 0;
}
