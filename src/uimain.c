#include "tokenizer.h"
#include "history.h"
#include <stdio.h>
#include <stdlib.h>


int menuOpt(char str,char hflag)
{
    if((str == 's'||str == 'S')){//returns 1 in order to go to case 1 
        return 1;
    }
    else if(str == '!'){
        if (hflag&&hflag!='h'){//returns 1 in order to go to case 2 
            return 2;
        }
        return 3;//returns 3 in order to go to case 3  
        
    }
    else if(str == 'q'|| str == 'Q'){//returns 1 in order to go to case 4 
        return 4;
    }
    else{//returns 5 and goes to default case 
        return 5;
    }
}

int main()
{
    char str[100]; 
    int i;
    char **tokens;
    char *hlist;
    List *history= init_history();
    while(1)
    {
        printf("1. Enter 's' to type and record a sentence.\n2. Enter '!' followed by a number to display a certain sentence from history.\n3. Enter '!h' to display all recorded sentences.\n3. Enter 'q'to quit.\n");
        printf("$ ");
        
        fgets(str,100,stdin);
        i = menuOpt(str[0],str[1]);//will return an int to go to the case with the method that the user chose
    
        switch(i)//i
        {
            case 1: //tokenize user string and prints string in tokens
                printf("Please enter your sentence:\n$");
                fgets(str, 100, stdin);
                add_history(history,str);
                tokens = tokenize(str);
                printf("\n");
                print_tokens(tokens);
                free_tokens(tokens);
                break;
                    
            case 2: // get certain string from history list and prints as tokens
                hlist = get_history(history,atoi(str+1));
                tokens = tokenize(hlist);
                printf("\n");
                print_tokens(tokens);
                free_tokens(tokens);
                break;  
            
            case 3://prints all sentences stored in history
                print_history(history);
                break;// history case  
                
            case 4: //quits program
                printf("Thank you, Goodbye!\n");
                free_history(history);
                return 0;
                
            default: // if user does not enter a vaild option
                printf("Sorry, that was not a valid option please try again.\n");
                break;
        }
    }
}
