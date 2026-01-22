/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> histogram(10, 0);
    double value;
    int ignored = 0;

    for (int i = 0; i < n; ++i) {
        cin >> value;
        if (value < 0.0 || value > 10.0) {
            ignored++;
        } else if (value == 10.0) {
            histogram[9]++;
        } else {
            int index = static_cast<int>(value) + (value < 1.0 ? 0 : 1);
            histogram[index]++;
        }
    }
    
    int max_freq = *max_element(histogram.begin(), histogram.end());
    for (int i = 20; i >= 0; --i) {
        cout << setw(5) << i * max_freq / 20 << " +";
        for (int j = 0; j < 10; ++j) {
            cout << (histogram[j] * 20 / max_freq >= i ? '*' : ' ');
            cout << '|';
        }
        cout << endl;
    }
    
    cout << setw(5) << 0 << " +";
    for (int j = 0; j < 10; ++j) {
        cout << '--' << '+';
    }
    cout << endl << "    0.0      5.0      10.0" << endl;
    cout << "Valores ignorados: " << ignored << endl;

    return 0;
}
