#include"criba.h"
//k=NumBits(x);
bool div2(const nat &num){
    const nat a(1);
    nat r;
    r=num & a;
    if(r==0)
        return true;
    return false;
}
bool div3(string xs){
    nat rpta(0);
    //const nat b(1);
    for(string::iterator it=xs.begin();it!=xs.end();it++){
        string t1;
        t1+=*it;
        rpta+=StringToNumber<nat>(t1);
    }
    while(rpta>100){
        string ys=NumberToString(rpta);
        rpta=0;
        for(string::iterator jt=ys.begin();jt!=ys.end();jt++){
            string t2;
            t2+=*jt;
            rpta+=StringToNumber<nat>(t2);
        }
    }
    if(rpta%3==0)
        return true; //true b=1
    return false; //false b=0
}
bool div5(string xs){
    //const nat b(1);
    //string ax=xs.substr(xs.length()-1);
    char ax;
    string::iterator it=xs.end()-1;
    ax=*it;
    if(ax=='0' || ax=='5')
        return true;
    return false;
}
bool div7(string xs){
    //const nat b(1);
    nat num;
    while(xs.length()>2){
        string ax=xs.substr(xs.length()-1);
        xs.erase(xs.length()-1);
        num=StringToNumber<nat>(xs);
        nat ber=StringToNumber<nat>(ax);
        num-=2*ber;
        xs.clear();
        xs=NumberToString(num);
    }
    if(num%7==0)
        return true;
    return false;
}
bool div11(string xs){
    //nat b(1);
    nat x(0);
    nat y(0);
    string::iterator it=xs.begin();
    string::iterator jt=xs.begin()+1;
    while(true){
        if(it==xs.end())
            break;
        if(jt==xs.end())
            break;
        string t1;
        string t2;
        t1+=*it;
        t2+=*jt;
        x+=StringToNumber<nat>(t1);
        y+=StringToNumber<nat>(t2);
        it+=2;
        jt+=2;
    }
    if(it!=xs.end()){
        string t3;
        t3+=*it;
        x+=StringToNumber<nat>(t3);
    }
    x-=y;
    if(x%11==0)
        return true;
    return false;
}
bool div13(string xs){
    //const nat b(1);
    nat num;
    while(xs.length()>2){
        string ax=xs.substr(xs.length()-1);
        xs.erase(xs.length()-1);
        num=StringToNumber<nat>(xs);
        nat ber=StringToNumber<nat>(ax);
        num-=9*ber;
        xs.clear();
        xs=NumberToString(num);
    }
    if(num%13==0)
        return true;
    return false;
}
bool div17(string xs){
    //const nat b(1);
    nat num;
    while(xs.length()>2){
        string ax=xs.substr(xs.length()-1);
        xs.erase(xs.length()-1);
        num=StringToNumber<nat>(xs);
        nat ber=StringToNumber<nat>(ax);
        num-=5*ber;
        xs.clear();
        xs=NumberToString(num);
    }
    if(num%17==0)
        return true;
    return false;
}
bool div19(string xs){
    //const nat b(1);
    nat num;
    while(xs.length()>2){
        string ax=xs.substr(xs.length()-1);
        xs.erase(xs.length()-1);
        num=StringToNumber<nat>(xs);
        nat ber=StringToNumber<nat>(ax);
        num+=2*ber;
        xs.clear();
        xs=NumberToString(num);
    }
    if(num%19==0)
        return true;
    return false;
}
bool div29(string xs){
    //const nat b(1);
    nat num;
    while(xs.length()>2){
        string ax=xs.substr(xs.length()-1);
        xs.erase(xs.length()-1);
        num=StringToNumber<nat>(xs);
        nat ber=StringToNumber<nat>(ax);
        num+=3*ber;
        xs.clear();
        xs=NumberToString(num);
    }
    if(num%29==0)
        return true;
    return false;
}
bool div31(string xs){
    //const nat b(1);
    nat num;
    while(xs.length()>2){
        string ax=xs.substr(xs.length()-1);
        xs.erase(xs.length()-1);
        num=StringToNumber<nat>(xs);
        nat ber=StringToNumber<nat>(ax);
        num-=3*ber;
        xs.clear();
        xs=NumberToString(num);
    }
    if(num%31==0)
        return true;
    return false;
}
/*Test de Miller-Rabin */
// base^exp % mod
nat modulo(nat base,nat exp,nat mod){
    nat rpta(1);
    nat b(1);
    nat c;
    c=exp & b;
    base%=mod;
    if(c==1)
        rpta=base%mod;
    exp>>=1;
    while(exp > 0){
        base=(base*base)%mod;
        c=exp & b;
        if(c==1)
            rpta=(base*rpta)%mod;
        exp>>=1;
    }
    return rpta;
}
bool millerTest(nat d,nat n){
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    nat a;
    a = 2 + RandomBnd(n - 4);
    // Compute a^d % n
    nat x;
    x = modulo(a, d, n);
    if (x == 1  || x == n-1)
       return true;
    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n-1){
        x = (x * x) % n;
        d *= 2;
        if (x == 1)
            return false;
        if (x == n-1)
            return true;
    }
    // Return composite
    return false;
}
bool isPrime(nat n,nat k){
    // Corner cases
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;
    // Find r such that n = 2^d * r + 1 for some r >= 1
    nat d;
    d=n-1;
    while (div2(d))
        d>>=1;
    // Iterate given nber of 'k' times
    for (nat i(0);i<k;i++)
         if (millerTest(d, n) == false)
              return false;
    return true;
}
vector<nat> Hash::getVector(int32 bit){
    return this->m_table[bit].m_vec;
}
void Hash::push(int32 bit,nat value){
    this->m_table[bit].m_vec.push_back(value);
}
void Hash::push(int32 bit,vector<nat> primos){
    if(m_table[bit].m_vec.empty())
        m_table[bit].m_vec=primos;
}
void Hash::pop(int32 bit){
    if(m_table[bit].m_vec.empty())
        cout<<"esta vacio el vector \n";
    else
        m_table[bit].m_vec.pop_back();
}
void Hash::llenar(nat numero){
    vector<bool (*)(string)> funcion;
    funcion.push_back(div3);
    funcion.push_back(div5);
    funcion.push_back(div7);
    funcion.push_back(div11);
    funcion.push_back(div13);
    funcion.push_back(div17);
    funcion.push_back(div19);
    funcion.push_back(div29);
    funcion.push_back(div31);

    nat k(4);
    int32 h;
    for(nat n(1); n < numero; n++){
        h=NumBits(n);
        if(isPrime(n, k))
            push(h,n);
    }
    //numero=SqrRoot(numero);
    for(nat i(100);i<=numero;i++){
        h=NumBits(i);
        if(div2(i))
            continue;
        string ms=NumberToString(i);
        /*if(div11(ms))
            continue;*/
        vector<bool (*)(string)>::iterator it=funcion.begin();
        while(it!=funcion.end()){
            if((*it)(ms))
                break;
            it++;
        }
        if(it!=funcion.end()){
            if((*it)(ms))
                continue;
        }
        if(isPrime(i,k)){
            push(h,i);
        }
    }
}

int main(){
    nat x(654527654527);
    Hash p(x);
    cout<<p;
    /*vector<nat> v=p.getVector(8);
    for(vector<nat>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<' ';
    }*/
    /*
    nat test(1024);
    string ms=NumberToString(test);
    string ax = ms.substr(ms.length()-1);
    nat numer=StringToNumber<nat>(ax);
    cout<<div11(ms)<<endl;
    nat k(4);  // Number of iterations
 
    cout << "All primes smaller than 100: \n";
    for (nat n(1); n < 100; n++)
       if (isPrime(n, k))
          cout << n << " ";*/
    return 0;
}


