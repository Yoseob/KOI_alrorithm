#if 0

#include <iostream>
using namespace std;

int main(){
    int min = 100;
    int sum = 0;
    int input = 0;
    for(int i = 0; i <7; i ++){
        cin >> input;
        if(input%2){
            sum+= input;
            if(input  < min){
                min = input;
            }
        }
    }
    
    if(input == 0){
        cout << -1  <<endl;
        return 0;
    }
    cout << sum << endl << min <<endl;
    
}
#endif