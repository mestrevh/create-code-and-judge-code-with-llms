/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int s, e, v;
};

bool compareJobs(const Job& a, const Job& b) {
    if (a.e != b.e) return a.e < b.e;
    return a.s < b.s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int caseNum = 1;
    while (cin >> n) {
        vector<Job> jobs(n);
        for (int i = 0; i < n; ++i) {
            cin >> jobs[i].s >> jobs[i].e >> jobs[i].v;
        }

        if (n <= 0) {
            if (cin.eof()) break;
            cout << "caso " << caseNum++ << ": 0\n\n";
            continue;
        }

        sort(jobs.begin(), jobs.end(), compareJobs);

        vector<long long> dp(n);
        for (int i = 0; i < n; ++i) {
            long long includeProfit = jobs[i].v;
            int p = -1;
            int low = 0, high = i - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (jobs[mid].e < jobs[i].s) {
                    p = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (p != -1) {
                includeProfit += dp[p];
            }

            long long excludeProfit = (i > 0) ? dp[i - 1] : 0;
            dp[i] = (includeProfit > excludeProfit) ? includeProfit : excludeProfit;
        }

        cout << "caso " << caseNum++ << ": " << dp[n - 1] << "\n\n";
    }

    return 0;
}