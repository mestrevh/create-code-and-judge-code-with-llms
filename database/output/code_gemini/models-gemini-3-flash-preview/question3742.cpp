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

    float fahrenheit;
    if (!(cin >> fahrenheit)) return 0;

    float celsius = (fahrenheit - 32.0f) * 5.0f / 9.0f;

    cout << fixed << setprecision(10) << celsius << endl;

    return 0;
}