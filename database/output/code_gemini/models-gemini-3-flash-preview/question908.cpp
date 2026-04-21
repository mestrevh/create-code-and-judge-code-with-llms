/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[20];
    for (int i = 0; i < 20; ++i) {
        arr[i] = i * i;
    }

    for (int i = 0; i < 20; ++i) {
        cout << arr[i] << "\n";
    }

    return 0;
}