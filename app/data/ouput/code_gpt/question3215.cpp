/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool canDistribute(const vector<int>& times, int maxTime, int numMembers) {
    int currentSum = 0, requiredMembers = 1;
    for (int time : times) {
        if (currentSum + time > maxTime) {
            requiredMembers++;
            currentSum = time;
            if (requiredMembers > numMembers) return false;
        } else {
            currentSum += time;
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> times(M);
    for (int i = 0; i < M; ++i) {
        cin >> times[i];
    }

    int left = *max_element(times.begin(), times.end());
    int right = accumulate(times.begin(), times.end(), 0);
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canDistribute(times, mid, N)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}
