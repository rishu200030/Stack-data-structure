#include <iostream>
#include <cstdlib>
using namespace std;
int top = -1;
int stack[6];
   
int n = 6;
void push(){
    if(top == n-1){
        cout<<"Stack is Full"<<endl;
    }else{
        top = top+1;
        cout<<"Enter the element to be inserted : ";
        cin>>stack[top];
        cout<<endl;
    }
    
}

void pop(){
    if(top == -1){
        cout<<"Stack is Empty"<<endl;
    }else{
        cout<<"The element "<<stack[top] <<" is poped"<<endl;
        top = top-1;
    }
    
};

void peek(){
    int index;
    cout<<"Enter the index position of element"<<endl;
    cin>>index;
    if(index >= 0 && index <= top){
        cout<<"The element at index position "<<index<<" is "<<stack[top]<<endl;
    }else{
        cout<<"Index out of range"<<endl;
    }
    
};

void isEmptyOrFull(){
    if(top == -1 || top < n-1){
        cout<<"The Stack is empty"<<endl;
        
    };
    if(top == n-1){
        cout<<"Stack is FUll"<<endl;
    };
    
};


void display(){
    if(top == -1){
        cout<<"The Stack is empty"<<endl;
    }else{
        cout<< "The elements of stack are : ";
        for(int i=0 ; i <=top; i++){
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
    
};
int main(){
   int option = 0;
   
    do{ 
        cout<<"********************************************"<<endl;
        cout<<"Enter the operations to be performed "<<endl;
        cout<<"PUSH              press 1"<<endl;
        cout<<"POP               press 2"<<endl;
        cout<<"PEEK              press 3"<<endl;
        cout<<"DISPLAY           press 4"<<endl;
        cout<<"IS Empty or Full  press 5"<<endl;
        cout<<"QUIT              press 6"<<endl;
        cin>>option;
        cout<<"********************************************"<<endl;
        
        switch(option){
            case 1:push();break;
            case 2:pop();break;
            case 3:peek();break;
            case 4:display();break;
            case 5:isEmptyOrFull();break;
            case 6:break;
            default :cout<<"Please enter valid option"<<endl;break;
        }
    }while(option != 6);
    return 0;
}