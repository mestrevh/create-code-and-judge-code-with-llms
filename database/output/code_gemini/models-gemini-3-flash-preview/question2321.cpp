/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Grande Mestre em Programação Competitiva.
 * Task: L5Q3 - Audition
 * Complexity: O(N * S), where N is number of candidates and S is max name length.
 * Recursion is used to fulfill the problem's strict requirement.
 */

// Recursive function to process each candidate one by one.
// Tail-recursive to optimize stack usage and avoid overflow.
void findWinnerRecursive(int currentIdx, int totalCandidates, double patience, double& maxScore, string& winner) {
    if (currentIdx >= totalCandidates) {
        return;
    }

    string candidateName;
    // Reading candidate's full name including spaces.
    if (!getline(cin, candidateName)) return;
    
    // In case of a leftover empty line after reading V and N.
    if (candidateName.empty() && currentIdx == 0) {
        if (!getline(cin, candidateName)) return;
    }

    // Calculating the ASCII sum of all characters in the name.
    long long asciiSum = 0;
    for (unsigned char c : candidateName) {
        asciiSum += (int)c;
    }

    // Calculating the base score based on ASCII sum and current patience level.
    double candidateScore = (double)asciiSum * patience;

    // Adding bonus points for specific candidates as requested.
    // Bonus names are case-sensitive and space-sensitive.
    if (candidateName == "Troy Bolton" || candidateName == "Gabriella Montez" || 
        candidateName == "Sharpay Evans" || candidateName == "Ryan Evans") {
        candidateScore += 350.0;
    }

    // Updating the winner if the current score is strictly higher.
    // This keeps the first candidate in case of a score tie.
    if (currentIdx == 0 || candidateScore > maxScore) {
        maxScore = candidateScore;
        winner = candidateName;
    }

    // Recursive call for the next candidate with a 1% reduction in patience level.
    findWinnerRecursive(currentIdx + 1, totalCandidates, patience * 0.99, maxScore, winner);
}

int main() {
    // Standard competitive programming I/O optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double initialPatience;
    int numCandidates;

    // Reading initial patience and the number of candidates.
    if (!(cin >> initialPatience >> numCandidates)) {
        return 0;
    }

    // Consuming the leftover newline character from the cin buffer.
    string dummy;
    getline(cin, dummy);

    double maxScore = -1.0;
    string winningName = "";

    // If there are candidates, start the recursive process.
    if (numCandidates > 0) {
        findWinnerRecursive(0, numCandidates, initialPatience, maxScore, winningName);
        
        // Output formatting exactly as specified in the problem description.
        cout << "O grande vencedor(a) do papel principal desse ano foi " << winningName << "!" << endl;
    }

    return 0;
}