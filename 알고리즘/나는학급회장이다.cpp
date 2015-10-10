#if 0 
#include <iostream>
using namespace std;

int arr[3][4] = {0,};

int main(){
    
    int student;
    int vote = 0;
    cin >> student;
    for(int i = 0; i< student; i ++){
        for(int j = 0;j<3; j++){
            cin >> vote;
            arr[j][vote]++;
        }
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = 1; j <=3; j ++){
            arr[i][0] += (arr[i][j] * j);
        }
    }
    
    
    int max = 0;
    int maxindex = 0;
    
    int result = 0;
    int resultMax = 0;
    for(int i = 0; i <3 ; i++){
        if(max < arr[i][0]){
            max = arr[i][0];
            maxindex = i;
            resultMax =arr[maxindex][0];
            result = i+1;
            
        }else if(max == arr[i][0]){
            int a = arr[maxindex][3];
            int b = arr[i][3];
            if(a!=b){
                if(a > b){
                    result = maxindex+1;
                    resultMax  =  arr[maxindex][0];
                }else{
                    result = i+1;
                    resultMax  =  arr[i][0];
                }
            }else{
                int a = arr[maxindex][2];
                int b = arr[i][2];
                if(a!=b){
                    if(a > b){
                        result = maxindex+1;
                        resultMax  =  arr[maxindex][0];
                        
                    }else{
                        result = i+1;
                        resultMax  =  arr[i][0];
                        
                    }
                }else{
                    result = 0;
                    resultMax  =  arr[i][0];
                }
            }
        }else{
            
        }
        
    }
    
    cout << result << " " << resultMax <<endl;
    //    cout << maxindex  << " / " << arr[maxindex][0];
    
    
}


/*
 
 6
 1 2 3
 2 3 1
 3 1 2
 1 2 3
 3 1 2
 1 2 3
 
 6
 2 3 1
 2 3 1
 3 1 2
 1 2 3
 3 1 2
 1 2 3
 
 7
 3 1 2
 2 3 1
 3 1 2
 1 2 3
 3 1 2
 1 2 3
 1 2 3
 
 
 8
 3 1 2
 2 3 1
 3 1 2
 1 2 3
 3 1 2
 1 2 3
 1 2 3
 1 3 2
 
 
 8
 3 1 2
 2 3 1
 3 1 2
 1 2 3
 3 1 2
 1 2 3
 1 2 3
 3 2 1
 
 */
#endif