#if 0 

#include <iostream>
#include <string>
using namespace std;

enum RSP{
    R = 0,
    S,
    P,
    N,
};

string s[12];
int disAble[13]={0,};
int rsp[3]={0,};


void init(int size){
    
    
    for(int i = 0; i<=11; i ++){
        s[i].clear();
        disAble[i] = 0;
    }
    
    
    for(int i = 0 ; i < size; i ++){
        cin >> s[i];
    }
    
    
}

RSP validation(){
    
    RSP ret = N;
    if(rsp[R] == 0 && rsp[P]> 0 && rsp[S] > 0){
        ret =S;
    }
    else if(rsp[R] > 0 && rsp[P] == 0 && rsp[S] > 0){
        ret =R;
    }
    else if(rsp[R] > 0 && rsp[P]> 0 && rsp[S] == 0){
        ret =P;
    }
    
    return ret;
}

void injectResult(RSP ret , int size){
    
    
    for(int j = 0; j < size; j++){
        
        
        string temp = s[j];
        if(temp.length() == 0 && disAble[j] == -1) continue;
        if(ret == N){
            
            disAble[j] ++;
            continue;
        }
        char c = temp[disAble[j]];
        RSP cnt = N;
        switch (c) {
            case 'R':
                cnt = R;
                break;
            case 'S':
                cnt = S;
                break;
            case 'P':
                cnt = P;
                break;
                
            default:
                break;
        }
        if(cnt == ret){
            disAble[j]++;
            continue;
        }
        if(ret != cnt && cnt != N && ret != N){
            s[j].clear();
            disAble[j] = -1;
        }
    }
}

void print(int size){
    
    long tempSize = s[0].length();
    for(int i = 0 ; i <tempSize; i ++){
        rsp[R] = rsp[S] = rsp[P] = 0;
        for(int j = 0; j < size; j++){
            string temp = s[j];
            char cnt =temp[disAble[j]];
            switch (cnt) {
                case 'R':
                    rsp[R]++;
                    break;
                case 'S':
                    rsp[S]++;
                    break;
                case 'P':
                    rsp[P] ++;
                    break;
                    
                default:
                    break;
            }
            
        }
        
        RSP ret =validation();
        injectResult(ret , size );
        
    }
    
}
int main(){
    
    int tc;
    cin >> tc;
    while (tc--) {
        int size;
        cin >> size;
        init(size);
        print(size);
        
        
        int maxIndex = 0;
        int count = 0;
        for(int i = 0; i < size ; i++){
            if(disAble[i] != -1){
                count++;
                maxIndex = i;
            }
            
        }
        
        if(count == 1){
            cout << maxIndex+1<<endl;
        }else{
            cout << 0 <<endl;
        }
        
    }
}
#endif