#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<iostream>
using namespace std;
int main()
{
    system("cls");
    int i=0;
    for(i=0;i<1000;i++)
    {
        Beep(i,10);
       //textcolor(3);
       //cprintf("**");
       cout<< "your sound value:"<<i<<endl;
    }
    //nosound();
    return 0;
}
