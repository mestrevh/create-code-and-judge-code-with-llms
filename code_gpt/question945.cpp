/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LIS(vector<int>& seq) {
    vector<int> dp(seq.size(), 1);
    for (int i = 1; i < seq.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (seq[i] > seq[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> correct(n);
    for (int i = 0; i < n; i++) {
        cin >> correct[i];
    }

    vector<int> position(n + 1);
    for (int i = 0; i < n; i++) {
        position[correct[i]] = i;
    }

    int student_response[n];
    while (true) {
        bool end = true;
        for (int i = 0; i < n; i++) {
            if (!(cin >> student_response[i])) {
                end = false;
                break;
            }
        }
        if (!end) break;

        vector<int> transformed;
        for (int i = 0; i < n; i++) {
            transformed.push_back(position[student_response[i]]);
        }
        
        cout << LIS(transformed) << endl;
    }
    return 0;
}
