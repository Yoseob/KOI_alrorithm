#if 0

#include <iostream>
using namespace std;

int main(){
    
    int line[100]={0,};
    int input ;
    cin  >> input;
    
    int card;
    int index = 0;
    for(int i = 1; i <=input; i++){
        cin >> card;
        index = input-card;
        if(line[index] == 0){
            line[index] = i;
            
        }else{
            for(int j= 0; j <index; line[j] = line[j+1] ,j++);
            line[index] = i;
        }
    }
    for(int i = 1; i <=input; cout << line[i++]<< " ");
    cout <<endl;
    
}

#endif