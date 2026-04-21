/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Voter {
    string name;
    int agregados;
    string food;
    string drink;
    string artist;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Voter> voters(n);
    map<int, int> freqAgregados;
    map<string, int> freqFood;
    map<string, int> freqDrink;
    map<string, int> freqArtist;

    for (int i = 0; i < n; ++i) {
        cin >> voters[i].name >> voters[i].agregados >> voters[i].food >> voters[i].drink;
        getline(cin >> ws, voters[i].artist);

        freqAgregados[voters[i].agregados]++;
        freqFood[voters[i].food]++;
        freqDrink[voters[i].drink]++;
        freqArtist[voters[i].artist]++;
    }

    int winAgregados = 0, maxA = 0;
    for (auto const& [val, freq] : freqAgregados) {
        if (freq > maxA) {
            maxA = freq;
            winAgregados = val;
        }
    }

    string winFood;
    int maxF = 0;
    for (auto const& [val, freq] : freqFood) {
        if (freq > maxF) {
            maxF = freq;
            winFood = val;
        }
    }

    string winDrink;
    int maxD = 0;
    for (auto const& [val, freq] : freqDrink) {
        if (freq > maxD) {
            maxD = freq;
            winDrink = val;
        }
    }

    string winArtist;
    int maxAr = 0;
    for (auto const& [val, freq] : freqArtist) {
        if (freq > maxAr) {
            maxAr = freq;
            winArtist = val;
        }
    }

    cout << winAgregados << "\n";
    cout << winFood << "\n";
    cout << winDrink << "\n";
    cout << winArtist << "\n";
    cout << "convidados vip:" << "\n";

    vector<string> vips;
    for (int i = 0; i < n; ++i) {
        int matches = 0;
        if (voters[i].agregados == winAgregados) matches++;
        if (voters[i].food == winFood) matches++;
        if (voters[i].drink == winDrink) matches++;
        if (voters[i].artist == winArtist) matches++;

        if (matches >= 2) {
            vips.push_back(voters[i].name);
        }
    }

    sort(vips.begin(), vips.end());

    for (const string& name : vips) {
        cout << name << "\n";
    }

    return 0;
}