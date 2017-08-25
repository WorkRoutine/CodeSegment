Echo Usage
----------------------------------------------------

 echo - display a line of text 
 echo [SHORT-OPTION]... [STRING]... 

 [Commands] echo "Hello World" 
 [Describe] Echo the STRING(s) to standard output
 Hello World!

 [Commands] echo -n "Hello World"
 [Describe] do not output the trailing newline
 Hello World!
 [Commands] echo -e "Hello\ World!"
 [Describe] 
 Hello World!

 [Commands] echo -E "Hello\ World!"
 [Describe] disable interpretation of backslash escapes (default)
 Hello\ World!

 [Commands] echo --version
 [Describe] output version information and exit
 --version

 If -e is in effect, the following sequences are recognized: 
 [Commands] echo -e "Hello\ \ World!"
 [Describe] backslash
 Hello\world!

 [Commands] echo -e "Hello\a World"
 [Describe] alert (BEL)
 Hello World

 [Commands] echo -e "Hello\b World!"
 [Describe] backspace
 Hell World!

 [Commands] echo -e "Hello\c World!"
 [Describe] produce no further output
 Hello
 [Commands] echo -e "Hello\e World!"
 [Describe] escape
 Hello World!

 [Commands] echo -e "Hello\f World!"
 [Describe] form feed
 Hello
       World!

 [Commands] echo -e "Hello\n World!"
 [Describe] new line
 Hello
 World!

 [Commands] echo -e "Hello\r World!"
 [Describe] carriage return
 World!

 [Commands] echo -e "Hello\t World!"
 [Describe] horizontal tab
 Hello	 World!

 [Commands] echo -e "Hello\v World!"
 [Describe] vertical tab
 Hello
       World!

 [Commands] echo -e "Hello \063!"
 [Describe] byte with octal value NNN
 Hello 3

 [Commands] echo -e "Hello \x63!"
 [Describe] byte with hexadecimal value HH
 Hello c

 [Commands] echo -e "\033[30m Hello world! \033[0m"
 Color Black
 Hello World!

 [Commands] echo -e "\033[31m Hello world! \033[0m"
 Color Red
 Hello World!

 [Commands] echo -e "\033[32m Hello world! \033[0m"
 Color Green
 Hello World!

 [Commands] echo -e "\033[33m Hello world! \033[0m"
 Color Yellow
 Hello World!

 [Commands] echo -e "\033[34m Hello world! \033[0m"
 Color Blue
 Hello World!

 [Commands] echo -e "\033[35m Hello world! \033[0m"
 Color Purple
 Hello World!

 [Commands] echo -e "\033[36m Hello world! \033[0m"
 Color Sky Blue
 Hello World!

 [Commands] echo -e "\033[37m Hello world! \033[0m"
 Color White
 Hello World!

 [Commands] echo -e "\033[40m Hello world! \033[0m"
 BackColor Black
 Hello World!

 [Commands] echo -e "\033[41m Hello world! \033[0m"
 BackColor Red
 Hello World!

 [Commands] echo -e "\033[42m Hello world! \033[0m"
 BackColor Green
 Hello World!

 [Commands] echo -e "\033[43m Hello world! \033[0m"
 BackColor Yellow
 Hello World!

 [Commands] echo -e "\033[44m Hello world! \033[0m"
 BackColor Blue
 Hello World!

 [Commands] echo -e "\033[45m Hello world! \033[0m"
 BackColor Purple
 Hello World!

 [Commands] echo -e "\033[46m Hello world! \033[0m"
 BackColor SkyBlue
 Hello World!

 [Commands] echo -e "\033[47m Hello world! \033[0m"
 BackColor White
 Hello World!

 [Commands] echo -e "\033[0m Hello world! \033[0m"
 Close all attribute
 Hello World! 

 [Commands] echo -e "\033[1m Hello world! \033[0m"
 High Light
 Hello World! 

 [Commands] echo -e "\033[4m Hello world! \033[0m"
 Underline 
 Hello World! 

 [Commands] echo -e "\033[5m Hello world! \033[0m"
 Flash 
 Hello World! 

 [Commands] echo -e "\033[7m Hello world! \033[0m"
 Invert 
 Hello World! 

 [Commands] echo -e "\033[8m Hello world! \033[0m"
 Blanking 
 Hello World! 

 [Commands] echo -e "\033[2A Hello world! \033[0m"
 Shift Up 2

 [Commands] echo -e "\033[2B Hello world! \033[0m"
 Shitf down 2

 [Commands] echo -e "\033[2C Hello world! \033[0m"
 Shift right 2

 [Commands] echo -e "\033[2D Hello world! \033[0m"
 Shitf left 2

 [Commands] echo -e "\033[2:2H Hello world! \033[0m"
 Point specify location 

 [Commands] echo -e "\033[2J Hello world! \033[0m"
 Clear screen 
























 Hello World! 

 [Commands] echo -e "\033[K Hello world! \033[0m"
 Clear from point to end 

 [Commands] echo -e "\033[s Hello world! \033[0m"
 Save surrent posion
 Hello World! 

 [Commands] echo -e "\033[u Hello world! \033[0m"
 Recover posion
 Hello World! 

 [Commands] echo -e "\033[?251 Hello world! \033[0m"
 Hide point
[?251 Hello World! 

 [Commands] echo -e "\033[?25h Hello world! \033[0m"
 Display point
 Hello World! 


