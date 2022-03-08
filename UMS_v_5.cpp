#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

//-------------------------Data structures start ----------------------------
const int TOTAL_USER = 10;
int count_user = 0;
int exitmain = 0;
int student_count = 0;
string usernameA[TOTAL_USER];
string passwordA[TOTAL_USER];
string rolesA[TOTAL_USER];
const int TOTAL_STUDENT = 20;
string student_nameA[TOTAL_STUDENT];
string matricA[TOTAL_STUDENT];
string fscA[TOTAL_STUDENT];
string ecatA[TOTAL_STUDENT];
string pref1A[TOTAL_STUDENT];
string pref2A[TOTAL_STUDENT];
string pref3A[TOTAL_STUDENT];
string department[] = {"CS", "CE", "EE"};
bool resultannouce = false;
int seatsA[] = {0, 0, 0};
string loginusername = " ";

//---------------------------data structure end-----------------------------

//------------------------functions start -----------------------------------
void adduser(string username, string password, string role)
{
    if (count_user < TOTAL_USER)
    {
        usernameA[count_user] = username;
        passwordA[count_user] = password;
        rolesA[count_user] = role;
        count_user = count_user + 1;
    }
    else
    {
        cout << "There is no more space " << endl;
    }
}
string who()
{
    string username1, password1;
    cout << "Enter user name   :  ";
    cin >> username1;
    cout << "Enter Password    :  ";
    cin >> password1;
    for (int i = 0; i < TOTAL_USER; i++)
    {
        if (usernameA[i] == username1 && passwordA[i] == password1)
        {
            loginusername = username1;
            return rolesA[i];
            break;
        }
    }
    return "WRONG";
}
char adminmenu()
{
    char option;
    cout << "Main Menu  > Admin Menu" << endl;
    cout << "-------------------" << endl;
    cout << "Select one of the following options number - - -" << endl;
    cout << "1. Add New Student" << endl;
    cout << "2. View all Students " << endl;
    cout << "3. print in merit order " << endl;
    cout << "4. Generate Merit List " << endl;
    cout << "5. Add Users" << endl;
    cout << "6. Seat Managmennt" << endl;
    cout << "7. Annouce Result" << endl;
    cout << "8. Logout" << endl;
    cout << "Choose Your OPtion ..... ";
    cin >> option;
    return option;
}
char studentmenu()
{
    char option;
    cout << "Main Menu  > Student Menu" << endl;
    cout << "-------------------" << endl;
    cout << "Select one of the following options number - - -" << endl;
    cout << "1. View Profile" << endl;
    cout << "2. Check Addmision Status" << endl;
    cout << "3. Change Password " << endl;
    cout << "4. Logout " << endl;
    cout << "Choose Your OPtion ..... ";
    cin >> option;
    return option;
}
void clear_screen()
{
    cout << "Enter any key to continue :";
    getch();
    system("cls");
}
void header()
{
    cout << "*********************************************************" << endl;
    cout << "*        University Admission Management System         *" << endl;
    cout << "*********************************************************" << endl;
}
void subheader()
{
    cout << "  Enter the Name of Prefrences    " << endl;
    cout << "  ****************************   " << endl;
    cout << "  Choose between these descipline     " << endl;
    cout << "  1 )  CS for Computer Science    " << endl;
    cout << "  2 )  CE for Computer Engineering    " << endl;
    cout << "  3 )  EE foe Electric Engineering      " << endl;
}
void addstudenttoarray(string name, int matric, int fsc, int ecat, string p1, string p2, string p3)
{
    student_nameA[student_count] = name;
    matricA[student_count] = matric;
    fscA[student_count] = fsc;
    ecatA[student_count] = ecat;
    pref1A[student_count] = p1;
    pref2A[student_count] = p2;
    pref3A[student_count] = p3;
    student_count = student_count + 1;
}
void addstudent()
{
    int matric, fsc, ecat;
    string name, pref1, pref2, pref3;
    cout << "Please Enter Your Name : ";
    cin >> name;
    cout << "Please Enter Your Matric Marks : ";
    cin >> matric;
    cout << "Please Enter Your FSc Marks : ";
    cin >> fsc;
    cout << "Please Enter Your ECAT Marks : ";
    cin >> ecat;
    cout << endl;
    subheader();
    cout << "Enter you first prefrence :";
    cin >> pref1;
    cout << "Enter you second prefrence :";
    cin >> pref2;
    cout << "Enter you third prefrence :";
    cin >> pref3;
    addstudenttoarray(name, matric, fsc, ecat, pref1, pref2, pref3);
}
int seatmangmentmenu()
{
    header();
    cout << "Seat Managment Menu > " << endl;
    cout << "1)  Edit CS Capacity" << endl;
    cout << "2)  Edit CE Capacity" << endl;
    cout << "3)  Edit EE Capacity" << endl;
    cout << "4)  View Seat Details " << endl;
    cout << "5)  Exit" << endl;
    int option;
    cin >> option;
    return option;
}
void seatmangment()
{
    int seatoption = 0;
    while (true)
    {
        seatoption = seatmangmentmenu();
        if (seatoption == 1 || seatoption == 2 || seatoption == 3)
        {
            cout << "Enter your seats for " << department[seatoption - 1] << endl;
            int seats;
            cin >> seats;
            seatsA[seatoption - 1] = seats;
        }
        else if (seatoption == 4)
        {
            for (int i = 0; i < 3; i++)
            {
                cout << department[i] << " seats are " << seatsA[i] << endl;
            }
        }
        else if (seatoption == 5)
        {
            break;
        }
        else
        {
            cout << "You have entered the wrong input" << endl;
        }
    }
}
void viewallstudents()
{
    cout << "Name\tMatric\tFsc\tECAT\t1st Preference\t2nd Preference\t3rd Preference" << endl;
    for (int i = 0; i < student_count; i++)
    {
        cout << student_nameA[i] << "\t" << matricA[i] << "\t" << fscA[i] << "\t" << ecatA[i] << "\t" << pref1A[i] << "\t\t" << pref2A[i] << "\t\t" << pref3A[i] << endl;
    }
}
void addnewuser()
{
    string username, password, role;
    cout << "Enter username";
    cin >> username;
    cout << "Enter Password";
    cin >> password;
    cout << "Enter role";
    cin >> role;
    adduser(username, password, role);
}
void viewyourinfo()
{
    if (loginusername != " ")
    {
        for (int i = 0; i < student_count; i++)
        {
            if (student_nameA[i] == loginusername)
            {
                cout << student_nameA[i] << "    " << matricA[i] << "    " << fscA[i] << "    " << ecatA[i] << "    " << endl;
            }
        }
    }
}

// ------------------------function end-------------------------------------

main() //---------------------main_menu
{
    adduser("admin", "123", "admin");
    adduser("ali", "123", "student");
    while (exitmain != 1)
    {
        string w = " ";
        w = who();
        if (w == "admin")
        {
            system("cls");
            char admin_option = ' ';
            while (true)
            {
                header();
                admin_option = adminmenu();
                if (admin_option == '1')
                {
                    addstudent();
                }
                else if (admin_option == '2')
                {
                    viewallstudents();
                }
                else if (admin_option == '3')
                {
                }
                else if (admin_option == '4')
                {
                }
                else if (admin_option == '5')
                {
                    addnewuser();
                }
                else if (admin_option == '6')
                {
                    seatmangment();
                }
                else if (admin_option == '7')
                {
                    cout << "Press 2 to annouce the result" << endl;
                    char result;
                    cin >> result;
                    if (result == '2')
                    {
                        resultannouce = true;
                    }
                }
                else if (admin_option == '8')
                {
                    break;
                }
                else
                {
                    cout << "Wrong input.Try again" << endl;
                }
                clear_screen();
            }
        }
        else if (w == "student")
        {
            system("cls");
            char student_option = ' ';
            while (true)
            {
                student_option = studentmenu();
                if (student_option == '1')
                {
                    viewyourinfo();
                }
                else if (student_option == '2')
                {
                    if (resultannouce == true)
                    {
                        cout << "Your result has been announced" << endl;
                    }
                    else
                    {
                        cout << "Your result is not announced yet" << endl;
                    }
                }
                else if (student_option == '3')
                {
                }
                else if (student_option == '4')
                {
                    break;
                }
                else
                {
                    cout << "Wrong input.Try again" << endl;
                }
                clear_screen();
            }
        }
        else
        {
            cout << "Wrong username or141 password" << endl;
        }
    }
}