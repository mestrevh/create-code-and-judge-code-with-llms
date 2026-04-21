/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> temp;

void merge(vector<int>& arr, int l, int mid, int r) {
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (arr[i] >= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    for (int m = l; m <= r; ++m) {
        arr[m] = temp[m];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x0, a, c, m;
    while (cin >> n >> x0 >> a >> c >> m) {
        if (n <= 0) {
            cout << "\n";
            continue;
        }

        vector<int> arr(n);
        temp.assign(n, 0);
        arr[0] = (int)x0;
        for (int j = 1; j < n; j++) {
            arr[j] = (int)((a * arr[j - 1] + c) % m);
        }

        vector<pair<int, int>> segments;
        for (int i = 0; i < n; i++) {
            segments.push_back({i, i});
        }

        while (segments.size() > 1) {
            vector<pair<int, int>> next_segments;
            for (int i = (int)segments.size() - 1; i >= 0; ) {
                if (i >= 1) {
                    merge(arr, segments[i - 1].first, segments[i - 1].second, segments[i].second);
                    next_segments.push_back({segments[i - 1].first, segments[i].second});
                    i -= 2;
                } else {
                    next_segments.push_back(segments[i]);
                    i -= 1;
                }
            }
            reverse(next_segments.begin(), next_segments.end());
            segments = next_segments;

            for (const auto& seg : segments) {
                cout << "| ";
                for (int j = seg.first; j <= seg.second; j++) {
                    cout << arr[j] << " ";
                }
            }
            cout << "| \n";
        }
        cout << "\n";
    }

    return 0;
}

