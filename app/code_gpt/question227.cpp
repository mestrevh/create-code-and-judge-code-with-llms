/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool canMove(const string &card1, const string &card2) {
    return (card1[0] == card2[0] || card1[1] == card2[1]);
}

void compressPiles(vector<vector<string>> &piles) {
    for (size_t i = 0; i < piles.size(); ++i) {
        if (piles[i].empty()) {
            piles.erase(piles.begin() + i);
            --i;
        }
    }
    for (size_t i = 0; i < piles.size(); ++i) {
        if (i + 1 < piles.size() && piles[i].back() == piles[i + 1].back()) {
            piles[i].insert(piles[i].end(), piles[i + 1].begin(), piles[i + 1].end());
            piles.erase(piles.begin() + i + 1);
            --i;
        }
    }
}

void simulateGame(vector<string> &cards) {
    vector<vector<string>> piles;
    
    for (const auto &card : cards) {
        if (piles.empty() || !canMove(piles.back().back(), card)) {
            piles.emplace_back(vector<string> {card});
        } else {
            piles.back().emplace_back(card);
        }
    }
    
    while (true) {
        bool moved = false;
        for (size_t i = 0; i < piles.size(); ++i) {
            if (i >= 1 && canMove(piles[i].back(), piles[i - 1].back())) {
                piles[i - 1].emplace_back(piles[i].back());
                piles[i].pop_back();
                moved = true;
            } else if (i >= 2 && canMove(piles[i].back(), piles[i - 2].back())) {
                piles[i - 2].emplace_back(piles[i].back());
                piles[i].pop_back();
                moved = true;
            }
        }
        compressPiles(piles);
        if (!moved) break;
    }
    
    cout << piles.size() << " pilhas sobrando: ";
    for (const auto &pile : piles) {
        cout << pile.size() << " ";
    }
    cout << endl;
}

int main() {
    string line1, line2;
    while (getline(cin, line1) && getline(cin, line2)) {
        if (line1[0] == '#') break;
        stringstream ss1(line1), ss2(line2);
        vector<string> cards;
        string card;
        while (ss1 >> card) cards.push_back(card);
        while (ss2 >> card) cards.push_back(card);
        simulateGame(cards);
    }
    return 0;
}
