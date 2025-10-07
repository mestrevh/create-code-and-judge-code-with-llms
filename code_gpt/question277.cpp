/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    int N;
    cin >> N;

    if (N <= 0 || N >= 10) return -1;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        if (arr[i] < 0) {
            cout << "-1\n";
            return 0;
        }
    }

    set<pair<int, tuple<int, int, int>>> uniqueSums;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
                int sum = arr[i] + arr[j] + arr[k];
                uniqueSums.insert({sum, {arr[i], arr[j], arr[k]}});
            }
        }
    }

    map<int, int> sumCount;
    for (const auto& elem : uniqueSums) {
        int sum = elem.first;
        sumCount[sum]++;
    }

    vector<string> results;
    for (const auto& elem : uniqueSums) {
        int sum = elem.first;
        auto indices = elem.second;
        if (sumCount[sum] == 1) {
            results.push_back("{" + to_string(get<0>(indices)) + "," + to_string(get<1>(indices)) + "," + to_string(get<2>(indices)) + "} = " + to_string(sum));
        }
    }

    sort(results.begin(), results.end());

    for (const auto& result : results) {
        cout << result << endl;
    }

    return 0;
}
