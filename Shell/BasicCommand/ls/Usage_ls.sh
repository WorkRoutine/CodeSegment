#!/bin/bash
set -e

# ---------------------------------------------
# Basic usage of 'ls'
# Maintainer: Buddy <buddy.zhang@aliyun.com>
# ---------------------------------------------

echo -e "\033[31m [Commands] ls\033[0m"
echo -e "\033[32m [Describe] ls - list directory contents\033[0m"
echo -e "\033[32m [SYNOPSIS] ls [OPTION]... [FILE]... \033[0m"

echo "" 

echo -e "\033[32m [Describe] list directory contents\033[0m"
echo -e "\033[31m [Commands] ls\033[0m"
ls
echo "" 

echo -e "\033[32m [Describe] do not ignore entries starting with . \033[0m"
echo -e "\033[31m [Commands] ls -a\033[0m"
ls -a
echo -e "\033[31m [Commands] ls --all \033[0m"
ls --all
echo "" 

echo -e "\033[32m [Describe] do not list implied . and .. \033[0m"
echo -e "\033[31m [Commands] ls -A \033[0m"
ls -A
echo -e "\033[31m [Commands] ls --almost-all \033[0m"
ls --almost-all
echo "" 

echo -e "\033[32m [Describe] with -l, print the author of each file \033[0m"
echo -e "\033[31m [Commands] ls --author -l\033[0m"
ls --author -l
echo "" 

echo -e "\033[32m [Describe] print C-style escapes for nongraphic characters \033[0m"
echo -e "\033[31m [Commands] ls -b\033[0m"
ls -b
echo -e "\033[31m [Commands] ls --escape \033[0m"
ls --escape
echo "" 

echo -e "\033[32m [Describe] scale sizes by SIZE before printing them. E.g.,\033[0m"
echo -e "\033[32m [Describe] '--block-size=M'  prints sizes in units of 1,048,576 bytes. \033[0m"
echo -e "\033[31m [Commands] ls -l --block-size=M \033[0m"
ls -l --block-size=M
echo -e "\033[31m [Commands] ls -l --block-size=K \033[0m"
ls -l --block-size=K
echo -e "\033[31m [Commands] ls -l --block-size=G \033[0m"
ls -l --block-size=G
echo -e "\033[31m [Commands] ls -l --block-size=512 \033[0m"
ls -l --block-size=512
echo -e "\033[31m [Commands] ls -l --block-size=4K \033[0m"
ls -l --block-size=4K
echo "" 

echo -e "\033[32m [Describe] do not list implied entries ending with ~ \033[0m"
echo -e "\033[31m [Commands] ls -B \033[0m"
ls -B 
echo -e "\033[31m [Commands] ls --ignore-backups \033[0m"
ls --ignore-backups
echo "" 

echo -e "\033[32m [Describe] with -lt: sort by, and show, ctime (time of last modification of \033[0m"
echo -e "\033[32m [Describe] file  status  information)  with -l: show ctime and sort by name \033[0m"
echo -e "\033[32m [Describe] otherwise: sort by ctime, newest first \033[0m"
echo -e "\033[31m [Commands] ls -c -lt\033[0m"
ls -c -lt
echo "" 

echo -e "\033[32m [Describe] list entries by columns \033[0m"
echo -e "\033[31m [Commands] ls -C \033[0m"
ls -C
echo "" 

echo -e "\033[32m [Describe] colorize the output. WHEN defaults to 'always' or can be 'never' or 'auto'. More info below\033[0m"
echo -e "\033[31m [Commands] ls --color=always \033[0m"
ls --color=always
echo -e "\033[31m [Commands] ls --color=never \033[0m"
ls --color=never
echo -e "\033[31m [Commands] ls --color=auto \033[0m"
ls --color=auto
echo "" 

echo -e "\033[32m [Describe] list  directory entries instead of contents, and do not dereferent symbolic links\033[0m"
echo -e "\033[31m [Commands] ls -d\033[0m"
ls -d
echo -e "\033[31m [Commands] ls --directory \033[0m"
ls --directory
echo "" 
echo -e "\033[32m [Describe] generate output designed for Emacs' dired mode \033[0m"
echo -e "\033[31m [Commands] ls -D \033[0m"
ls -D
echo -e "\033[31m [Commands] ls -dired \033[0m"
ls --dired
echo "" 

echo -e "\033[32m [Describe] do not sort, enable -aU, disable -ls --color \033[0m"
echo -e "\033[31m [Commands] ls -f \033[0m"
ls -f
echo "" 

echo -e "\033[32m [Describe] append indicator (one of */=>@|) to entries \033[0m"
echo -e "\033[31m [Commands] ls -F\033[0m"
ls -F
echo -e "\033[31m [Commands] ls --classify\033[0m"
ls --classify
echo "" 

echo -e "\033[32m [Describe] likewise, except do not append '*'\033[0m"
echo -e "\033[31m [Commands] ls --file-type \033[0m"
ls --file-type
echo "" 


echo -e "\033[32m [Describe] across -x, commas -m, horizontal -x, long -l, single-column  -1, verbose -l, vertical -C\033[0m"
echo -e "\033[31m [Commands] ls --format=verbose\033[0m"
ls --format=verbose
echo -e "\033[31m [Commands] ls --format=long\033[0m"
ls --format=long
echo -e "\033[31m [Commands] ls --format=horizontal\033[0m"
ls --format=horizontal
echo -e "\033[31m [Commands] ls --format=across\033[0m"
ls --format=across
echo -e "\033[31m [Commands] ls --format=commas\033[0m"
ls --format=commas
echo -e "\033[31m [Commands] ls --format=vertical\033[0m"
ls --format=vertical
echo "" 

echo -e "\033[32m [Describe] like -l --time-style=full-iso\033[0m"
echo -e "\033[31m [Commands] ls --full-time \033[0m"
ls --full-time
echo "" 

echo -e "\033[32m [Describe] like -l, but do not list owner \033[0m"
echo -e "\033[31m [Commands] ls -g\033[0m"
ls -g
echo "" 

echo -e "\033[32m [Describe] group directories before files \033[0m"
echo -e "\033[31m [Commands] ls --group-directories-first \033[0m"
ls --group-directories-first
echo "" 

echo -e "\033[32m [Describe] in a long listing, don't print group names \033[0m"
echo -e "\033[31m [Commands] ls -G \033[0m"
ls -G
echo -e "\033[31m [Commands] ls --no-group \033[0m"
ls --no-group
echo "" 

echo -e "\033[32m [Describe] with -l, print sizes in human readable format (e.g., 1K 234M 2G) \033[0m"
echo -e "\033[31m [Commands] ls -l -h\033[0m"
ls -lh
echo -e "\033[31m [Commands] ls -l --human-readable \033[0m"
ls -l --human-readable
echo "" 

echo -e "\033[32m [Describe] likewise, but use powers of 1000 not 1024 \033[0m"
echo -e "\033[31m [Commands] ls --si -l\033[0m"
ls --si -l
echo "" 

echo -e "\033[32m [Describe] follow symbolic links listed on the command line \033[0m"
echo -e "\033[31m [Commands] ls -H\033[0m"
ls -H
echo -e "\033[31m [Commands] ls --dereference-command-line \033[0m"
ls --dereference-command-line
echo "" 

echo -e "\033[32m [Describe] follow each command line symbolic link that points to  a  directory \033[0m"
echo -e "\033[31m [Commands] ls --dereference-command-line-symlink-to-dir \033[0m"
ls --dereference-command-line-symlink-to-dir
echo "" 

echo -e "\033[33m [Parament] [--hide=PATTERN]\033[0m"
echo -e "\033[32m [Describe] do  not  list implied entries matching shell PATTERN\033[0m"
echo -e "\033[31m [Commands] ls --hide="U*"  \033[0m"
ls --hide="U*"
echo "" 

echo -e "\033[33m [Parament] [--indicator-style=WORD]\033[0m"
echo -e "\033[32m [Describe] append indicator with style WORD to entry names: none (default), slash (-p), file-type (--file-type), classify (-F) \033[0m"
echo -e "\033[31m [Commands] ls --indicator-style=none\033[0m"
ls --indicator-style=none
echo -e "\033[31m [Commands] ls --indicator-style=slash\033[0m"
ls --indicator-style=slash
echo -e "\033[31m [Commands] ls --indicator-style=file-type\033[0m"
ls --indicator-style=file-type
echo -e "\033[31m [Commands] ls --indicator-style=classify\033[0m"
ls --indicator-style=classify
echo "" 

echo -e "\033[33m [Parament] [-i, --inode]\033[0m"
echo -e "\033[32m [Describe] print the index number of each file\033[0m"
echo -e "\033[31m [Commands] ls -i\033[0m"
ls -i
echo -e "\033[31m [Commands] ls --inode \033[0m"
ls --inode
echo "" 

echo -e "\033[33m [Parament] [-I, --ignore=PATTERN]\033[0m"
echo -e "\033[32m [Describe] do not list implied entries matching shell PATTERN\033[0m"
echo -e "\033[31m [Commands] ls -I".*"\033[0m"
ls -I".*"
echo -e "\033[31m [Commands] ls --ignore=".*"\033[0m"
ls --ignore=".*"
echo "" 

echo -e "\033[33m [Parament] [-k, --kibibytes]\033[0m"
echo -e "\033[32m [Describe] use 1024-byte blocks\033[0m"
echo -e "\033[31m [Commands] ls -k -l\033[0m"
ls -k 
echo -e "\033[31m [Commands] ls -l --kibibytes\033[0m"
ls --kibibytes 
echo "" 

echo -e "\033[33m [Parament] [-l]\033[0m"
echo -e "\033[32m [Describe] use a long listing format \033[0m"
echo -e "\033[31m [Commands] ls -l\033[0m"
ls -l
echo "" 

echo -e "\033[33m [Parament] [-L, --dereference]\033[0m"
echo -e "\033[32m [Describe] when showing file information for a symbolic link, show informa‐\033[0m"
echo -e "\033[32m [Describe] tion for the file the link references rather than for  the  link itself\033[0m"
echo -e "\033[31m [Commands] ls -L\033[0m"
ls -L
echo -e "\033[31m [Commands] ls --dereference\033[0m"
ls --dereference
echo "" 

echo -e "\033[33m [Parament] [-m]\033[0m"
echo -e "\033[32m [Describe] fill width with a comma separated list of entries\033[0m"
echo -e "\033[31m [Commands] ls -m\033[0m"
ls -m
echo "" 

echo -e "\033[33m [Parament] [-n, --numeric-uid-gid]\033[0m"
echo -e "\033[32m [Describe] like -l, but list numeric user and group IDs\033[0m"
echo -e "\033[31m [Commands] ls -n\033[0m"
ls -n
echo -e "\033[31m [Commands] ls --numeric-uid-gid\033[0m"
ls --numeric-uid-gid
echo "" 

echo -e "\033[33m [Parament] [-N, --literal]\033[0m"
echo -e "\033[32m [Describe] print  raw entry names (don't treat e.g. control characters specially\033[0m"
echo -e "\033[31m [Commands] ls -N\033[0m"
ls -N
echo -e "\033[31m [Commands] ls --literal\033[0m"
ls --literal
echo "" 

echo -e "\033[33m [Parament] [-o]\033[0m"
echo -e "\033[32m [Describe] like -l, but do not list group information\033[0m"
echo -e "\033[31m [Commands] ls -o\033[0m"
ls -o
echo "" 

echo -e "\033[33m [Parament] [-p, --indicator-style=slash]\033[0m"
echo -e "\033[32m [Describe] append / indicator to directories\033[0m"
echo -e "\033[31m [Commands] ls -p\033[0m"
ls -p
echo -e "\033[31m [Commands] ls --indicator-style=slash\033[0m"
ls --indicator-style=slash
echo "" 

echo -e "\033[33m [Parament] [-q, --hide-control-chars]\033[0m"
echo -e "\033[32m [Describe] print ? instead of non graphic characters\033[0m"
echo -e "\033[31m [Commands] ls -q\033[0m"
ls -q
echo -e "\033[31m [Commands] ls --hide-control-chars\033[0m"
ls --hide-control-chars
echo "" 

echo -e "\033[33m [Parament] [--show-control-chars]\033[0m"
echo -e "\033[32m [Describe] show non graphic characters as-is (default unless\033[0m"
echo -e "\033[32m [Describe] program is 'ls' and output is a terminal\033[0m"
echo -e "\033[31m [Commands] ls --show-control-chars\033[0m"
ls --show-control-chars
echo "" 

echo -e "\033[33m [Parament] [-Q, --quote-name]\033[0m"
echo -e "\033[32m [Describe] enclose entry names in double quotes\033[0m"
echo -e "\033[31m [Commands] ls -Q\033[0m"
ls -Q
echo -e "\033[31m [Commands] ls --quote-name\033[0m"
ls --quote-name
echo "" 

echo -e "\033[33m [Parament] [--quoting-style=WORD]\033[0m"
echo -e "\033[32m [Describe] use  quoting style WORD for entry names: literal, locale, shell,\033[0m"
echo -e "\033[32m [Describe] shell-always, c, escape\033[0m"
echo -e "\033[31m [Commands] ls --quoting-style=literal\033[0m"
ls --quoting-style=literal
echo -e "\033[31m [Commands] ls --quoting-style=locale\033[0m"
ls --quoting-style=locale
echo -e "\033[31m [Commands] ls --quoting-style=shell\033[0m"
ls --quoting-style=shell
echo -e "\033[31m [Commands] ls --quoting-style=shell-always\033[0m"
ls --quoting-style=shell-always
echo -e "\033[31m [Commands] ls --quoting-style=c\033[0m"
ls --quoting-style=c
echo -e "\033[31m [Commands] ls --quoting-style=escape\033[0m"
ls --quoting-style=escape
echo "" 

echo -e "\033[33m [Parament] [-r, --reverse]\033[0m"
echo -e "\033[32m [Describe] reverse order while sorting\033[0m"
echo -e "\033[31m [Commands] ls -r\033[0m"
ls -r
echo -e "\033[31m [Commands] ls --reverse\033[0m"
ls --reverse
echo "" 

echo -e "\033[33m [Parament] [-R, --recursive]\033[0m"
echo -e "\033[32m [Describe] list subdirectories recursively\033[0m"
echo -e "\033[31m [Commands] ls -R\033[0m"
ls -R
echo -e "\033[31m [Commands] ls --recursive\033[0m"
ls --recursive
echo "" 

echo -e "\033[33m [Parament] [-s, --size]\033[0m"
echo -e "\033[32m [Describe] print the allocated size of each file, in blocks\033[0m"
echo -e "\033[31m [Commands] ls -s\033[0m"
ls -s
echo -e "\033[31m [Commands] ls --size\033[0m"
ls --size
echo "" 

echo -e "\033[33m [Parament] [-S]\033[0m"
echo -e "\033[32m [Describe] sort by file size\033[0m"
echo -e "\033[31m [Commands] ls -S\033[0m"
ls -S
echo "" 

echo -e "\033[33m [Parament] [--sort=WORD]\033[0m"
echo -e "\033[32m [Describe] sort by WORD instead of name: none -U, extension  -X,  size  -S,\033[0m"
echo -e "\033[32m [Describe] time -t, version -v\033[0m"
echo -e "\033[31m [Commands] ls --sort=none\033[0m"
ls --sort=none
echo -e "\033[31m [Commands] ls --sort=extension\033[0m"
ls --sort=extension
echo -e "\033[31m [Commands] ls --sort=size\033[0m"
ls --sort=size
echo -e "\033[31m [Commands] ls --sort=time\033[0m"
ls --sort=time
echo -e "\033[31m [Commands] ls --sort=version\033[0m"
ls --sort=version
echo "" 

echo -e "\033[33m [Parament] [--time=WORD]\033[0m"
echo -e "\033[32m [Describe] with  -l,  show time as WORD instead of modification time: atime \033[0m"
echo -e "\033[32m [Describe] -u, access -u, use -u, ctime -c, or  status  -c;  use  specified \033[0m"
echo -e "\033[32m [Describe] time as sort key if --sort=time \033[0m"
echo -e "\033[31m [Commands] ls -l --time=atime \033[0m"
ls -l --time=atime
echo -e "\033[31m [Commands] ls -l --time=access \033[0m"
ls -l --time=access
echo -e "\033[31m [Commands] ls -l --time=use \033[0m"
ls -l --time=use
echo -e "\033[31m [Commands] ls -l --time=ctime \033[0m"
ls -l --time=ctime
echo -e "\033[31m [Commands] ls -l --time=status \033[0m"
ls -l --time=status
echo "" 

echo -e "\033[33m [Parament] [--time-style=STYLE]\033[0m"
echo -e "\033[32m [Describe] with  -l, show times using style STYLE: full-iso, long-iso, iso, \033[0m"
echo -e "\033[32m [Describe] locale, +FORMAT.  FORMAT is interpreted like 'date';  if  FORMAT \033[0m"
echo -e "\033[32m [Describe] is  FORMAT1<newline>FORMAT2, FORMAT1 applies to non-recent files \033[0m"
echo -e "\033[32m [Describe] and FORMAT2 to recent files; if STYLE is prefixed with 'posix-', \033[0m"
echo -e "\033[32m [Describe] STYLE takes effect only outside the POSIX locale \033[0m"
echo -e "\033[31m [Commands] ls -l --time-style=full-iso \033[0m"
ls -l --time-style=full-iso
echo -e "\033[31m [Commands] ls -l --time-style=long-iso \033[0m"
ls -l --time-style=long-iso
echo -e "\033[31m [Commands] ls -l --time-style=iso \033[0m"
ls -l --time-style=iso
echo -e "\033[31m [Commands] ls -l --time-style=locale \033[0m"
ls -l --time-style=locale
echo -e "\033[31m [Commands] ls -l --time-style=+20 \033[0m"
ls -l --time-style=+20
echo "" 

echo -e "\033[33m [Parament] [-t]\033[0m"
echo -e "\033[32m [Describe] sort by modification time, newest first \033[0m"
echo -e "\033[31m [Commands] ls -t\033[0m"
ls -t
echo "" 

echo -e "\033[33m [Parament] [-T, --tabsize=COLS]\033[0m"
echo -e "\033[32m [Describe] assume tab stops at each COLS instead of 8 \033[0m"
echo -e "\033[31m [Commands] ls -T 4 \033[0m"
ls -T 4
echo -e "\033[31m [Commands] ls --tabsize=8  \033[0m"
ls --tabsize=8
echo "" 

echo -e "\033[33m [Parament] [-u]\033[0m"
echo -e "\033[32m [Describe] with  -lt:  sort  by, and show, access time with -l: show access \033[0m"
echo -e "\033[32m [Describe] time and sort by name otherwise: sort by access time \033[0m"
echo -e "\033[31m [Commands] ls -lt -u \033[0m"
ls -u -lt
echo "" 

echo -e "\033[33m [Parament] [-U]\033[0m"
echo -e "\033[32m [Describe] do not sort; list entries in directory order \033[0m"
echo -e "\033[31m [Commands] ls -U \033[0m"
ls -U
echo "" 

echo -e "\033[33m [Parament] [-v]\033[0m"
echo -e "\033[32m [Describe] natural sort of (version) numbers within text\033[0m"
echo -e "\033[31m [Commands] ls -v \033[0m"
ls -v
echo "" 

echo -e "\033[33m [Parament] [-w, --width=COLS]\033[0m"
echo -e "\033[32m [Describe] assume screen width instead of current value \033[0m"
echo -e "\033[31m [Commands] ls -w 3 \033[0m"
ls -l -w 3
echo -e "\033[31m [Commands] ls --width=3 \033[0m"
ls -l --width=3
echo "" 

echo -e "\033[33m [Parament] [-x]\033[0m"
echo -e "\033[32m [Describe] list entries by lines instead of by columns \033[0m"
echo -e "\033[31m [Commands] ls -x \033[0m"
ls -x
echo "" 

echo -e "\033[33m [Parament] [-X]\033[0m"
echo -e "\033[32m [Describe] sort alphabetically by entry extension \033[0m"
echo -e "\033[31m [Commands] ls -X \033[0m"
ls -X
echo "" 

echo -e "\033[33m [Parament] [-Z, --context]\033[0m"
echo -e "\033[32m [Describe] print any SELinux security context of each file \033[0m"
echo -e "\033[31m [Commands] ls -Z\033[0m"
ls -Z
echo -e "\033[31m [Commands] ls --context \033[0m"
ls --context
echo "" 

echo -e "\033[33m [Parament] [-1]\033[0m"
echo -e "\033[32m [Describe] list one file per line\033[0m"
echo -e "\033[31m [Commands] ls -1\033[0m"
ls -1
echo "" 

echo -e "\033[33m [Parament] [--version]\033[0m"
echo -e "\033[32m [Describe] output version information and exit \033[0m"
echo -e "\033[31m [Commands] ls --version \033[0m"
ls --version
echo "" 
