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
    m_size = (i64)sqrt(m_numero);
}
void Hash::llenar(){
    i64 segment_size=this->m_size;
    i64 s = 3;
    i64 n = 3;
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
    for (nat low(0); low <= m_numero; low += segment_size){
        fill(sieve.begin(), sieve.end(), 1);
        nat high = min(low + segment_size - 1,m_numero);
        /*if(high<256){
            n=(i8) n;
            s=(i8) s;
        }
        else if(high<65536){
            n=(i16) n;
            s=(i16) s;
        }
        else if(high<4294967296){
            n=(i32) n;
            s=(i32) s;
        }
        else{
            n=(i64) n;
            s=(i64) s;
        }*/
        for (; s * s <= high; s += 2){
            if (is_prime[s]){
                primes.push_back((inat) s);
                next.push_back((inat)s*s-low);
            }
        }
        for (size_t i = 0; i < primes.size(); i++){
            inat j = next[i];
            for (inat k = primes[i] * 2; j < segment_size; j += k)
                sieve[j] = 0;
            next[i] = j - segment_size;
        }
        for (; n <= high; n += 2){
            if (sieve[n-low])
                this->m_table[w].m_vector.push_back(n);
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
