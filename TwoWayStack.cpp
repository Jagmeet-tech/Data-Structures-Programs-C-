#include<iostream>
#include<conio.h>
using namespace std;

class TwoWayStack
{
    private:
      int capacity;
      int top_left;
      int top_right;
      int *ptr;
    public:
            void push_Right(int );
            void push_Left(int );
            int pop_Right();
            int pop_Left();
            int peek_Left();
            int peek_Right();
            int isEmptyRight();
            int isEmptyLeft();
            int isFull();
    TwoWayStack(int cap)
    {
        capacity=cap;
        top_left=-1;
        top_right=capacity;
        ptr=new int[capacity];
        cout<<top_left<<top_right;
    }

    ~TwoWayStack()
    {
        delete []ptr;
    }
};

int TwoWayStack::isFull()
{
    if(top_left+1==top_right)
        return 1;
    else
            return 0;
}

int TwoWayStack::isEmptyLeft()
{
    if(top_left==-1)
        return 1;
    else
        return 0;
}

int TwoWayStack::isEmptyRight()
{
    if(top_right==capacity)
        return 1;
    else
        return 0;
}

int TwoWayStack::peek_Left()
{
  if(isEmptyLeft())
      {
          cout<<" no peek in stack left";
          return 0;
      }
  else
    return ptr[top_left];
}


int TwoWayStack::peek_Right()
{
  if(isEmptyRight())
      {
          cout<<" no peek in stack right";
          return 0;
      }
  else
    return ptr[top_right];
}

int TwoWayStack::pop_Left()
{
    int value;
    if(isEmptyLeft())
    {
        cout<<"stack underflow";
        return 0;
    }
    else
    {
        value=ptr[top_left];
        top_left--;
        return value;
    }

}

int TwoWayStack::pop_Right()
{
    int value;
    if(isEmptyRight())
    {
        cout<<"stack underflow";
        return 0;
    }
    else
    {
        value=ptr[top_right];
        top_right++;
        return value;
    }
}

void TwoWayStack::push_Left(int value)
{
    if(isFull())
        cout<<"stack overflow";
   else
   {
       top_left++;
       ptr[top_left]=value;
   }
}

void TwoWayStack::push_Right(int value)
{
    if(isFull())
        cout<<"stack overflow";
   else
   {
       top_right--;
       ptr[top_right]=value;
   }
}

int menu()
{
    cout<<"\n1. insert value from stack 1:";
    cout<<"\n2. insert value from stack 2:";
    cout<<"\n3. delete value from stack 1:";
    cout<<"\n4. delete value from stack 2:";
    cout<<"\n5. peek value from stack 1:";
    cout<<"\n6. peek value from stack 2:";
    cout<<"\n7. exit:";
    cout<<"\n\n enter your choice: ";
    int choice;
    cin>>choice;
    return choice;
}

int main()
{
    TwoWayStack t1(6);
    int data;
    while(1)
    {
        switch(menu())
        {
        case 1:
            cout<<"enter value to insert in left :";
            cin>>data;
            t1.push_Left(data);
            break;
        case 2:
            cout<<"enter value to insert in right :";
            cin>>data;
            t1.push_Right(data);
            break;
        case 3:
            cout<<"delete value  of left :"<<t1.pop_Left();
            break;
        case 4:
             cout<<"delete value  of right :"<<t1.pop_Right();
             break;
        case 5:
             cout<<"peek value  of left :"<<t1.peek_Left();
             break;
        case 6:
             cout<<"peek value  of right :"<<t1.peek_Right();
             break;
        case 7:
            cout<<"THANKs for this .. program ends";
            exit(0);
        default:
            cout<<"invalid choice";
            break;
        }
        getch();
        system("cls");
    }
    return 0;
}

