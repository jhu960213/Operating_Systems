//
//  shell.c
//  The_OS_Shell
//
//  Created by Jack Hu on 2019-01-19.
//  Copyright © 2019 Jack Hu. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "shell.h"

int main(int argc, const char * argv[]) {
    // starting of shell, user greetings and version goes here
    printf("\n\nWelcome to Jack Hu's Shell!\n");
    printf("Version 1.0 Created January 2019\n\n");
    displayShellPromptAndPassCommand();
    return 0;
}

// to display shell prompt indefinitley until script hits a certain exit code to finish and end process
void displayShellPromptAndPassCommand() {
    
    // instantiating char arrays to display prompt and store user inputs
    char prompt[1000] = {'$',' '};
    char userInput[1000];
    int errorCode = 0; // 0 meaning default code, no error
    
    // display the shell prompt indefinitley until an error code is reached and the function breaks out of the infinite loop
    while(1) {
        printf("%s",prompt);
        memset(&userInput[0],0,sizeof(userInput));
        // To account for when running script like this ./mysh < testfile.txt
        // When reading from terminal the fgets will eventually reach null
        // Thus when it reaches null then reroute stdin to keyboard
        if (fgets(userInput, sizeof(userInput), stdin) != NULL) {
            errorCode = parse(userInput);
            if (errorCode == -1) {
                break;
            }
        } else {
            freopen("/dev/tty", "r", stdin);
        }
    }
}

// this function when called parses user inputs and stores individual strings in an array of pointers for the interpretor to utilize
int parse(char ui[]) {
    
    // instantiating indexes and char arrays and array pointers to store parsed user input's address of the strings
    char tmp[400];
    char *words[1000];
    int i,j;
    int index = 0;
    
    for(i = 0; ui[i] == ' ' && i < 1000; i++); // skipping over white spaces
    while(ui[i] != '\0' && i<1000) {
        for(j = 0; ui[i]!='\0' && ui[i]!=' ' && i < 1000; i++, j++) { // copying over letters
            tmp[j] = ui[i];
            // to account for the carriage return 
            if (ui[i] == '\r') {
                j--;
            } else if (ui[i] == '\n') {
                j--;
            }
        }
        tmp[j] = '\0';
        words[index] = strdup(tmp); // mallocs a specific amounts of space in memory converts chars into string and stores the string's pointer at k = 0 of words
        for(i = i; ui[i] == ' ' && i < 1000; i++); // skipping over white spaces until the next user input string
        index++; // increment the words pointer array index
    }
    
    /*printf("%s\n", words[0]);
    printf("%s\n", words[1]);
    printf("%s\n", words[2]);*/
    return interpreter(words);
}
