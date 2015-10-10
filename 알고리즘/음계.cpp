#if 0
#include <iostream>

using namespace std;

int main(){
    
    int pre , crt;
    cin >> pre;
    int asc = 0 , dec = 0 ;
    for(int i = 1 ; i<8 ; i++){
        
        cin >> crt;
        if(pre < crt){
            asc = 1;
        }else{
            dec = 1;
        }
        pre = crt;
    }
    
    if(asc  == 1 && dec == 0){
        cout << "ascending"<<endl;
    }else if(asc == 0 && dec == 1){
        cout << "descending"<<endl;
    }else if(asc == 1 && dec == 1){
        cout << "mixed"<<endl;
    }
    
}
#endif