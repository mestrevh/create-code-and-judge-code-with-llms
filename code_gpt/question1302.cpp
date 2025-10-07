/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

int main() {
    int mat[3][3], count = 0, sumNeg = 0, minVal = INT_MAX;
    double positiveSum = 0.0;
    
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j) {
            cin >> mat[i][j];
            if(mat[i][j] > 0) {
                positiveSum += mat[i][j];
                count++;
            }
            if(mat[i][j] < minVal) {
                minVal = mat[i][j];
            }
        }
    
    int delta = (minVal % 2 == 0) ? 1 : 0;
    
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j) {
            if(i != j) {
                sumNeg += mat[i][j];
           ```cpp
            }
        }
    
    double avg = (count > 0) ? positiveSum / count : 0.0;

    cout << fixed << setprecision(2) << avg << " " << minVal << " " << delta << " " << sumNeg << endl;

    return 0;
}
