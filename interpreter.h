//
//  interpreter.h
//  The_OS_Shell
//
//  Created by Jack Hu on 2019-01-28.
//  Copyright © 2019 Jack Hu. All rights reserved.
//

#ifndef interpreter_h
#define interpreter_h

// These functions are now public 
int quit(void);
int help(void);
int set(char *words[]);
int print(char *words[]);
int script(char *words[]);

#endif /* interpreter_h */
