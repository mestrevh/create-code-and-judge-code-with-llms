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

    while (N--) {
        double X;
        if (!(cin >> X)) break;
        
        int days = 0;
        while (X > 1.0) {
            X /= 2.0;
            days++;
        }
        
        cout << days << " dias\n";
    }

    return 0;
}