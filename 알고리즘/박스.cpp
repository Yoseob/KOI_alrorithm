#if 0
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int map[101][101] ={0,};

int m , n ;
vector<int> v;

void initWithClear(){
    
    for(int i = 0; i <100; i ++){
        for(int j = 0; j<100; j ++){
            map[i][j] = 0;
        }
    }
    cin >> m >> n;
    
    for(int i = 0; i <m ;i++){
        for(int j = 0; j <n ; j++){
            cin >>map[i][j];
        }
    }
    
}

void topDown(){
    
    
    int total = 0;
    int height = m;
    for(int i = 0; i<n ; i++){
        height = m-1;
        for(int j = m; j>= 0; j--){
            if(map[j][i] == 1){
                total +=height-j;
                height--;
            }
        }
    }
    cout << total <<endl;
    
    
}


int main(){
    int tc;
    cin >> tc;
    while (tc--) {
        initWithClear();
        topDown();
        
    }
    
    vector<int> ::iterator itr = v.begin();
    
    while (itr != v.end()) {
        
        //        cout << (*itr) <<endl;
        itr++;
    }
    
}
#endif