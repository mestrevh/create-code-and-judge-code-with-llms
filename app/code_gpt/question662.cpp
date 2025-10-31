/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>
#include <vector>

int main() {
    int A, B;
    while (std::cin >> A >> B, A || B) {
        std::set<int> aliceCards, beatrizCards;
        int card;
        
        for (int i = 0; i < A; ++i) {
            std::cin >> card;
            aliceCards.insert(card);
        }
        
        for (int i = 0; i < B; ++i) {
            std::cin >> card;
            beatrizCards.insert(card);
        }
        
        std::vector<int> distinctAlice(aliceCards.begin(), aliceCards.end());
        std::vector<int> distinctBeatriz(beatrizCards.begin(), beatrizCards.end());
        
        int aliceUnique = distinctAlice.size();
        int beatrizUnique = distinctBeatriz.size();
        
        int exchangeCount = 0;
        for (int card : distinctAlice) {
            if (beatrizCards.find(card) == beatrizCards.end()) {
                exchangeCount++;
            }
        }
        
        for (int card : distinctBeatriz) {
            if (aliceCards.find(card) == aliceCards.end()) {
                exchangeCount++;
            }
        }

        std::cout << std::min(exchangeCount/2, std::min(aliceUnique, beatrizUnique)) << std::endl;
    }
    return 0;
}
