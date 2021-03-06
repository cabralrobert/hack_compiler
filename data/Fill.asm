// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.


(READ_KEYBOARD)
@24576
D=M
@WHITE
M+1;JEQ
@BLACK
0; JMP

(BLACK)
@SCREEN
D=A
@counter
M=D

@black
M=-1

(LOOP1)
@black
D=M
@counter
A=M
M=D

@counter
M=M+1
D=M

@24576
D=A-D
@LOOP1
D; JGT

@READ_KEYBOARD
0; JMP

(WHITE)
@SCREEN
D=A
@counter
M=D

@black
M=0

(LOOP2)
@black
D=M
@counter
A=M
M=D

@counter
M=M+1
D=M

@24576
D=A-D
@LOOP2
D; JGT

@READ_KEYBOARD
0; JMP

(END)
@END
0;JMP
