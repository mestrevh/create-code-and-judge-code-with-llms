/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Data structure to store phone info.
 * Pi (Name) and Ci (Number).
 */
struct Phone {
    string name;
    long long number;
};

/**
 * Data structure to store the result of the recursive search.
 * val: the maximum number found in the sub-array.
 * isAlison: boolean indicating if "Alison" owns a phone with that maximum value.
 */
struct Result {
    long long val;
    bool isAlison;
};

/**
 * Recursive Divide and Conquer function as described in the problem.
 * - Base case: if size is 1, max is the only element.
 * - Recursive case: divide into two, find max of left and right.
 */
Result findMaxRecursive(int l, int r, const vector<Phone>& phones) {
    // Base case: array has size 1
    if (l == r) {
        Result res;
        res.val = phones[l].number;
        res.isAlison = (phones[l].name == "Alison");
        return res;
    }

    // Recursive case: divide the array in two
    int mid = l + (r - l) / 2;
    Result leftResult = findMaxRecursive(l, mid, phones);
    Result rightResult = findMaxRecursive(mid + 1, r, phones);

    // Combine step: find the maximum between the two halves
    Result combined;
    if (leftResult.val > rightResult.val) {
        combined.val = leftResult.val;
        combined.isAlison = leftResult.isAlison;
    } else if (rightResult.val > leftResult.val) {
        combined.val = rightResult.val;
        combined.isAlison = rightResult.isAlison;
    } else {
        // If values are equal, Alison is found if she exists in either half with that value
        combined.val = leftResult.val;
        combined.isAlison = leftResult.isAlison || rightResult.isAlison;
    }

    return combined;
}

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Process input using while loop to handle potential multiple entries
    while (cin >> n) {
        if (n <= 0) continue;

        vector<Phone> phones(n);
        for (int i = 0; i < n; ++i) {
            cin >> phones[i].name >> phones[i].number;
        }

        // Execute the mandatory recursive algorithm
        Result finalResult = findMaxRecursive(0, n - 1, phones);

        /**
         * Rule: Alison's phone has the largest number.
         * If Alison's name is associated with the maximum number found, her phone is on the wall.
         * Otherwise, she "stole it again".
         */
        if (finalResult.isAlison) {
            cout << "Ela nao tentou bancar a espertinha de novo!" << endl;
        } else {
            cout << "ELA ROUBOU DE NOVO! TODOS ATRAS DE ALISON! O maior numero na parede e " << finalResult.val << "!" << endl;
        }
    }

    return 0;
}