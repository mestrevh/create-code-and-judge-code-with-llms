/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int X, Y;
    while (cin >> X >> Y) {
        if (X == 0) break;
        
        vector<int> distances;
        int d;
        while (cin >> d && d != 0) {
            distances.push_back(d);
        }

        int left = lower_bound(distances.begin(), distances.end(), Y) - distances.begin();
        int right = upper_bound(distances.begin(), distances.end(), X) - distances.begin() - 1;

        if (left <= right) {
            cout << left + 1 << " " << right + 1 << endl;
        } else {
            cout << "0 0" << endl;
        }
    }
    return 0;
}
