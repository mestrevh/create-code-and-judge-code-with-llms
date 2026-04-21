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

    long long sum = 0;
    int count = 0;
    int val;

    while (cin >> val) {
        sum += val;
        count++;
    }

    if (count > 0) {
        double average = static_cast<double>(sum) / count;
        cout << "Media = " << fixed << setprecision(1) << average << endl;
    }

    return 0;
}