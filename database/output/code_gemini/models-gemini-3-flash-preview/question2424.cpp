/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    double x;

    if (!(cin >> n >> x)) return 0;

    if (n == 0) {
        cout << "Vamos pro posto Ipiranga ja!" << endl;
        return 0;
    }

    double total_dist = 0;
    for (int i = 0; i < 4; ++i) {
        string s;
        double d;
        if (cin >> s >> d) {
            total_dist += d;
        }
    }

    double fuel_range = (double)n * x;

    if (fuel_range >= total_dist) {
        cout << "Tokyo e demais, temos que vir de novo!" << endl;
    } else {
        cout << "Vamos de metro mesmo!" << endl;
    }

    return 0;
}