/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int get_priority(const string& name) {
    if (name == "Mario") return 1;
    if (name == "Toad") return 2;
    if (name == "Luigi") return 3;
    if (name == "Yoshi") return 4;
    return 5;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> arrivals(5);
    for (int i = 0; i < 5; ++i) {
        if (!(cin >> arrivals[i])) break;
    }

    // Parity of arrival order (1st, 2nd, 3rd, 4th, 5th)
    // 1st (index 0) - Princesa, Head of table (Position 1)
    // 2nd (index 1) - Even
    // 3rd (index 2) - Odd
    // 4th (index 3) - Even
    // 5th (index 4) - Odd

    vector<string> even_side;
    even_side.push_back(arrivals[1]);
    even_side.push_back(arrivals[3]);

    vector<string> odd_side;
    odd_side.push_back(arrivals[2]);
    odd_side.push_back(arrivals[4]);

    auto cmp = [](const string& a, const string& b) {
        return get_priority(a) < get_priority(b);
    };

    sort(even_side.begin(), even_side.end(), cmp);
    sort(odd_side.begin(), odd_side.end(), cmp);

    // Output positions in table order: 1, 2, 3, 4, 5
    // Parity of positions matches arrival parity rules
    cout << arrivals[0] << "\n";  // Position 1 (Princesa)
    cout << even_side[0] << "\n"; // Position 2 (Closest Even)
    cout << odd_side[0] << "\n";  // Position 3 (Closest Odd)
    cout << even_side[1] << "\n"; // Position 4 (Further Even)
    cout << odd_side[1] << "\n";  // Position 5 (Further Odd)

    return 0;
}