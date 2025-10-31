/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main() {
    map<int, double> prices = {
        {1001, 1.50},
        {1002```cpp
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main() {
    map<int, double> prices = {
        {1001, 1.50},
        {1002, 2.50},
        {1003, 3.50},
        {1004, 4.50},
        {1005, 5.50}
    };
    
    int N;
    cin >> N;
    double total = 0.0;

    for (int i = 0; i < N; ++i) {
        int code, quantity;
        cin >> code >> quantity;
        total += prices[code] * quantity;
    }

    cout << fixed << setprecision(2) << total << endl;
    return 0;
}
