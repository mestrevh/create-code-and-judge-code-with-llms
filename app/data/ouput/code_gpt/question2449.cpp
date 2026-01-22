/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    vector<int> results;
    
    while (getline(cin, line)) {
        if (line == "[") {
            int time = 0, distance = 20, pathNum = results.size() + 1;
            bool valid = true;

            while (getline(cin, line) && line != "]") {
                if (line == "C") time += 5;
                else if (line == "T") time += 10;
                else {
                    int temp;
                    stringstream(line) >> temp;
                    time += temp;
                }
                if (time > 20) distance -= 3;
                else distance -= 1;
            }
            distance += time <= 20 ? 1 : 0;
            if (distance > 0) results.push_back(pathNum);
        }
    }

    if (results.empty()) cout << "UoooooOOooOOooooo UooooOOooOOooo" << endl;
    else cout << "Tarzan fugir caminho " << results.front() << endl;

    return 0;
}
