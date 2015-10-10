#if  0

#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int , int> a;





int pre = -1;
int maxPath = -1;

void mMax(int b , int inpu){
    if(maxPath < b){
        maxPath = b;
    }
    pre = inpu;
}

int main()
{
    int count;
    int input = 0;
    int rCount = 0;
    int hCount = 0;
    cin >> count;
    
    cin >> pre;
    
    for(int i = 1; i <count; i ++){
        cin >> input;
        
        
        
        if(pre > input){
            hCount = 0;
            rCount++;
            
        } if(pre < input){
            rCount = 0;
            hCount++;
        }if(pre == input){
            rCount++;
            hCount++;
        }
        
        mMax(rCount <hCount ? hCount :rCount,input);
        
    }
    cout << maxPath+1 <<endl;
    
}
#endif