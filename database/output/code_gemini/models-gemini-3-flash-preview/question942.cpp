/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Loop 1: Reading the input values as required by the rule of separate loops.
    vector<double> sales(n);
    for (int i = 0; i < n; ++i) {
        cin >> sales[i];
    }

    // Loop 2: Calculating worked days and total sum.
    int workedDays = 0;
    double totalSum = 0;
    for (int i = 0; i < n; ++i) {
        totalSum += sales[i];
        if (sales[i] > 0.0) {
            workedDays++;
        }
    }

    // Loop 3: Calculating maximum and minimum revenue values (excluding non-working days).
    double maxRevenue = -1.0;
    double minRevenue = -1.0;
    bool foundWorkedDay = false;
    for (int i = 0; i < n; ++i) {
        if (sales[i] > 0.0) {
            if (!foundWorkedDay) {
                maxRevenue = sales[i];
                minRevenue = sales[i];
                foundWorkedDay = true;
            } else {
                if (sales[i] > maxRevenue) maxRevenue = sales[i];
                if (sales[i] < minRevenue) minRevenue = sales[i];
            }
        }
    }

    // Loop 4: Identifying the specific days for max and min revenues.
    vector<int> maxDays;
    vector<int> minDays;
    for (int i = 0; i < n; ++i) {
        if (sales[i] > 0.0) {
            if (sales[i] == maxRevenue) {
                maxDays.push_back(i + 1);
            }
            if (sales[i] == minRevenue) {
                minDays.push_back(i + 1);
            }
        }
    }

    // Formatting output. Averages are fixed to 2 decimal places.
    cout << workedDays << "\n";
    cout << fixed << setprecision(2) << (totalSum / (double)n) << "\n";
    if (workedDays > 0) {
        cout << fixed << setprecision(2) << (totalSum / (double)workedDays) << "\n";
    } else {
        cout << fixed << setprecision(2) << 0.00 << "\n";
    }

    // Max and min revenues use default precision settings unless they were integers.
    cout << defaultfloat << setprecision(6);
    if (foundWorkedDay) {
        cout << maxRevenue << "\n";
        for (size_t i = 0; i < maxDays.size(); ++i) {
            cout << maxDays[i] << " ";
        }
        cout << "\n";
        cout << minRevenue << "\n";
        for (size_t i = 0; i < minDays.size(); ++i) {
            cout << minDays[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}