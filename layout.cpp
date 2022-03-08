Main Menu
PF (CS-2021)A, B, C, D
Week 10 - Lab 2 - UAMS Starter Code
Maida Shahid
•
Yesterday
UAMStemplate.cpp
Text
Class comments

//________Header Files________________
#include <iostream>
#include <conio.h>

using namespace std;

// _____________________Prototypes________________
void mainHeader();
char adminMenu();
void clearScreen();
string loginMenu();
void addStudent();
void viewAllStudents();
void subheader();
char studentMenu();
void addStudentIntoArray(string name, int matric, int fsc, int ecat, string p1, string p2, string p3);
int seatManagementMenu();
void viewSeatsDetails();
void addUser(string name, string pass, string role);
void print_Recd();
float aggrigate(float mMarks, float fMarks, float eMarks);
void generate_Mlist();
int studentInfo();

//_____________________Data Structures_______________________
const int MAX_RECORDS = 20;
string usernameA[MAX_RECORDS];
string passwordsA[MAX_RECORDS];
string rolesA[MAX_RECORDS];
int userCount = 0;
int count = 0;

string student_name[MAX_RECORDS];
float student_ecat[MAX_RECORDS];
float student_matric[MAX_RECORDS];
float student_fsc[MAX_RECORDS];
string student_pref1[MAX_RECORDS];
string student_pref2[MAX_RECORDS];
string student_pref3[MAX_RECORDS];
float aggr[MAX_RECORDS];
int entry_count = 0;

string department[] = {"CS", "CE", "EE"};
int seats[] = {0, 0, 0};
int capacity = 0;
bool announce = false;

string username;
//_____________ Main function___________
main()
{

   addUser("admin", "123", "ADMIN"); //__________DEFAULT VALUE SET__________

   string who = " ";
   while (true)
   {
      who = loginMenu();
      if (who == "ADMIN")
      {
         char option = ' ';
         while (true)
         {
            system("cls");
            option = adminMenu();
            if (option == '1')
            {
               addStudent();
            }
            else if (option == '2')
            {
               viewAllStudents();
            }
            else if (option == '3')
            {
               //----------Print the record in merit order
               print_Recd();
               viewAllStudents();
            }
            else if (option == '4')
            {
               //------------ Generate merit list
               generate_Mlist();
            }
            else if (option == '5')
            {
               //------------ Add Users
               cout << "Enter username........ ";
               string username;
               cin >> username;

               cout << "Enter password........ ";
               string pass;
               cin >> pass;

               cout << "Enter role........";
               string role;
               cin >> role;
               addUser(username, pass, role);
            }
            else if (option == '6')
            {
               while (true)
               {
                  system("cls");
                  int dpIndex = seatManagementMenu();
                  if (dpIndex == 1 || dpIndex == 2 || dpIndex == 3)
                  {
                     cout << "Enter New Capacity for " << department[dpIndex - 1] << endl;
                     cin >> capacity;
                     seats[dpIndex - 1] = capacity;
                  }
                  else if (dpIndex == 4)
                  {
                     viewSeatsDetails();
                     clearScreen();
                  }
                  else if (dpIndex == 5)
                  {
                     break;
                  }
                  else
                  {
                     cout << "You chose wrong option!" << endl;
                     clearScreen();
                  }
               } //end of seats management
            }
            else if (option == '7')
            {
               cout << "Press 2 to Announce the Result ";
               int annouce;
               cin >> annouce;
               if (annouce == 2)
               {
                  announce = true;
               }
            }
            else if (option == '8')
            {
               break;
            }
            else
            {
               cout << "You Chose Wrong option " << endl;
            }
            clearScreen();
         } //end of admin wile loop
      }
      else if (who == "STUDENT")
      {
         char studentOption = ' ';
         while (true)
         {
            system("cls");
            studentOption = studentMenu();
            if (studentOption == '1')
            {
               // View student information
               int st_index = studentInfo();
               cout << student_name[st_index] << "\t" << student_matric[st_index] << "\t" << student_fsc[st_index] << "\t" << student_ecat[st_index] << "\t" << aggr[st_index] << endl;
            }
            else if (studentOption == '2')
            {
               if (announce)
               {
                  //----pending to implement
               }
               else
               {
                  cout << "Result is not announced yet " << endl;
               }
            }
            else if (studentOption == '3')
            { //________logout option______
               break;
            }
            else
            {
               cout << "Wrong selection! Try again";
            }
            clearScreen();
         } //end of student menu while loop
      }
      else if (who == "EXIT")
      {
         cout << "choose correct option" << endl;
      }
      else
      {
         cout << "You entered wrong option " << endl;
      }
      clearScreen();
   } //end of while

} //end of main function

//__________________________ Function definitions_____________
void mainHeader()
{
   cout << "----------------------------------------------" << endl;
   cout << "--- University Admission Management System ---" << endl;
   cout << "----------------------------------------------" << endl;
}

string loginMenu()
{ //________Get user credentials and check whether user is present in array or not_______
   mainHeader();
}

int seatManagementMenu()
{ //________Discipline with capacity of student. this data should store in variable int seats[] = {0,0,0};_____
   mainHeader();
   cout << "Seat Management Menu > " << endl;
   cout << "1- Edit CS Capacity " << endl;
   cout << "2- Edit CE Capacity " << endl;
   cout << "3- Edit EE Capacity " << endl;
   cout << "4- View Seats Details " << endl;
   cout << "5- Back " << endl;
}

void viewSeatsDetails()
{ //______View total seats according to discipline_________
}

char adminMenu()
{ //_______Administrator level menu goes here__________
   mainHeader();
   cout << "Admin Main Menu > " << endl;
   cout << "1- Add New Student " << endl;
   cout << "2- View All Students" << endl;
   cout << "3- Print the record in merit order " << endl;
   cout << "4- Generate Merit " << endl;
   cout << "5- Add Users " << endl;
   cout << "6- Seat Management " << endl;
   cout << "7- Announce Result " << endl;
   cout << "8- Logout " << endl;
   cout << " Choose Your Option : ";
}

char studentMenu()
{ //_________Student or user menu, what user can choose_________
   mainHeader();
   cout << "Student Main Menu > " << endl;
   cout << "1- View Your Profile " << endl;
   cout << "2- Check Admission Status " << endl;
   cout << "3- Logout " << endl;
   cout << " Choose Your Option : ";
}

void clearScreen()
{ //____clear screen_____
   cout << "Press any key to continue " << endl;
   getch();
   system("CLS");
}

void addStudent()
{ //__________Get student data and their preferences__________
   addStudentIntoArray();
}

void addStudentIntoArray(string name, int matric, int fsc, int ecat, string p1, string p2, string p3)
{ //______Store student data into array____each time addStudent() function is called. it will store into global array
}
void viewAllStudents()
{ //_______Retrieve student data and show on screen_______
}

void subheader()
{ //________header for preference______
   cout << "   Enter the Name for Preferences    " << endl;
   cout << "********************************************" << endl;
   cout << "Choose between these disciplines " << endl;
   cout << "1- CS for Compter Science" << endl;
   cout << "2- CE for Compter Engineering" << endl;
   cout << "3- EE for Electrical Engineering" << endl;
   cout << "********************************************" << endl;
}

void addUser(string name, string pass, string role)
{ //______Add user, only admin can add_________
}

float aggrigate(float mMarks, float fMarks, float eMarks)
{ //_____________calculate aggrigate_______________
}

void print_Recd()
{ //_____________calculate & sort in merit order_________
}

void generate_Mlist()
{ //_________________Generate merit according to discipline a student get admit____________
}

int studentInfo()
{ //____________Student as user info__________
}

UAMStemplate.cpp
Displaying UAMStemplate.cpp.