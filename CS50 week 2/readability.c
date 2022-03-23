#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int letter = 0; //counts letters
    int word = 1; //counts words
    int sentence = 0; //counts sentences
    string text = get_string("Text:"); //gets text from user
    int length = strlen(text); //checks the text length
    for (int i = 0; i < length; i++) //pass through the length of text to count letters
    {
        if (isalpha(text[i])) //checks if text is alphabetical
        {
            letter++; //if the text is alphabetical increment letters by 1
        }

    }
    for (int j = 0; j < length; j++) //pass through length of text to count words
    {
        if (isspace(text[j])) //checks if there is white space 
        {
            word++; // if i found white space increment the words by 1
        }

    }
    for (int k = 0; k < length; k++) //pass through length of text to count sentences
    {
        if (text[k] == '.' || text[k] == '?' || text[k] == '!') //checks if there is . or ? or ! sentence
        {
            sentence++; //if there is . or ? or ! increment sentences by 1
        }

    }
    float unrounded_index = 0.0588 * ((letter * 100.0) / word) - 0.296 * ((sentence * 100.0) / word) - 
                            15.8; // calculate Coleman-Liau index
    int index = round(unrounded_index); //round index to nearest whole number
    if (index < 1) //checks if index is less than 1
    {
        printf("Before Grade 1\n"); //if yes print before grade 1
    }
    else if (index >= 16) //checks is index is greater than or equal 16
    {
        printf("Grade 16+\n"); //if yes print grade 16+
    }
    else
    {
        printf("Grade %i\n", index); //otherwise print the grade equals index
    }


}