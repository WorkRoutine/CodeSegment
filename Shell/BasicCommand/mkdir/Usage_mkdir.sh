#!/bin/bash
set -e

# ---------------------------------------------
# Basic usage of 'mkdir'
# Maintainer: Buddy <buddy.zhang@aliyun.com>
# ---------------------------------------------

DIRENT="Hello_WorldA Hello_WorldB Hello_WorldC Hello_WorldD Hello_WorldE Hello_WorldF Hello_WorldG"
if [ -d Hello_WorldA ]; then
    rm -rf $DIRENT
fi

echo -e "\033[31m [Commands] mkdir\033[0m"
echo -e "\033[32m [Describe] mkdir - make directories \033[0m"
echo -e "\033[33m [SYNOPSIS] mkdir [OPTION]... DIRECTORY... \033[0m"

echo "" 

echo -e "\033[33m [Argument] [-m, --mode=MODE] \033[0m"
echo -e "\033[32m [Describe] set file mode (as in chmod), not a=rwx - umask \033[0m"
echo -e "\033[31m [Commands] mkdir -v -m 755 Hello_WorldA \033[0m"
mkdir -v -m 755 Hello_WorldA
echo -e "\033[31m [Commands] mkdir -v --mode= 755 Hello_WorldB \033[0m"
mkdir -v --mode=755 Hello_WorldB
echo "" 

echo -e "\033[33m [Argument] [-p, --parents] \033[0m"
echo -e "\033[32m [Describe] no error if existing, make parent directories as needed \033[0m"
echo -e "\033[31m [Commands] mkdir -v -p Hello_WorldC/A \033[0m"
mkdir -v -p Hello_WorldC/A
echo -e "\033[31m [Commands] mkdir -v --parents Hello_WorldD/A \033[0m"
mkdir -v --parents Hello_WorldD/A
echo "" 

echo -e "\033[33m [Argument] [-v, --verbose] \033[0m"
echo -e "\033[32m [Describe] print a message for each created directory \033[0m"
echo -e "\033[31m [Commands] mkdir -v Hello_WorldE\033[0m"
mkdir -v Hello_WorldE
echo -e "\033[31m [Commands] mkdir --verbose Hello_WorldF\033[0m"
mkdir --verbose Hello_WorldF
echo "" 

echo -e "\033[33m [Argument] [-Z, --context=CTX] \033[0m"
echo -e "\033[32m [Describe] set the SELinux security context of each created directory to CTX\033[0m"
#echo -e "\033[31m [Commands] mkdir -v -Z Hello_WorldG\033[0m"
#mkdir -v -Z Hello_WorldG
#echo -e "\033[31m [Commands] mkdir -v --context=CTX Hello_WorldG\033[0m"
#mkdir -v --context=CTX Hello_WorldG
echo "" 

echo -e "\033[33m [Argument] [--version] \033[0m"
echo -e "\033[32m [Describe] output version information and exit \033[0m"
echo -e "\033[31m [Commands] mkdir --version\033[0m"
mkdir --version
echo "" 
