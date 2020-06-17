#include <iostream>
#include <vector>
using namespace std;

#define ll long long
ll MOD;

ll k;
vector<ll> a,b,c;

//Multiply two matrices
vector<vector<ll> > multiply(vector<vector<ll> > A,vector<vector<ll> > B ){

    //third matrix mei result store
    vector<vector<ll> > C(k+1,vector<ll>(k+1));

    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int x=1;x<=k;x++){

                C[i][j] = (C[i][j] + (A[i][x]*B[x][j])%MOD)%MOD;
            }

        }
    }


    return C;
}


vector<vector<ll> >  pow(vector<vector<ll> > A,ll p){

    //Base case
    if(p==1){
        return A;
    }
    //Rec Case
    // A^p = A * A^p-1   for odd
    if(p&1){
        return multiply(A, pow(A,p-1));
    }
    else{
        // A^p = A^(p/2)*A^(p/2)  for even
        vector<vector<ll> > X = pow(A,p/2);
        return multiply(X,X);
    }

}


ll compute(ll n){
    //Base case
    if(n==0){
        return 0;
    }

    //Suppose n<=k
    // age k se km he to wo to ques me hi given he na bc!!
    if(n<=k){
        return b[n-1];
    }

    //Otherwise we use matrix exponentiation, indexing 1 se, that's y size is k+1
    vector<ll> F1(k+1);

    //1. Setting up F1 vector
    for(int i=1;i<=k;i++){
        F1[i] = b[i-1];
    }

    //2. Transformation matrix
    vector<vector<ll> > T(k+1,vector<ll>(k+1));
    // Let's init T

    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            // every row except the last one has either 0 or 1 in it
            if(i<k){
                if(j==i+1){
                    // 1 at next element to diagonal
                    T[i][j] = 1;
                }
                else{
                    T[i][j] = 0;
                }
                continue;
            }
            //Last Row - store the Coefficients in reverse order
            T[i][j] = c[k-j];

        }

    }

    // 3. T^n-1
    T = pow(T,n-1);

    // 4. multiply by F1
    // we only need the first term, so no need to multiply whole again
    ll res = 0;
    for(int i=1;i<=k;i++){
        res = (res + (T[1][i]*F1[i])%MOD)%MOD;
    }

    return res;

}

int main() {

    ll t,n,m,p,num;

    cin>>t;
    while(t--){

        cin>>k;

        // enter vector b
        //Init Vector F1
        for(int i=0;i<k;i++){
            cin>>num;
            b.push_back(num);
        }

        //Coefficients
        // enter vector c
        for(int i=0;i<k;i++){
            cin>>num;
            c.push_back(num);
        }
        // the value of m,n and p
        cin>>m>>n>>p;
        MOD=p;
        
        ll ans1 = compute(m+1)%p;
        ll ans2 = compute(n+2)%p;

        ll ans = (ans2-ans1);
        
        if(ans<0){
          ans=(ans+p)%p;
          cout<<ans%p<<endl;
        }
        else
        cout<<ans%p<<endl;

        b.clear();
        c.clear();
    }

    return 0;

}
