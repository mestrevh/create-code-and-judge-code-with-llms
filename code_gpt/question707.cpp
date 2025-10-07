/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, X;
        cin >> N >> X;

        vector<int> presents(N);
        for (int i = 0; i < N; ++i) {
            cin >> presents[i];
        }

        bool found = false;
        for (int start = 0; start < N; ++start) {
            int sum = 0;
            for (int end = start; end < N; ++end) {
                sum += presents[end];
                if (sum == X) {
                    found = true;
                    break;
                }
                if (sum > X) break;
            }
            if (found) break;
        }

        cout << (found ? "YES" : "NO") << endl;
    }

    return 0;
}
