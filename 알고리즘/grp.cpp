#if 0
#include <iostream>
using namespace std;
int main(){
    int k ,n;
    
    cin >> n >> k;
    int sum ;
    int result = 0;
    for(int i= 0; i<n-k+1; i++){
        sum = 0;
        for(int j = i+1; j<=k+i; j ++){
            sum+=j;
        }
        if(sum%15 ==0){
            result++;
        }
    }
    cout << result <<endl;
}
#endif