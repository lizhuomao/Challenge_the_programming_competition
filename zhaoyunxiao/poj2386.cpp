#include <iostream>
using namespace std;

int n,m,num=0;
void dfs(int x,int y,char **array);
int main(){
    cin>>n>>m;
    char **array=new char* [n];
    for(int i=0;i<n;i++) array[i]=new char[m];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>array[i][j];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(array[i][j]=='W'){
                dfs(i,j,array);
                num++;
            }
        }
    }
    cout<<num<<endl;
    return 0;
}

void dfs(int x,int y,char **array){
    array[x][y]='.';
    for(int dx=-1;dx<=1;dx++){
        for(int dy=-1;dy<=1;dy++){
            int nx=x+dx,ny=y+dy;
            if(nx>=0 && ny>=0 &&nx<n &&ny<m &&array[nx][ny]=='W')  dfs(nx,ny,array);
        }
    }
}

