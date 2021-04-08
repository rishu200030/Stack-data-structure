#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};


int isFull(){
    struct Node *n =(struct Node *)malloc(sizeof(struct Node));
    if(n == NULL){  //it will try to create an empty node if node is not created by malloc it will return NULL
                    // this indicates memory in heap is full no nodes can be created further
        return 1;
    }else{
        return 0;
    }
};

int isEmpty(struct Node * top){
     if(top == NULL){
        return 1;
    }else{
        return 0;
    }
};

int display(struct Node *top)
{
    if (! isEmpty(top))
    {
        
        cout << "The Elements of Stack are : ";

        while (top != NULL)
        {
            cout << top->data << "  ";
            top = top->next;
        }
        cout<<endl;
    }
    else
    {
        cout << "Stack Underflow " << endl;
    }
    return 1;
};

struct Node *push(struct Node *top){
    struct Node *n =(struct Node *)malloc(sizeof(struct Node));
    if(isFull()){
        cout<<"Stack Overflow"<<endl;
    }else{
        struct Node *ptr =(struct Node *)malloc(sizeof(struct Node));
        cout<<"Enter the element to be Pushed : ";
        cin>>ptr->data;
        ptr->next = top;
        top = ptr;

    }
    return top;
};

struct Node *pop(struct Node *top){

    if(isEmpty(top)){
        cout<<"Stack Underflow"<<endl;
    }else{
        struct Node *ptr = top;
        top = ptr->next;
        cout<<"The poped element is : "<<ptr->data<<endl;
        free(ptr);
    }
    return top;
};

struct Node *peek(struct Node *top){

    if(isEmpty(top)){
        cout<<"Stack Underflow"<<endl;
    }else{
        int i,c = 0,j=1 ;
        cout<<"Enter the index position of element : ";
        cin>>i;
        struct Node * temp = top;
         while (temp != NULL)
        {
            temp = temp->next;
            c++;
        }

        if( i<=c && i>0 ){
           
            while(i != j ){
                top = top->next;
                j++;
            } 
            cout<<"the element at index position "<<i<< " is "<<top->data<<endl;
        }else{
            cout<<"Please enter proper index position"<<endl;
        }
    }
    return top;
};



int main(){
    struct Node * top = NULL;
    int option;
   do{ 
        cout<<"********************************************"<<endl;
        cout<<"Enter the operations to be performed on Stack "<<endl;
        cout<<"PUSH              press 1"<<endl;
        cout<<"POP               press 2"<<endl;
        cout<<"PEEK              press 3"<<endl;
        cout<<"DISPLAY           press 4"<<endl;
        cout<<"QUIT              press 5"<<endl;
        cin>>option;
        cout<<"********************************************"<<endl;
        
        switch(option){
            case 1:top =push(top);break;
            case 2:top =pop(top);break;
            case 3:peek(top);break;
            case 4:display(top);break;
            case 5:break;
            default :cout<<"Please enter valid option"<<endl;break;
        }
    }while(option !=5);
    return 0;

    
    return 0;
}