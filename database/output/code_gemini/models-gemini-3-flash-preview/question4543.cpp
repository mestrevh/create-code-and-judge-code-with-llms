/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    vector<int> v;
    v.reserve(100005);

    // If the first input read is not a sequence of comparison symbols, 
    // it must be the first number in the sequence.
    if (!s.empty() && s[0] != '<' && s[0] != '>') {
        try {
            v.push_back(stoi(s));
        } catch (...) {}
        s = "";
    }

    int val;
    while (cin >> val) {
        v.push_back(val);
    }

    if (v.empty()) return 0;

    // Sorting the sequence allows us to use a greedy approach based on blocks.
    sort(v.begin(), v.end());

    int m = (int)s.length();
    int n = (int)v.size();

    // To satisfy any arbitrary sequence of < and >:
    // 1. Sort the numbers.
    // 2. Identify contiguous blocks of '>' symbols.
    // 3. For each block of '>' starting at index i and ending at j-1,
    //    it implies v[i] > v[i+1] > ... > v[j].
    //    Since our array is sorted (v[i] < v[i+1] < ... < v[j]), 
    //    we reverse this subsegment to satisfy the decreasing requirement.
    for (int i = 0; i < m && i < n - 1; ) {
        if (s[i] == '>') {
            int j = i;
            while (j < m && j < n - 1 && s[j] == '>') {
                j++;
            }
            // Reverse elements at positions i through j
            reverse(v.begin() + i, v.begin() + j + 1);
            i = j;
        } else {
            i++;
        }
    }

    // Output formatting according to the requirements: num1 sym1 num2 sym2 ... numN
    for (int i = 0; i < n; ++i) {
        cout << v[i];
        if (i < m && i < n - 1) {
            cout << " " << s[i] << " ";
        }
    }
    cout << endl;

    return 0;
}