/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string current_name;
    double total_spent = 0.0;
    double max_price = -1.0;
    string most_expensive_item = "";

    while (cin >> current_name) {
        string upper_name = current_name;
        for (char &c : upper_name) {
            c = (char)toupper((unsigned char)c);
        }

        if (upper_name == "FIM") {
            break;
        }

        double price;
        if (!(cin >> price)) {
            break;
        }

        total_spent += price;

        if (price > max_price) {
            max_price = price;
            most_expensive_item = upper_name;
        }
    }

    cout << fixed << setprecision(2) << total_spent << "\n";
    cout << most_expensive_item << "\n";

    return 0;
}

