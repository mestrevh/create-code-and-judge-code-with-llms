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
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        int maxLength = 1, start = 0, bestStart = 0, bestEnd = 0;
        for (int i = 1; i < N; i++) {
            int currentLength = 2;
            while (i < N && A[i] - A[i - 1] == A[start + 1] - A[start]) {
                currentLength++;
                i++;
            }
            if (currentLength > maxLength) {
                maxLength = currentLength;
                bestStart = start;
                bestEnd = start + currentLength - 1;
            }
            start = i - 1;
        }
        cout << bestStart + 1 << " " << bestEnd + 1 << endl;  // Output using 1-based index
    }
    return 0;
}
