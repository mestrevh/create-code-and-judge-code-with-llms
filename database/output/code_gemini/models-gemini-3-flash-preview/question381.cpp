/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double weight;
    double current_sum = 0.0;
    int book_count = 0;
    const double capacity = 18.0;

    while (cin >> weight) {
        if (current_sum + weight <= capacity) {
            current_sum += weight;
            book_count++;
        } else {
            break;
        }
    }

    cout << book_count << "\n";

    return 0;
}