/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countOnes(int num) {
    return __builtin_popcount(num);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> numbers(N);
        for (int i = 0; i < N; i++) {
            cin >> numbers[i];
        }
        vector<int> points(N);
        for (int i = 0; i < N; i++) {
            points[i] = countOnes(numbers[i]);
        }
        sort(points.rbegin(), points.rend());
        int maxPoints = 0;
        for (int i = 0; i < K; i++) {
            maxPoints += points[i];
        }
        cout << maxPoints << endl;
    }
    return 0;
}
