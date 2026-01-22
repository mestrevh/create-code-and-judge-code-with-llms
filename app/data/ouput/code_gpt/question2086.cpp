/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    while (true) {
        vector<int> nums(1000);
        int first;
        cin >> first;
        if (first == -1) break;
        
        nums[0] = first;
        for (int i = 1; i < 1000; ++i) {
            cin >> nums[i];
        }
        
        int N;
        cin >> N;
        
        int count = 0;
        for (int num : nums) {
            if (num == N) count++;
        }
        
        cout << N << " appeared " << count << " times" << endl;
    }
    return 0;
}
