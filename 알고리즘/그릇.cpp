#if 0
#include <iostream>
using namespace std;
int main(){
    char input = 0;
    char arr[50];
    cin >> arr;
    int index = 0;
    char pre = arr[index++];
    int height =10;
    while ((input = arr[index++])!= '\0') {
        if(pre == '('){
            if(input =='('){
                height+=5;
            }else{
                height+=10;
            }
        }else{
            if(input =='('){
                height+=10;
            }else{
                height+=5;
            }
            
        }
        pre = input;
    }
    
    cout<< height <<endl;
    
}
#endif