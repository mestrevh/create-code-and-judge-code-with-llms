/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <cctype>

using namespace std;

/**
 * Problem Solution: The Pandorica Opens
 * Persona: Competitive Programming Grandmaster
 * 
 * Strategy:
 * 1. Use a std::list to manage the enemies (FIFO queue behavior). std::list is used 
 *    to strictly follow the "no arrays" rule while maintaining O(1) removals.
 * 2. Process each line of the speech iteratively.
 * 3. Use std::search with a custom case-insensitive comparator for name matching.
 * 4. Use character-by-character comparison (case-insensitive) for morale reduction.
 * 5. Handle the "chain effect" where a single line can repel multiple enemies.
 * 
 * Complexity:
 * - Time: O(L * (E + S)), where L is the number of speech lines, E is enemy name length,
 *   and S is the average speech line length. This is highly efficient for the 3s limit.
 * - Space: O(N * E), where N is the number of enemies.
 */

struct Enemy {
    string name;
    int morale;
};

int main() {
    // Optimization for Competitive Programming I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    list<Enemy> enemies;
    string line;

    // Phase 1: Input Enemy Data
    // Expecting: Name, then Morale on separate lines until "----------"
    while (getline(cin, line) && line != "----------") {
        if (line.empty()) continue;
        string morale_str;
        if (!getline(cin, morale_str)) break;
        try {
            int m = stoi(morale_str);
            enemies.push_back({line, m});
        } catch (...) {
            // Robustness for potential trailing spaces or malformed integers
        }
    }

    // Phase 2: Process the Doctor's Speech
    while (getline(cin, line)) {
        // According to the rules, a single line continues affecting subsequent
        // enemies in the queue if the previous one flees.
        while (!enemies.empty()) {
            Enemy &e = enemies.front();
            bool fled = false;

            if (e.name.empty()) {
                fled = true;
            } else {
                // Check if the Doctor mentions the race name (Case Insensitive)
                auto it_found = search(line.begin(), line.end(), e.name.begin(), e.name.end(),
                    [](char a, char b) {
                        return tolower((unsigned char)a) == tolower((unsigned char)b);
                    });

                if (it_found != line.end()) {
                    fled = true;
                } else {
                    // Reduce morale based on occurrences of the first letter (Case Insensitive)
                    char target = (char)tolower((unsigned char)e.name[0]);
                    int matched_chars = 0;
                    for (char c : line) {
                        if ((char)tolower((unsigned char)c) == target) {
                            matched_chars++;
                        }
                    }
                    e.morale -= matched_chars;
                    if (e.morale <= 0) fled = true;
                }
            }

            if (fled) {
                cout << "A horda de " << e.name << " fugiu" << endl;
                enemies.pop_front();
                // "essa linha também afetará a próxima raça da fila"
                // The inner loop continues with the current 'line'
            } else {
                // Line processing finishes if the current enemy doesn't flee
                break;
            }
        }
    }

    // Phase 3: Final Status Output
    if (enemies.empty()) {
        cout << "Nao ha mais inimigos a vista." << endl;
    } else {
        cout << "Infelizmente o discurso nao foi tao intimidador assim." << endl;
    }

    return 0;
}