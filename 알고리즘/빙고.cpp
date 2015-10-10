#if 0

#include <iostream>
using namespace std;
int bingo[5][5] = {0,};

int flag = 1;
int ret = 0;
void call(int a){
    for(int i = 0;i<5; i ++){
        for(int j = 0; j<5; j++){
            if(bingo[i][j] == a){
                bingo[i][j] = 0;
                return;
            }
        }
    }
}
void print(){
    for(int i = 0;i<5; i ++){
        for(int j = 0; j<5; j++){
            //            printf("%2d ",bingo[i][j]);
        }
        cout <<endl;
    }
    cout <<endl;
}
int checkBingo(int result){
    int mcount = 0;
    for(int i = 0; i < 5; i ++){
        int rowCount = 0;
        int colCount = 0;
        for(int j = 0; j<5;j++){
            if(bingo[i][j] == 0 ){
                rowCount++;
                if(rowCount ==5){
                    mcount ++;
                }
            }
            if(bingo[j][i] == 0){
                colCount++;
                if(colCount ==5){
                    mcount ++;
                }
            }
        }
    }
    int x[4] = {0,};
    for(int s = 0; s <5; s++){
        if(bingo[s][s] == 0){
            x[0]++;
            if(x[0]==5){
                mcount ++;
            }
        }if(bingo[4-s][s] == 0 )
        {
            x[2]++;
            if(x[2]==5)
            {
                mcount ++;
            }
        }
    }
    return mcount;
}

int main(){
    
    for(int i = 0;i<5; i ++){
        for(int j = 0; j<5; j++){
            cin >> bingo[i][j];
        }
    }
    int inputs[26]=  {0,};
    int input = 0;
    for(int i = 1;i<=25; i ++){
        cin >> inputs[i];
    }
    for(int i = 1; i <=25; i ++){
        input = inputs[i];
        call(input);
        if(checkBingo(i) >=3){
            cout << i << endl;
            break;
        }
    }
    return 0;
}
#endif