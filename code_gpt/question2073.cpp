/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long p1, p2, p3, l, r;
    cin >> p1 >> p2 >> p3 >> l >> r;

    vector<long long> nums;
    for (int i = 0; p1 * i <= r; i++) {
        for (int j = 0; p2 * j + p1 * i <= r; j++) {
            for (int k = 0; p3 * k + p2 * j + p1 * i <= r; k++) {
                long long x = p1 * i * p2 * j * p3 * k;
                if (x >= l) {
                    nums.push_back(x);
                }
            }
        }
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int count = 0;
    long long min_x = -1, max_x = -1;

    for (long long number : nums) {
        if (number >= l && number <= r) {
            count++;
            if (min_x == -1) min_x = number;
            max_x = number;
        }
    }

    cout << count << " " << min_x << " " << max_x << endl;

    return 0;
}
