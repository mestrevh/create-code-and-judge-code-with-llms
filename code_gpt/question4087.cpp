/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    string neighborhood, day;
    getline(cin, neighborhood);
    getline(cin, day);
    
    unordered_set<string> area1 = {"Moon Knight", "Daredevil", "Jessica Jones"};
    unordered_set<string> area2 = {"WandaVision", "Loki", "Hawkeye"};

    if (area1.find(neighborhood) != area1.end()) {
        if (day == "Tuesday") {
            cout << "Water Available" << endl;
        } else {
            cout << "Water not Available" << endl;
        }
    } else if (area2.find(neighborhood) != area2.end()) {
        if (day == "Wednesday") {
            cout << "Water Available" << endl;
        } else {
            cout << "Water not Available" << endl;
        }
    } else {
        cout << "Invalid Neighborhood" << endl;
    }

    return 0;
}
