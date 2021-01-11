#include<string>
#include<cstring>
#include<iostream>
using namespace std ;

class Date
{
public :
    Date()
    {
        this->day=0;
        this->month=0;
        this->year=0;
    }
    static bool isLeap( int year)
    {
        if( ( year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            return true;
        }
        return false;
    }
    int daysInMonth( int month, int year)
    {

        switch( month )
        {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 1 :
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 2 :
            if( isLeap( year ))
            {
                return 29;
            }
            return 28;
        default:
            return -1;

        }
    }
    bool setDate( int dd, int month, int year )
    {
        if( month < 1 || month >12 )
        {
            return false;
        }
        if( dd < 1 || dd > daysInMonth( month, year ))
        {
            return false;
        }
        if ( year <= 0)
        {
            return false;
        }
        this -> day = dd;
        this -> month = month;
        this -> year = year;
        return true;
    }
    int getDay()
    {
        return day;
    }
    int getMonth()
    {
        return month;
    }
    int getYear()
    {
        return year;
    }
    void input()
    {
        int day, month, year;
        do
        {
            cout<<"day: ";
            cin>> day;
            cout<<"month: ";
            cin>> month;
            cout<<"year: " ;
            cin>> year;
            if( !setDate( day, month, year ))
            {
                cout<< "date is wrong" << endl;
            }
        }
        while( !setDate( day, month, year ) );
    }
    void display()
    {
        cout<< getDay() << "-" <<getMonth() << "-" << getYear();
    }

    string display2()
    {
        string r1 ;
        string r2;
        string r3       ;
        ostringstream convertDay;
        ostringstream convertMonth;
        ostringstream convertYear;

        convertDay << day;
        r1=convertDay.str();
        convertMonth<<month ;
        r2=convertMonth.str();
        convertYear<<year ;
        r3=convertYear.str();
        return  r1+"-"+r2+"-"+r3 ;
    }

        int dayOfTheYear()
        {
            int dem = 0 ;
            for( int i = 1 ; i < month ; i++ )
            {
                dem += daysInMonth( i, getYear() );
            }
            dem += getDay();
            return dem;
        }
public :
        int day, month, year ;
};
