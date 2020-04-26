#include <bits/stdc++.h>
//#define MOD 10000000007

using namespace std;
const int MOD = 1000000007;
vector<string> split_string(string);

// Complete the countArray function below.
/* there are only 2 states , weather array ends with x or not */
long countArray(int n, int k, int x) {
    long long* endsWithX = new long long[n];
    long long* dontEndsWithX = new long long[n];
    endsWithX[0]  = x == 1 ? 1 : 0; // ends in x
    dontEndsWithX[0] = x == 1 ? 0 : 1; // doesn't end in x
    for(int i = 1; i < n; i++){
        endsWithX[i] = dontEndsWithX[i-1] % MOD;
        dontEndsWithX[i] = ((endsWithX[i-1]*(k-1))%MOD + (dontEndsWithX[i-1]*(k-2))%MOD)%MOD;
    }
    long ans = endsWithX[n-1] % MOD;
    delete [] endsWithX;
    delete [] dontEndsWithX;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nkx_temp;
    getline(cin, nkx_temp);

    vector<string> nkx = split_string(nkx_temp);

    int n = stoi(nkx[0]);

    int k = stoi(nkx[1]);

    int x = stoi(nkx[2]);

    long answer = countArray(n, k, x);

    fout << answer << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
