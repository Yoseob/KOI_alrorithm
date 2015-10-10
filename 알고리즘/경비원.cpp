#if 0



#include <iostream>
#include <math.h>
#define FLOW 1

using namespace std;

struct Pos{
    int x;
    int y;
    int position;
    int see;
};


Pos shop[101]={0,};
Pos my;

Pos rMyLoc[5];
int rFlow[5] ={0,1,4,2,3};

Pos myLocs[5];
int flow[5] = {0,1,3,2,4};
int h;
int w;
inline int mabs(int a){
    return a > 0 ? a: a*(-1);
}

void initPoint(){
    rMyLoc[1] = {w,0,1,4};
    rMyLoc[2] = {0,h,2,3};
    rMyLoc[3] = {0,0,3,1};
    rMyLoc[4] = {w,h,4,2};
    
    myLocs[1] = {0,0,1,3};
    myLocs[2] = {w,h,2,4};
    myLocs[3] = {0,h,3,2};
    myLocs[4] = {w,0,4,1};
    
}
int findStartLoc(int *arr ,int loc){
    for(int i = 1; i <=4; i++){
        if(*(arr+i) == loc){
            return i;
        }
    }
    return 0;
}

int getDistance(Pos x , Pos x_){
    return  sqrt(pow(mabs(x.x-x_.x), 2)+pow(mabs(x.y-x_.y), 2));
}


int main(){
    int count;
    cin >> w >> h ;
    cin >> count;
    
    int pos;
    int len;
    for(int i = 1; i <=count; i ++){
        cin >> pos >> len;
        
        if(pos == 1|| pos == 2){
            shop[i].x = len;
            shop[i].y = 0;
            if(pos == 2) {shop[i].y = h;}
            shop[i].position = pos;
        }else{
            shop[i].y = len;
            shop[i].x = 0;
            if(pos == 4) shop[i].x = w;
            shop[i].position = pos;
        }
    }
    cin >> pos >> len;
    
    my.position = pos;
    if(pos ==1 || pos == 2){
        my.x = len;
        if(pos == 2) {my.y = h;}
    }else{
        my.y = len;
        if(pos == 4) my.x = w;
    }
    
    initPoint();
    Pos currentShop;
    Pos tempMy;
    int startloc;
    
    
    int minSum=0;
    int onepathLen = 0;
    int secondpathLen = 0;
    for(int i = 1; i <=count; i ++) {
        currentShop = shop[i];
        tempMy = my;
        startloc = findStartLoc(rFlow, tempMy.position);
        //rFlow;
        
        onepathLen = secondpathLen = 0;
        for(int j = 0; j<4; j++){
            
            int nextLoc = rFlow[startloc];
            if(currentShop.position == my.position && j == 0){
                
                onepathLen+= getDistance(currentShop, tempMy);
                break;
            }
            if(currentShop.position == tempMy.see){
                onepathLen += getDistance(currentShop, tempMy) ;
                break;
            }else{
                onepathLen+= getDistance(rMyLoc[nextLoc], tempMy);
                tempMy =rMyLoc[nextLoc];
                
            }
            if(startloc == 4){
                startloc =1;
            }else{
                startloc++;
            }
            
        }
        
        //
        tempMy = my;
        startloc = findStartLoc(flow, tempMy.position);
        for(int j = 0; j<4; j++){
            
            int nextLoc = flow[startloc];
            
            if(currentShop.position == my.position && j == 0){
                
                secondpathLen+= getDistance(currentShop, tempMy);
                break;
                
            }
            if(currentShop.position == tempMy.see){
                secondpathLen+= getDistance(currentShop, tempMy);
                break;
            }
            else{
                secondpathLen+= getDistance(myLocs[nextLoc], tempMy);
                tempMy =myLocs[nextLoc];
                
            }
            if(startloc == 4){
                startloc =1;
            }else{
                startloc++;
            }
            
        }
        
        minSum +=  onepathLen > secondpathLen ? secondpathLen : onepathLen;
        
        
    }
    cout << minSum <<endl;
    
    
    
    
    
}


#endif