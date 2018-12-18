#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int strlength(char ch[15]) {
    int i;
    for( i=0;ch[i]!='\0';i++) {
    }
    return i;
}

void revString(char ch[15],int l){
    char temp[15];
    for(int i=0;i<l;i++) {
        temp[i]=ch[l-1-i];
    }
    cout<<"Reverse String : "<<temp;
}



int main() {

    system("cls");
    char str1[15];
    cout<<"Enter String : ";
    gets(str1);
    int len=strlength(str1);
    revString(str1,len);
    return 0;
}
