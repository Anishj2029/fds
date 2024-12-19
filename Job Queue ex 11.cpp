// Queues are frequently used in computer programming, and a typical example is the
// creation of a job queue by an operating system. If the operating system does not use
// priorities, then the jobs are processed in the order they enter the system. Write C++
// program for simulating job queue. Write functions to add job and delete job from queue.
#include<iostream>
#include<string>
using namespace std;
#define size 5
string Queue[size];

class job{
    private:
    int front,rear;
    public:
    
    job(){
        front = -1;
        rear  = -1;
    }
    
    bool isfull(){
        return rear == size -1;
    }
    bool isempty(){
        return front == -1 || front > rear;
    }
    
    void addjob(string id){
        if(isfull()){
            cout<<"The Queue is full !!!"<<endl;
        }
        else{
            if(front=-1)
            front = 0;
            rear = rear + 1;
            Queue[rear] = id;
            cout<<"Job added successfully !!!"<<endl;
        }
    }
    
    void deljob(){
        if(isempty()){
            cout<<"The Queue is empty !!!"<<endl;
        }
        else{
            cout<<"The job is deleted"<<Queue[front]<<endl;
            front = front + 1;
            cout<<"Job is deleted successfully !!!"<<endl;
        }
    }
    
    void display(){
        if(isempty()){
            cout<<"The Queue is empty !!!"<<endl;
        }
        else{
            for( int i =0 ; i<=rear;i++){
                cout<<"job : "<<Queue[i]<<endl;
            }
        }
    }
};

int main(){
    job j;
    string id;
    int ch;
    do{
        cout<<"---Menu---"<<endl;
        cout<<"1. Add job"<<endl;
        cout<<"2. Delete job"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        
        cout<<"\nEnter the choice : ";
        cin>>ch;
        
        switch(ch){
            case 1:
            cout<<"Enter the job: ";
            cin>>id;
            j.addjob(id);
            break;
            
            case 2:
            j.deljob();
            break;
            
            case 3:
            j.display();
            break;
            
            case 4:
            cout<<"Program Ended !!!"<<endl;
            break;
        }
    }while(ch != 4);
}