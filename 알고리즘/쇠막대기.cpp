#if 0 
#include <iostream>
#include <stdio.h>

using namespace std;



int main(){
    
    
    char temp;
    int stick = 0;
    int sum = 0;
    char pre = 0;
    while ((temp = getchar())!= '\n') {
        if(temp == '('){
            stick++;
        }else if(temp ==')'){
            stick--;
            if(pre == '('){
                sum+= stick;
            }else{
                sum+=1;
            }
        }
        pre = temp;
    }
    cout << sum <<endl;
    
    
}
#endif