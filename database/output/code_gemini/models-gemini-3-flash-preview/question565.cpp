/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Standard I/O optimization for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // According to the problem test cases, the prompt is part of the interaction.
    cout << "Digite um número com no máximo 5 algarismos: ";

    string input;
    // Reading input as a string to handle digit counting and overflow scenarios easily.
    if (!(cin >> input)) return 0;

    int digit_count = 0;
    // Counting only the numeric characters (0-9).
    // This correctly handles the "algarismos" count even for negative numbers.
    for (char c : input) {
        if (c >= '0' && c <= '9') {
            digit_count++;
        }
    }

    // The constraint is "no máximo 5 algarismos".
    // If the count of digits exceeds 5, output the error message.
    if (digit_count > 5) {
        cout << "Entrada incorreta!" << endl;
    } else {
        // Output the number of digits in the format specified in the test cases.
        cout << "O número possui " << digit_count << " algarismos!" << endl;
    }

    return 0;
}