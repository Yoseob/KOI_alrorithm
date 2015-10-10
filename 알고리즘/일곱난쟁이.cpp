#if 0
#include <iostream>

using namespace std;
/*
 
 입력 : 9개의 정수가 주어진다.
 
 알고리즘 :
 
 소팅을 먼저 한다. 그래야 좋을꺼같다...ㅋㅋㅋㅋㅋ
 그리고 순열 찾듣이 배열에 넣고 비에프돌린다.? 순서에 상관없이 ??
 
 출력:9개중 7개의 합이 100인 부분 집합을 찾아, 오름차순으로 정렬한다.
 
 
 
 */

int visited[10] ={1,};
int list[10] = {0,};
int result[10] = {0,};
int real[10] = {0,};
int sum = 0;
int flag = 1;

void sort(){
    
    for(int i = 1; i <=7; i++){
        for(int j = 1; j<=7; j++){
            if(real[i] < real[j]){
                int t = real[i];
                real[i] = real[j];
                real[j] = t;
            }
        }
    }
}
void findGroup(int index){
    if(index == 8 ){
        int s = 0;
        for(int i = 1; i <=7; i++){
            if(result[i] != 0){
                s += result[i];
                real[i] = result[i];
            }
        }
        if(s == 100){
            if(flag ==1){
                sort();
                for(int i = 1; i <=7; i++){
                    cout << real[i]  <<endl;
                }
                flag = 0;
            }
        }
        return ;
    }

    for(int j = 1; j<=9; j ++){
        if(visited[j] != 0){
            visited[j]--;
            result[index] = list[j];
            findGroup(index+1);
            visited[j]++;
        }
    }
}
int main(){
    
    for(int i = 1; i <=9; i ++){
        cin >> list[i];
        visited[i] = 1;
    }
    
    findGroup(1);
    
    
    
    
}


#endif