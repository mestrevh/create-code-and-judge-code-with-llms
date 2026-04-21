/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long V, P;
    if (!(cin >> V >> P)) return 0;

    const double PI = 3.14;
    const double BASE_AREA = 500.0 * 400.0; // Pool dimensions: 5m x 4m = 500cm x 400cm

    // Voltorb: height 0.5m = 50cm diameter => radius = 25cm
    const double rV = 25.0;
    // Pokeball: 7cm diameter => radius = 3.5cm
    const double rP = 3.5;

    // Volume of a sphere = (4/3) * PI * r^3
    double volumeV = (4.0 / 3.0) * PI * rV * rV * rV;
    double volumeP = (4.0 / 3.0) * PI * rP * rP * rP;

    double totalDisplacedVolume = (static_cast<double>(V) * volumeV) + (static_cast<double>(P) * volumeP);
    
    // Height increase H = Volume / Area
    double H = totalDisplacedVolume / BASE_AREA;

    cout << "Altura da piscina aumentou: " << fixed << setprecision(1) << H << " cm" << endl;

    return 0;
}