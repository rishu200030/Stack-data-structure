#include <iostream>
#include <cstdlib>
using namespace std;

struct stack
{
    int size;
    int top;
    int * arr;
};

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size -1){
        return 1;
    }else{
        return 0;
    }
};

int isEmpty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }else{
        return 0;
    } 
};

int push(struct stack * ptr){
    if(isFull(ptr)){
        cout<<"Stack overflow"<<endl;
    }else{
        ptr->top = ptr->top + 1;
        cout<<"Enter the value to be pushed : ";
        cin>>ptr->arr[ptr->top];
        
    }
   return 1;
}

int peek(struct stack * ptr){
    int i;
    cout<<"Enter the element to be Peeked : ";
    cin>>i;
    if(ptr->top-i+1 < 0 ){
        cout<<"Please enter proper position"<<endl;
    }else{
        cout<<"The element at position "<<i<<" is "<<ptr->arr[ptr->top - i +1]<<endl;
    }
    return 1;
}

int pop(struct stack * ptr){
    if(isEmpty(ptr)){
        cout<<"stack underflow"<<endl;
    }else{
        cout<<"The poped element is : "<<ptr->arr[ptr->top]<<endl;
        ptr->top = ptr->top - 1;
    }
    return 1;
}

int display(struct stack *ptr){
    if(isEmpty(ptr)){
        cout<<"stack underflow"<<endl;
    }else{
        int temp = ptr->top;
        cout<<"the Elements of stack are : ";
        while(temp != -1){
            cout<<ptr->arr[temp]<<" ";
            temp = temp -1;
        };
        cout<<endl;
    }
    return 1;
}
int main(){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = - 1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    int option = 0;
   
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
            case 1:push(sp);break;
            case 2:pop(sp);break;
            case 3:peek(sp);break;
            case 4:display(sp);break;
            case 5:break;
            default :cout<<"Please enter valid option"<<endl;break;
        }
    }while(option !=5);
    return 0;
}