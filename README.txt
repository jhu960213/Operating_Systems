Notes about my program:
- I complied with gcc on linux.mc.mcgill.ca so this is the OS that you will need to run my program
- My program works for all the commands separately and it also runs the script test file.txt when entered from the terminal like this: ./mysh < testfile.txt 
- When entered like that from the terminal it executes all the commands and brings program back to the shell prompt 
- Let's say if there's a quit command as the last command of the script then it quits out of my shell as it is supposed to according to assignment requirements 
- The run function also executes the testfile.txt and brings program either to an end or back to shell prompt depending on if quit was the last command. 
- For my program to execute the script, the .txt file must be in the same directory as my executable 
- If there is a run command within the testfile.txt then it will run the script again within the script that it is in (./mysh < testfile.txt ) but somehow on the last command it may loop a few times then come to a stop. I've tried fixing this but didn't make any progress 