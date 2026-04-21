/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

/**
 * Problem: Sales Site Management
 * Constraints: Max 10 sales per week, "encerrar" as stop condition.
 * Logic: Use a loop to read up to 10 entries, accumulate totals, and track the maximum purchase.
 * Complexity: O(N) where N is the number of sales (N <= 10).
 */

int main() {
    // Optimize standard I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int totalQuantity = 0;
    double totalAmount = 0.0;
    double maxPurchaseValue = -1.0;
    string winnerName = "";
    string winnerCity = "";

    for (int i = 0; i < 10; ++i) {
        string clientName;
        // Read client name; handle stopping condition "encerrar" or EOF
        if (!getline(cin, clientName) || clientName == "encerrar") {
            break;
        }

        // Handle potential empty lines between records
        if (clientName.empty()) {
            i--;
            continue;
        }

        int quantity;
        double value;
        string city;

        // Read numeric values
        if (!(cin >> quantity >> value)) {
            break;
        }

        // Consume the leftover newline and any trailing characters on the line after 'value'
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Read destination city
        if (!getline(cin, city)) {
            break;
        }

        // Update weekly totals
        totalQuantity += quantity;
        totalAmount += value;

        // Determine if this client has the highest purchase value for the gift
        if (value > maxPurchaseValue) {
            maxPurchaseValue = value;
            winnerName = clientName;
            winnerCity = city;
        }
    }

    // Output formatting: Quantity (integer) and Amount (2 decimal places)
    cout << "Quantidade vendida: " << totalQuantity << "\n";
    cout << "Valor arrecadado: " << fixed << setprecision(2) << totalAmount << "\n";

    // Output the gift recipient if at least one sale was recorded
    if (maxPurchaseValue != -1.0) {
        cout << winnerName << "\n";
        cout << winnerCity << "\n";
    }

    return 0;
}