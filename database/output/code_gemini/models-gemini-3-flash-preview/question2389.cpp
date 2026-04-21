/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    int counts[101] = {0};
    for (int i = 0; i < m; ++i) {
        int food_type;
        cin >> food_type;
        if (food_type >= 1 && food_type <= 100) {
            counts[food_type]++;
        }
    }

    int low = 1, high = 100, result = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid == 0) {
            low = 1;
            continue;
        }
        
        int total_people_supported = 0;
        for (int i = 1; i <= 100; ++i) {
            total_people_supported += counts[i] / mid;
        }

        if (total_people_supported >= n) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}