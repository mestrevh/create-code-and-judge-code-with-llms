/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

bool isValidMatrix(const vector<vector<int>>& matrix) {
    return (matrix[0][0] == 1 && matrix[1][1] == 1 && matrix[2][2] == 1 &&
            matrix[0][1] == 0 && matrix[0][2] == 0 &&
            matrix[1][0] == 0 && matrix[1][2] == 0 &&
            matrix[2][0] == 0 && matrix[2][1] == 0) ||
           (matrix[0][2] == 1 && matrix[1][1] == 1 && matrix[2][0] == 1 &&
            matrix[0][0] == 0 && matrix[0][1] == 0 &&
            matrix[1][0] == 0 && matrix[1][2] == 0 &&
            matrix[2][1] == 0 && matrix[2][2] == 0);
}

int main() {
    int lifeLuke, lifeVader;
    cin >> lifeLuke >> lifeVader;
    cin.ignore();
    
    string emptyLine;
    vector<vector<int>> lukeMatrix(3, vector<int>(3)), vaderMatrix(3, vector<int>(3));
    
    while (true) {
        getline(cin, emptyLine);
        if (emptyLine.empty()) break;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> lukeMatrix[i][j];
        
        cin.ignore();
        
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> vaderMatrix[i][j];
        
        bool validLuke = isValidMatrix(lukeMatrix);
        bool validVader = isValidMatrix(vaderMatrix);
        
        if (!validLuke && validVader) lifeLuke -= 15;
        if (validLuke && !validVader) lifeVader -= 15;
        if (validLuke && validVader && lukeMatrix[0][0] != vaderMatrix[0][0]) {}

        cin.ignore();
    }

    if (lifeLuke > lifeVader) cout << "Luke Skywalker venceu." << endl;
    else if (lifeVader > lifeLuke) cout << "Darth Vader venceu." << endl;
    else cout << "Houve empate." << endl;

    return 0;
}
