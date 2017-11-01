#include <bits/stdc++.h>
#include<map>
using namespace std;
map<int,map<int,int>>mp;
// N x N chessmat
#define N 12
int cnt=0;
int ans=0;
// Function to check if two queens threaten each other or not
bool isSafe(char mat[][N], int r, int c)
{
	// return false if two queens share the same cumn
	for (int i = 0; i < r; i++)
		if (mat[i][c] == 'Q')
			return false;

	// return false if two queens share the same \ diagonal
	for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
		if (mat[i][j] == 'Q')
			return false;

	// return false if two queens share the same / diagonal
	for (int i = r, j = c; i >= 0 && j < N; i--, j++)
		if (mat[i][j] == 'Q')
			return false;
		 int m1=r+2,m2=r-2,m3=c+2,m4=c-2;
    if(mat[m1][c-1]== 'Q' || mat[m1][c+1]== 'Q' || mat[m2][c-1]== 'Q'|| mat[m2][c+1]== 'Q')return false;
    if(mat[r+1][m3]== 'Q'|| mat[r-1][m3]== 'Q' || mat[r+1][m4]== 'Q'|| mat[r-1][m4]== 'Q')return false;

	return true;
}

void nQueen(char mat[][N], int r, int c)
{
	// if N queens are placed successfully, print the solution
	if (c == 0 && r == N)
	{
		cnt++;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++){
				//cout << mat[i][j] << " ";
				if(mat[i][j]=='Q')mp[i][j]++;}
			//cout << endl;
		}
		//cout << endl;
		int flag=0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++){

			if(mat[i][j]=='Q'){if(mp[i][j]>1)flag=1;


			}
		}
		}
		if(flag==0)ans++;


		return;
	}

	// place Queen at every square in current r r
	// and recurse for each valid movement
	for (int i = 0; i < N; i++)
	{
		// if no two queens threaten each other
		if (isSafe(mat, r, i))
		{
			// place queen on current square
			mat[r][i] = 'Q';

			// recurse for next r
			nQueen(mat, r + 1, 0);

			// backtrack and remove queen from current square
			mat[r][i] = '-';
		}
	}
}

int main()
{
	// mat[][] keeps track of position of Queens in current configuration
	char mat[N][N];

	// initalize mat[][] by '-'
	memset(mat, '-', sizeof mat);

	nQueen(mat, 0, 0);
	cout<<"total: "<<cnt<<endl;
	cout<<"dis: "<<ans<<endl;
	return 0;
}
