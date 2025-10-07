/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    double sum = 0;
    for (int num : nums) {
        sum += num;
    }
    double mean = sum / n;

    sort(nums.begin(), nums.end());
    double median;
    if (n % 2 == 0) {
        median = (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    } else {
        median = nums[n / 2];
    }

    map<int, int> counts;
    for (int num : nums) {
        counts[num]++;
    }

    int mode = nums[0];
    int maxCount = 0;
    for (auto const& [num, count] : counts) {
        if (count > maxCount) {
            maxCount = count;
            mode = num;
        } else if (count == maxCount && num > mode) {
            mode = num;
        }
    }

    cout << fixed << setprecision(2) << mean << " " << median << " " << mode << endl;

    return 0;
}
