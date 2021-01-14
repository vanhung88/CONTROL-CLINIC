#include<string>
#include<cstring>

using namespace std ;

// bat ky tu
bool checkString(string s)
{

    char db[] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '{', '}', '[', ']',
                  '"', '?', '>', '<', '.', ','
                };
    bool b = false;
    char a[50];
    strcpy(a, s.c_str());
    for (int i = 0; i < strlen(a); i++)
    {
        for (int j = 0; j < strlen(db); j++)
        {
            if (a[i] == db[j])
                b = true;
        }
    }
    return b;
}

char num[] = {'0','1','2','3','4','5','6','7','8','9','\0','\n'};

bool checknumber(string s)
{
    bool b = false;
    char a[50];
    strcpy(a, s.c_str());
    for (int i = 0; i < strlen(a); i++)
    {
        for (int j = 0; j < strlen(num); j++)
        {
            if (a[i] == num[j])
                b = true;
        }
    }
    return b;
}
char word[]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
              'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'
             } ;

bool checkWord(string s)
{
    bool b = false;
    char a[50];
    strcpy(a, s.c_str());
    for (int i = 0; i < strlen(a); i++)
    {
        for (int j = 0; j < strlen(word); j++)
        {
            if (a[i] == word[j])
                b = true;
        }
    }
    return b;
}

// end try catch
