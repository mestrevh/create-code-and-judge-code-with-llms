/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h1, m1, h2, m2;
    while (cin >> h1 >> m1 >> h2 >> m2 && (h1 != 0 || m1 != 0 || h2 != 0 || m2 != 0)) {
        int startTime = h1 * 60 + m1;
        int alarmTime = h2 * 60 + m2;
        
        int diff = alarmTime - startTime;
        if (diff <= 0) {
            diff += 1440;
        }
        
        cout << diff << "\n";
    }

    return 0;
}