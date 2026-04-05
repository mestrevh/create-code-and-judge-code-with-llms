/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b, c;
    if (cin >> a >> b >> c) {
        double average = (a + b + c) / 3.0;
        int count = 0;
        if (a > average) count++;
        if (b > average) count++;
        if (c > average) count++;
        cout << count << endl;
    }

    return 0;
}