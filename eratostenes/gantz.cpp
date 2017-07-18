#include"gantz.h"

vector<nat> Hash::getVector(i64 bit){
    return this->m_table[bit].m_vector;
}
void Hash::push(i64 bit, nat value){
    this->m_table[bit].m_vector.push_back(value);
}
void Hash::pop(i64 bit){
    if(m_table[bit].m_vector.empty())
        cout<<"vector vacio "<<endl;
    else
        m_table[bit].m_vector.pop_back();
}
void Hash::setSize(){
    m_raiz=SqrRoot(m_numero);
    string xs=NumberToString(m_raiz);
    m_size = StringToNumber<i64>(xs);
}
void Hash::llenar(){
    i64 segment_size=this->m_size;
    i64 s = 3;
    nat n(3);
  // generate small primes <= sqrt
    vector<char> is_prime(m_size + 1, 1);
    for (i64 i = 2; i * i <= m_size; i++)
        if (is_prime[i])
            for (i64 j = i * i; j <= m_size; j += i)
                is_prime[j] = 0;
  // vector used for sieving
    vector<char> sieve(segment_size);
    vector<int> primes;
    vector<int> next;
    i64 w=0;
    for (nat low(0); low <= m_numero; low += m_raiz){
        fill(sieve.begin(), sieve.end(), 1);
        nat high;
        high = minimo(low + m_raiz - 1,m_numero);
        for (; s * s <= high; s += 2){
            if (is_prime[s]){
                primes.push_back((inat) s);
                nat abc;
                abc = conv<ZZ>(s) * conv<ZZ>(s) - low;
                string rs=NumberToString(abc);
                inat s2=StringToNumber<inat>(rs);
                next.push_back(s2);
            }
        }
        for (size_t i = 0; i < primes.size(); i++){
            inat j = next[i];
            for (inat k = primes[i] * 2; j < segment_size; j += k)
                sieve[j] = 0;
            next[i] = j - segment_size;
        }
        for (; n <= high; n += 2){
            nat abc;
            abc=n-low;
            string xs=NumberToString(abc);
            inat pos=StringToNumber<inat>(xs);
            if (sieve[pos])
                this->push(w,n);
        }
        w++;
    }
}

int main(){
    nat n;
    n=100000000;
    Hash xs(n);
    return 0;
}
