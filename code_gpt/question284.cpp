/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long findMinQ(int N) {
    if (N < 10) return -1;
    
    vector<int> digits;
    
    for (int i = 9; i > 1; --i) {
        while (N % i == 0) {
            digits.push_back(i);
            N /= i;
        }
    }
    
    if (N > 1) return -1;
    
    sort(digits.begin(), digits.end());
    
    long long result = 0;
    for (int i = 0; i < digits.size(); ++i) {
        result = result * 10 + digits[i];
    }
    
    return result;
}

int main() {
    int N;
    cin >> N;
    
    cout << findMinQ(N) << endl;
    
    return 0;
}
