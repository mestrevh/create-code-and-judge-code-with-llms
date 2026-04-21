/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long C;
    if (!(cin >> N >> C)) return 0;

    long long current_people = 0;
    bool exceeded = false;

    for (int i = 0; i < N; ++i) {
        long long S, E;
        if (!(cin >> S >> E)) break;
        
        current_people -= S;
        current_people += E;

        if (current_people > C) {
            exceeded = true;
        }
    }

    if (exceeded) {
        cout << "Selvagens sao dificeis de ensinar." << endl;
    } else {
        cout << "Viva a conscientizacao." << endl;
    }

    return 0;
}