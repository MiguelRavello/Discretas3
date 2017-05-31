#include<iostream>

using namespace std;

typedef unsigned int nat;
nat fun(nat&,nat&,nat&);

nat fun(nat &base,nat &exp,nat &mod){
    nat rpta;
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

int main(){
    nat a,b,c;
    a=4;
    b=21;
    c=7;
    cout<<fun(a,b,c);
    return 0;
}
