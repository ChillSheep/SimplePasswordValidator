#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
int main() {
char symbols[]="!@#$%^&*()_+{}|=-<>,.?/\\"; //24 chars from 0 to 23
char numbers[]="0123456789";
    start:
cout<<"Enter the a password and see if it is strong or not\n";
string password;
getline(cin, password);
char* text = &password[0]; //gets and stores the pw without an array
unsigned short size = password.size();
if(size<8 | size>32) {
    cout<<"The password you entered is not the correct length\n";
    cout<<"The password should be less than 32 characters and more than 8\n";
    goto start;
}

bool valid=0;
bool no_valid=0;
bool no_repeats=1;
bool upper_chars=0;
for (unsigned short i=0; i<size; i++) {
    if (isupper(password[i]))
        upper_chars=1;
    for (unsigned short j=0; j<24; j++)
        if (password[i]==symbols[j])
            valid=1;
    for (unsigned short j=0; j<9; j++)
        if (password[i]==numbers[j])
            no_valid=1; }
    for (unsigned short i=2; i<size; i++)
        if (password[i]==password[i-1] & password[i-1]==password[i-2])
            no_repeats=0;
if (valid==0 | no_valid==0 | no_repeats==0 | upper_chars==0) {
    cout<<"You need to include at least one symbol, number, capital letter and no repeats.\n";
    goto start;
}
cout<<"Congrats! That is a strong password!\n";
cout<<"Press any key to exit the program.\n";
getch();
}
