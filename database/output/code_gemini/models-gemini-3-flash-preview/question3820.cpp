/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    map<char, long long> category_totals;
    long long grand_total = 0;

    for (int i = 0; i < n; ++i) {
        char category;
        long long value;
        if (!(cin >> category >> value)) break;
        category_totals[category] += value;
        grand_total += value;
    }

    for (auto const& [category, total] : category_totals) {
        cout << category << " " << total << "\n";
    }

    cout << "TOTAL " << grand_total << endl;

    return 0;
}