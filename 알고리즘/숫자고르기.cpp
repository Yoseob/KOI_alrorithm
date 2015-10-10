#if 0
#include <iostream>
using namespace std;
int main(){
    
    int c= 0;
    
    cin >> c;
    
    int down[101] = {0,};
    int input = 0;
    
    for(int i = 1; i<=c; i ++){
        cin >> input;
        down[i] = input;
    }
    
    int temp = 0;
    int count = 0;
    int result = 0;
    int arr[100] = {0,};
    
    for(int i = 1; i <=c; i++){
        
        input = i;
        temp = i;
        
        do {
            if(count > c){
                break;
            }
            
            temp = down[temp];
            count ++;
            
        } while (input != temp);
        
        if(input == temp){
            arr[result++] = input;
        }
        
        count = 0;
    }
    
    cout << result <<endl;
    
    for(int i = 0; i < result ; i++){
        cout <<arr[i] <<endl;
    }
    
}


#endif