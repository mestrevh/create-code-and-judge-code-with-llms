/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static long long modll(long long a, long long m){
    a %= m;
    if(a < 0) a += m;
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    if(!(cin >> s1 >> s2)) return 0;

    auto parseDate = [&](const string& s){
        int d = 0, m = 0, y = 0;
        int dd=0, mm=0, yy=0;
        if(sscanf(s.c_str(), "%d/%d/%d", &dd, &mm, &yy) == 3){
            d = dd; m = mm; y = yy;
        }
        return tuple<int,int,int>(d,m,y);
    };

    auto [d1, m1, y1] = parseDate(s1);
    auto [d2, m2, y2] = parseDate(s2);

    long long amor = 0;
    amor += d1 + m1 + y1 + d2 + m2 + y2;
    amor = modll(amor * 7, 101);

    long long diffY = y2 - y1;
    long long positiveDiff = llabs(diffY);
    long long sorte = 0;
    sorte += d1 + d2;
    sorte += (long long)m1 * 9;
    sorte += (long long)m2 * 9;
    sorte += positiveDiff;
    sorte = modll(sorte, 101);

    long long trabalho = 0;
    trabalho += y1 + y2;
    trabalho -= (long long)d1 * 8;
    trabalho -= (long long)m1 * 8;
    trabalho -= (long long)d2 * 8;
    trabalho -= (long long)m2 * 8;
    trabalho = modll(trabalho, 101);

    long long cor = 0;
    cor += (long long)d1 * d1 + (long long)m1 * m1 + (long long)y1 * y1;
    cor += (long long)d2 * d2 + (long long)m2 * m2 + (long long)y2 * y2;
    cor = modll(cor, 11);

    auto amorMessage = [&](long long p){
        if(p <= 20) return string("Um dia pouco inspirador para amar. Ps: Cuidado com a intensidade.");
        if(p <= 40) return string("Melhor manter o coracao <3 longe de perigo.");
        if(p <= 60) return string("Boas chances para amar hoje. Ps: Viva com calma e carinho.");
        if(p <= 80) return string("Um dia deslumbrantemente lindo para amar. Ps: Cuidado com a intensidade.");
        return string("Um dia perfeito para amar. Ps: Não deixe a paixão dominar sua razão.");
    };

    auto sorteMessage = [&](long long p){
        if(p <= 20) return string("Talvez não seja o melhor dia para ousar.");
        if(p <= 40) return string("Hoje pode ser um dia de sorte, mas com cautela.");
        if(p <= 60) return string("Um bom pressagio no ar. Se for arriscar, vai com leveza.");
        if(p <= 80) return string("Boas energias para tentar algo novo hoje.");
        return string("Hoje vale a pena arriscar. Sem tigrinho nem jogos de azar, por favor!");
    };

    auto trabalhoMessage = [&](long long p){
        if(p <= 20) return string("Pouca produtividade hoje. Organize e planeje o resto.");
        if(p <= 40) return string("Dia ok para o trabalho, sem grandes saltos.");
        if(p <= 60) return string("Boas vibracoes hoje, chances podem estar ao seu redor.");
        if(p <= 80) return string("Dia promissor: avance com confiança e foco.");
        return string("Excelente fase para trabalho e metas. Aproveite!");
    };

    auto corMessage = [&](long long k){
        static vector<string> names = {
            "Vermelho.", "Laranja.", "Amarelo.", "Verde.", "Azul.",
            "Indigo.", "Roxo.", "Rosa.", "Preto.", "Cinza.", "Branco."
        };
        if(0 <= k && k < (long long)names.size()) return names[(size_t)k];
        return string("Branco.");
    };

    cout << "Amor: " << (amor == 100 ? 100 : amor) << "% " << amorMessage(amor) << "\n";
    cout << "Sorte: " << (sorte == 100 ? 100 : sorte) << "% " << sorteMessage(sorte) << "\n";
    cout << "Trabalho: " << (trabalho == 100 ? 100 : trabalho) << "% " << trabalhoMessage(trabalho) << "\n";
    cout << "Cor: " << corMessage(cor) << "\n";

    return 0;
}