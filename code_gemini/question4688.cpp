/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int target;
    cin >> target;

    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
    }

    int left = 0;
    int right = nums.size() - 1;
    int operations = 0;
    int index = -1;

    while (left <= right) {
        operations++;
        int mid = floor((left + right) / 2);
        if (nums[mid] == target) {
            index = mid;
            break;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << index << endl;
    cout << operations << endl;

    return 0;
}
