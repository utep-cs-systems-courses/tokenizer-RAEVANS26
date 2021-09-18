#include "tokenizer.h"
#include <stdio.h>

int menuOpt(char str,char hflag)
{
    if((str == 's'||str == 'S')){
        return 1;
    }
    else if(str == '!'){
        return 2;
    }
    else if(str == 'q'|| str == 'Q'){
        return 3;
    }
    else{
        return 4;
    }
}

int main()
{
    char str[100]; 
    int i;
    while(1)
    {
        printf("1. Enter 's' to type and record a sentence.\n2. Enter '!' followed by a number to display a certain sentence from history.\n3. Enter '!h' to display all recorded sentences.\n3. Enter 'q'to quit.\n");
        printf("$ ");
        
        fgets(str,100,stdin);
        i = menuOpt(str[0],str[1]);
        
        switch(i)//i
        {
            case 1: 
                printf("Please enter your sentence:\n$");
                fgets(str, 100, stdin);
                char **tokens = tokenize(str);
                printf("\n");
                print_tokens(tokens);
                free_tokens(tokens);
                break;
                    
            case 2: 
                break;// history case  
                
            case 3: 
                printf("Thank you, Goodbye!\n");
                return 0;
                
            default: 
                printf("Sorry, that was not a valid option please try again.\n");
                break;
        }
    }
}
