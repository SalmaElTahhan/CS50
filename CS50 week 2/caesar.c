#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2) //checks if argument is not equal 2
    {
        printf("Usage: ./caesar key\n");  //if so print this
        return 1; //then return 1
    }
    int length = strlen(argv[1]); //get length of string in argument
    for (int i = 0; i < length; i++) //pass through the length of string
    {
        if (!isdigit(argv[1][i])) //checks if the character in the string is not digit
        {
            printf("Usage: ./caesar key\n"); //if not print this
            return 1; //then return 1
        }

    }
    int key = atoi(argv[1]); //convert string to integer
    string plaintext = get_string("plaintext: ");  //get plaintext from user
    printf("ciphertext: "); //the enciphered text will be placed here
    int plaintext_length = strlen(plaintext);  //checks the length of plaintext
    for (int i = 0; i < plaintext_length; i++) //pass through the whole plaintext the user entered
    {
        if (isupper(plaintext[i])) //checks if character is uppercase
        {
            printf("%c", (((plaintext[i] - 65) + key) % 26) + 65); //if so do this calculation then print the new character
        }
        else if (islower(plaintext[i])) //checks if character is lowercase
        {
            printf("%c", (((plaintext[i] - 97) + key) % 26) + 97); //if so do this calculation then print new character
        }
        else //if character is not alphabet
        {
            printf("%c", plaintext[i]); //just print the character as it is
        }
    }
    printf("\n");

}