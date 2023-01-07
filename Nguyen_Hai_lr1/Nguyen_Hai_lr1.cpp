#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int pos = 0;
int count = 0;

void symbol(string arr, char& a){
    a = arr[pos];
    pos++;
}

bool bracket(string arr,char& a, int& FlagErr){
        symbol(arr,a);
        if(a != '\0'){
                if(a == 'A')
                        FlagErr = 0;
                else if(a == '('){
                        symbol(arr,a);
                        if(a!='\0' && a == 'B'){
                                        if(bracket(arr, a, FlagErr)){
                                                if(bracket(arr,a,FlagErr)){
                                                        symbol(arr,a);
                                                        if(a!='\0' && a == ')'){
                                                                FlagErr = 0;
                                                        } else FlagErr = 1;
                                                } else FlagErr = 2;
                                        } else FlagErr = 3;
                        } else FlagErr = 4;
                } else FlagErr = 5;
        } else FlagErr = 5;
        if(FlagErr == 0)
                return true;
        else
                return false;
}


int main(){
        string arr;
        char a;
        int FlagErr;
        cin>>arr;
        bracket(arr,a,FlagErr);
        symbol(arr,a);
        if(a!='\0')
                FlagErr = 6;

        switch(FlagErr){
                case 0:
                        cout<<"It's a bracket."<<endl;
                        break;
                case 1:
                        cout<<"Error: Missing '('."<<endl;
                        break;
                case 2:
                        cout<<"Second bracket error."<<endl;
                        break;
                case 3:
                        cout<<"First bracket error."<<endl;
                        break;
                case 4:
                        cout<<"Error: Missing 'B'."<<endl;
                        break;
                case 5:
                        cout<<"Error: Missing 'A' or '('."<<endl;
                        break;
                case 6:
                        cout<<"Err: Extra characters in input string."<<endl;
                        break;
        }
        return 0;
}

