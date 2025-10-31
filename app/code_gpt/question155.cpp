/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canCut(const vector<int>& sizes, int sliceSize, int people) {
    int count = 0;
    for (int size : sizes) {
        count += size / sliceSize;
        if (count >= people) return true;
    }
    return count >= people;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> sizes(K);
    for (int i = 0; i < K; ++i) {
        cin >> sizes[i];
    }
    
    int left = 1, right = *max_element(sizes.begin(), sizes.end());
    int maxSliceSize = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canCut(sizes, mid, N)) {
            maxSliceSize = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << maxSliceSize << endl;
    return 0;
}
