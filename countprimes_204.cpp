#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int countPrimes(int n) {

        // No primes below 2
        if(n <= 2)
            return 0;

        // Assume all numbers are prime initially
        vector<bool> isPrime(n, true);

        isPrime[0] = false;
        isPrime[1] = false;

        // Sieve of Eratosthenes
        for(int i = 2; i * i < n; i++) {

            if(isPrime[i]) {

                // Mark multiples as non-prime
                for(int j = i * i; j < n; j += i) {

                    isPrime[j] = false;
                }
            }
        }

        int count = 0;

        // Count prime numbers
        for(int i = 2; i < n; i++) {

            if(isPrime[i])
                count++;
        }

        return count;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter n: ";
    cin >> n;

    int ans = obj.countPrimes(n);

    cout << "Number of Prime Numbers less than "
         << n << " is: " << ans << endl;

    return 0;
}