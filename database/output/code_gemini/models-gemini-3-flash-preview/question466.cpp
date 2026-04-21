/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string currentCity;
    string bestCity = "";
    int maxDistance = -1;

    while (cin >> currentCity) {
        string check = currentCity;
        for (char &c : check) {
            c = (char)tolower((unsigned char)c);
        }
        
        if (check == "fim") {
            break;
        }

        int distance;
        double price;
        
        if (!(cin >> distance >> price)) {
            break;
        }

        if (price * 2.0 <= 300.0) {
            if (distance > maxDistance) {
                maxDistance = distance;
                bestCity = currentCity;
            }
        }
    }

    if (bestCity.empty()) {
        cout << "SEM DESTINO" << endl;
    } else {
        for (char &c : bestCity) {
            c = (char)toupper((unsigned char)c);
        }
        cout << bestCity << endl;
    }

    return 0;
}