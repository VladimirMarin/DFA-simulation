#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
using namespace std;

ifstream f("datein.txt");

int int_sorter( const void *first_arg, const void *second_arg )
{
    int first = *(int*)first_arg;
    int second = *(int*)second_arg;
    if ( first < second )
    {
        return -1;
    }
    else if ( first == second )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    string Q, E, F;
    char q0;
    f>>Q>>E>>F>>q0;
    qsort(&(E[0]), E.length(), sizeof(char), int_sorter);


    char **myFunction;
    myFunction = new char*['z' - 'a'];

    for(int i = 0 ; i <= ('z' - 'a'); i++)
    {
        size_t found = E.find('a' + i);
        if(found != string::npos)
        {
            myFunction[i] = new char[Q.length()];
            for(unsigned j = 0 ; j < Q.length() ; j++)
                f>>myFunction[i][j];
        }

    }
    /*
    for(int i = 0 ; i <= 'z' - 'a'; i++)
    {
        size_t found = E.find('a' + i);
        if(found != string::npos)
        {
            cout<< (char)('a' + i) << ":"  << endl;
            for(unsigned j = 0 ; j < Q.length() ; j++)
                 cout<< myFunction[i][j] << "  ";
            cout << endl;
        }

    }*/




    unsigned i = 0;
    string word;char a; bool isGood =false; char current = q0;
    cin >> word;
    while(i < word.length())
    {
        a = word[i];

        current = myFunction[(int)(current - 'a')][(int)( a - 'a')];
        //cout << current << " " << a << endl;
        i++;



    }
    for(unsigned i = 0 ; i < F.length() ; i++)
        if(current == F[i])
        {
            isGood = true;
            break;
        }
    if(isGood)
        cout << word << " is a valid word";
    else
        cout << word << "  is not a valid word";
    return 0;
}
