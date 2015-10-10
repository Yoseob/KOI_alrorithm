#if 0 

#include <iostream>
#include <queue>
using namespace std;
class Postion{
    int i ,j;
public:
    
    Postion(int i,int j): i(i), j(j){
    }
    int getI(){
        return this->i;
    }
    int getJ(){
        return this->j;
    }
    
};
int dxdy[4][2] ={{1,0},{0,1},{0,-1},{-1,0},};

class Map{
    char map[52][52];
    int visited[52][52];
    int row, col;
    int result;
    queue<Postion> q;
    
public:
    Map(){
        cin >> row >> col;
        result  = 0;
        for(int i = 0; i <row; i ++){
            for(int j = 0 ; j<col; j++){
                cin >>map[i][j];
            }
        }
    }
    
    void findImpl(Postion pos ){
        clean();q.push(pos);
        
        int breath = 1;
        visited[pos.getI()][pos.getJ()] = breath;
        
        int nexti = 0 , nextj = 0;
        while (!q.empty()) {
            Postion current = q.front();q.pop();
            for(int i = 0; i <4; i ++ ){
                nexti = current.getI()+dxdy[i][0];
                nextj = current.getJ()+dxdy[i][1];
                
                if((nexti>=0 && nexti <=row ) && (nextj>=0 && nextj <=col) &&
                   (visited[nexti][nextj] ==0) && map[nexti][nextj]=='L'){
                    visited[nexti][nextj] = visited[current.getI()][current.getJ()] +1;
                    breath = visited[nexti][nextj];
                    q.push(Postion(nexti, nextj));
                }
            }
            if(breath> result){
                result =breath;
            }
        }
    }
    
    void clean(){
        for(int i = 0; i <row; i ++){
            for(int j = 0 ; j<col; j++){
                visited[i][j] = 0;
                
            }
        }
    }
    
    void find(){
        
        for(int i = 0; i <row; i ++){
            for(int j = 0 ; j<col; j++){
                if(map[i][j] == 'L'){
                    findImpl(Postion(i, j));
                }
            }
        }
        cout <<result-1 <<endl;
    }
};


int main(){
    Map map;
    
    map.find();
    
    
}
#endif