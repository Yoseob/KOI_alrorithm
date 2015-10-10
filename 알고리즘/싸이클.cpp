#if 0
#include <iostream>
using namespace std;

int main(){
    
    
    
    
    int n,p, tempn;
    int cycle[10000]= {0,};
    int visted[10000] = {0,};
    int ret= 0;
    int index = 0;
    
    cin >> n >> p;
    tempn = n;
    cycle[index++] = n;
    visted[n]++;
    while (1) {
        cycle[index] = (n*tempn)%p;
        tempn = ((n*tempn)%p);
        
        if(visted[tempn] == 1){
            ret ++;
        }
        if(visted[tempn] == 2){
            break;
        }
        
        visted[tempn]++;
        index++;
    }
    
    
    
    
    cout << ret <<endl;
    
    
}

#endif