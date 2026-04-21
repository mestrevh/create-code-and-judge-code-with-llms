/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        long long dx = x2 - x1;
        long long dy = y2 - y1;
        
        bool aligned = true;
        for (int i = 2; i < n; ++i) {
            long long xi, yi;
            cin >> xi >> yi;
            if (aligned) {
                if (dy * (xi - x1) != (yi - y1) * dx) {
                    aligned = false;
                }
            }
        }
        
        if (aligned) {
            cout << "ALINHADOS\n";
        } else {
            cout << "NAO_ALINHADOS\n";
        }
    }

    return 0;
}