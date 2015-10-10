#if 0 

#include <iostream>
using namespace std;

int mCount = 0;
int edge;
int result = 0;
int map[101][101] = {0,};
void dfs(int node){
    if(map[node][0] == 1){
        return;
    }
    result++;
    map[node][0] = 1;
    
    for(int i = 1;i<=mCount; i ++){
        if(map[node][i] == 1){
            dfs(i);
        }
    }
}
int main(){
    
    
    cin >> mCount >> edge;
    
    int nodeI, nodeJ;
    for(int i = 1; i <=edge; i++){
        cin >> nodeI >> nodeJ;
        map[nodeI][nodeJ] =  map[nodeJ][nodeI] = 1;
    }
    
    dfs(1);
    cout << --result <<endl;
    
    
}

#endif