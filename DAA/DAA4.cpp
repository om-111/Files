#include <iostream>
#include <cstring>
using namespace std;
int LCS_table[51][51],i,j;
char Dir_table[51][51];
void lcs(string S1, string S2, int m, int n) {
  for (i = 0; i <= m; i++) {
    for (j = 0; j <= n; j++) {
      if (i == 0 || j == 0) {
      //initialize ith row and jth column with zeroes
      LCS_table[i][j] = 0;
      Dir_table[i][j] = '0';
      }
      //if the char are identical set dir as Diagonal and add 1 to prev lcs answer
      else if (S1[i - 1] == S2[j - 1]) {
      LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      Dir_table[i][j] = 'D';
      }
      else if (LCS_table[i - 1][j]>=LCS_table[i][j - 1]) {
      //If top value is larger than bottom value
      LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
      Dir_table[i][j] = 'U';
      }
      else {
      //If left value is larger than right value
      LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
      Dir_table[i][j] = 'L';
      }
    }
  }
  int index = LCS_table[m][n];
  char res[index + 1];
  res[index] = '\0';

  int i = m, j = n;
  //Start from the LCS_Table[m][n]
  while (i > 0 && j > 0) {
    if (S1[i - 1] == S2[j - 1]) {
      //if chars are same in both strings append to result string and move up diagonally
      res[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
    }
    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
    //if value to left is greater than value above, move left
      i--;
    else
    //else move up
      j--;
  }
  cout<<"LCS Table"<<endl;
  for(i=0;i<=m;i++){
      for(j=0;j<=n;j++){
          cout<<LCS_table[i][j]<<" ";

      }
      cout<<endl;
  }
  cout<<"Directional Table"<<endl;
  for(i=0;i<=m;i++){
      for(j=0;j<=n;j++){
            cout<<Dir_table[i][j]<<" ";
      }
      cout<<endl;
  }
  

  cout<<"S1 : "<<S1<<endl<<"S2: "<<S2<<endl<<"LCS: "<<res<<endl;
}

int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    //s1="ACADB";
    //s2="CBDA";
    int m = s1.length();
    int n = s2.length();
    lcs(s1, s2, m, n);
    //Sample Inputs
	//BDCABA
	//ABCBDAB
	
	//BDAB
}
