/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline bool isVar(const string& s){ return s.size()==2 && s[0]=='R' && isdigit((unsigned char)s[1]); }
static inline int varIdx(const string& s){ return s[1]-'0'; }

struct Opnd{
    bool isVar;
    int idx;
    int val;
};

struct Instr{
    string type;
    Opnd a,b;
    int lineNext=-1;
    int lineJump=-1;
};

static inline int mod1000(int x){
    x%=1000;
    if(x<0) x+=1000;
    return x;
}

struct State{
    uint16_t pc;
    array<uint16_t,10> r;
};

struct KeyHash{
    size_t operator()(State const& s) const noexcept{
        size_t h = s.pc;
        for(int i=0;i<10;i++) h = h*1009u + s.r[i];
        return h;
    }
};
struct KeyEq{
    bool operator()(State const& x, State const& y) const noexcept{
        if(x.pc!=y.pc) return false;
        return x.r==y.r;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L,N;
    while(true){
        if(!(cin>>L>>N)) return 0;
        if(L==0 && N==0) break;

        string line;
        vector<Instr> prog(L+1);
        for(int i=1;i<=L;i++){
            cin>>line;
            string op = line;
            Instr in;
            in.type = op;

            if(op=="MOV"||op=="ADD"||op=="SUB"||op=="MUL"||op=="DIV"||op=="MOD"||
               op=="IFEQ"||op=="IFNEQ"||op=="IFG"||op=="IFL"||op=="IFGE"||op=="IFLE"){
                string s1,s2; cin>>s1>>s2;
                auto parse = [&](const string& s)->Opnd{
                    if(isVar(s)){
                        return Opnd{true,varIdx(s),0};
                    }else{
                        int v=stoi(s);
                        return Opnd{false,0,v};
                    }
                };
                in.a=parse(s1);
                in.b=parse(s2);
                prog[i]=in;
            }else if(op=="CALL"||op=="RET"){
                string s1; cin>>s1;
                auto parse = [&](const string& s)->Opnd{
                    if(isVar(s)){
                        return Opnd{true,varIdx(s),0};
                    }else{
                        int v=stoi(s);
                        return Opnd{false,0,v};
                    }
                };
                in.a=parse(s1);
                prog[i]=in;
            }else if(op=="ENDIF"){
                in.type="ENDIF";
                prog[i]=in;
            }else{
                prog[i]=in;
            }
        }

        vector<int> stack;
        for(int i=1;i<=L;i++){
            if(prog[i].type=="IFEQ"||prog[i].type=="IFNEQ"||prog[i].type=="IFG"||prog[i].type=="IFL"||
               prog[i].type=="IFGE"||prog[i].type=="IFLE"){
                stack.push_back(i);
            }else if(prog[i].type=="ENDIF"){
                int start = stack.back(); stack.pop_back();
                prog[start].lineNext = i+1;
                prog[start].lineJump = i+1;
                prog[i].lineNext = i+1;
            }
        }
        for(int i=1;i<=L;i++){
            if(prog[i].type=="IFEQ"||prog[i].type=="IFNEQ"||prog[i].type=="IFG"||prog[i].type=="IFL"||
               prog[i].type=="IFGE"||prog[i].type=="IFLE"){
                int end = prog[i].lineNext-1;
                prog[i].lineJump = prog[i].lineNext;
            }
        }

        auto evalOpnd = [&](const array<int,10>& r, const Opnd& o)->int{
            if(o.isVar) return r[o.idx];
            return mod1000(o.val);
        };

        auto step = [&](const State& st)->pair<bool,int>{
            array<int,10> r;
            for(int i=0;i<10;i++) r[i]=st.r[i];
            int pc=st.pc;
            while(true){
                if(pc<1 || pc>L) return {false,-1};
                Instr const& in=prog[pc];
                if(in.type=="MOV"){
                    int v2=evalOpnd(r,in.b);
                    r[in.a.idx]=v2;
                    r[in.a.idx]=mod1000(r[in.a.idx]);
                    pc++;
                }else if(in.type=="ADD"){
                    int v2=evalOpnd(r,in.b);
                    r[in.a.idx]=mod1000(r[in.a.idx]+v2);
                    pc++;
                }else if(in.type=="SUB"){
                    int v2=evalOpnd(r,in.b);
                    r[in.a.idx]=mod1000(r[in.a.idx]-v2);
                    pc++;
                }else if(in.type=="MUL"){
                    int v2=evalOpnd(r,in.b);
                    r[in.a.idx]=mod1000(r[in.a.idx]*v2);
                    pc++;
                }else if(in.type=="DIV"){
                    int v2=evalOpnd(r,in.b);
                    int cur=r[in.a.idx];
                    if(v2==0 || cur==0) r[in.a.idx]=0;
                    else r[in.a.idx]=mod1000(cur/v2);
                    pc++;
                }else if(in.type=="MOD"){
                    int v2=evalOpnd(r,in.b);
                    int cur=r[in.a.idx];
                    if(v2==0 || cur==0) r[in.a.idx]=0;
                    else r[in.a.idx]=mod1000(cur%v2);
                    pc++;
                }else if(in.type=="IFEQ"||in.type=="IFNEQ"||in.type=="IFG"||in.type=="IFL"||in.type=="IFGE"||in.type=="IFLE"){
                    int v1=evalOpnd(r,in.a);
                    int v2=evalOpnd(r,in.b);
                    bool cond=false;
                    if(in.type=="IFEQ") cond = (v1==v2);
                    else if(in.type=="IFNEQ") cond = (v1!=v2);
                    else if(in.type=="IFG") cond = (v1>v2);
                    else if(in.type=="IFL") cond = (v1<v2);
                    else if(in.type=="IFGE") cond = (v1>=v2);
                    else if(in.type=="IFLE") cond = (v1<=v2);
                    if(cond) pc++;
                    else pc=in.lineNext;
                }else if(in.type=="ENDIF"){
                    pc++;
                }else if(in.type=="CALL"){
                    int param=evalOpnd(r,in.a);
                    State next;
                    next.pc = (uint16_t)1;
                    for(int i=0;i<10;i++) next.r[i]=0;
                    next.r[0]=(uint16_t)param;
                    for(int i=0;i<10;i++){
                        if(i==0) continue;
                        next.r[i]=(uint16_t)0;
                    }
                    return {true,(int)pc}; 
                }else if(in.type=="RET"){
                    int retv=evalOpnd(r,in.a);
                    return {false,retv};
                }else{
                    pc++;
                }
                if(pc>L) return {false,-1};
                break;
            }
            return {false,-1};
        };

        unordered_map<State,int,KeyHash,KeyEq> vis;
        struct Frame{ uint16_t pcAfter; array<uint16_t,10> callerR; };
        vector<Frame> callstack;

        State st;
        st.pc=1;
        for(int i=0;i<10;i++) st.r[i]=0;
        st.r[0]=(uint16_t)mod1000(N);

        int answer;
        bool finished=false, star=false;

        while(true){
            if(vis.find(st)!=vis.end()){
                star=true;
                break;
            }
            vis[st]=1;

            Instr const& in=prog[st.pc];
            array<int,10> r;
            for(int i=0;i<10;i++) r[i]=st.r[i];

            if(in.type=="MOV"){
                int v2=evalOpnd(r,in.b);
                r[in.a.idx]=mod1000(v2);
                st.pc++;
                for(int i=0;i<10;i++) st.r[i]=r[i];
            }else if(in.type=="ADD"){
                int v2=evalOpnd(r,in.b);
                r[in.a.idx]=mod1000(r[in.a.idx]+v2);
                st.pc++;
                for(int i=0;i<10;i++) st.r[i]=r[i];
            }else if(in.type=="SUB"){
                int v2=evalOpnd(r,in.b);
                r[in.a.idx]=mod1000(r[in.a.idx]-v2);
                st.pc++;
                for(int i=0;i<10;i++) st.r[i]=r[i];
            }else if(in.type=="MUL"){
                int v2=evalOpnd(r,in.b);
                r[in.a.idx]=mod1000(r[in.a.idx]*v2);
                st.pc++;
                for(int i=0;i<10;i++) st.r[i]=r[i];
            }else if(in.type=="DIV"){
                int v2=evalOpnd(r,in.b);
                int cur=r[in.a.idx];
                if(v2==0 || cur==0) r[in.a.idx]=0;
                else r[in.a.idx]=mod1000(cur/v2);
                st.pc++;
                for(int i=0;i<10;i++) st.r[i]=r[i];
            }else if(in.type=="MOD"){
                int v2=evalOpnd(r,in.b);
                int cur=r[in.a.idx];
                if(v2==0 || cur==0) r[in.a.idx]=0;
                else r[in.a.idx]=mod1000(cur%v2);
                st.pc++;
                for(int i=0;i<10;i++) st.r[i]=r[i];
            }else if(in.type=="IFEQ"||in.type=="IFNEQ"||in.type=="IFG"||in.type=="IFL"||in.type=="IFGE"||in.type=="IFLE"){
                int v1=evalOpnd(r,in.a);
                int v2=evalOpnd(r,in.b);
                bool cond=false;
                if(in.type=="IFEQ") cond = (v1==v2);
                else if(in.type=="IFNEQ") cond = (v1!=v2);
                else if(in.type=="IFG") cond = (v1>v2);
                else if(in.type=="IFL") cond = (v1<v2);
                else if(in.type=="IFGE") cond = (v1>=v2);
                else if(in.type=="IFLE") cond = (v1<=v2);
                st.pc = cond ? (st.pc+1) : (uint16_t)in.lineNext;
                for(int i=0;i<10;i++) st.r[i]=r[i];
            }else if(in.type=="ENDIF"){
                st.pc++;
            }else if(in.type=="CALL"){
                int param=evalOpnd(r,in.a);
                Frame fr;
                fr.pcAfter = (uint16_t)(st.pc+1);
                fr.callerR = st.r;
                callstack.push_back(fr);

                st.pc=1;
                for(int i=0;i<10;i++) st.r[i]=0;
                st.r[0]=(uint16_t)param;
            }else if(in.type=="RET"){
                int retv=evalOpnd(r,in.a);
                if(callstack.empty()){
                    answer=retv;
                    finished=true;
                    break;
                }else{
                    Frame fr=callstack.back();
                    callstack.pop_back();
                    fr.callerR[9]=(uint16_t)retv;
                    st=State{fr.pcAfter, fr.callerR};
                }
            }else{
                st.pc++;
            }
        }

        if(star) cout<<"*\n";
        else cout<<answer<<"\n";
    }
    return 0;
}