/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, m, add_m;
    char colon;

    if (cin >> h >> colon >> m >> add_m) {
        int total_minutes = h * 60 + m + add_m;
        
        int final_h = (total_minutes / 60) % 24;
        int final_m = total_minutes % 60;

        if (final_h < 0) final_h += 24;

        cout << setfill('0') << setw(2) << final_h << ":"
             << setfill('0') << setw(2) << final_m << endl;
    }

    return 0;
}