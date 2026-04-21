/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    if (!(cin >> n >> c)) return 0;

    int current_occupancy = 0;
    bool exceeded = false;

    for (int i = 0; i < n; ++i) {
        int s, e;
        cin >> s >> e;
        
        current_occupancy -= s;
        current_occupancy += e;

        if (current_occupancy > c) {
            exceeded = true;
        }
    }

    if (exceeded) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}