#if 0

#include <iostream>
using namespace std;

int dxdy[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};

int cinema[1001][1001] ={0,};
int r, c;
void printMap(){
    for(int i = 1; i <=r; i ++ ){
        for(int j = 1; j<=c; j++){
            cout <<cinema[i][j] << " ";
        }
        cout <<endl;
        
    }
}
int main(){
    
    
    cin >> r >> c;
    int finish;
    cin >> finish;
    
    
    int count=1;
    int starti =1 , startj = 2;
    int i = 1 , j = 0;
    int dx , dy;
    int dir = 0;
    
    int tempc = c, tempr =r;
    
    
    if(finish > r*c){
        
        cout << 0 << endl;
        return 0;
    }
    
    
    
    while ((finish--) != 0) {
        if(dir == 4){
            dir = 0;
        }
        
        
        dx = dxdy[dir][0];
        dy = dxdy[dir][1];
        dx+=i;
        dy+=j;
        cinema[dx][dy] =  count++;
        switch (dir) {
            case 0:j++;break;
            case 1:i++;break;
            case 2:j--;break;
            case 3:i--;break;
            default:break;
        }
        
        if(j == tempc && dir == 0){
            dir ++;
            tempc--;
        }else if(i == tempr && dir== 1){
            dir++;
            tempr--;
        }
        else if(j == starti && dir == 2){
            dir++;
            starti++;
        }else if(i == startj && dir == 3){
            dir++;
            startj++;
        }
        
        
        //        printMap();
        //        getchar();
    }
    cout << i << " "<<j <<endl;
    
}



#endif