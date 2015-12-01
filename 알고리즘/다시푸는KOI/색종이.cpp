#if 0

#include <iostream>
using namespace std;
int colorPaper[7];
int numberOfPannel;


void init(){
    for(int i = 1 ;i <=6; i ++){
        cin >> colorPaper[i];
    }
}

int decreasePaper(int size , int remainCount){
    int count = 0;
    while (remainCount-=(size * size)) {
        if(colorPaper[size] == 0){
            break;
        }
        count+=(size * size);
        colorPaper[size]--;
        
    }
    return count;
}

int decreasePaper1(int size , int remainCount){
    int count = 0;
    while (remainCount) {
        if(colorPaper[size] == 0 && remainCount == 0){
            break;
        }else if(colorPaper[size] == 0 && remainCount > 0 ){
            
        }
        
        count+=(size * size);
        colorPaper[size]--;
        remainCount -=(size * size);
        
    }
    return count;
}

void fillSegment(){
#pragma mark - first largest Paper
    numberOfPannel+=colorPaper[6];
    cout << "fill" <<endl;
    
    int pannel = 36;
    int totalCount = 0;
    for(int i = 5; i > 0 ; i --){
        pannel = 36;
        while (colorPaper[i]--) {
            pannel -=(i * i);
            if(i == 5){
                pannel -=decreasePaper(6-i,pannel);
            }else if(i == 4){
                
            }
            
            
        }
        
        if(pannel == 0){
            totalCount++;
        }
    }
    
    cout << totalCount <<endl;
    
}
int main(){
    init();
    fillSegment();
}

/*
 11
 0
 1
 0
 1
 0
 
 */
#endif