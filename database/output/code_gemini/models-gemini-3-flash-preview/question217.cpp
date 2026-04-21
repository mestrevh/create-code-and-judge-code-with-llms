/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    if (N <= 0) {
        cout << 0 << "\n";
        return 0;
    }

    long long last_v, v;
    cin >> last_v;
    
    int max_c = 1;
    int cur_c = 1;

    for (int i = 1; i < N; ++i) {
        if (!(cin >> v)) break;
        if (v == last_v) {
            cur_c++;
        } else {
            cur_c = 1;
            last_v = v;
        }
        if (cur_c > max_c) {
            max_c = cur_c;
        }
    }

    cout << max_c << "\n";

    return 0;
}