/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int max_product = nums[0] * nums[1];
    for (int i = 1; i < n - 1; ++i) {
        int product = nums[i] * nums[i + 1];
        if (product > max_product) {
            max_product = product;
        }
    }

    cout << max_product << endl;
    return 0;
}
