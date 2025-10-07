/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> agregados_votes;
    map<string, int> comida_votes;
    map<string, int> bebida_votes;
    map<string, int> artista_votes;
    vector<tuple<string, int, string, string, string>> votes;

    for (int i = 0; i < n; ++i) {
        string nome, comida, bebida, artista;
        int agregados;
        cin >> nome >> agregados >> comida >> bebida >> artista;
        votes.emplace_back(nome, agregados, comida, bebida, artista);

        agregados_votes[agregados]++;
        comida_votes[comida]++;
        bebida_votes[bebida]++;
        artista_votes[artista]++;
    }

    int min_agregados = -1;
    int max_agregados_votes = -1;
    for (auto const& [agregados, count] : agregados_votes) {
        if (count > max_agregados_votes) {
            max_agregados_votes = count;
            min_agregados = agregados;
        } else if (count == max_agregados_votes) {
            min_agregados = min(min_agregados, agregados);
        }
    }

    string winning_comida = "";
    int max_comida_votes = -1;
    for (auto const& [comida, count] : comida_votes) {
        if (count > max_comida_votes) {
            max_comida_votes = count;
            winning_comida = comida;
        } else if (count == max_comida_votes) {
            winning_comida = min(winning_comida, comida);
        }
    }
    
    string winning_bebida = "";
    int max_bebida_votes = -1;
    for (auto const& [bebida, count] : bebida_votes) {
        if (count > max_bebida_votes) {
            max_bebida_votes = count;
            winning_bebida = bebida;
        } else if (count == max_bebida_votes) {
            winning_bebida = min(winning_bebida, bebida);
        }
    }

    string winning_artista = "";
    int max_artista_votes = -1;
    for (auto const& [artista, count] : artista_votes) {
        if (count > max_artista_votes) {
            max_artista_votes = count;
            winning_artista = artista;
        } else if (count == max_artista_votes) {
            winning_artista = min(winning_artista, artista);
        }
    }

    cout << min_agregados << endl;
    cout << winning_comida << endl;
    cout << winning_bebida << endl;
    cout << winning_artista << endl;
    cout << "convidados vip:" << endl;


    vector<string> vip_guests;
    for (const auto& [nome, agregados, comida, bebida, artista] : votes) {
        int matches = 0;
        if (agregados == min_agregados) matches++;
        if (comida == winning_comida) matches++;
        if (bebida == winning_bebida) matches++;
        if (artista == winning_artista) matches++;
        if (matches >= 2) {
            vip_guests.push_back(nome);
        }
    }
    sort(vip_guests.begin(), vip_guests.end());
    for (const string& guest : vip_guests) {
        cout << guest << endl;
    }

    return 0;
}
