

#if 0
int w,h;
int antStartI , antStartJ;
int finishTime;
int main(){
    
    cin >> w >> h ;
    cin >> antStartJ >> antStartI;
    cin >> finishTime;
    
    finishTime = (finishTime % (w * h));
    cout << finishTime <<endl;
    int dirI = 1;
    int dirJ = 1;
    
    while (finishTime--) {
        if(antStartI == 0){
            dirI = 1;
        } if(antStartI == h){
            dirI = -1;
        } if(antStartJ == 0){
            dirJ = 1;
        } if(antStartJ == w){
            dirJ = -1;
        }
        
        if(dirI == 0 && dirJ == 0){
            
        }
        
        cout << antStartJ << " "<<antStartI <<endl;
        antStartJ += dirJ;
        antStartI += dirI;
        
        
    }
    cout << antStartJ <<" " <<antStartI << endl;
}

#endif