#ifndef GANTZ_H
#define GANTZ_H

#include<NTL/ZZ.h>
#include<algorithm>/*fill */
#include<cstdlib> /*size_t*/
#include<stdint.h> /*uint64_t*/
#include<string>
#include<sstream>
#include<vector>
using namespace std;
using namespace NTL;

typedef ZZ nat;
typedef uint16_t i16;
typedef uint64_t i64;
typedef unsigned int inat;
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
    istringstream ss(Text);
    T result;
    if(!(ss >> result))
        return 0;
    return result;
}

template<class T>
T minimo(T a,T b){
    if(a<=b)
        return a;
    return b;
}

struct Nodo{
    vector<nat> m_vector;
};
class Hash{
protected:
    i64 m_size;
    nat m_raiz;
    nat m_numero;
    Nodo *m_table;
public:
    Hash(nat numero):m_numero(numero){
        this->setSize();
        m_table=new Nodo[m_size+1];
        this->llenar();
    }
    ~Hash(){    delete[] m_table;}
    i64 getSize(){ return m_size;}
    vector<nat> getVector(i64 bit);
    nat getNumero(){    return m_numero;}
    void setSize();
    void push(i64 bit, nat value);
    void pop(i64 bit);
    void llenar();
    friend ostream& operator<<(ostream& out, Hash &m){
        for(i64 i=0;i<m.m_size;i++){
            if(m.m_table[i].m_vector.empty())
                continue;
            cout<<"iteracion: "<<i<<endl;
            for(vector<nat>::iterator it=m.m_table[i].m_vector.begin();it!=m.m_table[i].m_vector.end();++it)
                out<<' '<<*it;
            cout<<endl;
        }
        return out;
    }
};


#endif
