#if 0
#include <iostream>
using namespace std;
int arr[10] = {0,};

int main(){
    int index = 0;
    cin >> index;
    int input;
    for(int i = 0; i < 5; i ++){
        cin >> input;
        arr[input]++;
    }
    cout << arr[index] << endl;
}
#endif