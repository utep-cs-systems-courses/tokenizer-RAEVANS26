#include <stdio.h>
#include "tokenizer.h"
#include "malloc.h"

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
    //Pretty much the opposite of space_char
}

char *word_start(char *word)
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

char *word_terminator(char *word)
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

int count_words(char *str)
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

char *copy_str(char *inStr, short len)
{
    char *copyStr = malloc((len + 1) * sizeof(char));
    int i;
    for (i=0; i < len; i++){
        copyStr[i] = inStr[i];
    }
    copyStr[i] = '\0';
    return copyStr;
}

int word_length(char *str)
{   
    char *tmpS = word_start(str);
    char *tmpE = word_terminator(tmpS);
    int i = 0;
    int length = 0;
    length = tmpE - tmpS;
    return length;
}

char **tokenize(char *str)
{
    int size = count_words(str);
    char **tokens = malloc((size + 1) * sizeof(char *));
    int i;
    int length;
    char *p = str;
    for(i = 0;i < size;i++){
        p = word_start(p);
        length = word_length(p);
        tokens[i] = copy_str(p, length);
        p = word_terminator(p);
    }
    tokens[i] = '\0';
    return tokens;
}

void print_tokens(char **tokens)
{
    int i=0;
    while (tokens[i]){
        printf("Token[%d] = %s\n", i, tokens[i]);
        i++;
    }
}

void free_tokens(char **tokens)
{
    int i = 0;
    while(tokens[i]){
        free(tokens[i]);
        i++;
    }
    free(tokens);
}

