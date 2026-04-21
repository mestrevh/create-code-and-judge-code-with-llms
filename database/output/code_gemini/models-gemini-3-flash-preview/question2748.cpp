/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int fd, bd, md;
    int fr, br, mr;

    if (!(cin >> fd >> bd >> md)) return 0;
    if (!(cin >> fr >> br >> mr)) return 0;

    int total_missed = 0;

    if (fr > fd) {
        total_missed += (fr - fd);
    }
    if (br > bd) {
        total_missed += (br - bd);
    }
    if (mr > md) {
        total_missed += (mr - md);
    }

    cout << total_missed << endl;

    return 0;
}
