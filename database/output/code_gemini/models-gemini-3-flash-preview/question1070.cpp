/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string day, option, name;
    double price;

    // Reading the day of the week, price, product option, and name
    // Based on the format: Day (string), Price (float), Option (string), Name (string)
    if (cin >> day >> price >> option >> name) {
        double finalPrice;

        // Rule 1: Monday (seg), Tuesday (ter), or Wednesday (qua) and option is "ouro"
        if ((day == "seg" || day == "ter" || day == "qua") && option == "ouro") {
            finalPrice = price / 2.0;
        }
        // Rule 2: Thursday (qui) or Friday (sex) and price is between 10.00 and 100.00 (inclusive)
        else if ((day == "qui" || day == "sex") && (price >= 10.0 && price <= 100.0)) {
            finalPrice = price / 3.0;
        }
        // Rule 3: Saturday (sab) and option is "prata"
        else if (day == "sab" && option == "prata") {
            finalPrice = price * 3.0;
        }
        // Rule 4: Any other case
        else {
            finalPrice = price * 2.0;
        }

        // Output the result following the specified format
        // Default cout precision is used as it matches the test case requirements 
        // (handling values like 191.94 and avoiding unnecessary trailing zeros)
        cout << "O preco do produto " << name << " no dia " << day << " eh " << finalPrice << endl;
    }

    return 0;
}