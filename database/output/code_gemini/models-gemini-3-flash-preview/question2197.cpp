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

    vector<char> message(N + 1);
    for (int i = 0; i < N; ++i) {
        int pos;
        char c;
        cin >> pos >> c;
        if (pos >= 1 && pos <= N) {
            message[pos] = c;
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << message[i];
    }
    cout << endl;

    return 0;
}