/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long V, P;
    if (!(cin >> V >> P)) return 0;

    double pi = 3.14;
    
    // Voltorb: diameter 0.5m = 50cm, so radius = 25cm
    double rV = 25.0;
    // Pokebola: diameter 7cm, so radius = 3.5cm
    double rP = 3.5;
    
    // Volume of sphere = (4/3) * pi * r^3
    double volV = (4.0 / 3.0) * pi * pow(rV, 3);
    double volP = (4.0 / 3.0) * pi * pow(rP, 3);
    
    // Pool base area: 5m x 4m = 500cm x 400cm
    double baseArea = 500.0 * 400.0;
    
    // Total volume of submerged objects in cm^3
    double totalVolume = (double)V * volV + (double)P * volP;
    
    // Height rise H = Volume / Area
    double H = totalVolume / baseArea;
    
    printf("Altura da piscina aumentou: %.1f cm\n", H);

    return 0;
}

