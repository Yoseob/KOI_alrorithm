#if 0
#include <iostream>
#include <queue>
using namespace std;

class Postion{
public:
    int i;
    int j;
    Postion(){}
    Postion(int  mi ,int mj) : i(mi) , j(mj){
    }
};

int dxdy[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};


queue<Postion> q;
int totalCount =0;
int total[100] = {0,};
int myMp[26][26] ={0,};
int mapSize;
int visited[26][26]={0,};
void postNumber(Postion pos){
    
    int zcount = 1;
    q.push(pos);
    visited[pos.i][pos.j] = zcount++;
    myMp[pos.i][pos.j] = -1;
    while (!q.empty()) {
        
        Postion crt = q.front();q.pop();
        for(int i = 0; i<4; i++){
            int di = crt.i + dxdy[i][0];
            int dj = crt.j + dxdy[i][1];
            if(visited[di][dj] == 0 && myMp[di][dj] == 1 &&
               di > 0 && di <= mapSize && dj > 0 && dj <=mapSize){
                q.push(Postion(di , dj));
                visited[di][dj] = zcount++;
                myMp[di][dj] =zcount;
            }
        }
        
    }
    total[totalCount ++] = zcount-1;
}
int main(){
    
    cin >> mapSize;
    char lines[25];
    int temp = 0;
    for(int i = 1; i <=mapSize ; i ++){
        cin >> lines;
        
        for(int j = 1 ; j<=mapSize; j++){
            temp =   lines[j-1] - '0';
            myMp[i][j] = temp;
            
        }
    }
    
    
    for(int i = 1; i <=mapSize ; i ++){
        for(int j = 1 ; j<=mapSize; j++){
            if(myMp[i][j] == 1){
                postNumber(Postion(i,j));
            }
        }
    }
    for(int i = 0; i <totalCount; i ++){
        for(int j = 0; j<totalCount ; j++){
            if(total[i] < total[j]){
                int temp = total[j];
                total[j] =total[i];
                total[i] = temp;
            }
        }
    }
    cout << totalCount <<endl;
    for(int i = 0; i <totalCount; cout <<total[i++]<<endl);
    
}
#endif