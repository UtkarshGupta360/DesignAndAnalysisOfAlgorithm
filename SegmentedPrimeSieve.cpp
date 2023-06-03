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
    vector<ll> primes = PrimeSieve(100000);
    //for(auto p: primes) cout<<p<<' ';
    ll ts, m, n;
    cin>>ts;
    while(ts--)
    {
        cin>>m>>n;
        sievebuild(m,n,primes);
        //cout<<'\n';
    }
    return 0;
}


