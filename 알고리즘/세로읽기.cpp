#if 0 
#include <iostream>
#include <stdio.h>
using namespace std;
char arr[5][15] = {0,};

int main(){
    
    char input = 0;
    int index = 0;
    int maxIndex = 0;
    for(int i = 0; i < 5; i ++){
        index = 0;
        while ((input = getchar())!= '\n') {
            arr[i][index++] = input;
        }
        arr[i][index] = '\0';
        if(maxIndex < index){
            maxIndex = index;
        }
    }
    
    
    char crt =0;
    for(int i = 0; i<maxIndex; i ++){
        for(int j = 0; j<maxIndex; j++){
            crt = arr[j][i];
            if( crt!= 0 || crt != '\0'){
                cout << crt ;
            }
        }
    }
}
#endif