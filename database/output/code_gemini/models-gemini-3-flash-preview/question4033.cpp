/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n1, n2, n3;
    char gender;
    double maxAvg = -1.0;
    char maxGender = ' ';
    double sumTotal = 0;
    int countTotal = 0;
    int approvedCount = 0;
    int finalCount = 0;
    int failedCount = 0;
    double sumM = 0;
    int countM = 0;
    double sumH = 0;
    int countH = 0;

    while (cin >> n1 >> n2 >> n3 >> gender) {
        double avg = (n1 + n2 + n3) / 3.0;
        
        if (avg >= maxAvg) {
            maxAvg = avg;
            maxGender = gender;
        }
        
        sumTotal += avg;
        countTotal++;
        
        if (avg >= 7.0) {
            approvedCount++;
        } else if (avg >= 3.0) {
            finalCount++;
        } else {
            failedCount++;
        }
        
        if (gender == 'M') {
            sumM += avg;
            countM++;
        } else if (gender == 'H') {
            sumH += avg;
            countH++;
        }
    }

    if (countTotal > 0) {
        cout << fixed << setprecision(1);
        cout << "A maior media da turma foi " << maxAvg << " e pertence a " << (maxGender == 'M' ? "uma mulher" : "um homem") << "." << endl;
        cout << "A media geral foi de " << (sumTotal / countTotal) << "." << endl;
        cout << approvedCount << " alunos foram aprovados por media." << endl;
        cout << finalCount << " alunos podem fazer o exame final." << endl;
        cout << failedCount << " alunos foram reprovados." << endl;
        cout << "A media das mulheres foi de " << (countM > 0 ? sumM / countM : 0.0) << "." << endl;
        cout << "A media dos homens foi de " << (countH > 0 ? sumH / countH : 0.0) << "." << endl;
    }

    return 0;
}