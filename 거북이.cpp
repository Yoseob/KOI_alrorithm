#if 0 

#include <iostream>
using namespace std;
int main(){
    
    int arr[4] = {0,};
    for(int i = 0 ;i<4 ; i ++){
        cin >>arr[i] ;
    }
    for(int i = 0; i < 4; i ++){
        for(int j = 0; j <4; j ++){
            if(arr[i] > arr[j]){
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
    
    
    cout << arr[3] * arr[1] <<endl;
}
#endif