/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

/**
 * Recursive function to process each attempt as per the problem's mandatory recursion rule.
 * n: number of attempts remaining.
 * sumSuc: cumulative sum of people in successful attempts.
 * sumFail: cumulative sum of people in failed attempts.
 */
void processAttempts(int n, long long &sumSuc, long long &sumFail) {
    if (n <= 0) return;

    int x;
    string y;
    if (!(cin >> x >> y)) return;

    if (y == "Conseguiu") {
        sumSuc += x;
    } else {
        sumFail += x;
    }

    // Recursive call to process the next attempt
    processAttempts(n - 1, sumSuc, sumFail);
}

int main() {
    // Standard I/O optimization for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    long long sumSuc = 0;
    long long sumFail = 0;

    // Process all N attempts using recursion
    processAttempts(n, sumSuc, sumFail);

    /**
     * Logic Calculation:
     * Failure rule: For every 2 people, 3 shots are fired.
     * Success rule: Instead of 3, 6 shots are fired for every 2 people.
     * Based on Test Case 0: (16 suc people / 2) * 6 + (4 fail people / 2) * 3 = 48 + 6 = 54.
     * Based on Test Case 1: (8 suc people / 2) * 6 + (1 fail person / 2) * 3 = 24 + 0 = 24.
     */
    long long totalShots = (sumSuc / 2) * 6 + (sumFail / 2) * 3;

    cout << "Foram disparados: " << totalShots << " tiros" << endl;

    /**
     * Final output based on the shot threshold (50).
     * Note: String literals follow the specific spelling/punctuation provided in the test case outputs.
     */
    if (totalShots > 50) {
        cout << "Meus alunos estao estragando tudo! Preciso intervir!" << endl;
    } else {
        cout << "Esta tudo sobre controle, posso passar mais tempo com Raquel..." << endl;
    }

    return 0;
}