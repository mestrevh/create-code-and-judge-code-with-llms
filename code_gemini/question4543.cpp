/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string comparators;
    cin >> comparators;

    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    vector<int> result(nums.size());
    int left = 0;
    int right = nums.size() - 1;

    for (int i = 0; i < nums.size(); ++i) {
        if (i % 2 == 0) {
            result[i] = nums[left++];
        } else {
            result[i] = nums[right--];
        }
    }
    
    for (int i = 0; i < nums.size(); ++i) {
        cout << result[i];
        if (i < comparators.length()) {
            cout << " " << comparators[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
