#!/bin/bash
set -e

# ---------------------------------------------
# Basic usage of 'echo'
# Maintainer: Buddy <buddy.zhang@aliyun.com>
# ---------------------------------------------

echo -e "\033[31m echo - display a line of text \033[0m"
echo -e "\033[34m echo [SHORT-OPTION]... [STRING]... \033[0m"
echo ""

echo -e "\033[31m [Commands] echo \"Hello World\" \033[0m"
echo -e "\033[32m [Describe] Echo the STRING(s) to standard output\033[0m"
echo " Hello World!"
echo "" 

echo -e "\033[31m [Commands] echo -n \"Hello World\"\033[0m"
echo -e "\033[32m [Describe] do not output the trailing newline\033[0m"
echo -n " Hello World!"
echo "" 

echo -e "\033[31m [Commands] echo -e \"Hello\\ World!\"\033[0m"
echo -e "\033[32m [Describe] \033[0m"
echo -e " Hello World!"
echo "" 

echo -e "\033[31m [Commands] echo -E \"Hello\\ World!\"\033[0m"
echo -e "\033[32m [Describe] disable interpretation of backslash escapes (default)\033[0m"
echo -E " Hello\\ World!"
echo "" 

echo -e "\033[31m [Commands] echo --version\033[0m"
echo -e "\033[32m [Describe] output version information and exit\033[0m"
echo " --version"
echo "" 

echo -e "\033[31m If -e is in effect, the following sequences are recognized: \033[0m"

echo -e "\033[31m [Commands] echo -e \"Hello\\ \\ World!\"\033[0m"
echo -e "\033[32m [Describe] backslash\033[0m"
echo -e " Hello\\world!"
echo "" 

echo -e "\033[31m [Commands] echo -e \"Hello\\\a World\"\033[0m"
echo -e "\033[32m [Describe] alert (BEL)\033[0m"
echo -e " Hello\a World"
echo "" 

echo -e "\033[31m [Commands] echo -e \"Hello\\\b World!\"\033[0m"
echo -e "\033[32m [Describe] backspace\033[0m"
echo -e " Hello\b World!"
echo "" 

echo -e "\033[31m [Commands] echo -e \"Hello\\\c World!\"\033[0m"
echo -e "\033[32m [Describe] produce no further output\033[0m"
echo -e " Hello\c World!"
echo "" 

echo -e "\033[31m [Commands] echo -e \"Hello\\\e World!\"\033[0m"
echo -e "\033[32m [Describe] escape\033[0m"
echo -e " Hello\e World!"
echo "" 

echo -e "\033[31m [Commands] echo -e \"Hello\\\f World!\"\033[0m"
echo -e "\033[32m [Describe] form feed\033[0m"
echo -e " Hello\f World!"
echo "" 

echo -e "\033[31m [Commands] echo -e \"Hello\\\n World!\"\033[0m"
echo -e "\033[32m [Describe] new line\033[0m"
echo -e " Hello\n World!"
echo "" 

echo -e "\033[31m [Commands] echo -e \"Hello\\\r World!\"\033[0m"
echo -e "\033[32m [Describe] carriage return\033[0m"
echo -e " Hello\r World!"
echo "" 

echo -e "\033[31m [Commands] echo -e \"Hello\\\t World!\"\033[0m"
echo -e "\033[32m [Describe] horizontal tab\033[0m"
echo -e " Hello\t World!"
echo "" 

echo -e "\033[31m [Commands] echo -e \"Hello\\\v World!\"\033[0m"
echo -e "\033[32m [Describe] vertical tab\033[0m"
echo -e " Hello\v World!"
echo "" 

echo -e "\033[31m [Commands] echo -e \"Hello \\\063!\"\033[0m"
echo -e "\033[32m [Describe] byte with octal value NNN\033[0m"
echo -e " Hello \063"
echo "" 

echo -e "\033[31m [Commands] echo -e \"Hello \\\x63!\"\033[0m"
echo -e "\033[32m [Describe] byte with hexadecimal value HH\033[0m"
echo -e " Hello \x63"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[30m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Color Black\033[0m"
echo -e "\033[30m Hello World!\033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[31m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Color Red\033[0m"
echo -e "\033[31m Hello World!\033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[32m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Color Green\033[0m"
echo -e "\033[32m Hello World!\033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[33m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Color Yellow\033[0m"
echo -e "\033[33m Hello World!\033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[34m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Color Blue\033[0m"
echo -e "\033[34m Hello World!\033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[35m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Color Purple\033[0m"
echo -e "\033[35m Hello World!\033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[36m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Color Sky Blue\033[0m"
echo -e "\033[36m Hello World!\033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[37m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Color White\033[0m"
echo -e "\033[37m Hello World!\033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[40m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m BackColor Black\033[0m"
echo -e "\033[40m Hello World!\033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[41m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m BackColor Red\033[0m"
echo -e "\033[41m Hello World!\033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[42m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m BackColor Green\033[0m"
echo -e "\033[42m Hello World!\033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[43m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m BackColor Yellow\033[0m"
echo -e "\033[43m Hello World!\033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[44m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m BackColor Blue\033[0m"
echo -e "\033[44m Hello World!\033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[45m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m BackColor Purple\033[0m"
echo -e "\033[46m Hello World!\033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[46m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m BackColor SkyBlue\033[0m"
echo -e "\033[46m Hello World!\033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[47m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m BackColor White\033[0m"
echo -e "\033[47m Hello World!\033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[0m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Close all attribute\033[0m"
echo -e "\033[0m Hello World! \033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[1m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m High Light\033[0m"
echo -e "\033[1m Hello World! \033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[4m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Underline \033[0m"
echo -e "\033[4m Hello World! \033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[5m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Flash \033[0m"
echo -e "\033[5m Hello World! \033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[7m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Invert \033[0m"
echo -e "\033[7m Hello World! \033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[8m Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Blanking \033[0m"
echo -e "\033[8m Hello World! \033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[2A Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Shift Up 2\033[0m"
# echo -e "\033[2A Hello World! \033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[2B Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Shitf down 2\033[0m"
# echo -e "\033[2B Hello World! \033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[2C Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Shift right 2\033[0m"
# echo -e "\033[2C Hello World! \033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[2D Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Shitf left 2\033[0m"
# echo -e "\033[2D Hello World! \033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[2:2H Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Point specify location \033[0m"
# echo -e "\033[2:2H Hello World! \033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[2J Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Clear screen \033[0m"
echo -e "\033[2J Hello World! \033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[K Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Clear from point to end \033[0m"
# echo -e "\033[K Hello World! \033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[s Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Save surrent posion\033[0m"
echo -e "\033[s Hello World! \033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[u Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Recover posion\033[0m"
echo -e "\033[u Hello World! \033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[?251 Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Hide point\033[0m"
echo -e "\033[?251 Hello World! \033[0m"
echo "" 

echo -e "\033[31m [Commands] echo -e \"\\\033[?25h Hello world! \\\033[0m\"\033[0m"
echo -e "\033[32m Display point\033[0m"
echo -e "\033[?25h Hello World! \033[0m"
echo "" 

