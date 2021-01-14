#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<people.h>
#include <sstream>
//#include<format.h>

using namespace std;


class patient :public people
{
    char idnum[50];
//    char name[50];
//    char sex[50];
//    Date dayOfBirth ;
//    //char age[50];
//    //new
private:
    char adress[50];
    char PhoneNumber[50] ;
    char bloodgroup[50];
    char prehistoric[50];

public:
    void getdata(); // input
    void showdata(); // display
    void show_tabular(); // display table
    int getIDNum() const; // get ID
};

void patient::getdata()
{
//    cin.ignore();
//    cout<<"\nEnter ID ";
//    cin.getline(idnum,50);
//    while( checkString(idnum)==true)
//    {
//        cout<<"Enter ID again: ";
//        cin.getline(idnum,50);
//    }
//    cout<<"\nEnter patient Name: ";
//    cin.getline(name,50);
//    //string s= (string)idnum ;
//    while(checknumber(name) == true || checkString(name)==true)
//    {
//        cout<<"Enter patient Name again: ";
//        cin.getline(name,50);
//    }
//
//    cout<<"\nEnter sex: ";
//    cin.getline(sex,50);
//    while(checknumber(sex) == true || checkString(sex)==true)
//    {
//        cout<<"Enter sex again: ";
//        cin.getline(sex,50);
//    }
//
//    cout<<"\nEnter day of birth: "<<endl;
//    //cin.getline(age,50);
//    dayOfBirth.input() ;
    cin.ignore();
    cout<<"\nEnter ID ";
    cin.getline(idnum,50);
    while( checkString(idnum)==true)
    {
        cout<<"Enter ID again: ";
        cin.getline(idnum,50);
    }
    people::getdata() ;
    cin.ignore();
    cout<<"\nEnter phone number: ";
    cin.getline(PhoneNumber,50);
    while(checkWord(PhoneNumber) == true || checkString(PhoneNumber)==true)
    {
        cout<<"Enter phone number again: ";
        cin.getline(PhoneNumber,50);
    }

    cout<<"\nEnter adress: ";
    cin.getline(adress,50);
    while( checkString(adress)==true)
    {
        cout<<"Enter adress again: ";
        cin.getline(adress,50);
    }
    format(adress);


    cout<<"\nEnter blood group: ";
    cin.getline(bloodgroup,50);
    while( checkString(bloodgroup)==true)
    {
        cout<<"Enter blood group again: ";
        cin.getline(bloodgroup,50);
    }

    cout<<"\nEnter prehistoric of patient: ";
    cin.getline(prehistoric,50);
    while(checkString(prehistoric)==true)
    {
        cout<<"Enter prehistoric of patient again: ";
        cin.getline(prehistoric,50);
    }
    //calculate();
}

void patient::showdata()
{
//    cout<<"\nID Number: "<<idnum;
//    cout<<"\nName Patient: "<<format(name);
//    cout<<"\nSex: "<<sex;
//    cout<<"\nDay of birth: "; dayOfBirth.display2();
    //cout<<"\Age: "<<age ;

    people::showdata();
    cout<<"\nPhone Number: "<<PhoneNumber;
    cout<<"\nAdress: "<<format(adress);;
    cout<<"\nBlood group: "<<bloodgroup;
    cout<<"\nPrehistoric of patient: "<<prehistoric;
    //cout<<"\nLetter Grade: "<<grade;
}

void patient::show_tabular()
{
    cout<<idnum<<setw(4)
    <<" "<<format(getName()) ;

    if((getName().length())<10)
        cout<<setw(15) ;
    else cout<<setw(10) ;

    cout<<getSex()<<setw(13)
    <<getDayOfBirth().display2()<<setw(18)<<PhoneNumber<<setw(15)
        <<format(adress)<<setw(10)<<bloodgroup<<setw(25)<<prehistoric<<endl;
}

int  patient::getIDNum() const
{
    int idINT = stoi(idnum);
    return idINT;
}

// Function of system
void add_Patient() ; //thêm bệnh nhân
void FindPatient(int);  // tìm kiếm một bệnh nhân bằng ID
void updatePatient(int); // update thông tin bệnh nhân bằng ID
void deletePatient(int); // xóa một bệnh nhân bằng ID
void ShowListPatient();  // hiển thị dạng bảng
void displayAllPatient(); // hiển thị dạng liệt kê

void add_Patient()
{
    /*
    patient st;
    ofstream outFile;
    outFile.open("patient.txt",ios::binary|ios::app);
    st.getdata();
    outFile.write(reinterpret_cast<char *> (&st), sizeof(patient));
    outFile.close();
       	cout<<"\n\npatient record Has Been Created ";
    //cin.ignore();
    cin.get();
    */

   patient p ;
   ofstream ghiFile ;
   ghiFile.open("patient.txt" , ios::binary|ios::app);
   p.getdata() ;
   ghiFile.write(reinterpret_cast<char *>(&p),sizeof(patient)) ;
   ghiFile.close() ;
        	cout<<"\n\npatient record Has Been Created ";
   cin.ignore();
   //cin.get() ;
}

void FindPatient(int n)
{
    patient st;
    ifstream inFile;
    inFile.open("patient.txt",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&st), sizeof(patient)))
    {
        if(st.getIDNum()==n)
        {
            st.showdata();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nrecord not exist";
    cin.ignore();
    cin.get();
}


void updatePatient(int n)
{
    bool found=false;
    patient st;
    fstream File;
    File.open("patient.txt",ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    while(!File.eof() && found==false)
    {

        File.read(reinterpret_cast<char *> (&st), sizeof(patient));
        if(st.getIDNum()==n)
        {
            st.showdata();
            cout<<"\n\nPlease Enter The New Details of patient"<<endl;
            st.getdata();
            int pos=(-1)*static_cast<int>(sizeof(st));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&st), sizeof(patient));
            cout<<"\n\n\t Record Updated";
            found=true;
        }
    }
    File.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
    cin.ignore();
    cin.get();
}

void deletePatient(int n)
{
    patient st;
    ifstream inFile;
    inFile.open("patient.txt",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("Temp2.txt",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&st), sizeof(patient)))
    {
        if(st.getIDNum()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&st), sizeof(patient));
        }
    }
    outFile.close();
    inFile.close();
    remove("patient.txt");
    rename("Temp2.txt","patient.txt");
    cout<<"\n\n\tRecord Deleted ..";
    cin.ignore();
    cin.get();
}


void ShowListPatient()
{
    patient st;
    ifstream inFile;
    inFile.open("patient.txt",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tALL patientS RESULT \n\n";
    cout<<"------------------------------------------------------------------------------------------------------------\n";
    cout<<"ID   Name              sex     Day of birth     Phone Number     Adress       Blood group     Prechistoric of patient"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------\n";
    while(inFile.read(reinterpret_cast<char *> (&st), sizeof(patient)))
    {
        st.show_tabular();
    }
    cin.ignore();
    cin.get();
    inFile.close();
}


void displayAllPatient()
{
    patient st;
    ifstream inFile;
    inFile.open("patient.txt",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    while(inFile.read(reinterpret_cast<char *> (&st), sizeof(patient)))
    {
        st.showdata();
        cout<<"\n\n-------------------------------------------------------------------------------\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}






