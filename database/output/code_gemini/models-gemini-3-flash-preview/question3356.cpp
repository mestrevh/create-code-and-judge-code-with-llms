/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d, m, y;
    if (!(cin >> d >> m >> y)) return 0;

    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool valid = true;
    if (m < 1 || m > 12) {
        valid = false;
    } else if (d < 1 || d > days_in_month[m]) {
        valid = false;
    }

    if (!valid) {
        cout << "Data invalida" << endl;
    } else {
        d++;
        if (d > days_in_month[m]) {
            d = 1;
            m++;
            if (m > 12) {
                m = 1;
                y++;
            }
        }
        cout << d << "." << m << "." << y << endl;
    }

    return 0;
}
