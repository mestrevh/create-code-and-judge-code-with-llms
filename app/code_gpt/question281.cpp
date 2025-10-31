/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countSwaps(vector<int>& arr) {
    int swaps = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        while (arr[i] != i + 1) {
            swap(arr[i], arr[arr[i] - 1]);
            swaps++;
        }
    }
    return swaps;
}

int main() {
    int L;
    while (cin >> L) {
        vector<int> train(L);
        for (int i = 0; i < L; i++) {
            cin >> train[i];
        }
        int steps = countSwaps(train);
        cout << "A melhor troca leva " << steps << " passos" << endl;
    }
    return 0;
}
