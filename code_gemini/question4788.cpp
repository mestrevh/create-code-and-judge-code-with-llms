/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int best_event = 1;
    int max_knockouts = -1;

    for (int event = 1; event <= n; ++event) {
        int x;
        cin >> x;

        int knockouts = 0;

        for (int i = 0; i < x; ++i) {
            string def_name, chal_name;
            int def_grappling, def_striking, def_cardio;
            int chal_grappling, chal_striking, chal_cardio;

            cin >> def_name >> def_grappling >> def_striking >> def_cardio;
            cin >> chal_name >> chal_grappling >> chal_striking >> chal_cardio;

            if (chal_grappling > def_striking) {
                cout << chal_name << " ganhou por submissao" << endl;
            } else if (chal_grappling < def_striking) {
                 cout << def_name << " ganhou por nocaute" << endl;
                 knockouts++;
            }
             else if (chal_striking > def_grappling) {
                cout << chal_name << " ganhou por nocaute" << endl;
                knockouts++;
            } else if (chal_striking < def_grappling) {
                cout << def_name << " ganhou por submissao" << endl;
            }
             else if (chal_cardio > def_cardio) {
                cout << chal_name << " ganhou por decisao" << endl;
            } else {
                cout << def_name << " ganhou por decisao" << endl;
            }
        }

        if (knockouts > max_knockouts) {
            max_knockouts = knockouts;
            best_event = event;
        }
    }

    cout << "Melhor evento foi " << best_event << endl;

    return 0;
}
