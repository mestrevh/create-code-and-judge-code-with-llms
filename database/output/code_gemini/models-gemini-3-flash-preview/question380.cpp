/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    int cinema_votes = 0;
    int boliche_votes = 0;

    for (int i = 0; i < 7; ++i) {
        if (!(cin >> input)) break;
        
        string processed = input;
        for (char &c : processed) {
            c = tolower((unsigned char)c);
        }

        if (processed == "cinema") {
            cinema_votes++;
        } else if (processed == "boliche") {
            boliche_votes++;
        }
    }

    if (cinema_votes > boliche_votes) {
        cout << "CINEMA" << endl;
    } else {
        cout << "BOLICHE" << endl;
    }

    return 0;
}