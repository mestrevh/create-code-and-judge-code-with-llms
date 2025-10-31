/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums(101);
    for (int i = 0; i < 101; ++i) {
        cin >> nums[i];
    }
    int target = nums[100];
    for (int i = 0; i < 100; ++i) {
        if (nums[i] == target) {
            cout << i << endl;
        }
    }
    return 0;
}
