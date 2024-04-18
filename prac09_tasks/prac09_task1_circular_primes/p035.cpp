#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_N = 1000000;
// const int MAX_N = 100;

vector<int> sieve_of_eratosthenes(int limit)
{
    // Initialize a boolean vector "prime" and fill all entries as true.
    // A value in prime[i] will finally be false if i is Not a prime, else true.
    vector<bool> prime(limit + 1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= limit; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p])
        {
            // Updating all multiples of p
            for (int i = p * p; i <= limit; i += p)
            {
                prime[i] = false;
            }
        }
    }

    // Collecting all prime numbers
    vector<int> primes;
    for (int p = 2; p <= limit; p++)
    {
        if (prime[p])
        {
            primes.push_back(p);
        }
    }
    return primes;
}

bool isCircularPrime(int n, const vector<int> &primes)
{
    string s = to_string(n);
    for (int i = 0; i < s.length(); i++)
    {
        if (find(primes.begin(), primes.end(), stoi(s)) == primes.end())
        {
            return false;
        }
        s = s.substr(1) + s[0];
    }
    return true;
}

int main()
{
    vector<int> primes = sieve_of_eratosthenes(MAX_N);
    int res = 0;
    for (int n : primes)
    {
        if (isCircularPrime(n, primes))
        {
            res++;
            cout << "n= " << n << ", res= " << res << endl;
        }
    }
    std::cout << "DONE" << endl;
    return 0;
}