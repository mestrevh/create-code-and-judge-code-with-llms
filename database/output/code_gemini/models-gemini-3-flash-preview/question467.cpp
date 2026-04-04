/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 0;
    double total_weight = 0.0;
    double weight;

    while (cin >> weight && weight != 0.0) {
        if (count < 7 && (total_weight + weight) <= 560.0) {
            count++;
            total_weight += weight;
            if (count == 7 || total_weight >= 560.0) {
                break;
            }
        } else {
            break;
        }
    }

    cout << count << "\n";
    cout << fixed << setprecision(1) << total_weight << endl;

    return 0;
}