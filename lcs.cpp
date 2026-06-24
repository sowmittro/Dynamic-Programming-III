#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string LCS(string s1, string s2){
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j <= m; j++){
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string lcs = "";
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(s1[i - 1] == s2[j - 1]){
            lcs += s1[i - 1];
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main(){
    string s1, s2;

    cin >> s1;
    cin >> s2;

    string result = LCS(s1, s2);

    cout << "Length = " << result.length() << endl;
    cout << "LCS = " << result << endl;
    return 0;
}
