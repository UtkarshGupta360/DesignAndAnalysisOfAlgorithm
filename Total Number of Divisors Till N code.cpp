#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
/*
vector<int> ExtendedGCD(int a, int b)
{
    if(b == 0) return {1, 0};
    
    vector<int> result = ExtendedGCD(b, a%b);
    int x = result[0];
    int y = result[1];
    
    int SmallX = y;
    int SmallY = x - (a/b)*y;
    //int gcd = (a*SmallX) + (b*SmallY);
    return {SmallX, SmallY};
    
}

int modInverse(int a, int m)
{
    vector<int> result = ExtendedGCD(a,m);
    int x = result[0];
    int y = result[1];
    int gcd = a*x + m*y;
    
    if(gcd != 1){
        cout <<"It Doesn't exists";
        return -1;
    }
    
    int ans = (x%m + m)%m;
    return ans;
}
*/
vector <ll> PrimeSieve(ll num)
{
    ll PS[num] = {0};
    vector<ll> prime;
    PS[0] = PS[1] = 1;
    for(ll i = 2; i <= num; i++)
    {
        if(PS[i] == 0)
        { 
            prime.push_back(i);
            for(ll j = i*i; j <= num; j = j + i)
            {
                PS[j] = 1;
            }
        }
    }
    
    return prime;
}

void sievebuild(ll a, ll b, vector<ll> primes)
{
    vector<int> segment((int)(b - a + 1), 0);
    for(auto p : primes)
    {
        if(p*p > b) break;
        int start = (a/p)*p;
        if(p >= a and p <= b) start = p*2;
        for(ll j = start; j <= b; j = j + p)
        {
            if(j < a) continue;
            segment[j - a] = 1;
        }
    }
    for(ll i = a; i <= b; i++)
    {
        if(segment[i - a] == 0 && i != 1) cout<< i<<endl;
    }
    cout<<endl;
}


int main()
{
    ll n, ans = 0;
    cin>>n;
    vector <int> primes = {2,3,5,7,11,13,17,19,23,29};
    int m = primes.size();
    
    for(int i = 1; i < (1 << m) ; i++)
    {
        int lcm = 1;
        for(int j = 0; j < m; j++) if((i >> j) & 1)lcm *= primes[j];
        if(__builtin_popcount(i) % 2 == 0) ans -= (n/lcm);
        else ans += (n/lcm);
    }
    cout<<ans;
    
    return 0;
}


