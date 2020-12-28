#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>

class gEmail {

public:

    gEmail();           //Initialise the string in gName[] with a space-character, i.e. " "

                        //Initialise the string in gMail[] with a NULL string, i.e. ""

    void setgName(char* gN); //Set gName[] to store the string pointed by gN

    void setgMail(char* gM); //Set gMail[] to store the string pointed by gM

    char* getgName();  //Return the address of gName[]

    char* getgMail();  //Return the address of gMail[]

private:

    char gName[100];    //Store the string of a person's name (e.g. "Li Mi")

    char gMail[100];    //Store the string of an e-mail address (e.g. li.mi@ghi.com)

};