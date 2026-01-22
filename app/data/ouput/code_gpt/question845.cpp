/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long wood_needed(const vector<int>& heights, int cut_height) {
    long long total = 0;
    for (int height : heights) {
        if (height > cut_height) {
            total += height - cut_height;
        }
    }
    return total;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    sort(heights.begin(), heights.end());

    int low = 0, high = n - 1, answer = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        long long wood = wood_needed(heights, heights[mid]);
        if (wood >= m) {
            answer = heights[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer << endl;
    return 0;
}
