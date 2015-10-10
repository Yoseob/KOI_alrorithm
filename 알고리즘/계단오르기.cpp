#if 0 

#include <iostream>
using namespace std;
int visit[301] = {0,};
int stair[301] = {0,};
int maxTable[301] = {0,};
int mmax ;
int finish;

inline int maxValue(int a, int b){
    return  a > b ? a : b;
}
int main(){
    
    
    cin >> finish;
    for(int i  = 1; i <=finish; i ++){
        cin >> stair[i];
    }
    maxTable[1] = stair[1];
    maxTable[2] = stair[2] + maxTable[1];
    
    for(int i = 3; i <=finish;i ++){
        maxTable[i] = maxValue((stair[i-1] + maxTable[i-3]) ,maxTable[i-2] ) + stair[i];
    }
    
    
    //    cout <<maxTable[finish] <<endl;
    cout << endl;
    cout << 10*10%11 <<endl;
    
}
#endif