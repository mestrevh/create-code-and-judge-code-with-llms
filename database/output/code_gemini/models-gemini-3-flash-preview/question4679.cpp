/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem: Organize students into classes 1, 2, and 3 based on input.
 * Requirements:
 * 1. Read name (line 1) and class number (line 2) until EOF.
 * 2. Use dynamic memory allocation (handled efficiently by std::vector).
 * 3. Output students organized by class in order of entry.
 * 4. Complexity: O(N) time and space.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Using an array of vectors for the three classes (index 1 to 3)
    vector<string> turmas[4];
    string student_name;

    // Read student name until EOF
    while (getline(cin, student_name)) {
        // Sanitize name: remove carriage return if present (Windows/Linux compatibility)
        if (!student_name.empty() && student_name.back() == '\r') {
            student_name.pop_back();
        }
        
        // Skip potential empty lines between entries
        if (student_name.empty()) continue;

        int class_id;
        // Read the class number on the next line
        if (!(cin >> class_id)) break;

        // Store the name in the corresponding class vector
        if (class_id >= 1 && class_id <= 3) {
            turmas[class_id].push_back(student_name);
        }

        // Consume the trailing newline after reading the integer to prepare for next getline
        string buffer_clear;
        getline(cin, buffer_clear);
    }

    // Output results for each class in numerical order
    for (int i = 1; i <= 3; ++i) {
        cout << "Turma " << i << ":\n";
        for (const auto& name : turmas[i]) {
            cout << name << "\n";
        }
        
        // Print a newline between turmas as per test case format (except after the last one)
        if (i < 3) {
            cout << "\n";
        }
    }

    return 0;
}