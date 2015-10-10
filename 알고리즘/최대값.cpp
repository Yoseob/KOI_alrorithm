#if 0 

#include <iostream>
using namespace std;


int main(){
    
    int pre;
    int max = 0;
    int maxIndex = 1;
    
    
    for(int i = 1; i <10; i ++){
        cin >> pre;
        if(pre  > max){
            max=pre;
            maxIndex=i;
        }
        
    }
    
    
    cout << max <<endl << maxIndex <<endl;
}
#endif