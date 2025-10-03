/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    vector<int> left_max(N), right_max(N);
    left_max[0] = H[0];
    for (int i = 1; i < N; i++)
        left_max[i] = max(left_max[i-1], H[i]);
    right_max[N-1] = H[N-1];
    for (int i = N-2; i >= 0; i--)
        right_max[i] = max(right_max[i+1], H[i]);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int water = min(left_max[i], right_max[i]) - H[i];
        if (water >= 1)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
