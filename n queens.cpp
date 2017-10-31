#include<iostream>
#include<map>
using namespace std;
int n;
int cnt=0,ans=0;
int flag=0;
int mp[100][100]={0};
//map<int,map<int,int>>mp;
int board[100][100];
bool check(int row,int col)
{
    for(int i=0; i<col; i++)
    {
        if(board[row][i])return false;
    }
    for(int i=row,j=col; i>=0&&j>=0; i--,j--)
    {
        if(board[i][j])return false;
    }
    for(int i=row,j=col; i<n&&j>=0; i++,j--)
    {
        if(board[i][j])return false;
    }
    int m1=row+2,m2=row-2,m3=col+2,m4=col-2;
    if(board[m1][col-1]==1 || board[m1][col+1]==1 || board[m2][col-1]==1 || board[m2][col+1]==1)return false;
    if(board[row+1][m3]==1 || board[row-1][m3]==1 || board[row+1][m4]==1 || board[row-1][m4]==1)return false;

    return true;
}

int solve(int col)
{
    if(col==n)
    {
        ans++;
        cout<<"sol: "<<ans<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
               if(board[i][j]) mp[i][j]++;
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

         for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
               if(mp[i][j]>1)flag=1;

            }

        }
        if(flag==0)cnt++;
        flag=0;
        //board[100][100]={0};
        return 0;
    }
    for(int i=0; i<n; i++)
    {
        if(check(i,col))
        {
            board[i][col]=1;
            if(solve(col+1))
            {
                return 1;
            }
            board[i][col]=0;
        }

    }
     return 0;


}

int main()
{
    cin>>n;
    solve(0);
    cout<<"total solution: "<<ans<<endl;
    cout<<"distict solution: "<<cnt<<endl;
}
