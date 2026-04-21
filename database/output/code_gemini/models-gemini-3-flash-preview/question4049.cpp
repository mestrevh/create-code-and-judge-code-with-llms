/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;

struct Establishment {
    string name;
    long double x, y;
    string flavor;
    double price;
    bool visited;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double curX, curY;
    if (!(cin >> curX >> curY)) return 0;

    int n;
    if (!(cin >> n)) return 0;

    vector<Establishment> ests(n);
    for (int i = 0; i < n; ++i) {
        cin >> ests[i].name >> ests[i].x >> ests[i].y >> ests[i].flavor >> ests[i].price;
        ests[i].visited = false;
    }

    int k;
    if (!(cin >> k)) k = 0;
    vector<string> wishlist(k);
    for (int i = 0; i < k; ++i) {
        cin >> wishlist[i];
    }

    set<string> tasted;
    for (int i = 0; i < n; ++i) {
        int bestIdx = -1;
        long double minDistSq = 0;
        double minPrice = 0;

        for (int j = 0; j < n; ++j) {
            if (ests[j].visited) continue;

            long double dx = ests[j].x - curX;
            long double dy = ests[j].y - curY;
            long double d2 = dx * dx + dy * dy;

            if (bestIdx == -1 || d2 < minDistSq - 1e-11L) {
                minDistSq = d2;
                minPrice = ests[j].price;
                bestIdx = j;
            } else if (fabsl(d2 - minDistSq) < 1e-11L) {
                if (ests[j].price < minPrice) {
                    minPrice = ests[j].price;
                    bestIdx = j;
                }
            }
        }

        if (bestIdx != -1) {
            ests[bestIdx].visited = true;
            cout << ests[bestIdx].name << "\n";
            tasted.insert(ests[bestIdx].flavor);
            curX = ests[bestIdx].x;
            curY = ests[bestIdx].y;
        }
    }

    bool ok = true;
    for (int i = 0; i < k; i++) {
        if (tasted.find(wishlist[i]) == tasted.end()) {
            ok = false;
            break;
        }
    }

    if (ok) {
        cout << "Completou a lista" << endl;
    } else {
        cout << "Vou fazer as que faltaram quando chegar em casa" << endl;
    }

    return 0;
}