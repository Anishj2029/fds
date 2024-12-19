// Department of Computer Engineering has student's club named 'Pinnacle Club'. Students 
// of second, third and final year of department can be granted membership on request. 
// Similarly one may cancel the membership of club. First node is reserved for president of 
// club and last node is reserved for secretary of club. Write C++ program to maintain club 
// member‘s information using singly linked list. Store student PRN and Name. Write 
// functions to:
// a) Add and delete the members as well as president or even secretary.
// b) Compute total number of members of club
// c) Display members
// d) Two linked lists exists for two divisions. Concatenate two lists.

#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
    int prn;
    string name;
    struct node* next;
};
class list{
    public:
    struct node* head = new node;
    
    
    
    void create(struct node* head)
    {
        int prn;
        string name;
        cout<<"\nEnter prn: ";
        cin>>prn;
        cin.ignore();
        cout<<"\nEnter name: ";
        getline(cin,name);
        
        struct node* temp = new node;
        temp->prn=prn;
        temp->name=name;
        temp->next=NULL;
            
    }
    
    void addpresedent(struct node *head)
    {
        int prn;
        string name;
        cout<<"\nEnter presedent prn: ";
        cin.ignore();
        cin>>prn;
        cout<<"\nEnter presedent name: ";
        getline(cin,name);
        
        struct node* temp = new node;
        temp->prn=prn;
        temp->name=name;
        temp->next=NULL;
        

        temp->next = head;
        head=temp;
        cout<<"\nNew presedent created";
    
    }
    
    void addsecretory(struct node* head)
    {
        int prn;
        string name;
        cout<<"\nEnter secretary ptr: ";
        cin>>prn;
        cin.ignore();
        cout<<"\nEnter name of secretary: ";
        getline(cin,name);
    
        struct node* temp = new node;
        temp->prn=prn;
        temp->name=name;
        temp->next=NULL;
    
        struct node* temp1 = head;
        while(temp1->next != NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;
        cout<<"\nNew secretary added";
        
    }
    
    void addmember(struct node *head)
    {
        int prn;
        string name;
        cout<<"\nEnter secretary ptr: ";
        cin>>prn;
        cin.ignore();
        cout<<"\nEnter name of secretary: ";
        getline(cin,name);
        struct node* temp = new node;
        temp->prn=prn;
        temp->name=name;
        temp->next=NULL;
        
        temp->next = head->next;
        head->next = temp;
        cout<<"\nnew member is added";
        
        
    }
    void rempresident(struct node* head)
    {
        struct node* temp = head;
        temp->next = head;
        free(temp);
        temp=NULL;
        cout<<"\npresedent is succefully removed";
        
    }
    void remsecretory(struct node* head)
    {
        struct node* temp = head;
        struct node* temp1 = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next =temp1;
        free(temp1);
        temp1= NULL;
        cout<<"\nsuccesfully secretary removed";
        
    }
    
    void remmember(struct node* head)
    {
        struct node* temp = head;
        temp=head->next;
        temp->next = head->next;
        free(temp);
        temp = NULL;
        cout<<"\nsuccesfully member is removed";
        
        
    }
    void display(struct node* head)
    {
        int count = 0;
        struct node* temp = head;
        while(temp->next != NULL){
            cout<<"the prn is: "<<temp->prn<<"\n"<<"the name is: "<<temp->name;
            count = count + 1;
            temp=temp->next;
        }
        cout<<count;
        cout<<"\nList displayed Successfully !!!";
        
    }
    
    void Concatenate(list& other)
    {
        if(head == NULL){
            head =other.head;
        }
        struct node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head;
        cout<<"\nThe list is Concatenated succesfully !!!";
        
    }
    
    
};

int main(){
    struct node* head = new node;
    list l;
    list l1,l2;
    int prn;
    string name;
    int ch;
    
    do{
        cout<<"Menu";
        cout<<"\n1.Create list\n2.Add president\n3.Add secretary\n4.Add member\n5.Remove president\n6.Remove secretary\n7.Remove member\n8.Display\n9.Concatenate two list\n10.Exit\n";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        
        switch(ch){
            case 1:
            l1.create(l1.head);
            break;
            
            case 2:
            l1.addpresedent(l1.head);
            break;
            
            case 3:
            l1.addsecretory(l1.head);
            break;
            
            case 4:
            l1.addmember(l1.head);
            break;
            
            case 5:
            l1.rempresident(l1.head);
            break;
            
            case 6:
            l1.remsecretory(l1.head);
            break;
            
            case 7:
            l1.remmember(l1.head);
            break;
            
            case 8:
            l1.display(l1.head);
            
            case 9:
            l2.create(l2.head);
            l2.addpresedent(l2.head);
            l2.addmember(l2.head);
            l2.addsecretory(l2.head);
            l1.Concatenate(l2);
            
            case 10:
            cout<<"Exiting from program !!!";
            break;
            
            
        }
    }while(ch != 10);
}
