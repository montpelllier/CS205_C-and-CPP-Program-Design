//
// Created by Think on 2021/1/21.
//

#include <iostream>
#include <stdio.h>

using namespace std;

void first(int x, int y)
{
    printf("Result:\nx value y value Expressions\tResult\n");
    printf("%d |%5d |\tx=y+3\t\t|x=%d\n", x,y,y+3);
    printf("%d |%5d |\tx=y-2\t\t|x=%d\n", x,y,y-2);
    printf("%d |%5d |\tx=y*5\t\t|x=%d\n", x,y,y*5);
    printf("%d |%5d |\tx=x/y\t\t|x=%d\n", x,y,x/y);
    printf("%d |%5d |\tx=x%%y\t\t|x=%d\n", x,y,x%y);
}

void second(int sec)
{
    printf("%d seconds = %d days, %d hours, %d minutes, %d seconds",sec,sec/86400,sec%86400/3600,sec%86400%3600/60,sec%86400%3600%60);
}

void third()
{

}


int main(){
    int x,y;
    cin >> x >> y;
    first(x, y);
//    printf("Enter the number of seconds:");
//    int sec;
//    cin >> sec;
//    second(sec);
    /*printf("Please Enter a Character : ");
    int ch;
    scanf("%c", &ch);

    printf("Please Enter an Integer Value : ");
    int integer;
    scanf("%d", &integer);

    printf("Please Enter Float Value : ");
    float f;
    scanf("%f", &f);

    printf("\nThe varibles you entered were:\n");
    printf("The Character Value that you Entered is : %c\n",ch);
    printf("The Integer Value that you Entered is : %d\n",integer);
    printf("The Float Value that you Entered is : %.4f\n",f);*/
    return 0;
}