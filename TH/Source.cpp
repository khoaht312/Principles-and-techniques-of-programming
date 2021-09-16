#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<fstream>

using namespace std;

struct grammer {
    char p[20];
    char prod[20];
    //string p;
    //string prod;
}g[10];

int main()
{
    int i, stpos, j, k, l, m, o, p, f, r;
    int np, tspos, cr;

    cout << "\nEnter Number of productions: 11";
    np = 11;

    char sc, ts[10];

    cout << "\nEnter productions:\nP->E\nE->E+T\nE->E-T\nE->T\nT->T*S\nT->T/S\nT->S\nS->F^S\nS->F\nF->(E)\nF->i";
    //for (i = 0; i < np; i++)
    //{
    //    cin >> ts;
    //    strncpy_s(g[i].p, ts, 1);
    //    strcpy_s(g[i].prod, &ts[3]);
    //}
    ifstream file;
    file.open("G.txt");

    if (!file)
    {
        cout << "Khong the mo file!!";
        system("pause");
        exit(1);
    }

    for (i = 0; i < np; i++)
    {
        file >> ts;
        strncpy_s(g[i].p, ts, 1);
        strcpy_s(g[i].prod, &ts[3]);
    }

    file.close();

    char ip[10];

    cout << "\nEnter Input:\ni+i*i^i+i";
    //cin >> ip;

    file.open("Input.txt");

    if (!file)
    {
        cout << "Khong the mo file!!";
        system("pause");
        exit(1);
    }

    file >> ip;

    file.close();

    int lip = strlen(ip);

    char stack[10];

    stpos = 0;
    i = 0;

    //moving input
    sc = ip[i];
    stack[stpos] = sc;
    i++; stpos++;

    cout << "\n\nStack\tInput\t\tAction";
    do
    {
        r = 1;
        while (r != 0)
        {
            cout << "\n";
            for (p = 0; p < stpos; p++)
            {
                cout << stack[p];
            }
            cout << "\t";
            for (p = i; p < lip; p++)
            {
                cout << ip[p];
            }

            if (r == 2)
            {
                cout << "\tReduced";
            }
            else
            {
                cout << "\tShifted";
            }
            r = 0;

            //try reducing
            for (k = 0; k < stpos; k++)
            {
                f = 0;

                for (l = 0; l < 10; l++)
                {
                    ts[l] = '\0';
                }

                tspos = 0;
                for (l = k; l < stpos; l++) //removing first character
                {
                    ts[tspos] = stack[l];
                    tspos++;
                }

                //now compare each possibility with production
                for (m = 0; m < np; m++)
                {
                    cr = strcmp(ts, g[m].prod);

                    //if cr is zero then match is found
                    if (cr == 0)
                    {
                        for (l = k; l < 10; l++) //removing matched part from stack
                        {
                            stack[l] = '\0';
                            stpos--;
                        }

                        stpos = k;

                        //concatinate the string
                        strcat_s(stack, g[m].p);
                        stpos++;
                        r = 2;
                    }
                }
            }
        }

        //moving input
        sc = ip[i];
        stack[stpos] = sc;
        i++; stpos++;

    } while (strlen(stack) != 1 && stpos != lip);

    if (strlen(stack) == 1)
    {
        cout << "\n String Accepted";
    }

    system("pause");
    return 0;
}