# mastermind
Program called mastermind, it is an implementation of the famous game. Written in C.
        MASTERMIND

MASTERMIND is an implementation of the famous game.

1. DESCRIPTION.
Game is composed of 8 pieces - numbers '0', '1', '2', '3', '4', '5', '6', '7'.
A secret code is composed of 4 distinct pieces. The player has 10 attempts to find the secret code.
After each input, the game indicates to the player the number of well placed pieces and the number
of misplaced pieces. A misplaced piece is a piece that is present in the secret code but that is not
in a good position.
If the player find the code, he wins, and the game stops.
The program receive the following parameters:
 -c [CODE]: specifies the secret code. If no code is specified, a random code will be generated.
 -t [ATTEMPTS]: specifies the number of attempts. By default, the player has 10 attempts.

 Example of calling programm:
 >./my_mastermind                  - random code and 10 attempts.
 >./my_mastermind -c 1234          - code "1234" and 10 attempts.
 >./my_mastermind -t 5             - random code and 5 attempts.
 >./my_mastermind -ct 1234 6       - code "1234" and 6 attempts.

 Calling in other way will not run the programm.
 After running the program player will be proposed to input the code.
 The code must be of different pieces. None except specified pieces allowed - otherwise will be printed an
 error.

 Example:
 >./my_mastermind -c 0123
 Will you find the secret code?
 ---
 Round 0
 >1456
 Well placed pieces: 0
 Misplaced pieces: 1
 ---
 Round 1
 >ghtf
 Wrong input!
 >4132
 Well placed pieces: 1
 Misplaced pieces: 2
 ---
 Round 2
 >0123
 Congratz! You did it!

 2. Technical information.
 The program consists of three files: main.c, my_mastermind.c and my_mastermind.h.
 In main.c contained base part of the program, that receives inputs, return outputs and errors.
 In my_mastermind.c there are 3 functions: 
 int my_mastermind(), which compare input to secret code and returns number of well placed and 
                        misplaced pieces;
 char* code(),        which gives the secret code, from given parameter or randomly;
 char error_check(),  which checks inputs of the code for finding mistakes.
 Modules, that used in program:
 <stdio.h>
 <stdlib.h>
 <time.h>
 <unistd.h>
 Also used header file my_mastermind.h with functions declaration.

