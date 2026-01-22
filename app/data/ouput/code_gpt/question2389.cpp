/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    unordered_map<int, int> food_count;

    for (int i = 0; i < M; i++) {
        cin >> A[i];
        food_count[A[i]]++;
    }

    int left = 1, right = M / N, max_days = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int total = 0;
        for (const auto& pair : food_count) {
            total += pair.second / mid;
        }
        if (total >= N) {
            max_days = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << max_days << endl;
    return 0;
}
