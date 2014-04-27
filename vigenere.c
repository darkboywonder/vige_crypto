#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // inputs string from second spot on command line and acts as key
    string k = (argv[1]);
    
    // if k isn' a word or no word exists return error    
    if( k == 0 || argc > 2 )
    {    
        printf("I need a word to encrypt\n");
        return 1;
    }
    
    // run program
    else
    {
        int h = 0;
        int g = strlen(k);
        
        //loops through keyword and checks that there isn't any numbers inside the word
        while( h < g )
        {
            if(isdigit(k[h]))
            {    
                printf("keyword must only contain letters A-Z and a-z\n");
                return 1;
            }
            h++;  
        }
        //if all checks pass get string from user
        string p = GetString();
           
        int l = 0;
        
        //loop through both keyword and actual string shifting letters as neccessary   
        for(int i = 0, m = strlen(k), n = strlen(p); i < n; i++)   
        { 
           //checks if current word is a letter if so continue on 
           if(isalpha(p[i]))
           {              
                //helps rotating through the key so we never run out of letters to key off of.
                int j = ( l % m );
                
                //if both letters are uppercase, use this formula to change the letter in the plaintext
                if(isupper(p[i]) && isupper(k[j]))   
                {
                    int alph_index = ((p[i]) - 65 );
                    int key_alph_index = ((k[j]) - 65 );
                    int c = (alph_index + key_alph_index) % 26;
                    int ascii = (c + 65);
                    printf("%c", ascii);
                    
                }
                //if both letters are lowercase, use this formula to change the letter in the plaintext
                else if( islower(p[i]) && islower(k[j]))
                {
                    int alph_index = ((p[i]) - 97 );
                    int key_alph_index = ((k[j]) - 97 );
                    int c = (alph_index + key_alph_index) % 26;
                    int ascii = (c + 97);
                    printf("%c", ascii);
                     
                }
                //if plaintext is upper and key is lower, use this formula to change the letter in the plaintext
                else if(isupper(p[i]) && islower(k[j]))
                {  
                    int alph_index = ((p[i]) - 65 );
                    int key_alph_index = ((k[j]) - 97 );
                    int c = (alph_index + key_alph_index) % 26;
                    int ascii = (c + 65);
                    printf("%c", ascii);
                    
                }
                //if plaintext is lower and key is upper, use this formula to change the letter in plaintext
                else if(islower(p[i]) && isupper(k[j]))
                {   
                    int alph_index = ((p[i]) - 97 );
                    int key_alph_index = ((k[j]) - 65 );
                    int c = (alph_index + key_alph_index) % 26;
                    int ascii = (c + 97);
                    printf("%c", ascii);
                   
                } 
                // current location isn't a letter, do nothing and print character as so (periods, commas, symbols, so forth)             
                else
                {
                    printf("%c", p[i]);
                }
            //increment letter postion    
            l++;      
            }
            //if current location is a space, print it forward
            else if(isspace(p[i]))
            {
            printf("%c", p[i]);
            }
            //if it doesnt meet any criteria, I don't want to do anything with it, print if forward       
            else
            {
             printf("%c", p[i]);
            }      
        }
        // print new line
        printf("\n");
    }
    //that's all folks!
    return 0;         
}
