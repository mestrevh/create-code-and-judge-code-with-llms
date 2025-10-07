/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int countOnes = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) countOnes++;
    }

    int maxOnes = countOnes;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int flipCount = 0;
            for (int k = i; k <= j; k++) {
                if (a[k] == 1) flipCount--;
                else flipCount++;
            }
            maxOnes = max(maxOnes, countOnes + flipCount);
        }
    }

    cout << maxOnes << endl;
    return 0;
}
