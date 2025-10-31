/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> seq(n);
    for (int i = 0; i < n; ++i) cin >> seq[i];

    int count = 0, idx = 0;
    int pattern[3] = {1, 2, 1};
    for (int i = 0; i < n; ++i) {
        if (seq[i] == pattern[idx]) {
            ++count;
            idx = (idx + 1) % 3;
        }
    }
    cout << count << endl;
    return 0;
}
