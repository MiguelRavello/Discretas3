#include<iostream>

using namespace std;

typedef unsigned int nat;
nat fun(nat,nat,nat);

nat fun(nat base,nat exp,nat mod){
    nat rpta=1;
    base%=mod;
    if(exp%2==1)
        rpta=base%mod;
    exp/=2;
    while(exp!=0){
        base=(base*base)%mod;
        if(exp%2==1)
            rpta=(base*rpta)%mod;
        exp/=2;
    }
    return rpta;
}

struct Generator{
    nat m_semilla;
    nat m_a;
    nat m_b;
    nat m_m;
    nat m_i;
    nat m_valor;
    Generator():m_semilla(0),m_a(0),m_b(0),m_m(0),m_i(0){}
    Generator(nat semilla,nat a,nat b,nat m, nat iteraciones):m_semilla(semilla),m_a(a),m_b(b),m_m(m),m_i(iteraciones){
        m_valor=m_semilla;
        for(nat i=0;i<m_i;i++){
            m_valor=(m_a*m_valor+m_b)%m_m;
        }
    }
    Generator(Generator &m):m_semilla(m.m_semilla),m_a(m.m_a),m_b(m.m_b),m_m(m.m_m),m_i(m.m_i),m_valor(m.m_valor){}
};

struct Leapfrog{
    Generator m_gen;
    nat m_n;
    nat m_xn;//valor a obtener
    nat m_an;
    nat m_bn;
    Leapfrog(nat semilla,nat a,nat b,nat m, nat iteraciones,nat n):m_n(n){
        Generator temp(semilla,a,b,m,iteraciones);
        m_gen=temp;
        m_xn=m_gen.m_valor;
        for(nat i=1;i<=m_n;i++){
            m_an=fun(m_gen.m_a,i,m_gen.m_m);
            m_bn=(m_gen.m_b * (m_an-1)/(m_gen.m_a-1))%m_gen.m_m;
            m_xn=(m_an*m_xn+m_bn)%m_gen.m_m;
        }
    }
};

int main(){
    Leapfrog a(1,2,1,13,8,1);
    nat r=a.m_xn;
    cout<<r;
    return 0;
}
