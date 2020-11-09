#include<bits/stdc++.h>
using namespace std;
#define MAX 32000               //our given maximum value is 10^9...and sqrt(10^9) = 31266.77
typedef long long ll;

vector<int>* sieve(){
    bool isPrime[MAX];
    for(int i=0; i<MAX; i++){
        isPrime[i] = true;      //initially declaring all as prime
    }
    for(int i=2; i*i<MAX; i++){ //looping for sqrt(MAX) times...according to sieve's algorithm
        if(isPrime[i]){
            for(int j = i*i; j < MAX; j += i){
                isPrime[j] = false;
            }
        }
    }
    vector <int>* primes = new vector<int>();
    primes -> push_back(2);
    for(int i=3; i<MAX; i++){
        if(isPrime[i]){
            primes -> push_back(i);
        }
    }

    return primes;
}

void printPrimes(ll l, ll r, vector<int>* & primes){
    bool isPrime[r-l+1];        //defining array in the range for the given L to R
    for(int i=0; i <= r-l; i++){
        isPrime[i] = true;      //all are primes, initially
    }
    for(int i=0; primes->at(i)*(ll)primes->at(i) <= r; i++){    //looping for sqrt(r) times...according to sieve's algorithm
        if(l == 1){
            isPrime[0] = false;
        }
        int currentPrime = primes->at(i);
        //for smaller or equal value to l
        ll base = (l/currentPrime)*currentPrime;    //in this way, base will be either equal to given L or lesser than L
        if(base<l){
            base = base + currentPrime;
        }

        //mark primes within L to R as false...marking the indexes..like L given 20..20 is not prime...so isPrime[0]=false
        for(ll j=base; j <= r; j+=currentPrime){
            isPrime[j-l] = false;
        }

        //handling rare case where base itself is a prime number
        if(base == currentPrime){
            isPrime[base-l] = true;
        }

    }
    for(int i=0; i<=r-l; i++){
        if(isPrime[i]){
            cout<<i+l<<endl;    //ultimately adding l to show the actual values
        }
    }
}

int main()
{

    vector <int>* primes = sieve();
    int n;
    cin>>n;
    while(n--){
        ll l, r;
        cin>>l;
        cin>>r;
        printPrimes(l, r, primes);

    }
    return 0;
}


