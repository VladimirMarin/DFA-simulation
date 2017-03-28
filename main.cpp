#include <iostream>
#include <iostream>
#include <fstream>
#include <string.h>
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

    qsort(&(Q[0]), Q.length(), sizeof(char), int_sorter);
    cout << Q << endl;

    char **myFunction;
    myFunction = new char*[Q.length()];
    for(unsigned i = 0 ; i < Q.length(); i++)
    {
        myFunction[i] = new char[E.length()];
        for(unsigned j = 0 ; j < E.length() ; j++)
            f>>myFunction[i][j];
    }

    for(unsigned i = 0 ; i < Q.length(); i++)
    {
        cout<< Q[i] << ":"  << endl;
        for(unsigned j = 0 ; j < E.length() ; j++)
            cout<< myFunction[i][j] << "  ";
        cout << endl;
    }

    unsigned i = 0;
    string word;char a; bool isGood =true; char current = q0;
    cin >> word;
    while(i < word.length())
    {
        a = word[i];
        current = myFunction[(int)a][(int)current];

    }
    return 0;
}
