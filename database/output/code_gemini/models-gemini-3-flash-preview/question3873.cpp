/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Client {
    string name;
    double final_invoice;
    bool benefited;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;
    
    string skip;
    getline(cin, skip); // Consume leftover newline after N

    vector<Client> clients;
    int benefited_count = 0;
    int not_benefited_count = 0;

    for (int i = 0; i < N; ++i) {
        string name;
        // Skip possible empty lines and read name
        while (getline(cin, name) && name.empty());
        
        string card;
        int cvv;
        double initial_value;
        if (!(cin >> card >> cvv >> initial_value)) break;
        getline(cin, skip); // Consume leftover newline after value

        int digit_sum = 0;
        for (char c : card) {
            if (c >= '0' && c <= '9') {
                digit_sum += (c - '0');
            }
        }

        Client c;
        c.name = name;
        if (digit_sum >= cvv) {
            c.benefited = true;
            c.final_invoice = 0.0;
            benefited_count++;
        } else {
            c.benefited = false;
            c.final_invoice = initial_value * (cvv - digit_sum);
            not_benefited_count++;
        }
        clients.push_back(c);
    }

    cout << "Um total de " << benefited_count << " clientes se beneficiaram da nova politica!\n";
    for (const auto& c : clients) {
        if (c.benefited) {
            cout << c.name << " " << fixed << setprecision(2) << c.final_invoice << "\n";
        }
    }

    cout << "No entanto, " << not_benefited_count << " clientes nao se beneficiaram da nova politica.\n";
    for (const auto& c : clients) {
        if (!c.benefited) {
            cout << c.name << " " << fixed << setprecision(2) << c.final_invoice << "\n";
        }
    }

    return 0;
}