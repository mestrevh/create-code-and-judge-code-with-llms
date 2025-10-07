/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Time {
    string nome;
    int pts, vit, e, der, gp, gc, sg;

    Time(string n) : nome(n), pts(0), vit(0), e(0), der(0), gp(0), gc(0), sg(0) {}

    bool operator<(const Time& other) const {
        if (pts != other.pts) return pts > other.pts;
        if (vit != other.vit) return vit > other.vit;
        if (sg != other.sg) return sg > other.sg;
        if (gp != other.gp) return gp > other.gp;
        return nome < other.nome;
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    vector<Time> times;
    for (int i = 0; i < n; ++i) {
        string linha;
        getline(cin, linha);
        stringstream ss(linha);
        string timeCasa, timeVisitante, x;
        int golsCasa, golsVisitante;
        ss >> timeCasa >> golsCasa >> x >> golsVisitante >> timeVisitante;

        bool casaEncontrado = false, visitanteEncontrado = false;
        for (auto& time : times) {
            if (time.nome == timeCasa) {
                time.gp += golsCasa;
                time.gc += golsVisitante;
                if (golsCasa > golsVisitante) {
                    time.pts += 3;
                    time.vit++;
                } else if (golsCasa < golsVisitante) {
                    time.der++;
                } else {
                    time.pts++;
                    time.e++;
                }
                casaEncontrado = true;
            } else if (time.nome == timeVisitante) {
                time.gp += golsVisitante;
                time.gc += golsCasa;
                if (golsVisitante > golsCasa) {
                    time.pts += 3;
                    time.vit++;
                } else if (golsVisitante < golsCasa) {
                    time.der++;
                } else {
                    time.pts++;
                    time.e++;
                }
                visitanteEncontrado = true;
            }
        }

        if (!casaEncontrado) {
            Time novoTimeCasa(timeCasa);
            novoTimeCasa.gp += golsCasa;
            novoTimeCasa.gc += golsVisitante;
            if (golsCasa > golsVisitante) {
                novoTimeCasa.pts += 3;
                novoTimeCasa.vit++;
            } else if (golsCasa < golsVisitante) {
                novoTimeCasa.der++;
            } else {
                novoTimeCasa.pts++;
                novoTimeCasa.e++;
            }
            times.push_back(novoTimeCasa);
        }
        if (!visitanteEncontrado) {
            Time novoTimeVisitante(timeVisitante);
            novoTimeVisitante.gp += golsVisitante;
            novoTimeVisitante.gc += golsCasa;
            if (golsVisitante > golsCasa) {
                novoTimeVisitante.pts += 3;
                novoTimeVisitante.vit++;
            } else if (golsVisitante < golsCasa) {
                novoTimeVisitante.der++;
            } else {
                novoTimeVisitante.pts++;
                novoTimeVisitante.e++;
            }
            times.push_back(novoTimeVisitante);
        }
    }

    for(auto& time : times) {
        time.sg = time.gp - time.gc;
    }

    sort(times.begin(), times.end());

    for (int i = 0; i < times.size(); ++i) {
        cout << i + 1 << ". " << times[i].nome << " " << times[i].pts << " " << times[i].vit << " " << times[i].e << " " << times[i].der << " " << times[i].gp << " " << times[i].gc << " " << times[i].sg << endl;
    }

    return 0;
}
