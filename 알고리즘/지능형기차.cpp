#if 0

#include <iostream>
using namespace std;

int main(){
    
    int sum = 0 , in ,out;
    int maxSum = -1;
    
    
    for(int i = 0; i< 4; i ++){
        
        cin >> out >> in;
        sum-=out;
        if(sum > maxSum) maxSum = sum;
        sum+=in;
        if(sum > maxSum) maxSum = sum;
    }
    
    cout << maxSum <<endl;
}
#endif