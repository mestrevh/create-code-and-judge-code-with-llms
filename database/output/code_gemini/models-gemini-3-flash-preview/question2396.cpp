/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s, t, f;
    if (cin >> s >> t >> f) {
        int arrival = (s + t + f) % 24;
        if (arrival < 0) {
            arrival += 24;
        }
        cout << arrival << "\n";
    }

    return 0;
}