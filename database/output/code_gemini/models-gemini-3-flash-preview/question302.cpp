/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, y, z;
    if (cin >> x >> y >> z) {
        long long relative_speed = y - x;
        if (relative_speed > 0) {
            long long time_minutes = (z * 60) / relative_speed;
            cout << time_minutes << " minutos" << endl;
        }
    }

    return 0;
}