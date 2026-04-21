/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> valid_plates;
    vector<string> invalid_plates;

    for (int i = 0; i < n; ++i) {
        string plate;
        cin >> plate;
        
        int letters = 0;
        int numbers = 0;
        
        for (char c : plate) {
            if (c >= 'A' && c <= 'Z') {
                letters++;
            } else if (c >= '0' && c <= '9') {
                numbers++;
            }
        }

        // Based on problem description: valid is 3 letters and 4 numbers
        if (letters == 3 && numbers == 4) {
            valid_plates.push_back(plate);
        } else {
            invalid_plates.push_back(plate);
        }
    }

    cout << valid_plates.size() << " placas:" << "\n";
    for (const string& s : valid_plates) {
        cout << s << "\n";
    }

    cout << invalid_plates.size() << " erros:" << "\n";
    for (const string& s : invalid_plates) {
        cout << s << "\n";
    }

    return 0;
}