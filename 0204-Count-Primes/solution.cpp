// class Solution {
// public:
//     int countPrimes(int n) {
//         if (n <= 2) return 0;  

//         vector<bool> isPrime(n, true);

//         isPrime[0] = isPrime[1] = false;

//         // Mark multiples of prime numbers
//         for (long long i = 2; i * i < n; i++) {
//             if (isPrime[i]) {

//                 for (long long j = i * i; j < n; j += i) {
//                     isPrime[j] = false;
//                 }
//             }
//         }

//         // Count remaining prime numbers
//         int ans = 0;

//         for (int i = 2; i < n; i++) {
//             if (isPrime[i])  ans++;
//             }
//         return ans;
//     }
// };

//time limit exceed
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<char> composite(n, 0);   // plain bytes, no bit-proxy overhead
        int count = n / 2;              // start by counting 2 and all odd numbers

        for (int i = 3; i <= (n - 1) / i; i += 2) {
            if (!composite[i]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    if (!composite[j]) {
                        composite[j] = 1;
                        count--;
                    }
                }
            }
        }
        return count;
    }
};