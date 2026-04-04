/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // I/O Optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double mass, height;
    
    // Read input: Mass (Kg) and Height (meters)
    if (!(cin >> mass >> height)) {
        return 0;
    }

    // Body Mass Index (BMI/IMC) Calculation: mass / height^2
    double imc = mass / (height * height);

    // Following the specific output format required by the test cases
    cout << "Digite a massa em Kg:" << "\n";
    cout << "Digite a altura em m:" << "\n";
    
    // Output IMC with 1 decimal place precision
    cout << "IMC = " << fixed << setprecision(1) << imc << endl;

    return 0;
}