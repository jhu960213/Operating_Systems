//
//  interpreter.c
//  The_OS_Shell
//
//  Created by Jack Hu on 2019-01-19.
//  Copyright © 2019 Jack Hu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"
#include "shellmemory.h"
#include "shell.h"

// this function will interpret the commands & argument when passed and will modify shell memory when appropriate
int interpreter(char *words[]) {
    
    // instantiating error code
    int errorCode = 0;
    
    // user is asking to run a script
    if (strcmp(words[0], "run") == 0) {
        errorCode = script(words);
    }
    
    // user is asking to run a single command
    else if (strcmp(words[0], "quit") == 0) {
        errorCode = quit();
    } else if (strcmp(words[0], "help") == 0) {
        errorCode = help();
    } else if (strcmp(words[0], "set") == 0) {
        errorCode = set(words);
    } else if (strcmp(words[0], "print") == 0) {
        errorCode = print(words);
    } else {
        printf("\nUnkown Command!\n\n");
        errorCode = 0;
    }
    // returns a certain error code according to each individual command
    return errorCode;
}

// displays all the commands this OS supports
int help() {
    printf("\n");
    printf("These are the available commands below.\n");
    printf("Command format: COMMAND ARGUMENTS \n");
    printf("1) quit: Exits/terminates the shell \n");
    printf("2) help: Display all the commands \n");
    printf("3) set: Assigns a value to shell memory \n");
    printf("4) print: Prints the STRING assigned to VAR  \n");
    printf("5) run: Executes the file SCRIPT.TXT or any other txt file \n");
    printf("\n");
    return 0; // error code for no error default code
}

// quits shell with text bye and returns error code -1 for the infinite while loop to terminate 
int quit() {
    printf("\nBye!\n\n");
    return (-1);
}

// checks to see if VAR already exists, if it exits then STRING overwrites the previous value assigned to VAR in shell
// memory, if VAR does not exist then creates a new variable and assign it the input STRING
int set(char *words[]) {
    setVarString(words[1], words[2]);
    printf("\nSuccess!\n\n");
    return 0;
}

// prints string assinged to VAR, checks to see if it exists, if it does then prints it, otherwise prints
// "Variable does not exist"
int print(char *words[]) {
    printValue(words[1]);
    return 0;
}

// user is asking to execute the run command which reads line by line in a text file of all the
// commands, once it gets to a newline then script closes the text file and displays the command
// prompt once more
// in the case while its reading the command and it encounters a quit command then the file closes and commandline prompt terminates
int script(char *words[]) {
    
    // to get rid of the newline char at the end of the script name
    char *tmp = strtok(words[1], "\n");
    int errCode = 0;
    char scriptInput[1000];
    
    // in the case that the script text file does not exist, just exits the program
    FILE *file = fopen(tmp, "r");
    if (file == NULL) {
        printf("\nScript not found!\n\n");
        return errCode;
    }
    
    // reading each line of the opened text file and sending it to interpreter as commands for shell to do something 
    //fgets(scriptInput, 999, file);
    while (fgets(scriptInput, sizeof(scriptInput), file) != NULL) {
        errCode = parse(scriptInput);
        if (errCode == -1) {
            fclose(file);
            return errCode;
        }
    }
    fclose(file);
    return errCode;
}


