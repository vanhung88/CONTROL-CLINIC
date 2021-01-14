#include<Date.h>
#include<tryCatch.h>
#include<iostream>
#include<format.h>

using namespace std ;
class people
{
private:
    //char idnum[50];
    char name[50];
    char sex[50];
    Date dayOfBirth ;

    public:

        string getName(){
            return name ;
        }
        string getSex(){
            return sex;
        }

        Date getDayOfBirth(){
            return dayOfBirth ;
        }
        virtual void getdata(); // input
        virtual void showdata(); // display
};

void people::getdata(){

    cout<<"\nEnter patient Name: ";
    cin.getline(name,50);
    //string s= (string)idnum ;
    while(checknumber(name) == true || checkString(name)==true)
    {
        cout<<"Enter patient Name again: ";
        cin.getline(name,50);
    }

    cout<<"\nEnter sex: ";
    cin.getline(sex,50);
    while(checknumber(sex) == true || checkString(sex)==true)
    {
        cout<<"Enter sex again: ";
        cin.getline(sex,50);
    }

    cout<<"\nEnter day of birth: "<<endl;
    //cin.getline(age,50);
    dayOfBirth.input() ;
}

void people::showdata(){
    //cout<<"\nID Number: "<<idnum;
    cout<<"\nName Patient: "<<format(name);
    cout<<"\nSex: "<<sex;
    cout<<"\nDay of birth: "; dayOfBirth.display2();
}
