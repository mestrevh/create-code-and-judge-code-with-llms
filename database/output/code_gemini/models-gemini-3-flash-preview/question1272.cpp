/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        const char* arr[] = {
            "0",
            "10",
            "25",
            "39",
            "77",
            "679",
            "6788",
            "68889",
            "2677889",
            "26888999"
        };

        for (int i = 0; i <= n; ++i) {
            if (i >= 0 && i <= 9) {
                cout << "O menor número com persistência " << i << " é " << arr[i] << "." << "\n";
            }
        }
    }

    return 0;
}