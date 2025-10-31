/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long countInversions(vector<int>& arr) {
    int n = arr.size();
    long long inv_count = 0;
    vector<int> temp(n);
    
    function<void(int, int)> mergeAndCount = [&](int left, int mid, int right) {
        int i = left, j = mid, k = left;
        while (i <= mid - 1 && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                inv_count += (mid - i);
            }
        }
        while (i <= mid - 1) temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];
        for (i = left; i <= right; i++) arr[i] = temp[i];
    };

    function<void(int, int)> mergeSortAndCount = [&](int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSortAndCount(left, mid);
            mergeSortAndCount(mid + 1, right);
            mergeAndCount(left, mid + 1, right);
        }
    };

    mergeSortAndCount(0, n - 1);
    return inv_count;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> V(N);
    for (int i = 0; i < N; i++)
        cin >> V[i];

    long long I = countInversions(V);
    vector<int> new_positions(M, -1);
    vector<int> results(N);

    for (int i = 0; i < N; i++) {
        int j = 0;
        int pos;
        do {
            pos = (V[i] + j * I) % M;
            j++;
        } while (new_positions[pos] != -1);

        new_positions[pos] = V[i];
        results[i] = pos;
    }

    for (int i = 0; i < N; i++)
        cout << results[i] << endl;

    return 0;
}
