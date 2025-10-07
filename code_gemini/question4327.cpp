/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x, y;
    while (cin >> x >> y) {
        if (x == 0 && y == 0) break;

        vector<int> distances;
        int distance;
        while (cin >> distance && distance != 0) {
            distances.push_back(distance);
        }

        int start = -1;
        int end = -1;

        for (int i = 0; i < distances.size(); ++i) {
            if (distances[i] >= y && distances[i] <= x) {
                if (start == -1) {
                    start = i + 1;
                }
                end = i + 1;
            }
        }

        if (start != -1) {
            cout << start << " " << end << endl;
        } else {
            cout << endl;
        }
    }
    return 0;
}
