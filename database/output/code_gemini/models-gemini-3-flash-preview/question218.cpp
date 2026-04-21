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

    int m[3];
    if (!(cin >> m[0] >> m[1] >> m[2])) return 0;
    
    int h, l;
    if (!(cin >> h >> l)) return 0;

    sort(m, m + 3);

    int d_min = h;
    int d_max = l;
    if (d_min > d_max) {
        swap(d_min, d_max);
    }

    if (m[0] <= d_min && m[1] <= d_max) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}