/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    double m;
    if (!(cin >> n >> m)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> ks;
    // Trip: 1 -> 2 -> 3 -> ... -> n -> 1
    // Each hop x -> y consists of: takeoff from x (a_x) and landing on y (b_y)
    // Hop 1 -> 2: takeoff 1 (a[0]), land 2 (b[1])
    // Hop 2 -> 3: takeoff 2 (a[1]), land 3 (b[2])
    // ...
    // Hop n-1 -> n: takeoff n-1 (a[n-2]), land n (b[n-1])
    // Hop n -> 1: takeoff n (a[n-1]), land 1 (b[0])

    ks.push_back(a[0]);
    for (int i = 1; i < n; ++i) {
        ks.push_back(b[i]);
        ks.push_back(a[i]);
    }
    ks.push_back(b[0]);

    double prod = 1.0;
    for (int k : ks) {
        if (k <= 1) {
            cout << -1 << endl;
            return 0;
        }
        // Formula: W_after = W_before * (1 - 1/k)
        // P = product of all (k-1)/k
        prod *= (double)(k - 1) / k;
    }

    // Rocket mass m = (initial mass W0) * prod
    // m = (m + fuel) * prod
    // fuel = m / prod - m
    double fuel = m / prod - m;

    cout << fixed << setprecision(2) << fuel << endl;

    return 0;
}