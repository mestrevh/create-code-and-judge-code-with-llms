/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> houses(N);
    for (int i = 0; i < N; ++i) {
        cin >> houses[i];
    }

    int K;
    cin >> K;

    int left = 0;
    int right = N - 1;

    while (left < right) {
        long long current_sum = (long long)houses[left] + houses[right];
        if (current_sum == K) {
            cout << houses[left] << " " << houses[right] << "\n";
            break;
        } else if (current_sum < K) {
            left++;
        } else {
            right--;
        }
    }

    return 0;
}