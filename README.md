### The Monty Language
=
#### Description
***
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python).  It relies on a unique stack, with specific instructions to manipulate it.

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument. 

#### Usage
***
* 'monty file'  
   Where 'file' is the path to file containig the byte code
* If the user does not give any file or more than one argument to the program,  
  print the error message 'USAGE: monty file', followed by a new line, and exit with the status 'EXIT_FAILURE'
* If, for any reason, it’s not possible to open the file, print the error message 
 'Error: Can't open file <file>', followed by a new line, and exit with the status 'EXIT_FAILURE'  
  where '<file>' is the name of the 'file'
* If the file contains an invalid instruction, the program print the error message  
 'L<line_number>: unknown instruction <opcode>', followed by a new line, and exit with the status 'EXIT_FAILURE'  
  where the 'line number' is where the instruction appears.  
  Line numbers always start at 1
* The monty program runs the bytecodes line by line and stop if either:  
      * it executed properly every line of the file
      * it finds an error in the file
      * an error occured
* If program can’t malloc anymore, it print the error message 'Error: malloc failed', followed by a new line, and exit with status 'EXIT_FAILURE'.
* The program uses malloc and free and does not use any other function from man malloc (realloc, calloc, …)

#### Tasks
***
-[x] **0.push, and pall.**  
The opcode push pushes element to the stack.  
	* Usage: 'push <int>  
	where '<int>' is an integer.  
	* if '<int>'is not an  integer or if there is no argument given to push, print the error message 'L<line_number>: usage: push integer', followed by a new line, and exit with the status 'EXIT_FAILURE'.  
The pall opcode  
It prints all values on the stack, starting from the top of the stack.  
	* Usage 'pall'
	* If the format is empty, don't print anything.   
**Format**  
'''julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
'''
-[x] **pop Opcode**  
The opcode pop removes the top element of the stack.  
	* Usage: 'pop'  
	* If the stack is empty, print the error message 'L<line_number>: can't pop an empty stack', followed by a new line, and exit with the status EXIT_FAILURE
-[x] **swap opcode**  
The opcode swps the top two elements of the stack.  
	* Usage: 'swap'
	* If the stack contains less than two elements, print the error message 'L<line_number>: can't swap, stack too short', followed by a new line, and exit with the status 'EXIT_FAILURE'
-[x]**add Opcode**  
The opcode 'add' adds the top two elements of the stack.  
	* Usage: 'add'  
	* If the stack contains less than two elements, print the error message 'L<line_number>: can't add, stack too short', followed by a new line, and exit with the status 'EXIT_FAILURE'
	* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:  
		The top element of the stack contains the result  
		The stack is one element shorter
-[x] **nop Opcode**  
The opcode 'nop' doesn't do anything.  
	* Usage 'nop'
-[x] **sub**
