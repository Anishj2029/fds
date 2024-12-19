// A double-ended queue (deque) is a linear list in which additions and deletions may be 
// made at either end. Obtain a data representation mapping a deque into a one-dimensional array. Write C++ program to simulate deque with functions to add and 
// delete elements from either end of the deque.
#include<iostream>
#include<string>
using namespace std;
#define size 5
string Dequeue[size];

class dequeue{
    private:
    int front,rear;
    
    public:
    dequeue(){
        front = -1;
        rear = -1;
    }
    
    bool isempty(){
        return front == -1 ;
    }
    bool isfull(){
        return (rear + 1) % size == front;
    }
    
    void addrear(string& data){
        if(isfull()){
            cout<<"The Queue is full !!!"<<endl;
        }
        if(isempty()){
            front =  0;
            rear  =  0;
        }
        else{
            rear = (rear + 1 )% size;
        }
        Dequeue[rear] = data;
        cout<<"Data is added at rear !"<<endl;
    }
    
    void removefront(){
        if(isempty()){
            cout<<"The Queue is empty !!!"<<endl;
        }
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            cout<<"Removed from front"<<Dequeue[front]<<endl;
            front = (front + 1) % size;
        }
    }

    
    void addfront(string data){
        if(isfull()){
            cout<<"The Queue is full !!!"<<endl;
        }
        if(isempty()){
            front =  0;
            rear  =  0;
        }
        else{
            front = (front - 1 + size )% size;
        }
        Dequeue[front]=data;
        cout<<"The data is added at front !!!"<<endl;
    }
    void removerear(){
        if(isempty()){
            cout<<"The Queue is empty !!!"<<endl;
        }
        if(front == rear){
            front = -1;
            rear = -1;
        }else{
            cout<<"The delete data from Queue"<<Dequeue[rear]<<endl;
            rear = (rear - 1 + size)% size;
        }
            
    }
    void display() {
    if (isempty()) {
        cout << "The Queue is empty!" << endl;
        return;
    }
    cout << "Queue contents: ";
    for (int i = front;; i = (i + 1) % size) {
        cout << Dequeue[i] << " ";
        if (i == rear)
            break;
    }
    cout << endl;
}

};

int main(){
    string data;
    int ch;
    dequeue d;
    
    do{
        cout<<"---Menu---"<<endl;
        cout<<"1. Add at rear"<<endl;
        cout<<"2. remove at front"<<endl;
        cout<<"3. Add at front"<<endl;
        cout<<"4. Remove at rear"<<endl;
        cout<<"5. Display"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"\nEnter the choice : ";
        cin>>ch;
        
        switch(ch){
            case 1:
            cout<<"Enter the data: ";
            cin>>data;
            d.addrear(data);
            break;
            
            case 2:
            d.removefront();
            break;
            
            case 3:
            cout<<"Enter the data: ";
            cin>>data;
            d.addfront(data);
            break;
            
            case 4:
            d.removerear();
            break;
            
            case 5:
            d.display();
            break;
            
            case 6:
            cout<<"The program is Ended !!!"<<endl;
            break;
        }
    }while(ch != 6);
}