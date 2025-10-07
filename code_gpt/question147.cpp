/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N;
    vector<int> casas(N);
    
    for (int i = 0; i < N; i++) {
        cin >> casas[i];
    }
    cin >> K;
    
    int left = 0, right = N - 1;
    
    while (left < right) {
        int sum = casas[left] + casas[right];
        if (sum == K) {
            cout << casas[left] << " " << casas[right] << endl;
            return 0;
        } else if (sum < K) {
            left++;
        } else {
            right--;
        }
    }
    
    return 0;
}
