/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {
    map<string, int> height_classes = {{"<1.50", 0}, {"1.50-1.59", 0}, {"1.60-1.69", 0}, {"1.70-1.79", 0}, {"1.80-1.89", 0}, {">=1.90", 0}};
    vector<int> age_counts(19, 0);
    int male_count = 0, female_count = 0;

    while (true) {
        double height;
        int age;
        char sex;

        cout << "Digite a altura do entrevistado:\n";
        cin >> height;
        if (height == 0) break;
        cout << "Digite a idade do entrevistado:\n";
        cin >> age;
        cout << "Digite o sexo do entrevistado (M ou F):\n";
        cin >> sex;

        if (age >= 0 && age <= 18) age_counts[age]++;
        if (sex == 'M') male_count++;
        else if (sex == 'F') female_count++;

        if (height < 1.50) height_classes["<1.50"]++;
        else if (height < 1.60) height_classes["1.50-1.59"]++;
        else if (height < 1.70) height_classes["1.60-1.69"]++;
        else if (height < 1.80) height_classes["1.70-1.79"]++;
        else if (height < 1.90) height_classes["1.80-1.89"]++;
        else height_classes[">=1.90"]++;
    }
    
    // Gráfico de barras horizontais para as classes de altura
    system("gnuplot -e \"set terminal png; set output 'altura.png'; set title 'Classes de Altura'; set xlabel 'Quantidade'; set ylabel 'Classes de Altura'; set style fill solid; plot '-' using 2:xtic(1) with boxes ls 1\"");

    for (const auto& hc : height_classes) {
        cout << hc.first << " " << hc.second << "\n";
        cout << hc.first << " " << hc.second << "\n";
    }
    cout << "e\n";

    // Gráfico de barras verticais para idades
    system("gnuplot -e \"set terminal png; set output 'idade.png'; set title 'Quantidade de Pessoas por Idade'; set xlabel 'Idade'; set ylabel 'Quantidade'; plot '-' using 1:2 with linespoints\"");

    for (int i = 0; i < 19; i++) {
        cout << i << " " << age_counts[i] << "\n";
    }
    cout << "e\n";

    // Gráfico de pizza para sexo
    system("gnuplot -e \"set terminal png; set output 'sexo.png'; set title 'Distribuição de Sexo'; set style fill solid; plot '-' using 2:1 with boxes\""); 

    cout << "M " << male_count << "\n";
    cout << "F " << female_count << "\n";
    cout << "e\n";

    return 0;
}
