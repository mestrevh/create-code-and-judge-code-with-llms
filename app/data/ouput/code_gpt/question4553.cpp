/*
Código criado pelo GPT 4o-mini
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
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // Média
    double sum = 0;
    for (int x : nums) {
        sum += x;
    }
    double media = sum / n;
    
    // Mediana
    sort(nums.begin(), nums.end());
    double mediana;
    if (n % 2 == 0) {
        mediana = (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    } else {
        mediana = nums[n / 2];
    }
    
    // Moda
    map<int, int> freq;
    for (int x : nums) {
        freq[x]++;
    }
    
    int moda = nums[0];
    int maxFreq = freq[moda];
    
    for (auto& p : freq) {
        if (p.second > maxFreq || (p.second == maxFreq && p.first > moda)) {
            moda = p.first;
            maxFreq = p.second;
        }
    }
    
    cout << fixed << setprecision(2) << media << " " << mediana << " " << moda << endl;
    return 0;
}
