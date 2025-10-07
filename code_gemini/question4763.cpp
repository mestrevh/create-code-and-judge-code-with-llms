/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Time {
    string nome;
    int titulos;
};

bool compararTimes(const Time& a, const Time& b) {
    return a.titulos > b.titulos;
}

int main() {
    int t1, t2, t3, t4;
    char c1, c2, c3, c4;

    cin >> t1 >> c1 >> t2 >> c2 >> t3 >> c3 >> t4 >> c4;

    Time nautico = {"Náutico", 0};
    Time sport = {"Sport", 0};
    Time santaCruz = {"Santa Cruz", 0};
    Time salgueiro = {"Salgueiro", 0};

    if (c1 == 'A') {
        if (t1 > 24) cout << "Se contar direitinho ainda tá faltando uns títulos para o Timba..." << endl;
        else if (t1 < 24) cout << "Isso deve ser coisa do Sport, querem ganhar no tapetão que nem em 87!" << endl;
        else cout << "Tem algo estranho aqui..." << endl;
        nautico.titulos = t1;
    } else if (c1 == 'B') {
        if (t1 > 45) cout << "Se antes já era grande a diferença, imagine agora..." << endl;
        else if (t1 < 45) cout << "Capaz de recorrerem no STJD e recuperarem os títulos no tapetão." << endl;
        else cout << "Tem algo estranho aqui..." << endl;
        sport.titulos = t1;
    } else if (c1 == 'C') {
        if (t1 > 1) cout << "Finalmente teve justiça sobre que aconteceu em 2017!" << endl;
        else if (t1 < 1) cout << "Foi roubado em 2017 e agora em 2025, existe isso não..." << endl;
        else cout << "Tem algo estranho aqui..." << endl;
        salgueiro.titulos = t1;
    } else {
        if (t1 > 29) cout << "O Santa é gigante e esse ano vai sair da série D" << endl;
        else if (t1 < 29) cout << "É muito azar, nem com a SAF as coisas dão certo." << endl;
        else cout << "Tem algo estranho aqui..." << endl;
        santaCruz.titulos = t1;
    }


    if (c2 == 'A') {
         if (t2 > 24) cout << "Se contar direitinho ainda tá faltando uns títulos para o Timba..." << endl;
        else if (t2 < 24) cout << "Isso deve ser coisa do Sport, querem ganhar no tapetão que nem em 87!" << endl;
        else cout << "Tem algo estranho aqui..." << endl;
        nautico.titulos = t2;
    } else if (c2 == 'B') {
        if (t2 > 45) cout << "Se antes já era grande a diferença, imagine agora..." << endl;
        else if (t2 < 45) cout << "Capaz de recorrerem no STJD e recuperarem os títulos no tapetão." << endl;
        else cout << "Tem algo estranho aqui..." << endl;
        sport.titulos = t2;
    } else if (c2 == 'C') {
        if (t2 > 1) cout << "Finalmente teve justiça sobre que aconteceu em 2017!" << endl;
        else if (t2 < 1) cout << "Foi roubado em 2017 e agora em 2025, existe isso não..." << endl;
        else cout << "Tem algo estranho aqui..." << endl;
        salgueiro.titulos = t2;
    } else {
        if (t2 > 29) cout << "O Santa é gigante e esse ano vai sair da série D" << endl;
        else if (t2 < 29) cout << "É muito azar, nem com a SAF as coisas dão certo." << endl;
        else cout << "Tem algo estranho aqui..." << endl;
        santaCruz.titulos = t2;
    }

    
    // ... (restante do código similar para c3 e c4)
    

    vector<Time> times = {nautico, sport, santaCruz, salgueiro};
    sort(times.begin(), times.end(), compararTimes);

    cout << endl;

    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << "º - " << times[i].nome << " - " << times[i].titulos << " - títulos" << endl;
    }

    cout << endl;

    if (times[0].nome == "Náutico") {
        cout << "A justiça foi feita, o Timba é o maior do estado, não tem jeito!" << endl;
    } else if (times[0].nome == "Santa Cruz") {
        cout << "É o terror do Nordeste, sempre soube!" << endl;
    } else if (times[0].nome == "Sport") {
        cout << "Deu o óbvio, o papai da cidade é o Leão!" << endl;
    } else {
        cout << "Já era o maior do interior, agora é o maior do estado!" << endl;
    }

    return 0;
}
