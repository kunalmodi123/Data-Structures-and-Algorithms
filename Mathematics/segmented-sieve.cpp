#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX = 100001;

vector<int> sieve(){
    vector<bool> isPrime(MAX+1, true);
    isPrime[0] = isPrime[1] = false;

    for(int i=2; i*i<=MAX; i++){
        if(isPrime[i]){
            for(int j = i*i; j<=MAX; j += i)
                isPrime[j] = false;
        }
    }

    vector<int> primes;
    primes.push_back(2);
    for(int i=3; i<=MAX; i += 2){
        if(isPrime[i])
            primes.push_back(i);
    }

    return primes;
}

void segmentedSieve(ll l, ll r, vector<int> primes){
    vector<bool> isPrime(r-l+1, true);
    
    for(int i=0; primes[i]*(ll)primes[i]<=r; i++){
        int currPrime = primes[i];
        ll base = (l/currPrime)*currPrime;

        if(base < l)
            base += currPrime;

        for(ll j=base; j<=r; j += currPrime){
            isPrime[j-l] = false;
        }

        if(base == currPrime)
            isPrime[base-l] = true;
    }

    for(int i=0; i<=r-l; i++){
        if(isPrime[i])
            cout << i+l << " ";
    }
}


int main(){
    vector<int> primes = sieve();
    ll l, r;
    cin >> l >> r;

    segmentedSieve(l, r, primes);
}