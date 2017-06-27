#ifndef CRIBA_H
#define CRIBA_H

#include<NTL/ZZ.h>
//#include<NTL/vector.h>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
using namespace NTL;

typedef ZZ nat;
typedef unsigned int int32;
//static int32 TABLA_SIZE=64;
//Usage: NumberToString ( Number );
template<typename T>
string NumberToString(T Number){
    ostringstream ss;
    ss << Number;
    return ss.str();
}
//Usage: StringToNumber<Type> ( String );
template<typename T>
T StringToNumber(const string &Text){
    nat a(0);
    istringstream ss(Text);
    T result;
    if(!(ss >> result))
        return a;
    return result;
}
//divisibilidad
bool div2(const nat&);
bool div3(string);
bool div5(string);
bool div7(string);
bool div11(string);
bool div13(string);
bool div17(string);
bool div19(string);
bool div29(string);
bool div31(string);
/*test de Miller-Rabin */
nat modulo(nat,nat,nat);
bool millerTest(nat,nat);
bool isPrime(nat,nat);

class Nodo{
public:
    int32 m_bit;
    vector<nat> m_vec;
    Nodo():m_bit(0){}
    Nodo(int32 bit):m_bit(bit){}
    Nodo(int32 bit,vector<nat> primos):m_bit(bit),m_vec(primos){}
    Nodo(Nodo &xs):m_bit(xs.m_bit),m_vec(xs.m_vec){}
};
class Hash{
private:
    int32 m_size;
    Nodo *m_table;
    nat m_numero;
public:
    Hash(nat numero):m_numero(numero){
        int32 h;
        h=NumBits(m_numero);
        m_size=h+1;
        numero=SqrRoot(numero);
        m_table=new Nodo[m_size];
        for(int32 i=0;i<m_size;i++)
            m_table[i].m_bit=i;
        this->llenar(numero);
        nat k(4);
        if(isPrime(m_numero,k))
            push(h,m_numero);
    }
    ~Hash(){
        delete[] m_table;
    }
    int32 getSize(){    return m_size;}
    vector<nat> getVector(int32 bit);
    nat getNumero(){    return m_numero;}
    void push(int32 bit, nat value);
    void push(int32 bit, vector<nat> primos);
    void pop(int32 bit);
    void llenar(nat numero);
    friend ostream& operator<<(ostream& out, Hash &m){
        for(int32 i=0;i < m.m_size;i++){
            if(m.m_table[i].m_vec.empty())
                continue;
            cout<<"numeros de : "<<i<<" bits"<<endl;
            for(vector<nat>::iterator it=m.m_table[i].m_vec.begin();it!=m.m_table[i].m_vec.end();++it)
                out<<' '<<*it;
            cout<<endl;
        }
        return out;
    }
};



#endif
