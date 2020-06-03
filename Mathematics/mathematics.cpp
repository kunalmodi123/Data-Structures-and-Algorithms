#include <bits/stdc++.h>

using namespace std;

void sieveOfEratosthenes(long int n)
{
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (long i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            for (long j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }

    int count = 0;

    for (long int i = 0; i <= n; i++)
    {
        if (prime[i])
        {
            count++;
            cout << i << endl;
        }
    }
    cout << "\n\n"
         << "No. of Primes upto " << n << " : " << count;
}

int digitsOfNumber(long int n)
{
    int x = floor(log10(n) + 1);
    return x;
}

int digitsOfFactorial(int n)
{
    double sum = 0.0;
    for (int i = 1; i <= n; i++)
    {
        sum += log10(i);
    }

    return (1 + floor(sum));
}

int euclideanAlgo(int a, int b)
{
    if (a == 0)
        return b;
    return euclideanAlgo(b % a, a);
}

int main()
{
    long int a, b;

    cout << "Enter the the value of a and b: ";
    cin >> a >> b;

    cout << endl
         << euclideanAlgo(a, b);
}