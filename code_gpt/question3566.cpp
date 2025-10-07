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
    vector<int> numbers(n);
    
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            cout << i << endl;
            int step = n / i;
            for (int j = 0; j < step; j++) {
                for (int k = 0; k < i / 2; k++) {
                    cout << numbers[j * step + k] << " - " 
                         << numbers[j * step + (i - 1 - k)] << endl;
                }
            }
        }
    }
    
    return 0;
}
