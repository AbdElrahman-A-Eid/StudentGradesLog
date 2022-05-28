#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

using namespace std;

/*
 Author: AbdElrahman Eid
 Github: AbdElrahman-A-Eid
*/

struct Student
{
    int Id;
    char Name[20];
    int Grades[5];

};

void gotoxy(int column, int line);
int down(int& currRow);
int up(int& currRow);
void PrintStd(Student* s, int no);
int isUnique(Student* s, int id, int& i,  int stdSize, int isReplace);
int FillStd(Student* s, int& i, int stdSize, int isReplace);
void Replace(Student* s, int stdSize);
void Add(Student* s, int& i, int stdSize);
void Disp(Student* s, int& i);
void DispAll(Student* s, int& i);
void menuInit (int& currRow);
void menuNav (int& currRow, Student* s, int& i, int stdSize, int& flag);

int main()
{
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console_color, 10);
    gotoxy(0, 0);
    cout << "**** AbdElrahman's Student Grades Log v2.0 ****" << endl;

    SetConsoleTextAttribute(console_color, 13);
    gotoxy(0, 2);
    cout << "Welcome!";

    SetConsoleTextAttribute(console_color, 14);
    gotoxy(9, 2);
    cout << "Please enter the number of students you would like to store data about: ";

    int stdSize;
    cin >> stdSize;

    int currRow = 5;
    int i = 0;

    system("cls");

    Student* stArr = new Student[stdSize];

    int flag = 1;

    if (stArr != NULL) {
        while (flag){
            menuInit(currRow);
            menuNav(currRow, stArr, i, stdSize, flag);
        }
    gotoxy(0, 12);
    delete(stArr);
    SetConsoleTextAttribute(console_color, 15);
    system("pause");
    }
    return 0;
}

void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle( STD_OUTPUT_HANDLE ),
        coord
    );
}

int down(int& currRow)
{
 int newRow;
 if (currRow < 8) {
    newRow = currRow + 1;
 } else {
    newRow = 5;
 }
 gotoxy(5, newRow);
 return newRow;
}


int up(int& currRow)
{
 int newRow;
 if (currRow > 5) {
    newRow = currRow - 1;
 } else {
    newRow = 8;
 }
 gotoxy(5, newRow);
 return newRow;
}

void menuInit (int& currRow)
{
    system("cls");
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console_color, 10);
    gotoxy(0, 0);
    cout << "**** AbdElrahman's Student Grades Log v2.0 ****" << endl;

    SetConsoleTextAttribute(console_color, 12);
    gotoxy(0, 1);
    cout << "Key Instructions:" << endl;

    SetConsoleTextAttribute(console_color, 23);
    gotoxy(0, 2);
    cout << "Up Arrow";
    SetConsoleTextAttribute(console_color, 15);
    gotoxy(8, 2);
    cout << " Navigate Upwards";

    SetConsoleTextAttribute(console_color, 23);
    gotoxy(30, 2);
    cout << "Down Arrow";
    SetConsoleTextAttribute(console_color, 15);
    gotoxy(40, 2);
    cout << " Navigate Downwards";

    SetConsoleTextAttribute(console_color, 23);
    gotoxy(70, 2);
    cout << "1~4 Keys";
    SetConsoleTextAttribute(console_color, 15);
    gotoxy(78, 2);
    cout << " Menu Navigation Shortcut";

    SetConsoleTextAttribute(console_color, 23);
    gotoxy(0, 3);
    cout << "Home";
    SetConsoleTextAttribute(console_color, 15);
    gotoxy(4, 3);
    cout << " Go to First Option";

    SetConsoleTextAttribute(console_color, 23);
    gotoxy(30, 3);
    cout << "Enter";
    SetConsoleTextAttribute(console_color, 15);
    gotoxy(35, 3);
    cout << " Choose Highlighted Operation";

    SetConsoleTextAttribute(console_color, 14);

    gotoxy(0, 4);
    cout << "Please choose the operation you would like to perform:" << endl;

    gotoxy(5, 5);
    cout << "1) Add";

    gotoxy(5, (5+1));
    cout << "2) Display";

    gotoxy(5, (5+2));
    cout << "3) Display All";

    gotoxy(5, (5+3));
    cout << "4) Exit" << endl;

    gotoxy(5, currRow);
}

void menuNav (int& currRow, Student* s, int& i, int stdSize, int& flag)
{
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    char ch = getch();

    if ((int)ch == -32) {
        ch = getch();
        switch ((int)ch) {
        case 80:
            currRow = down(currRow);
            break;
        case 72:
            currRow = up(currRow);
            break;
        case 71:
            currRow = 5;
            gotoxy(5, currRow);
            break;
        }
    } else if ((int)ch == 13) {
        switch(currRow) {
        case 5:
            Add(s, i, stdSize);
            break;
        case (5+1):
            Disp(s, i);
            break;
        case (5+2):
            DispAll(s, i);
            break;
        case (5+3):
            SetConsoleTextAttribute(console_color, 13);
            cout << "\n\n\tThank you for using my menu! The program will exit shortly..." << endl;
            Sleep(1000);
            flag = 0;
            break;
        }
    } else {

        switch(ch) {

        case '1':
            currRow = 5;
            gotoxy(5, currRow);
            break;
        case '2':
            currRow = 6;
            gotoxy(5, currRow);
            break;
        case '3':
            currRow = 7;
            gotoxy(5, currRow);
            break;
        case '4':
            currRow = 8;
            gotoxy(5, currRow);
            break;

        }

    }
}

void PrintStd(Student* s, int no, int& row)
{
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console_color, 12);

   gotoxy(0, row); // 3
   cout << "Student no. " << no << " Data";

   gotoxy(2, row+1); // 4
   SetConsoleTextAttribute(console_color, 9);
   cout << "{";

   gotoxy(5, row+2); // 5
   SetConsoleTextAttribute(console_color, 11);
   cout << "ID: ";
   gotoxy(13, row+2);
   SetConsoleTextAttribute(console_color, 15);
   cout << s[no-1].Id;

   gotoxy(5, row+3); // 6
   SetConsoleTextAttribute(console_color, 11);
   cout << "Name: ";

   gotoxy(13, row+3);
   SetConsoleTextAttribute(console_color, 15);
   cout << s[no-1].Name;

   gotoxy(5, row+4); // 7
   SetConsoleTextAttribute(console_color, 11);
   cout << "Grades: ";

   gotoxy(13, row+5); // 8
   SetConsoleTextAttribute(console_color, 1);
   cout << "{";

   int sub = 1;
   for (int col = 15; col <= 55; col += 10) {
        if (col < 50) {
            gotoxy(col, row+5);
            SetConsoleTextAttribute(console_color, 1);
            cout << "SUB" << sub << ",";
        } else {
            gotoxy(col, row+5);
            SetConsoleTextAttribute(console_color, 1);
            cout << "SUB" << sub;
        }
        sub++;
   }

   gotoxy(60, row+5);
   SetConsoleTextAttribute(console_color, 1);
   cout << "}";

   gotoxy(66, row+5);
   SetConsoleTextAttribute(console_color, 1);
   cout << "SUM";



   gotoxy(13, row+6); // 9
   SetConsoleTextAttribute(console_color, 9);
   cout << "{";

   int k = 0;
   int sum = 0;
   for (int col = 15; col <= 55; col += 10) {
        if (col < 50) {
            gotoxy(col+1, row+6);
            SetConsoleTextAttribute(console_color, 6);
            cout << s[no-1].Grades[k] << ",";
        } else {
            gotoxy(col+1, row+6);
            SetConsoleTextAttribute(console_color, 6);
            cout << s[no-1].Grades[k];
        }
        sum += s[no-1].Grades[k];
        k++;
   }

   gotoxy(60, row+6);
   SetConsoleTextAttribute(console_color, 9);
   cout << "}";

   gotoxy(63, row+6);
   SetConsoleTextAttribute(console_color, 13);
   cout << "=";

   gotoxy(66, row+6);
   SetConsoleTextAttribute(console_color, 6);
   cout << sum;

   gotoxy(2, row+7); // 10
   SetConsoleTextAttribute(console_color, 9);
   cout << "}";

}

int isUnique(Student* s, int id, int& i, int stdSize, int isReplace)
{
    int flag = 1;
    if (isReplace) {
        for (int j = 0; j < stdSize; j++){
            if(id == s[j].Id && j != i){
                flag = 0;
                break;
            }
        }
    } else {
        for (int j = 0; j < i; j++){
            if(id == s[j].Id){
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

int FillStd(Student* s, int& i, int stdSize, int isReplace)
{
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoxy(5, 3);
    SetConsoleTextAttribute(console_color, 14);
    cout << "Student ID: ";
    SetConsoleTextAttribute(console_color, 11);
    int tempId;
    cin >> tempId;
    if (isUnique(s, tempId, i, stdSize, isReplace)){
        s[i].Id = tempId;
        gotoxy(5, 4);
        SetConsoleTextAttribute(console_color, 14);
        cout << "Student Name: ";
        SetConsoleTextAttribute(console_color, 11);
        cin >> s[i].Name;
        gotoxy(5, 5);
        SetConsoleTextAttribute(console_color, 14);
        cout << "Student Grades: ";
        int sub = 1;
        for (int col = 10; col <= 70; col += 15) {
            gotoxy(col, 7);
            SetConsoleTextAttribute(console_color, 9);
            cout << "SUB" << sub;
            sub++;
        }
        int k = 0;
        for (int col = 10; col <= 70; col += 15) {
            gotoxy(col+1, 8);
            SetConsoleTextAttribute(console_color, 15);
            cin >> s[i].Grades[k];
            k++;
        }
    } else {
        SetConsoleTextAttribute(console_color, 12);
        cout << "\nThis ID is taken. Please enter a unique ID!" << endl;
        SetConsoleTextAttribute(console_color, 8);
        cout << "\nYou will be redirected to try again shortly...";
        Sleep(2000);
        isReplace ? Replace(s, stdSize) : Add(s, i, stdSize);
        return 0;
    }
    return 1;

}

void Replace(Student* s, int stdSize)
{
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    int index;
    system("cls");
    SetConsoleTextAttribute(console_color, 14);
    cout << "Please enter the student number to be replaced: ";
    cin >> index;
    index--;

    if (index > stdSize) {
        SetConsoleTextAttribute(console_color, 12);
        cout << "\n\nYou are trying to replace a student with a number that doesn't exist.\n" << endl;
        SetConsoleTextAttribute(console_color, 8);
        cout << "\nYou will be redirected to the main menu shortly...";
        Sleep(2000);
        return;
    }

    SetConsoleTextAttribute(console_color, 10);

    system("cls");
    gotoxy(0, 0);
    cout << "---- Student Data Replacement Screen ----";

    gotoxy(0, 2);
    SetConsoleTextAttribute(console_color, 14);
    cout << "Please enter the student's data below:";

    int isNotEdit;
    int isReplace = 1;
    isNotEdit = FillStd(s, index, stdSize, isReplace);

    if (isNotEdit) {
        gotoxy(0, 10);
        SetConsoleTextAttribute(console_color, 10);
        cout << "Student no. " << index+1 << " data has been replaced successfully" << endl;
    }
}

void Add(Student* s, int& i, int stdSize)
{
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console_color, 10);

    system("cls");
    gotoxy(0, 0);
    cout << "---- Student Data Insertion Screen ----";

    if (i < stdSize) {
        gotoxy(0, 2);
        SetConsoleTextAttribute(console_color, 14);
        cout << "Please enter the student's data below:";
        int isNotEdit;
        int isReplace = 0;
        isNotEdit = FillStd(s, i, stdSize, isReplace);

        if (isNotEdit) {
            gotoxy(0, 10);
            SetConsoleTextAttribute(console_color, 10);
            cout << "Student no. " << i+1 << " has been added successfully" << endl;
            i++;
            Sleep(2000);
        }

    } else {

        gotoxy(0, 2);
        SetConsoleTextAttribute(console_color, 12);
        cout << "You have already populated all of the " << stdSize << " students!" << endl;
        gotoxy(0, 4);
        SetConsoleTextAttribute(console_color, 14);
        cout << "Would you like to replace a specific student? (y/n) ";
        char answer;
        cin >> answer;

        if (tolower(answer) == 'n'){

            gotoxy(0, 6);
            SetConsoleTextAttribute(console_color, 8);
            cout << "You will be redirected to the main menu shortly...";
            Sleep(2000);
            return;
        }

        Replace(s, stdSize);
        gotoxy(0, 12);
        SetConsoleTextAttribute(console_color, 15);
        system("pause");

    }


}

void Disp(Student* s, int& i)
{
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    int row = 3;
    int index;
    system("cls");
    SetConsoleTextAttribute(console_color, 14);
    cout << "Please enter the student number to display: ";
    cin >> index;

    if (index > i) {
        SetConsoleTextAttribute(console_color, 12);
        cout << "\n\nThere is no data inserted for the specified student yet.\n" << endl;
        SetConsoleTextAttribute(console_color, 8);
        cout << "\nYou will be redirected to the main menu shortly...";
        Sleep(2000);
        return;
    }

    SetConsoleTextAttribute(console_color, 10);

    system("cls");
    gotoxy(0, 0);
    cout << "---- Student Data Display Screen ----";

    PrintStd(s, index, row);
    gotoxy(0, 12);
    SetConsoleTextAttribute(console_color, 15);
    system("pause");

}

void DispAll(Student* s, int& i)
{
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console_color, 10);

    int row = 3;
    system("cls");
    gotoxy(0, 0);
    cout << "---- Student Data Display Screen ----";
    if (i > 0) {
        int j;
        for (j = 0; j < i; j++) {
            PrintStd(s, j+1, row);
            gotoxy(0, 12*(j+1));
            if ((j+1) < i) {
                SetConsoleTextAttribute(console_color, 31);
                cout << "--------------------------------------------------------------------------";
            }
            row += 12;
        }
        gotoxy(15, (12*j)+2);
        SetConsoleTextAttribute(console_color, 10);
        cout << "A total of " << i << " students are displayed successfully!" << endl;
        gotoxy(0, (12*j)+4);
        SetConsoleTextAttribute(console_color, 15);
        system("pause");
    } else {
        SetConsoleTextAttribute(console_color, 12);
        gotoxy(0, 2);
        cout << "There are no students registered to display!\n";
        SetConsoleTextAttribute(console_color, 8);
        cout << "\nYou will be redirected to the main menu shortly...";
        Sleep(2000);
        return;
    }

}
