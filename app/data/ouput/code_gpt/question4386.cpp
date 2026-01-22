/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> M(K);
    for(int i = 0; i < K; i++) {
        cin >> M[i];
    }

    int low = 1, high = *max_element(M.begin(), M.end()), best = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int count = 0;

        for (int size : M) {
            count += size / mid;
        }

        if (count >= N) {
            best = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << best << endl;
    return 0;
}
