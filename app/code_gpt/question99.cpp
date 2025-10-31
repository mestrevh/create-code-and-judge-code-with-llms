/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Sprinkler {
    int id;
    float temperature;
    char smoke;
};

bool shouldActivateSprinkler(const Sprinkler& sprinkler, float avgTemp) {
    return sprinkler.smoke == 'S' || 
           (sprinkler.temperature < 40 && 
            sprinkler.temperature > avgTemp && 
            sprinkler.temperature <= avgTemp * 1.15);
}

int main() {
    int testCases;
    cin >> testCases;
    for (int t = 1; t <= testCases; ++t) {
        int n;
        cin >> n;
        vector<Sprinkler> sprinklers(n);
        float totalTemp = 0.0;

        for (int i = 0; i < n; ++i) {
            cin >> sprinklers[i].id >> sprinklers[i].temperature >> sprinklers[i].smoke;
            totalTemp += sprinklers[i].temperature;
        }

        float avgTemp = totalTemp / n;
        vector<int> activated;

        for (const auto& sprinkler : sprinklers) {
            if (shouldActivateSprinkler(sprinkler, avgTemp)) {
                activated.push_back(sprinkler.id);
            }
        }

        cout << "TESTE " << t << endl;
        for (const auto& id : activated) {
            cout << id << endl;
        }
    }
    return 0;
}
