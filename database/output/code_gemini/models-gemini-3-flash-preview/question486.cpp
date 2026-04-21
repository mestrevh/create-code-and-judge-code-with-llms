/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int max1 = numeric_limits<int>::min();
    int max2 = numeric_limits<int>::min();
    bool first = true;

    while (cin >> n && n != 99) {
        if (first) {
            max1 = n;
            first = false;
        } else {
            if (n >= max1) {
                max2 = max1;
                max1 = n;
            } else if (n > max2) {
                max2 = n;
            }
        }
    }

    cout << max2 << endl;

    return 0;
}