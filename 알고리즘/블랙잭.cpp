#if 0 
#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int numberOfcard;
    cin >> numberOfcard;
    
    int maxium = 0;
    cin >> maxium;
    
    int cards[101] = {  0,};
    for(int i = 0 ; i < numberOfcard ; i ++){
        cin >> cards[i];
    }
    
    int maxSum = 0;
    int tempSum = 0;
    
    int si , sj ,sz ;
    for(int i = 0; i < numberOfcard ; i ++){
        si  = cards[i];
        for(int  j = i+1 ; j<numberOfcard ; j ++){
            sj = cards[j];
            for(int z = j+1; z<numberOfcard ; z++){
                sz = cards[z];
                tempSum = si + sj + sz;
                if(tempSum <= maxium){
                    
                    if( tempSum > maxSum){
                        maxSum = tempSum;
                    }
                }
                
            }
        }
    }
    
    cout << maxSum <<endl;
}
#endif