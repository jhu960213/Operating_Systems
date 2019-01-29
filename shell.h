//
//  shell.h
//  The_OS_Shell
//
//  Created by Jack Hu on 2019-01-28.
//  Copyright © 2019 Jack Hu. All rights reserved.
//

#ifndef shell_h
#define shell_h

// These functions are public and could be called from outside shell.c
void displayShellPromptAndPassCommand(void);
int parse(char ui[]);
int interpreter(char *words[]);

#endif /* shell_h */
