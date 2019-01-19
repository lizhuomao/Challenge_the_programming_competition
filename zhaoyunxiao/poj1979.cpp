#include <iostream>
using namespace std;

int n,m,result;
char **field;

void dfs(int x,int y){
    if(x>=0 && y>=0 && x<n && y<m && (field[x][y]=='.' || field[x][y]=='@')){
        //cout<<"It is matching:"<<x<<" "<<y<<endl;
        field[x][y]='#';
        result++;
        dfs(x+1,y);
        dfs(x-1,y);
        dfs(x,y-1);
        dfs(x,y+1);
    }
}
int main(){
    int curX,curY;
    while(cin>>m>>n){
        if(n!=0 && m!=0){
            field=new char*[n];
            for(int i=0;i<n;i++)  field[i]=new char[m];
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cin>>field[i][j];
                    if(field[i][j]=='@'){
                        curX=i;
                        curY=j;
                    }
                }
            }
            result=0;
            dfs(curX,curY);
            cout<<result<<endl;
        }
    }
    return 0;
}
