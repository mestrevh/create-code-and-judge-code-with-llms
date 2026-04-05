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

    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 0) {
            arr[i] = 1;
        } else {
            arr[i] = -1;
        }
        sum += arr[i];
    }

    cout << sum << endl;

    return 0;
}