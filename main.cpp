#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <conio.h>
#define SPACE ' '
using namespace std;

void SetWindow(int Width, int Height)
{
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(Handle, coord);
    SetConsoleWindowInfo(Handle, TRUE, &Rect);
}

class enterCommand
{
public:
    string command;
    void helpf();
    void versionf();
    void authorf();
    void bookf();
    void categoryf();
    void openbookf(int x);
    void opencategoryf(int y);
    void exitf();
};

void enterCommand::helpf()
{
    cout << endl;
    cout << "help            - This command will show you help options." << endl;
    cout << "version         - This command will show you the version." << endl;
    cout << "author          - This command will show the identity of author." << endl;
    cout << "list.books      - To see book names and open books by their name." << endl;
    cout << "list.categories - To see book categories and open books by their category." << endl;
    cout << "open.book       - To open a specific book. After this command you need to choose the number of the book." << endl;
    cout << "open.category   - To open specific category .After this command you need to choose the number of the category." << endl;
    cout << "quit            - To exit application." << endl;
}

void enterCommand::versionf()
{
    cout << endl << "Beta Version" << endl;
}

void enterCommand::authorf()
{
    cout << endl << "NABIL ASHAB" << endl;
    cout << "Department of Computer Science and Engineering" << endl;
    cout << "Khulna University of Engineering and Technology" << endl;
    cout << "Roll: 1207016" << endl;
}

void enterCommand::bookf()
{
    cout << endl;
    cout << "1.Adventures of Huckleberry Finn (Part 1)" << endl;
    cout << "2.Adventures of Huckleberry Finn (Part 2 )" << endl;
    cout << "3.The Hound of the Baskervilles" << endl;
    cout << "4.The Mind and Its Education" << endl;
}

void enterCommand::categoryf()
{
    cout << endl;
    cout << "1.Adventure" << endl;
    cout << "2.Thriller" << endl;
    cout << "3.Education" << endl;
}

void enterCommand::openbookf(int x)
{
    FILE *infile;
    char ch, file_name[256];
    getcwd(file_name, 255);
    int booknum;
    booknum=x;
    if(booknum==1)
    {
        strcat(file_name, "\\books\\Adventures of Huckleberry Finn (Part 1).txt");
    }
    if(booknum==2)
    {
        strcat(file_name, "\\books\\Adventures of Huckleberry Finn (Part 2).txt");
    }
    if(booknum==3)
    {
        strcat(file_name, "\\books\\The Hound of the Baskervilles.txt");
    }
    if(booknum==4)
    {
        strcat(file_name, "\\books\\The Mind and Its Education.txt");
    }
    if((infile = fopen(file_name, "r")) == NULL)
    {
        cout << "Sorry, can't open " << file_name << endl;
        cout << "Please Make sure that all files is in their place.";
    }
    else	while((ch = getc(infile)) != EOF)
        {
            putc(ch, stdout);
        }
    fclose(infile);
    cout << "\n";
}

void enterCommand::opencategoryf(int y)
{
    int categorynum;
    categorynum=y;
    if(categorynum==1)
    {
        cout << "1.Adventures of Huckleberry Finn (Part 1)" << endl;
        cout << "2.Adventures of Huckleberry Finn (Part 2)" << endl;
    }
    if(categorynum==2)
    {
        cout << "2.The Hound of the Baskervilles" << endl;
    }
    if(categorynum==3)
    {
        cout << "4.The Mind and Its Education" << endl;
    }
}

void enterCommand::exitf()
{
    exit(1);
}

int main(void)
{
    system("color 3A");
    cout << endl;
    cout << "Project Gutenberg" << endl;
    cout << "NABIL ASHAB" << endl;
    cout << "Department of Computer Science and Engineering" << endl;
    cout << "Khulna University of Engineering and Technology" << endl;
    cout << "Roll: 1207016" << endl;
    SetWindow(160,9999);
    HWND hwnd;
    hwnd=GetForegroundWindow();
    SetWindowPos(hwnd, HWND_TOPMOST, 300, 300, 1168, 1160, NULL);
    for(;;)
    {
        string command;
        cout << endl;
        cout << "Please Enter Command: ";
        cin >> command;

        if(command=="help")
        {
            enterCommand helpfob;
            helpfob.helpf();
        }

        if(command=="version")
        {
            enterCommand versionfob;
            versionfob.versionf();
        }

        if(command=="author")
        {
            enterCommand authorfob;
            authorfob.authorf();
        }

        if(command=="list.books")
        {
            enterCommand bookfob;
            bookfob.bookf();
        }

        if(command=="quit")
        {
            enterCommand exitfob;
            exitfob.exitf();
        }

        if(command=="open.book")
        {
            int booknum;
            enterCommand bookfob;
            bookfob.bookf();
            cout << endl << "Enter book number: ";
            cin >> booknum;
            cout <<endl;
            if(booknum==1)
            {
                enterCommand openbookfob;
                openbookfob.openbookf(1);
            }
            if(booknum==2)
            {
                enterCommand openbookfob;
                openbookfob.openbookf(2);
            }
            if(booknum==3)
            {
                enterCommand openbookfob;
                openbookfob.openbookf(3);
            }
            if(booknum==4)
            {
                enterCommand openbookfob;
                openbookfob.openbookf(4);
            }
        }

        if(command=="list.categories")
        {
            enterCommand categoryfob;
            categoryfob.categoryf();
        }

        if(command=="open.category")
        {
            int categorynum,booknum;
            enterCommand categoryfob;
            categoryfob.categoryf();
            cout << endl << "Enter category number: ";
            cin >> categorynum;
            cout << endl;
            if(categorynum==1)
            {
                enterCommand opencategoryfob;
                opencategoryfob.opencategoryf(1);
            }
            if(categorynum==2)
            {
                enterCommand opencategoryfob;
                opencategoryfob.opencategoryf(2);
            }
            if(categorynum==3)
            {
                enterCommand opencategoryfob;
                opencategoryfob.opencategoryf(3);
            }
            cout << endl << "Enter book number: ";
            cin >> booknum;
            cout <<endl;
            if(booknum==1)
            {
                enterCommand openbookfob;
                openbookfob.openbookf(1);
            }
            if(booknum==2)
            {
                enterCommand openbookfob;
                openbookfob.openbookf(2);
            }
            if(booknum==3)
            {
                enterCommand openbookfob;
                openbookfob.openbookf(3);
            }
            if(booknum==4)
            {
                enterCommand openbookfob;
                openbookfob.openbookf(4);
            }
        }
    }
    getch();
    return 0;
}
