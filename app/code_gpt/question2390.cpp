/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

bool canTravel(double fuel, int m, vector<int>& a, vector<int>& b) {
    double total_fuel = fuel;
    double weight = m + fuel;
    
    for (int i = 0; i < a.size(); i++) {
        double takeoff = weight / a[i];
        if (takeoff > total_fuel) return false;
        total_fuel -= takeoff;
        weight -= takeoff; // weight after takeoff
        
        double landing = weight / b[i];
        total_fuel -= landing; // weight after landing
        weight += landing; // weight after landing
    }
    
    return total_fuel >= 0;
}

double binarySearch(int m, vector<int>& a, vector<int>& b) {
    double low = 0.0, high = 1e9, result = -1;

    while (high - low > 1e-9) {
        double mid = (low + high) / 2.0;
        if (canTravel(mid, m, a, b)) {
            result = mid;
            high = mid;             
        } else {
            low = mid;
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    double fuel = binarySearch(m, a, b);

    if (fuel == -1) {
        cout << -1 << endl;
    } else {
        cout << fixed << setprecision(2) << fuel << endl;
    }

    return 0;
}
