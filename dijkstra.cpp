#include<NTL/ZZ.h>
#include<omp.h>
#include<cstdio>
using namespace std;
using namespace NTL;

typedef ZZ nat;

nat mcd(nat &a,nat &b){
    if(a==0 || b==0)
        return a+b;
    else if(a>b){
        a%=b;
        return mcd(a,b);
    }
    else if(b>a){
        b%=a;
        return mcd(a,b);
    }
}
int main(){
    printf("-------- Simply count elapsed time (CountTime) -------\n");
    const double startTime = omp_get_wtime();
    nat a,b,c;
    a=9223372036854775800;
    b=4540737095516151000;
    int k,q;
    SetBit(a,63); //seteamos los bits de a 63 aunq sale despues 64
    SetBit(b,63); 
    k=NumBits(a); //verificamos con esta funcion los bits q se estan usando
    q=NumBits(b);
    c=mcd(a,b);
    cout<<"mcd: "<<c<<endl;
    cout<<"los bits de a: "<<k<<"\n"<<"los bits de b: "<<q<<endl;
    cout<<"los bytes de a: "<<sizeof(a)<<endl;
    cout<<"los bytes de b: "<<sizeof(b)<<endl;
    const double endTime = omp_get_wtime();
    printf("Duration = %lf seconds\n", (endTime - startTime));
    printf("------------------------------------------------------\n");
    return 0;
}

//g++ -g -O2 dijkstra.cpp -lgomp -o m -lntl -lgmp -lm
