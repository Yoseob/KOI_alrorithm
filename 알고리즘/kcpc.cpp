#if 0 

#include <iostream>
#include <algorithm>
using namespace std;
class Log{
    
public:
    int logIndex;
    int fre;
    int score;
    int teamnumber;
    Log():logIndex(0), fre(0),score(0) ,teamnumber(0){}
    Log(int i , int f ,int s ) : logIndex(i), fre(f),score(s){}
    void clear(){
        this->logIndex = 0;
        this->fre = 0;
        this->score = 0;
    }
    
};
bool isLarge(const Log l1 , const Log l2) {
    return ((l1.score < l2.score)||
            ((l1.score == l2.score) && (l1.fre > l2.fre))||
            ((l1.score == l2.score) && (l1.fre == l2.fre) && (l1.logIndex > l2.logIndex)));
}

int n , k ,t ,m;



void init(Log (*map)[101] , Log *resultSet ){
    
    
    
    
    cin >> n >> k >> t >> m;
    int teamId , numberofQustion , score;
    for(int i = 1; i <= m ; i++){
        cin >> teamId >> numberofQustion >> score;
        int fre = map[teamId][numberofQustion].fre;
        int preScore = map[teamId][numberofQustion].score;
        
        preScore = preScore > score  ? preScore : score;
        map[teamId][numberofQustion] = {i,fre+1, preScore};
        
        
        resultSet[teamId].fre++;
        resultSet[teamId].logIndex = resultSet[teamId].logIndex >i ?resultSet[teamId].logIndex : i;
        
    }
    
    
    for(int i = 1; i <=n ; i++){
        int total = 0;
        for(int j = 1; j <=k ; j ++){
            total += map[i][j].score;
        }
        resultSet[i].score = total;
        
    }
    
    int count = 0;
    for(int i = 1; i <=n ; i++){
        
        if(i == t) continue;
        
        if(isLarge(resultSet[t], resultSet[i])){
            count++;
        }
        
    }
    
    
    
    cout << count+1<< endl;
}

int main(){
    int tc ;
    cin >> tc ;
    while (tc--) {
        Log map[101][101];
        Log resultSet[101];
        init(map , resultSet);
        
    }
    
}
#endif