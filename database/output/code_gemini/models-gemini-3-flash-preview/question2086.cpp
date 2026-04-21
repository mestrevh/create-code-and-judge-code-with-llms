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

    int arr[1000];
    int first;

    while (cin >> first && first != -1) {
        arr[0] = first;
        for (int i = 1; i < 1000; ++i) {
            cin >> arr[i];
        }

        int n;
        cin >> n;

        int k = 0;
        for (int i = 0; i < 1000; ++i) {
            if (arr[i] == n) {
                k++;
            }
        }

        cout << n << " appeared " << k << " times" << "\n";
    }

    return 0;
}