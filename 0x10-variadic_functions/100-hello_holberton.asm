	SECTION .data
msg:	 db "Hello, Holberton", 10 ;message, use 10 for new line

	SECTION .text
	global main 		;declaration of main function for gcc
main:
	mov rdx, 17 		;third argument: length of string
	mov rcx, msg		;second argument: pointer to message to write
	mov rbx, 1		;first argument: file handle (stdout)
	mov rax, 4		;system call number (sys_write)
	int 0x80		;call kernel (interrupt)

	mov rbx, 0		;move 0 to rbx (exit code)
	mov rax, 1		;system call for exit
	int 0x80		;call kernel (interrupt)
