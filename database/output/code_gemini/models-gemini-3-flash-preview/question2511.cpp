/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> bag;
    string s;

    // Read exactly 5 non-empty bag items
    while (bag.size() < 5 && getline(cin, s)) {
        while (!s.empty() && (s.back() == '\r' || s.back() == '\n')) {
            s.pop_back();
        }
        if (s.empty()) continue;
        bag.push_back(s);
    }

    set<string> guesses;
    int attempts = 0;

    // Read up to 6 non-empty guess items
    while (attempts < 6 && getline(cin, s)) {
        while (!s.empty() && (s.back() == '\r' || s.back() == '\n')) {
            s.pop_back();
        }
        if (s.empty()) continue;
        guesses.insert(s);
        attempts++;
    }

    // Check if every item in the bag was among the guesses
    int found_count = 0;
    for (const string& bag_item : bag) {
        if (guesses.find(bag_item) != guesses.end()) {
            found_count++;
        }
    }

    if (found_count == 5) {
        cout << "Could I be more happy?" << endl;
    } else {
        cout << "It is all just a moo point" << endl;
    }

    return 0;
}