#if 0 

#include <iostream>

using namespace std;

int main(){
    
    int sum = 0;
    int input = 0;
    char chars[6][2] = {"E","A","B","C","D","E"};
    int result[3]={0,};
    for(int i = 0; i<3; i ++){
        sum = 0;
        for(int j = 0; j <4; j ++){
            cin >> input;
            if(!input) sum++;
        }
        result[i] = sum;
        
    }
    for(int i = 0; i<3; i ++){
        cout << chars[result[i]]<<endl;
    }
    
}
#endif