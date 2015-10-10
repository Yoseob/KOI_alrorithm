#if 0 


#include <iostream>
using namespace std;
int map[100][100] = {0,};

void draw(int x ,int dx, int y , int dy){
    for(int i = x ; i< dx; i ++){
        for(int j = y; j < dy; j ++){
            map[j][i] = 1;
        }
    }
}

void print(){
    int sum = 0;
    for(int i = 0; i <100; i ++){
        for(int j = 0; j<100; j ++){
            sum+= map[i][j];
            
        }
    }
    cout << sum <<endl;
}
int main(){
    
    int count;
    cin >> count;
    int x , y;
    int dx , dy;
    for(int i = 0; i<count; i ++){
        cin >> x >> y;
        
        dx = x+10;
        dy = y+10;
        if(dx >=100){
            dx = 100;
        }
        if(dy >= 100){
            dy = 100;
        }
        draw(x, dx, y, dy);
    }
    print();
    
}



#endif