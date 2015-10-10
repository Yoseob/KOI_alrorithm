#if 0
#include <iostream>
using namespace std;

class Map{
    char map[102][102];
    int count;
    int width, height ;
public :

    Map(){
        count = 0;
        cin >> height >> width;
        for(int i =1; i<=height; i++){
            for(int j = 1; j<=width; j++){
                cin >> map[i][j];
            }
        }
    }
    
    void findLake(){
        for(int i =1; i<=height; i++){
            for(int j = 1; j<=width; j++){
                if(map[i][j] == 'W'){
                    floodFill(i, j);
                    count++;
                }
            }
        }
    }
    
    int getLakeCount(){
         return count;
    }
    
private:
    void floodFill(int i,int j){
        if(map[i][j] == 'W' && ( j>0 && j <=width) &&  i>0 && i <=height){
            map[i][j] = '.';
            floodFill(i-1, j); // 오른쪽 대각선
            floodFill(i-1, j+1); // 오른쪽 대각선
            floodFill(i-1, j-1); // 오른쪽 대각선
            floodFill(i+1, j+1); // 오른쪽 대각선
            floodFill(i+1, j-1); // 왼쪽 대각선
            floodFill(i, j+1);  //오른쪽
            floodFill(i, j-1);  //온쪽
            floodFill(i+1, j);  //온쪽
        }

    }
    
    
};

int main(){

    
    Map map;
    map.findLake();
    cout <<map.getLakeCount() <<endl;

}

#endif

#if 0


#include <iostream>
using namespace std;

class Stack {
    public :
    char stack[31];
    int index;
    
    int resultIndex;
    int result[100];
    
    Stack(){
        index = 1;
        resultIndex = 0;
    }

    void push(char data){
        stack[index++] = data;
        result[resultIndex++] = 1;
    }
    char top(){
        return stack[index-1];
    }
    void pop(){
        result[resultIndex++] = 0;
        index--;
    }
    void printResult(){
        for(int i =0; i <resultIndex; i ++){
            if(result[i] == 1) {
                cout << "push" << endl;
            }else{
                cout <<"pop" << endl;
            }
        }
    }
};

int main(){

    
    char a = 'a';
    char inputArr[30] ={0,};
    int index= 0;
    int arrIndex = 0;
    int inputIndex = 0;

    
    
    cin >> inputArr;
    while (inputArr[index++]!= '\0'){}


    Stack stack;
    int temp = index;
    int flag = 1;
    index--;
    while (index) {
        if(stack.top()==inputArr[arrIndex]){
            arrIndex++;
            index--;
            stack.pop();
        }else{
            if(temp < inputIndex){
                flag = 0;
                break;
            }
            stack.push(a+inputIndex++);
        }
    }
    
    if(flag){
        stack.printResult();
    }else{
        cout << "impossible"<<endl;
    }
    
}

#endif  

#if 0
#include <iostream>
using namespace std;
///OCP

class SwitchAble{
protected:
    bool state;
public:
    virtual void on()= 0;
    virtual void off()= 0;
    void logger(){
        cout << state << endl;
    }
    virtual ~SwitchAble(){}
};

class Led : public SwitchAble{
private:

public:
    
    Led(){
        state = false;
    }
    void on(){
        state = true;
        logger();
    }
    
    void off(){
        state = false;
        logger();
    }
};

class TV : public SwitchAble{
private:

public:
    
    TV(){
        state = false;
    }
    void on(){
        state = true;
        logger();
    }
    
    void off(){
        state = false;
        logger();
        
    }
};

class Switch{
private:
    SwitchAble * mSwt;
    
public:
    Switch(SwitchAble * swt){
        mSwt = swt;
    }
    Switch(SwitchAble &swt){
        mSwt =&swt;
    }
    
    void turnOn(){
        mSwt->on();
    }
    void turnOff(){
        mSwt->off();
     
    }
    
    

    
};



int main(){
    Led led;
    
    TV * mTv = new TV();
    
    Switch*switcher = new Switch(mTv);
    switcher->turnOn();
    switcher->turnOff();
    
    Switch*ledSwitch = new Switch(&led);
    ledSwitch->turnOn();
    ledSwitch->turnOff();
    
    
}


#endif


#if 0 
#include <iostream>
using namespace std;

class Membership{
protected:
    string admin;
    string name;
public:
    Membership(){
        cout << "Membership" <<endl;
    }
    void coding(){}
    void study(){}
    virtual ~Membership(){
        cout << "~Membership" <<endl;
    }
};


class Friendship : public Membership{
public:
    string school;
    Friendship(){
        cout << "Friendship" <<endl;
    }
    ~Friendship(){
        cout << "~Friendship" <<endl;
    }
    
    
};

int main(){
    Friendship * f = new Friendship();
    delete f;
}




#endif

#if 0
#define interface struct
#include <iostream>
using namespace std;



interface ICamera{
public:
    virtual void take(){};
    virtual ~ICamera(){};
};


class DslrCamera : public ICamera{
public:
    void take(){
        cout << "DslrCamera take"<<endl;
    }
    
};


class Camera : public ICamera{
public:
    void take(){
        cout << "Camera take"<<endl;
    }
    ~Camera(){}
};


class People{

public:
    
    People(){}
    void take(ICamera	 * ca){
        ca->take();
    }
};

int main(){

    People * p =new People();
    Camera * c = new Camera();
    DslrCamera * d = new DslrCamera();
    p->take(c);

}
#endif

#if 0
#include <iostream>
using namespace std;

class DataObject{
    int age;
    string name;
public:
    DataObject(string name , int age ):age(age),name(name){}
    
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }

};

class AbstractReader{
public:
    virtual DataObject* readContent() = 0;
    virtual ~ AbstractReader(){}
};

class AbstractDisplayer{
public:
    virtual void displayContent(AbstractReader * reader) = 0;
    virtual ~ AbstractDisplayer(){}
};


class DbReader:public AbstractReader{
public:
    DbReader(){}
    virtual DataObject* readContent(){
        DataObject * data = new DataObject("yoseob",27);
        return data;
    }
};


class FileReader:public AbstractReader{
public:
    FileReader(){}
    virtual DataObject* readContent(){
        DataObject * data = new DataObject("yoseob",27);
        return data;
    }
};

class MobileDisplayer : public AbstractDisplayer{
public:
    MobileDisplayer(){}
    
    virtual void displayContent(AbstractReader * reader){
        DataObject * data = reader->readContent();
        cout << data->getAge() <<data->getName() <<endl;
    }
    
};

class PcDisplayer : public AbstractDisplayer{
public:
    PcDisplayer(){}
    
    virtual void displayContent(AbstractReader * reader){
        DataObject * data = reader->readContent();
        cout << data->getAge() <<data->getName() <<endl;
    }
    
};
int main(){
    
    FileReader * reader = new FileReader();
    DbReader * dbReader = new DbReader();
    PcDisplayer  *displayer = new PcDisplayer();
    
    displayer->displayContent(reader);
    displayer->displayContent(dbReader);
    
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;
class SwitchAble{

public:
    bool state;
    virtual void on()= 0;
    virtual void off() = 0;
    virtual bool getState() = 0;
    virtual ~SwitchAble(){}
};
class Led : public SwitchAble{

public:
    Led(){ state = false;}
    void on(){state = true;}
    void off(){state = false;}
    bool getState(){
        return state;
    }
};


class Switch{
public:
    Switch(){}
    void turnOn(SwitchAble * obj){
        obj->on();
        cout <<"turnOn" <<endl;
    }
    
    void turnOff(SwitchAble * obj){
        obj->off();
        cout <<"turnOff" <<endl;
    }
};


class Sensor{
    Switch * sw;
    SwitchAble * target;

public:
    
    Sensor(SwitchAble * obj) : target(obj){
        sw = new Switch();
    }
    void detect(){
        
        if(target->getState()){
            sw->turnOff(target);

        }else{
            sw->turnOn(target);
        }
        
    }
};


int main(){
    
    vector<SwitchAble*> list;
    list.push_back(new Led());

    int input = 0;
    SwitchAble * sa = (Led*)list.at(input);
    Sensor * sensor = new Sensor(sa);
    sensor->detect();
    sensor->detect();
    
}
#endif
#if 0 
//bui
#include <iostream>
using namespace std;
int main(){
    
    /*
     
     사이즈를 입력받는다. 
     좌우를 나눈다. 좌가 하나더 같는다. (좌는 같고 우만 홀짝을 나눈다.)
     
     
     */
    int size ;
    cin >> size;
    
    int row =0;
    cout <<" **";
    for(int i = 1; i<=size; i ++){
        cout <<" ";
    }
    cout <<"**"<<endl;

    
    int tSize=size+6;
    int flag = 0;
    while (++row) {
        row--;
        for(int i =0; i<row; i ++){
            cout << " ";
        }
        
        int end =tSize-row*2;
        for(int i =1; i<=end; i ++){
            if(i == 2 || i== 3  || i==(end-1) || i==(end-2)){
                if(i == 1){
                    if(size%2 == 1){
                        cout <<"* *";
                        flag = 1;

                    }else{
                        cout <<"**";
                        return 0;
                    }
                    break;
                }
                cout << " ";
            }else if(i >4 && i < end-3){
                cout <<" ";
                
            }else{
                cout << "*";
                if(flag == 1){
                    return 0;
                }
            }

        }
        for(int i =row; i<size; i ++){
            cout << " ";
        }
        row++;

        cout << endl;
        

    }
    
}

#endif

#if 0
#include <iostream>
using namespace std;
class Point;
class Queue{

    int font,rear;
    Point* q[100];
public:
    Queue() :rear(0),font(0){
    }
    void enQueue(Point * data){
        q[rear++] = data;
    }
   
    Point* deQueue(){
        return q[font++];
    }
    bool isEmpty(){
        return font == rear;
    }
};

class Point{
    int i,j;
public:
    Point(int i,int j):i(i) , j(j){}
    int getI(){return i;}
    int getj(){return j;}
};

Queue * q;


char map[20][20] ={0,};
int visited[20][20]={0,};
int dxdy[4][2]= {{0,1},{1,0},{-1,0},{0,-1}};


void draw(){
    for(int i = 0; i <20; i++){
        for(int j = 0; j<20; j++){
            if(visited[i][j] == 0){
                cout <<" ";
            }else{
                cout <<visited[i][j];
            }
        }
        cout <<endl;
        
    }
            cout <<endl;
}
void bfs(Point * point, int size){
    q->enQueue(point);
    visited[point->getI()][point->getj()]= size;
    
    
    while (!q->isEmpty()) {
        
        
        Point * currnt = q->deQueue();

            for(int i =0;i<4;i ++){
                int di = currnt->getI()+dxdy[i][0];
                int dj = currnt->getj()+dxdy[i][1];
                if(visited[di][dj] ==0  ){
                    int nextV =visited[currnt->getI()][currnt->getj()]-1;
                    if(nextV == 0){
                        draw();
                        return ;
                    }
                    visited[di][dj]= nextV;
                    q->enQueue(new Point(di,dj));
                    
                }
        }
    }
    draw();

    

}

int main(){
    int size;
    cin >> size;
 
    q= new Queue();
    
    bfs(new Point(size/2,size/2) , size/2+1 );
}
#endif