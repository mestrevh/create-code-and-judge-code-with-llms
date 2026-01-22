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
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        
        int maxLength = 0, startIdx = 0;
        for (int i = 0; i < N; i++) {
            int length = 1;
            for (int j = i + 1; j < N; j++) {
                if (arr[j] < arr[j - 1]) {
                    length++;
                } else {
                    break;
                }
            }
            if (length > maxLength) {
                maxLength = length;
                startIdx = i;
            }
            i += length - 1;
        }

        if (maxLength > 0) {
            cout << maxLength << endl;
            for (int i = 0; i < maxLength; i++) {
                cout << arr[startIdx + i] << (i < maxLength - 1 ? " " : "");
            }
            cout << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
