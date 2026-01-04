#include <bits/stdc++.h>
using namespace std;
const int N=316;
bitset<N+1> isPrime=0;
vector<int> prime;
int Div4[100001];

class Solution {
public:
    // Sieve of Eratosthenes to find all primes up to N
    static void Sieve(){ 
        if (isPrime[2]) return; // Already computed
        isPrime.set(); // Mark all as prime initially
        memset(Div4, -1, sizeof(Div4)); // Initialize memoization array
        isPrime[0]=isPrime[1]=0; // 0 and 1 are not prime
        Div4[0]=Div4[1]=0; // No 4-divisor numbers
        
        int Nsqrt=sqrt(N-1); 
        // Mark multiples of primes as non-prime
        for(int p=2; p<=Nsqrt; p+=1+(p&1)){ 
            if (isPrime[p]){ 
                Div4[p]=0; // Primes have only 2 divisors
                prime.push_back(p); 
                for(int i=p*p; i<N; i+=p) 
                    isPrime[i]=0; 
            } 
        } 
        // Collect remaining primes up to N
        for(int i=Nsqrt+((Nsqrt&1)==0); i<N; i+=2){ 
            if (isPrime[i]) 
                prime.push_back(i); 
        } 
    }

    // Returns sum of divisors if x has exactly 4 divisors, else 0
    static int sum4Div(int x){
        if (Div4[x]!=-1) return Div4[x]; // Return memoized result
        
        int y=x, sum=1+x, cntPF=0, xsqrt=sqrt(x);
        
        // Factor x and check divisor count
        for(int p: prime){
            if (p>xsqrt) break;
            if (y%p) continue;
            
            int e=0;
            while(y%p==0){
                y/=p;
                e++;
            }
            cntPF++;

            // Case: x = p^3 (divisors: 1, p, p^2, p^3)
            if (e==3 && y==1 && cntPF==1)
                return Div4[x]=1+p+p*p+p*p*p;

            // Invalid: exponent > 1 or too many prime factors
            if (e>1||cntPF>2) return Div4[x]=0;
            sum+=p;
        }
        
        // If y > 1, x has a remaining prime factor
        if (y>1){
            cntPF++;
            sum+=y;
        }
        
        // Return sum if exactly 2 prime factors (x = p*q form), else 0
        return Div4[x]=(cntPF==2)?sum:0;
    }

    // Main function to sum divisors of all numbers with exactly 4 divisors
    static int sumFourDivisors(vector<int>& nums) {
        Sieve();
        int ans=0;
        for(int x: nums)
            ans+=sum4Div(x);
        return ans;
    }
};