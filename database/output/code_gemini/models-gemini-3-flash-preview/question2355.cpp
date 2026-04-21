/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <limits>

using namespace std;

/**
 * Problem: L6Q5 - Visitas de Catalina
 * Goal: Read pairs of (Name, Distance) and output names sorted by distance.
 * Constraint: Use a data structure that maintains order during insertion (O(N log N)).
 * Approach: Utilize std::map to store distance as the key and name as the value.
 */

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // map in C++ is a Balanced BST (usually Red-Black Tree) 
    // which keeps keys sorted automatically upon insertion.
    map<double, string> locations;
    string name;

    // Read names which may contain spaces using getline
    while (getline(cin, name)) {
        // Handle possible carriage return characters from different OS line endings
        if (!name.empty() && name.back() == '\r') {
            name.pop_back();
        }
        
        // Skip empty lines if they exist between pairs
        if (name.empty()) continue;

        double distance;
        // Read the distance associated with the name
        if (!(cin >> distance)) break;

        // Clean the buffer to remove the newline after reading the number
        // so the next getline can read the next name correctly.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Insert into the map. This satisfies the "insert in order" requirement.
        locations[distance] = name;
    }

    // Output the names in ascending order of distance
    for (auto const& [dist, place] : locations) {
        cout << place << "\n";
    }

    return 0;
}