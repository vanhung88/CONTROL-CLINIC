
#include<iostream>
#include<patient.h>
#include<Drug.h>
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;
int main()
{
    char ch;
    int num;
    cout.setf(ios::fixed|ios::showpoint);
    cout<<setprecision(2);
    int choose=-1 ;
    cout<<"\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t1.PATIENT"<<endl;
    cout<<"\t\t\t\t\t\t\t2.DRUG"<<endl;
    cout<<"\t\t\t\t\t\t\tyou choose: "<<endl ;

    while(choose<1 || choose>2)
    {
        cout<<"\t\t\t\t\t\t\t" ;
        cin>>choose ;
    }

    switch(choose)
    {
    case 1:
        do
        {
            system("cls");
            cout<<"\t--------------------------------------------------";
            cout<<"\n\n\t1.Add patient";
            cout<<"\n\n\t2.Display all patient";
            cout<<"\n\n\t3.Find patient ";
            cout<<"\n\n\t4.Update patient information ";
            cout<<"\n\n\t5.Delete patient";
            cout<<"\n\n\t6.Show the patient list";
            cout<<"\n\n\t7. EXIT";
            cout<<"\n\n\t-----------------------------------------------";
            cout<<"\n\n\tPlease Enter Your Choice (1-7): ";
            cin>>ch;
            system("cls");
            switch(ch)
            {
            case '1':
                add_Patient();
                break;
            case '2':
                displayAllPatient();
                break;
            case '3':
                cout<<"\n\n\tPlease Enter Patient's ID number: ";
                cin>>num;
                FindPatient(num);
                break;
            case '4':
                cout<<"\n\n\tPlease Enter Patient's ID number: ";
                cin>>num;
                updatePatient(num);
                break;
            case '5':
                cout<<"\n\n\tPlease Enter Patient's ID number: ";
                cin>>num;
                deletePatient(num);
                break;
            case '6' :
                ShowListPatient();
                break;
            case '7':
                exit(0);
            default:
                cout<<"\a";
            }
        }
        while(ch!='7');
        break ;
    case 2:

        do
        {
            system("cls");
            cout<<"\t--------------------------------------------------";
            cout<<"\n\n\t1.Add Drug";
            cout<<"\n\n\t2.Display all Drug";
            cout<<"\n\n\t3.Find Drug ";
            cout<<"\n\n\t4.Update Drug information ";
            cout<<"\n\n\t5.Delete Drug";
            cout<<"\n\n\t6.Show the Drug list";
            cout<<"\n\n\t7. EXIT";
            cout<<"\n\n\t-----------------------------------------------";
            cout<<"\n\n\tPlease Enter Your Choice (1-7): ";
            cin>>ch;
            system("cls");
            switch(ch)
            {
            case '1':
                add_Drug();
                break;
            case '2':
                displayAllDrug();
                break;
            case '3':
                cout<<"\n\n\tPlease Enter Patient's ID number: ";
                cin>>num;
                FindDrug(num);
                break;
            case '4':
                cout<<"\n\n\tPlease Enter Patient's ID number: ";
                cin>>num;
                updateDrug(num);
                break;
            case '5':
                cout<<"\n\n\tPlease Enter Patient's ID number: ";
                cin>>num;
                deleteDrug(num);
                break;
            case '6' :
                ShowListDrug();
                break;
            case '7':
                exit(0);
            default:
                cout<<"\a";
            }
        }
        while(ch!='7');
        break ;
    }

    return 0;
}
