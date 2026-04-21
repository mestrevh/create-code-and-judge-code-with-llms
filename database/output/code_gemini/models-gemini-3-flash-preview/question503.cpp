/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {
    // Fast I/O optimization for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int socio_count = 0;
    int brinde_count = 0;
    double total_revenue = 0.0;

    // The problem specifies receiving data for exactly 5 clients.
    for (int i = 0; i < 5; ++i) {
        string car_size, wash_type_1, wash_type_2, client_type;
        
        // Reading inputs. Since "tipo de lavagem" is "com cera" or "sem cera",
        // it consists of two words that will be read as two separate strings by cin.
        if (!(cin >> car_size >> wash_type_1 >> wash_type_2 >> client_type)) break;

        // Determine if the car is Small (pequeno) or Large (grande) by the first character.
        bool is_small = (tolower((unsigned char)car_size[0]) == 'p');
        
        // Determine if the wash type is "com cera" by checking the first part of the wash description.
        bool is_wax = (tolower((unsigned char)wash_type_1[0]) == 'c');
        
        // Determine if the client is a member (sócio) or non-member (não-sócio).
        bool is_socio = (tolower((unsigned char)client_type[0]) == 's');

        // Increment the member counter.
        if (is_socio) {
            socio_count++;
        }

        // Increment the gift (brinde) counter if the wash is "com cera".
        if (is_wax) {
            brinde_count++;
        }

        // Calculate revenue based on the price table provided.
        if (is_small) {
            if (is_wax) {
                // Pequeno / Lavagem com cera: Sócio R$ 30 / Não-sócio R$ 40
                total_revenue += (is_socio ? 30.00 : 40.00);
            } else {
                // Pequeno / Lavagem sem cera: Sócio R$ 20 / Não-sócio R$ 30
                total_revenue += (is_socio ? 20.00 : 30.00);
            }
        } else {
            // Grande
            if (is_wax) {
                // Grande / Lavagem com cera: Sócio R$ 60 / Não-sócio R$ 80
                total_revenue += (is_socio ? 60.00 : 80.00);
            } else {
                // Grande / Lavagem sem cera: Sócio R$ 40 / Não-sócio R$ 50
                total_revenue += (is_socio ? 40.00 : 50.00);
            }
        }
    }

    // Output results: quantity of members, quantity of gifts, and total revenue.
    cout << socio_count << "\n";
    cout << brinde_count << "\n";
    cout << fixed << setprecision(2) << total_revenue << endl;

    return 0;
}