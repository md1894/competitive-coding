#include <iostream>
#include<vector>
using namespace std;
#define ll long long 
// defining initial variable making it global for using it eveywhere
vector<ll> b,c;
ll k,mod;
vector<vector<ll>> multiply(vector<vector<ll>> A,vector<vector<ll>> B)
{
    vector<vector<ll>> C(k+1,vector<ll>(k+1));

    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<=k;j++)
        {
            C[i][j]=0;
            for(int x=0;x<=k;x++)
            {
                C[i][j]=(C[i][j]+(A[i][x]*B[x][j])%mod)%mod;
            }
        }
    }
    return C;
}
// computing power of transition matrix
vector<vector<ll>> power(vector<vector<ll>> A,ll n)
{
    // base case 
    if(n==1)
    { 
        return A;
    }
    if(n&1)
    {
        return multiply(A,power(A,n-1));
    }
    else 
    {
        vector<vector<ll>> x=power(A,n/2);
        return multiply(x,x);
    }
}
ll compute(ll n)
{
    if(n<=k)
    {
        ll result=0;
        for(int i=0;i<n;i++)
        {
            result+=b[i];
        }
        return result;
    }
    // computing the sum sk
    ll sum=0;
    for(int i=0;i<k;i++)
    {
      sum+=b[i];
    }
    sum=sum;
    // making F1 vector
    vector<ll> F1(k+1);
    for(int i=0;i<=k;i++)
    {
        if(i==0)
        {
            F1[i]=sum;
        }
        else 
        {
            F1[i]=b[i-1];
        }
    } 
    // step 1 construct transition matrix i.e T
    vector<vector<ll>> T(k+1,vector<ll>(k+1));

    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(i==0 && j==0)
            {
                T[i][j]=1;
            }
            else if((i==0 || i==k) && j>0)
            {
                T[i][j]=c[k-j];
            }
            else if((i+1)==j)
            {
                T[i][j]=1;
            }
            else 
            {
                T[i][j]=0;
            }
          //  cout <<T[i][j] << ' ';
        }
      //  cout << endl;
    }
    cout << "b" << endl;
    for(auto i: b){
        cout << i << " ";
    }
    cout << endl;
    cout << "c" << endl;
    for(auto i: c){
        cout << i << " ";
    }
    cout << endl;
    cout << "T" << endl;
    for(ll i = 0; i <= k; i++){
        for(ll j = 0; j <= k; j++){
            cout << T[i][j] << " ";
        }
        cout << endl;
    }
    // computing power of transition matrix 
    T=power(T,n-k);
    // Now the final step for the answer computing Sn
    // reusing sum 
    cout << "T" << endl;
    for(ll i = 0; i <= k; i++){
        for(ll j = 0; j <= k; j++){
            cout << T[i][j] << " ";
        }
        cout << endl;
    }
    sum=0;
    for(int i=0;i<=k;i++)
    {
        sum=(sum+(T[0][i]*F1[i])%mod)%mod;
    }
    //cout << sum << endl;
    return sum;
}
int main() {
    int t;
    cin >> t ; 
    ll m,n;
    while(t--)
    {
        cin >> k;
        b.resize(k);
        c.resize(k);
        // taking initial element as input i.e. b1,b2.....bk
        for(int i=0;i<k;i++)
        {
            cin >> b[i];
        }
        // taking input coefficient of recurrence relation
        for(int i=0;i<k;i++)
        {
            cin >> c[i];
        }

        cin >> m >> n >> mod;
        ll result=(compute(n)%mod-compute(m-1)%mod+mod)%mod;

        cout << result << endl;
    }
}
