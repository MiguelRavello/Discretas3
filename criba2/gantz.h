#ifndef GANTZ_H
#define GANTZ_H

//#include<NTL/ZZ.h>
#include<iostream>
#include<algorithm>/*fill */
#include<cstdlib> /*size_t*/
#include<stdint.h> /*uint64_t*/
#include<cmath>
#include<vector>

using namespace std;
//using namespace NTL;
typedef uint64_t nat;
typedef uint8_t i8;
typedef uint16_t i16;
typedef uint32_t i32;
typedef uint64_t i64;
typedef unsigned int inat;

struct Nodo{
    vector<nat> m_vector;
};

class Hash{
protected:
    i64 m_size;
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
