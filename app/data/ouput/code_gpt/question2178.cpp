/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> v(n);
    
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }
    
    double mean = sum / n;
    double variance = 0.0;
    
    for (int i = 0; i < n; ++i) {
        variance += pow(v[i] - mean, 2);
    }
    
    variance /= n;
    double stddev = sqrt(variance);
    
    cout << fixed << setprecision(2) << stddev << endl;
    
    return 0;
}
