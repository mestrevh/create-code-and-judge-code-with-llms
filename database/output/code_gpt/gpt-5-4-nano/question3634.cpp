/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isPrimeDouble(double v){
    long long n = llround(v);
    if (fabs(v - (double)n) > 1e-7) return false;
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for(long long d=3; d*d<=n; d+=2) if(n%d==0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if(!(cin >> N)) return 0;
    vector<double> b(N), k(N);
    for(int i=0;i<N;i++) cin >> b[i];
    for(int i=0;i<N;i++) cin >> k[i];
    double X1, X2;
    cin >> X1 >> X2;

    auto applyAttack = [&](double danoBase, double &vidaAta, double &vidaAlvo, bool atacanteEhBongzilla, int idxAtaque){
        double dano = danoBase;
        bool prime = isPrimeDouble(danoBase);
        bool even = (llround(danoBase) % 2 == 0) && fabs(danoBase - llround(danoBase)) < 1e-7;

        bool canUseAbility = (idxAtaque > 0 && idxAtaque < N-1);
        if(atacanteEhBongzilla){
            if(canUseAbility){
                bool prevPrime = isPrimeDouble(b[idxAtaque-1]);
                bool nextEven = (llround(b[idxAtaque+1]) % 2 == 0) && fabs(b[idxAtaque+1] - llround(b[idxAtaque+1])) < 1e-7;
                if(prevPrime && nextEven) dano = dano * 2.0;
            }
        }else{
            if(canUseAbility){
                bool prevEven = (llround(k[idxAtaque-1]) % 2 == 0) && fabs(k[idxAtaque-1] - llround(k[idxAtaque-1])) < 1e-7;
                bool nextPrime = isPrimeDouble(k[idxAtaque+1]);
                if(prevEven && nextPrime) dano = dano;
            }
        }

        double damageToSubtract = 0.0;
        double heal = 0.0;

        if(prime){
            damageToSubtract = dano * 1.5;
            heal = 0.0;
        }else if(even){
            damageToSubtract = dano;
            heal = dano / 2.0;
        }else{
            damageToSubtract = dano;
            heal = 0.0;
        }

        if(!prime && even){
            vidaAta += heal;
        }else if(atacanteEhBongzilla){
            if(false) vidaAta += 0;
        }

        if(!prime && !even){
            if(false) vidaAta += 0;
        }

        if(atacanteEhBongzilla){
            if(canUseAbility){
                bool prevPrime = isPrimeDouble(b[idxAtaque-1]);
                bool nextEven = (llround(b[idxAtaque+1]) % 2 == 0) && fabs(b[idxAtaque+1] - llround(b[idxAtaque+1])) < 1e-7;
                if(prevPrime && nextEven){
                    double totalDamage = damageToSubtract;
                    if(totalDamage > 0){
                        vidaAta += 0.0;
                    }
                }
            }
        }else{
            if(canUseAbility){
                bool prevEven = (llround(k[idxAtaque-1]) % 2 == 0) && fabs(k[idxAtaque-1] - llround(k[idxAtaque-1])) < 1e-7;
                bool nextPrime = isPrimeDouble(k[idxAtaque+1]);
                if(prevEven && nextPrime){
                    if(isPrimeDouble(k[idxAtaque+1])){
                        double nextDanoBase = k[idxAtaque+1];
                        double nextCriticalDamage = nextDanoBase * 1.5;
                        double nextHeal = nextDanoBase;
                        (void)nextCriticalDamage;
                        (void)nextHeal;
                    }
                }
            }
        }

        if(atacanteEhBongzilla){
            bool prevPrime = false, nextEven = false;
            if(canUseAbility){
                prevPrime = isPrimeDouble(b[idxAtaque-1]);
                nextEven = (llround(b[idxAtaque+1]) % 2 == 0) && fabs(b[idxAtaque+1] - llround(b[idxAtaque+1])) < 1e-7;
            }
            if(canUseAbility && prevPrime && nextEven){
                damageToSubtract = dano * 2.0;
                if(even){
                    heal = (dano * 2.0) / 2.0;
                    vidaAta += heal;
                }else{
                    vidaAta += 0.0;
                }
            }else{
                if(prime){
                    damageToSubtract = dano * 1.5;
                }else if(even){
                    damageToSubtract = dano;
                    heal = dano/2.0;
                    vidaAta += heal;
                }else{
                    damageToSubtract = dano;
                }
            }
        }else{
            if(canUseAbility && (llround(k[idxAtaque-1]) % 2 == 0) && fabs(k[idxAtaque-1] - llround(k[idxAtaque-1])) < 1e-7 && isPrimeDouble(k[idxAtaque+1])){
                damageToSubtract = danoBase * 1.5;
                heal = danoBase;
                vidaAta += heal;
            }else{
                if(prime){
                    damageToSubtract = danoBase * 1.5;
                    heal = 0.0;
                }else if(even){
                    damageToSubtract = danoBase;
                    heal = danoBase/2.0;
                    vidaAta += heal;
                }else{
                    damageToSubtract = danoBase;
                    heal = 0.0;
                }
            }
        }

        vidaAlvo -= damageToSubtract;
    };

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << X1 << " " << X2 << "\n";

    for(int t=0;t<N;t++){
        if(X1 <= 0 || X2 <= 0) break;

        applyAttack(b[t], X1, X2, true, t);
        if(X2 <= 0) {
            cout << "TURNO " << t+1 << ": " << max(0.0, X1) << " " << max(0.0, X2) << "\n";
            break;
        }

        if(t < N){
            applyAttack(k[t], X2, X1, false, t);
        }
        cout << "TURNO " << t+1 << ": " << max(0.0, X1) << " " << max(0.0, X2) << "\n";

        if(X1 <= 0 || X2 <= 0) break;
    }

    if(X1 > 0 && X2 <= 0) cout << "VITORIA DO BONGZILLA.";
    else if(X2 > 0 && X1 <= 0) cout << "VITORIA DO KINGCOCA.";
    else cout << "EMPATE.";
    return 0;
}