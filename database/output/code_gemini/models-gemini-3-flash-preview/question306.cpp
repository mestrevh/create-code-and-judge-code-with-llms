/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int total_days;
    if (!(cin >> total_days)) return 0;

    int years = total_days / 365;
    int remaining_days = total_days % 365;
    int months = remaining_days / 30;
    int days = remaining_days % 30;

    cout << years << " ano(s)\n";
    cout << months << " mes(es)\n";
    cout << days << " dia(s)\n";

    return 0;
}