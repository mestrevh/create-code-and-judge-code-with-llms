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

    long long n;
    if (!(cin >> n)) return 0;

    long long groups_of_three = n / 3;
    long long remainder = n % 3;
    long long paid_units = (groups_of_three * 2) + remainder;
    
    double total_cost = (double)paid_units * 2.20;

    cout << fixed << setprecision(2) << total_cost << endl;

    return 0;
}