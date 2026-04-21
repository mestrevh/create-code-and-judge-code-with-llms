/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y, L1, H1, L2, H2;
    if (!(cin >> X >> Y >> L1 >> H1 >> L2 >> H2)) return 0;

    bool possible = false;

    // Possible orientations for the first photo
    int w1_opt[] = {L1, H1};
    int h1_opt[] = {H1, L1};
    
    // Possible orientations for the second photo
    int w2_opt[] = {L2, H2};
    int h2_opt[] = {H2, L2};

    // Iterate through all 2x2 = 4 combinations of rotations for the two photos
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            int w1 = w1_opt[i], h1 = h1_opt[i];
            int w2 = w2_opt[j], h2 = h2_opt[j];

            // Case 1: Photos placed side-by-side horizontally (total width <= page width)
            if (w1 + w2 <= X && max(h1, h2) <= Y) possible = true;
            // Case 2: Photos placed side-by-side vertically (total height <= page height)
            if (h1 + h2 <= Y && max(w1, w2) <= X) possible = true;
            
            // Repeat the same checks considering the page itself could be rotated 90 degrees
            // (Page width Y and height X)
            if (w1 + w2 <= Y && max(h1, h2) <= X) possible = true;
            if (h1 + h2 <= X && max(w1, w2) <= Y) possible = true;
            
            if (possible) break;
        }
        if (possible) break;
    }

    if (possible) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}