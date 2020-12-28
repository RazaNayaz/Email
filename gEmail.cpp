/*Raza Mohammed Nayaz
19086394D*/


#include "gEmail.h" //Include the header file that stores the class gEmail.

//Implement the class member functions here.
#include <string> 
gEmail::gEmail()
{
    strcpy(gName, " "); //Initialise the string in gName[] with a space-character, i.e. " "

                        
    strcpy(gMail, ""); //Initialise the string in gMail[] with a NULL string, i.e. ""
}
void gEmail::setgName(char* gN)
{
    strcpy(gName, gN); //Set gName[] to store the string pointed by gN
}
void gEmail::setgMail(char* gM)
{
    strcpy(gMail, gM); //Set gMail[] to store the string pointed by gM
}
char* gEmail::getgName()
{
    return gName; //Return the address of gName[]
}
char* gEmail::getgMail()
{
    return gMail;//Return the address of gMail[]
}


#include <iostream> //for cout and cin etc
#include <fstream> //for ofstream and ifstream

using namespace std;


//These four are function prototypes:
bool mMenu();
int matchEA();
void findWri(char mRef[]);
void enterM();

gEmail* pGArr; //Notice that pGArr is a global pointer.

int main() {

    pGArr = new gEmail[3]; //Claim a piece of heap memory for storing an array of 3 gEmail objects, and

       //store the array address to pGArr
    ofstream fi; //ofstream is used to write on the file
    fi.open("conBook.txt", ios::out); //Makes sure the file is empty at opening.
    fi.close(); //file close

    bool exitflag = true;

    while (exitflag == true)

        exitflag = mMenu(); //The loop ends when mMenu() returns true

    cout << "Test findWri() 3 times." << endl;

    char lineRef[100];

    findWri(lineRef);

    findWri(lineRef);

    findWri(lineRef);



    delete[] pGArr;//Release any memory ever claimed in the heap.

    return 0;

}

void enterM()
{
    int x = 0;
    int y = 3;
    char name[100], email[100];
    cin.ignore();
    do
    {

        cout << "Name: ";
        cin.getline(name, 100);
        pGArr[x].setgName(name); //calls in the setgName function from the class
        cout << "Email: ";
        cin.getline(email, 100);
        pGArr[x].setgMail(email); //calls in the setgMail function from the class
        x++;
    } while (x < y); //do while function to implement
}
bool mMenu()
{
    char input;
    cout << "========User Menu========" << endl; //Menu shown to user
    cout << "1. Enter contact book info" << endl;
    cout << "2. Show a record." << endl;
    cout << "3. End" << endl;
    cout << "Input your choice (1, 2 or 3 to end): ";
    cin >> input; //user input to choose what to do
    if (input == '1')
    {
        enterM();//calling enterM() function
        return true; // True to continue the loop
    }
    else if (input == '2')
    {
        int dp;
        cout << "Array index: ";
        cin >> dp;
        cout << pGArr[dp].getgName(); //calling the names from heap
        cout << "-";
        cout << pGArr[dp].getgMail();//calling the emails from heap
        cout << endl;
        return true;
    }
    else if (input == '3')
    {
        cout << "Thank You!" << endl;
        return false; // false to break the loop
    }
    else
    {
        cout << "Choice is unknown, enter again!" << endl; //if unknown choice is entered
        return true;
    }
}


int matchEA() {
    char Mails[100];
    cout << "Email address to match: ";
    cin >> Mails;//taking input from the user

    int i = 0;
    while (i < 3) {
        if (strcmp(Mails, pGArr[i].getgMail()) == 0) { return i; } //while loop to search through emails and compare them
        i++;//implement i by 1 each time the loop goes
    }

    return 89; //return 89

}

void findWri(char mRef[]) {

    int index;

    index = matchEA(); //To hold the index that is found, or 89 if not found.

    if (index == 89) { //89 is returned by matchEA when the email entered doesn't match,so when matchEA returns 89, the "Not found" string is stored in mRef
        strcpy(mRef, "Not found");
    }
    else {
        strcpy(mRef, pGArr[index].getgName()); //set the mRef to name
    }

    ofstream fi; //ofstream is used to write on the file
    fi.open("conBook.txt", ios::app); //ios::app for appending

    fi << mRef << endl; //Writing into the file.

    fi.close(); //file close
}
