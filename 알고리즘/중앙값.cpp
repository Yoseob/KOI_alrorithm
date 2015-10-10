#if 0
#include <iostream>
#include <stdio.h>
using namespace std;


int main(){
    
    int numbers[5]={0,};
    
    int sum = 0;
    for(int i = 0 ; i< 5; i ++){
        cin >> numbers[i];
        sum+=numbers[i];
    }
    
    sum =sum/5;
    
    
    for(int i = 0;i<5; i ++){
        for(int j = 0 ; j <5; j ++){
            if(numbers[i] < numbers[j]){
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    
    
    printf("%d\n",(int)sum);
    printf("%d\n",(int)numbers[2]);
    
    
    
    return 0;
}
#endif
