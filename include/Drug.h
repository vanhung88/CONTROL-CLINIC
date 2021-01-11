#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>

using namespace std;

class Drug
{
    char idDrug[50];
    char nameDrug[50] ;
    char producer[50] ;
    // Date d1=new Date();
    Date date1 ;
    Date date2 ;
    char amount[50];
public:
    void getdataDrug();
    void showdataDrug();
    void show_tabularDrug();
    int getIDNumDrug() const;
};

void Drug::getdataDrug()
{

    //ID
    cin.ignore();
    cout<<"\nEnter ID ";
    cin.getline(idDrug,50);
    while( checkString(idDrug)==true)
    {
        cout<<"Enter ID again: ";
        cin.getline(idDrug,50);
    }
    // name
    cout<<"\nEnter drug name: ";
    cin.getline(nameDrug,50);
    while(checkString(nameDrug) == true )
    {
        cout<<"Enter drug name again: ";
        cin.getline(nameDrug,50);
    }

    // producer
    cout<<"\nEnter name producer: ";
    cin.getline(producer,50);
    while(checkString(producer) == true )
    {
        cout<<"Enter name Producer again: ";
        cin.getline(producer,50);
    }

    // ngay SX - Ngay het han
    cout<<"\nEnter manufacture date: "<<endl;
    date1.input() ;
    cout<<"\nEnter expiration date: "<<endl;
    date2.input();

    cin.ignore();
    cout<<"\nEnter amount ";
    cin.getline(amount,50);
    while(checkString(amount)==true)
    {
        cout<<"Enter amount again: ";
        cin.getline(amount,50);
    }
}

void Drug::showdataDrug()
{
    cout<<"\nID: "<<idDrug;
    cout<<"\nName Drug: "<<format(nameDrug);
    cout<<"\nProducer: "<<format(producer);
    cout<<"\nManufacture date: "<<date1.display2();
    cout<<"\nExpiration date: "<<date2.display2();
    cout<<"\nAmount: "<<amount;
}

void Drug::show_tabularDrug()
{
    cout<<idDrug<<setw(15);

    cout<<format(nameDrug) ;
    if(strlen(nameDrug)<10)
    {
        cout<<setw(15);
    }
    else cout<<setw(20);

    cout<<format(producer)<<setw(17)<<date1.display2()<<setw(21)<<date2.display2()<<setw(17)
        <<amount<<endl;
}

int  Drug::getIDNumDrug() const
{
    int idINT = stoi(idDrug);
    return idINT;
}

// Function of system
void add_Drug() ; //thêm bệnh nhân
void FindDrug(int);  // tìm kiếm một bệnh nhân bằng ID
void updateDrug(int); // update thông tin bệnh nhân bằng ID
void deleteDrug(int); // xóa một bệnh nhân bằng ID
void ShowListDrug();  // hiển thị dạng bảng
void displayAllDrug(); // hiển thị dạng liệt kê

void add_Drug()
{

    Drug DG;
    ofstream outFile;
    outFile.open("Drug.txt",ios::binary|ios::app);
    DG.getdataDrug();
    outFile.write(reinterpret_cast<char *> (&DG), sizeof(Drug));
    outFile.close();
       	cout<<"\n\nDrug record Has Been Created ";
    //cin.ignore();
    cin.get();
}

void FindDrug(int n)
{
    Drug DG;
    ifstream inFile;
    inFile.open("Drug.txt",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&DG), sizeof(Drug)))
    {
        if(DG.getIDNumDrug()==n)
        {
            DG.showdataDrug();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nrecord not exist";
    cin.ignore();
    cin.get();
}


void updateDrug(int n)
{
    bool found=false;
    Drug DG;
    fstream File;
    File.open("Drug.txt",ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    while(!File.eof() && found==false)
    {

        File.read(reinterpret_cast<char *> (&DG), sizeof(Drug));
        if(DG.getIDNumDrug()==n)
        {
            DG.showdataDrug();
            cout<<"\n\nPlease Enter The New Details of patient"<<endl;
            DG.getdataDrug();
            int pos=(-1)*static_cast<int>(sizeof(DG));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&DG), sizeof(Drug));
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

void deleteDrug(int n)
{
    Drug DG;
    ifstream inFile;
    inFile.open("Drug.txt",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempDrug.txt",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&DG), sizeof(Drug)))
    {
        if(DG.getIDNumDrug()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&DG), sizeof(Drug));
        }
    }
    outFile.close();
    inFile.close();
    remove("Drug.txt");
    rename("TempDrug.txt","Drug.txt");
    cout<<"\n\n\tRecord Deleted ..";
    cin.ignore();
    cin.get();
}


void ShowListDrug()
{
    Drug DG;
    ifstream inFile;
    inFile.open("Drug.txt",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tALL DrugS RESULT \n\n";
    cout<<"------------------------------------------------------------------------------------------------------------\n";
    cout<<"ID      Name drug        producer       Manufacture date     Expiration date       Amount    "<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------\n";
    while(inFile.read(reinterpret_cast<char *> (&DG), sizeof(Drug)))
    {
        DG.show_tabularDrug();
    }
    cin.ignore();
    cin.get();
    inFile.close();
}


void displayAllDrug()
{
    Drug DG;
    ifstream inFile;
    inFile.open("Drug.txt",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    while(inFile.read(reinterpret_cast<char *> (&DG), sizeof(Drug)))
    {
        DG.showdataDrug();
        cout<<"\n\n-------------------------------------------------------------------------------\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}






