#if 0 

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


int map[101][101];
int maxNumber;
int childComNumber;
int c = 0;
vector<int> v;

void floodVirus(int i){
    
    if(map[i][0] == 1){
        return;
    }
    c++;
    map[i][0] = 1;
    for(int j = 1; j <=maxNumber; j ++){
        if(map[i][j] == 1){
            floodVirus(j);
        }
    }
}

void init(){
    cin >> maxNumber;
    cin >> childComNumber;
    
    memset(map, 0, sizeof(map));
    int ti,tj;
    
    for(int i = 0 ; i <childComNumber; i ++){
        cin >> ti >> tj;
        map[ti][tj] = map[tj][ti] = 1;
    }
    
}

int main(){
    init();
    
    floodVirus(1);
    cout << c-1 <<endl;
}
#endif