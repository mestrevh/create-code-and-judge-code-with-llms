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

    const int YEARS = 20;
    const int MONTHS = 12;
    const int START_YEAR = 2000;
    
    vector<int> production(YEARS * MONTHS);

    for (int i = 0; i < YEARS * MONTHS; ++i) {
        if (!(cin >> production[i])) break;
    }

    int m_start, y_start;
    int m_end, y_end;

    cin >> m_start >> y_start;
    cin >> m_end >> y_end;

    int start_index = (y_start - START_YEAR) * MONTHS + (m_start - 1);
    int end_index = (y_end - START_YEAR) * MONTHS + (m_end - 1);

    long long total_production = 0;
    if (start_index >= 0 && end_index < (YEARS * MONTHS)) {
        for (int i = start_index; i <= end_index; ++i) {
            total_production += production[i];
        }
    }

    cout << total_production << endl;

    return 0;
}
