/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void OrdenaMatriz(int *maior, int *segundo, int *terceiro, int *menor, int *matriz) {
    if (!maior || !segundo || !terceiro || !menor || !matriz) return;
    matriz[0] = *menor;
    matriz[1] = *segundo;
    matriz[2] = *terceiro;
    matriz[3] = *maior;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums;
    int val;
    for (int i = 0; i < 25; ++i) {
        if (cin >> val) {
            if (val != 0) {
                if (nums.size() < 4) {
                    nums.push_back(val < 0 ? -val : val);
                }
            }
        }
    }

    while (nums.size() < 4) {
        nums.push_back(0);
    }

    sort(nums.begin(), nums.end());

    int res[4];
    // nums[0] is Smallest (menor)
    // nums[1] is Second Smallest (terceiro)
    // nums[2] is Second Largest (segundo)
    // nums[3] is Largest (maior)
    
    OrdenaMatriz(&nums[3], &nums[2], &nums[1], &nums[0], res);

    cout << res[0] << " " << res[1] << "\n";
    cout << res[2] << " " << res[3] << "\n";

    return 0;
}