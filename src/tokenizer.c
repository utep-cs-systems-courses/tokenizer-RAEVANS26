#include <stdio.h>
#include "tokenizer.h"
//#include "malloc.h"
#include <stdlib.h>

int space_char(char c)
{
    if (( c == ' '|| c == '\t')){//checks if space or tab
        return 1;
    }
    return 0;
}

int non_space_char(char c)
{
    if ((c==' '||c=='\t'||c=='\n')){//checks if space or tab or newline
        return 0;   
    }
    return 1;
}

char *word_start(char *word)//moves pointer to the first char in the word
{
    int i=0;
    while(*(word + i))
    {
        if (non_space_char(*(word + i)))
        {
            return word + i;
        }
        i++;
    }
    return word + i;
}

char *word_terminator(char *word)//moves the pointer to the space character right after the last char in the word 
{
    int i=0;
    while(*(word + i))
    {
        if(space_char(*(word + i)))
        {
            return word + i;
        }
        i++;
    }
    return word + i;
}

int count_words(char *str)//returns a count of all the words in the user input string
{
    char *tmp = str;
    int count = 0;
    int i = 0;//pointer is on the first char in the first word
    tmp = word_start(tmp);
    while(non_space_char(*tmp))
    {
        if (*tmp == '\0')
        {
            return count ;
        }
        count++;
        tmp=word_terminator(tmp);
        tmp=word_start(tmp);
    }
    return count;
}

char *copy_str(char *inStr, short len)//returns copied string from user input string
{
    char *copyStr = malloc((len + 1) * sizeof(char));
    int i;
    for (i=0; i < len; i++){
        copyStr[i] = inStr[i];
    }
    copyStr[i] = '\0';
    return copyStr;
}

int word_length(char *str)//returns length of a word 
{   
    char *tmpS = word_start(str);
    char *tmpE = word_terminator(tmpS);
    int i = 0;
    int length = 0;
    length = tmpE - tmpS;
    return length;
}

char **tokenize(char *str)//returns double pointer of tokenized string
{
    int size = count_words(str);
    char **tokens = malloc((size + 1) * sizeof(char *));
    int i;
    int length;
    for(i = 0;i < size;i++){
        str = word_start(str);
        length = word_length(str);
        tokens[i] = copy_str(str, length);
        str = word_terminator(str);
    }
    tokens[i] = '\0';//ends with terminator so it will be easier to print
    return tokens;
}

void print_tokens(char **tokens)//prints tokens from double pointer of tokenized string
{
    int i=0;
    while (tokens[i]){
        printf("Token[%d] = %s\n", i, tokens[i]);
        i++;
    }
}

void free_tokens(char **tokens)//clears tokens to free memory
{
    int i = 0;
    while(tokens[i]){
        free(tokens[i]);
        i++;
    }
    free(tokens);
}

