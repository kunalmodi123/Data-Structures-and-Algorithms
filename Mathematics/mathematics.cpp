#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1000000007;


const int N = 1e5;
vector<bool> is_prime(N + 1, true);
vector<ll> spf(N + 1, 0); // smallest prime factor
vector<ll> primes_list[N];
vector<ll> no_of_divs(N + 1, 1);

void sieve(){ // nlog(logn)
    is_prime.assign(is_prime.size(), true);
    is_prime[0] = is_prime[1] = false;

    
    for(int i=1; i<=N; i++) spf[i] = i;
    
    //ll operations = 0;
    for (ll i = 2; i*i <= N; i++){
        if (!is_prime[i]) continue;
        for (ll j = 2*i; j <= N; j+=i){
            spf[j] = min(i, spf[j]);
            is_prime[j] = false;
           // operations++;
        }
    }
    // int c = 100;

    // for(int i=1; i<=c; i++) {
    //     cout << i << ":  " << spf[i] << "\n";
    // }

   // cout << operations;

    // int count = 0;

    // for (long int i = 0; i <= N; i++)
    // {
    //     if (is_prime[i])
    //     {
    //         count++;
    //         cout << i << endl;
    //     }
    // }
    // cout << "\N\N"
    //      << "No. of Primes upto " << N << " : " << count;
}

vector<bool> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

void process_prime_factors(){ // nlog2(n)
    for(int i=1; i<=N; i++)
        primes_list[i].clear();

    for(int i=1; i<=N; i++){
        int d = i;
        while(d != 1){
            primes_list[i].push_back(spf[d]);
            d /= spf[d];
        }
    }
}

void process_number_of_divisors(){ // nlogn
    for(int i=1; i<=N; i++){
        for(int d=2*i; d<=N; d += i)
            no_of_divs[d]++;
    }
}

ll sum_of_divisors(ll n){ // O(root(n))
    ll s = sqrt(n);
    ll sum = 0;
    for(ll i=1; i<=s; i++){
        if(n%i == 0){
            sum += i + (n/i);
        }
    }

    if((s*s) == n)
        sum -= s;

    return s;
}

int digitsOfNumber(long int N)
{
    int x = floor(log10(N) + 1);
    return x;
}

int digitsOfFactorial(int N)
{
    double sum = 0.0;
    for (int i = 1; i <= N; i++)
    {
        sum += log10(i);
    }

    return (1 + floor(sum));
}

int euclideanAlgo(int a, int b) // for calculating gcd 
{
    if (a == 0)
        return b;
    return euclideanAlgo(b % a, a);
}

// modular exponentiaion
int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0){
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// factorial with mod
int fact(int n) {
  int res = 1;
  for (int i = 1; i <= n; i++) {
    res = res * 1ll * i % mod;
  }
  return res;
}

// nCr function with mod
int nCr(int n, int k) {
  return fact(n) * 1ll * mpow(fact(k), mod - 2) % mod * 1ll * mpow(fact(n - k), mod - 2) % mod;
}

int main()
{
    // long int a, b;

    // cout << "Enter the the value of a and b: ";
    // cin >> a >> b;

    // cout << endl
    //      << euclideanAlgo(a, b);
    // ll n;
    // cin >> n;

    sieve();
    process_prime_factors();

    for(int i=13425; i<=13475; i++){
        cout << i << " :  ";
        for(auto x: primes_list[i]) cout << x << " ";
        cout << "\n";
    }

    // ll l, r;
    // cin >> l >> r;

    // vector<bool> segmented_sieve = segmentedSieve(l, r);
}