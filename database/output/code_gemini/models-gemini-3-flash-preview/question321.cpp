/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    double total_v = 0;
    long long total_kg = 0;

    for (int i = 1; i <= n; ++i) {
        double v;
        if (!(cin >> v)) break;
        
        // Clear buffer before getline
        string dummy;
        getline(cin, dummy);
        
        string line;
        if (!getline(cin, line)) break;

        int count = 0;
        stringstream ss(line);
        string fruit;
        while (ss >> fruit) {
            count++;
        }

        total_v += v;
        total_kg += count;

        cout << "dia " << i << ": " << count << " kg\n";
    }

    cout << fixed << setprecision(2);
    double avg_kg = static_cast<double>(total_kg) / n;
    double avg_v = total_v / n;

    cout << avg_kg << " kg por dia\n";
    cout << "R$ " << avg_v << " por dia\n";

    return 0;
}