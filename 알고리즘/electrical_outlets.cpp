#if 0

#include <iostream>
using namespace std;
int main(){
    //3 2 3 4
    int numberOfOutlet;
    cin >>numberOfOutlet;
    
    while (numberOfOutlet--) {
        
        int size;
        cin >>size;
        int input;
        int total = 0;
        for(int i = 0; i<size; i ++){
            cin >> input;
            if(i == 0){
                total += input;
            }else{
                total+=input-1;
            }
        }
        cout <<total<<endl;
    }
    
}

#endif