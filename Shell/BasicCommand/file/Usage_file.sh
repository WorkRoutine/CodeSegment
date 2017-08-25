#!/bin/bash

# ---------------------------------------------
# Basic usage of 'xxx'
# Maintainer: Buddy <buddy.zhang@aliyun.com>
# ---------------------------------------------
if [ -z $1 ]; then
	FILE="Usage_file.sh"
else
	FILE=$1
fi

echo -e "\033[31m file — determine file type \033[0m"
echo -e "\033[34m file [-bcEhiklLNnprsvzZ0] [--apple] [--extension] [--mime-encoding] \033[0m"
echo -e "\033[34m [--mime-type] [-e testname] [-F separator] [-f namefile] \033[0m"
echo -e "\033[34m [-m magicfiles] [-P name=value] file ... \033[0m"
echo -e "\033[34m file -C [-m magicfiles] \033[0m"
echo -e "\033[34m file [--help] \033[0m"
echo ""

echo -e "\033[33m [Argument] \033[0m"
echo -e "\033[32m [Describe] determine file type \033[0m"
echo -e "\033[31m [Commands] file ${FILE} \033[0m"
file ${FILE}
echo ""

echo -e "\033[33m [Argument] [--apple] \033[0m"
echo -e "\033[32m [Describe] Causes the file command to output the file type and creator code\033[0m"
echo -e "\033[32m [Describe] as used by older MacOS versions. The code consists of eight let‐\033[0m"
echo -e "\033[32m [Describe] ters, the first describing the file type, the latter the creator.\033[0m"
echo -e "\033[31m [Commands] file --apple ${FILE}\033[0m"
file --apple ${FILE}
echo ""

echo -e "\033[33m [Argument] [-b, --brief]\033[0m"
echo -e "\033[32m [Describe] Do not prepend filenames to output lines (brief mode).\033[0m"
echo -e "\033[31m [Commands] file -b ${FILE} \033[0m"
file -b ${FILE}
echo -e "\033[31m [Commands] file --brief ${FILE} \033[0m"
file --brief ${FILE}
echo ""

echo -e "\033[33m [Argument] [-C, --compile] \033[0m"
echo -e "\033[32m [Describe] Write a magic.mgc output file that contains a pre-parsed version\033[0m"
echo -e "\033[32m [Describe] of the magic file or directory.\033[0m"
echo -e "\033[31m [Commands] file -C ${FILE} \033[0m"
file -C ${FILE}
echo -e "\033[31m [Commands] file --compile ${FILE} \033[0m"
file --compile ${FILE}
echo ""

echo -e "\033[33m [Argument] [-c, --checking-printout] \033[0m"
echo -e "\033[32m [Describe] Cause a checking printout of the parsed form of the magic file. \033[0m"
echo -e "\033[32m [Describe] This is usually used in conjunction with the -m flag to debug a \033[0m"
echo -e "\033[32m [Describe] new magic file before installing it.\033[0m"
echo -e "\033[31m [Commands] file -m -c ${FILE} \033[0m"
file -m -c ${FILE}
echo -e "\033[31m [Commands] file -m --checking-printout \033[0m"
file -m --checking-printout ${FILE}
echo ""

echo -e "\033[33m [Argument] [-E]\033[0m"
echo -e "\033[32m [Describe] On filesystem errors (file not found etc), instead of handling \033[0m"
echo -e "\033[32m [Describe] the error as regular output as POSIX mandates and keep going,\033[0m"
echo -e "\033[32m [Describe] issue an error message and exit.\033[0m"
echo -e "\033[31m [Commands] file -E ${FILE} \033[0m"
file -E ${FILE}
echo ""

echo -e "\033[33m [Argument] [-e, --exclude testname] \033[0m"
echo -e "\033[32m [Describe] Exclude the test named in testname from the list of tests made to \033[0m"
echo -e "\033[32m [Describe] determine the file type.  Valid test names are:\033[0m"
echo -e "\033[32m [Describe] apptype   EMX application type (only on EMX).\033[0m"
echo -e "\033[31m [Commands] file -e apptype ${FILE}\033[0m"
file -e apptype ${FILE}
echo -e "\033[31m [Commands] file --exclude apptype ${FILE}\033[0m"
file --exclude apptype ${FILE}
echo -e "\033[32m [Describe] ascii     Various types of text files (this test will try to\033[0m"
echo -e "\033[32m [Describe] guess the text encoding, irrespective of the setting of\033[0m"
echo -e "\033[32m [Describe] the ‘encoding’ option).\033[0m"
echo -e "\033[31m [Commands] file -e ascii ${FILE} \033[0m"
file -e ascii ${FILE}
echo -e "\033[31m [Commands] file --exclude ascii ${FILE} \033[0m"
file --exclude ascii ${FILE}
echo -e "\033[32m [Describe] encoding  Different text encodings for soft magic tests.\033[0m"
echo -e "\033[31m [Commands] file -e encoding ${FILE} \033[0m"
file -e encoding ${FILE}
echo -e "\033[31m [Commands] file --exclude encoding ${FILE} \033[0m"
file --exclude encoding ${FILE}
echo -e "\033[32m [Describe] tokens    Ignored for backwards compatibility.\033[0m"
echo -e "\033[31m [Commands] file -e tokens ${FILE}\033[0m"
file -e tokens ${FILE}
echo -e "\033[31m [Commands] file --exclude token ${FILE}  \033[0m"
file --exclude tokens ${FILE}
echo -e "\033[32m [Describe] cdf       Prints details of Compound Document Files.\033[0m"
echo -e "\033[31m [Commands] file -e cdf ${FILE} \033[0m"
file -e cdf ${FILE}
echo -e "\033[31m [Commands] file --exclude cdf ${FILE} \033[0m"
file --exclude cdf ${FILE}
echo -e "\033[32m [Describe] compress  Checks for, and looks inside, compressed files.\033[0m"
echo -e "\033[31m [Commands] file -e compress ${FILE} \033[0m"
file -e compress ${FILE}
echo -e "\033[31m [Commands] file --exclude compress ${FILE} \033[0m"
file --exclude compress ${FILE}
echo -e "\033[32m [Describe] elf       Prints ELF file details.\033[0m"
echo -e "\033[31m [Commands] file -e elf ${FILE} \033[0m"
file -e elf ${FILE}
echo -e "\033[31m [Commands] file --exclude elf ${FILE} \033[0m"
file --exclude elf ${FILE}
echo -e "\033[32m [Describe] soft      Consults magic files.\033[0m"
echo -e "\033[31m [Commands] file -e soft ${FILE} \033[0m"
file -e soft ${FILE}
echo -e "\033[31m [Commands] file --exclude soft ${FILE} \033[0m"
file --exclude soft ${FILE}
echo -e "\033[32m [Describe] tar       Examines tar files.\033[0m"
echo -e "\033[31m [Commands] file -e tar ${FILE} \033[0m"
file -e tar ${FILE}
echo -e "\033[31m [Commands] file --exclude tar ${FILE} \033[0m"
file --exclude tar ${FILE}
echo ""

echo -e "\033[33m [Argument] [--extension]\033[0m"
echo -e "\033[32m [Describe] Print a slash-separated list of valid extensions for the file\033[0m"
echo -e "\033[32m [Describe] type found. \033[0m"
echo -e "\033[31m [Commands] file --extension ${FILE} \033[0m"
file --extension ${FILE}
echo ""

echo -e "\033[33m [Argument] [-F, --separator separator] \033[0m"
echo -e "\033[32m [Describe] Use the specified string as the separator between the filename \033[0m"
echo -e "\033[32m [Describe] and the file result returned.  Defaults to ‘:’. \033[0m"
echo -e "\033[31m [Commands] file -F \"=>\" ${FILE}\033[0m"
file -F "=>" ${FILE}
echo -e "\033[31m [Commands] file --separator \"=>\" ${FILE}\033[0m"
file --separator "=>" ${FILE}
echo ""

echo -e "\033[33m [Argument] [-f, --files-from namefile] \033[0m"
echo -e "\033[32m [Describe] Read the names of the files to be examined from namefile (one per \033[0m"
echo -e "\033[32m [Describe] line) before the argument list.  Either namefile or at least one \033[0m"
echo -e "\033[32m [Describe] filename argument must be present; to test the standard input, \033[0m"
echo -e "\033[32m [Describe] use ‘-’ as a filename argument.  Please note that namefile is\033[0m"
echo -e "\033[32m [Describe] unwrapped and the enclosed filenames are processed when this \033[0m"
echo -e "\033[32m [Describe] option is encountered and before any further options processing \033[0m"
echo -e "\033[32m [Describe] is done.  This allows one to process multiple lists of files with \033[0m"
echo -e "\033[32m [Describe] different command line arguments on the same file invocation. \033[0m"
echo -e "\033[32m [Describe] Thus if you want to set the delimiter, you need to do it before \033[0m"
echo -e "\033[32m [Describe] you specify the list of files, like: “-F @ -f namefile”, instead \033[0m"
echo -e "\033[32m [Describe] of: “-f namefile -F @”. \033[0m"
echo -e "\033[31m [Commands] file -f Current_dirent \033[0m"
ls > .tmp
file -f .tmp
echo -e "\033[31m [Commands] file --files-from Current_dirent \033[0m"
file --files-from .tmp
rm .tmp
echo ""

echo -e "\033[33m [Argument] [-h, --no-dereference]\033[0m"
echo -e "\033[32m [Describe] option causes symlinks not to be followed (on systems that sup‐ \033[0m"
echo -e "\033[32m [Describe] port symbolic links).  This is the default if the environment \033[0m"
echo -e "\033[32m [Describe] variable POSIXLY_CORRECT is not defined. \033[0m"
echo -e "\033[31m [Commands] file -h ${FILE}\033[0m"
file -h ${FILE}
echo -e "\033[31m [Commands] file --no-dereference ${FILE}\033[0m"
file --no-dereference ${FILE}
echo ""

echo -e "\033[33m [Argument] [-i, --mime]\033[0m"
echo -e "\033[32m [Describe] Causes the file command to output mime type strings rather than \033[0m"
echo -e "\033[32m [Describe] the more traditional human readable ones.  Thus it may say\033[0m"
echo -e "\033[32m [Describe] ‘text/plain; charset=us-ascii’ rather than “ASCII text”.\033[0m"
echo -e "\033[31m [Commands] file -i ${FILE} \033[0m"
file -i ${FILE}
echo -e "\033[31m [Commands] file --mime ${FILE} \033[0m"
file --mime ${FILE}
echo ""

echo -e "\033[33m [Argument] [--mime-type, --mime-encoding]  \033[0m"
echo -e "\033[32m [Describe] Like -i, but print only the specified element(s). \033[0m"
echo -e "\033[31m [Commands] file --mime-type ${FILE} \033[0m"
file --mime-type ${FILE}
echo -e "\033[31m [Commands] file --mime-encoding ${FILE} \033[0m"
file --mime-encoding ${FILE}
echo ""

echo -e "\033[33m [Argument] [-k, --keep-going] \033[0m"
echo -e "\033[32m [Describe] Don't stop at the first match, keep going.  Subsequent matches \033[0m"
echo -e "\033[32m [Describe] will be have the string ‘\012- ’ prepended.  (If you want a new‐ \033[0m"
echo -e "\033[32m [Describe] line, see the -r option.)  The magic pattern with the highest \033[0m"
echo -e "\033[32m [Describe] strength (see the -l option) comes first. \033[0m"
echo -e "\033[31m [Commands] file -k ${FILE}\033[0m"
file -k ${FILE}
echo -e "\033[31m [Commands] file --keep-going ${FILE}\033[0m"
file --keep-going ${FILE}
echo ""

echo -e "\033[33m [Argument] [-l, --list] \033[0m"
echo -e "\033[32m [Describe] Shows a list of patterns and their strength sorted descending by \033[0m"
echo -e "\033[32m [Describe] magic(4) strength which is used for the matching (see also the -k \033[0m"
echo -e "\033[32m [Describe] option). \033[0m"
echo -e "\033[31m [Commands] file -l ${FILE}\033[0m"
#file -l ${FILE}
echo -e "\033[31m [Commands] file --list ${FILE}\033[0m"
#file --list ${FILE}
echo ""

echo -e "\033[33m [Argument] [-L, --dereference] \033[0m"
echo -e "\033[32m [Describe] option causes symlinks to be followed, as the like-named option \033[0m"
echo -e "\033[32m [Describe] in ls(1) (on systems that support symbolic links).  This is the \033[0m"
echo -e "\033[32m [Describe] default if the environment variable POSIXLY_CORRECT is defined. \033[0m"
echo -e "\033[31m [Commands] file -L ${FILE} \033[0m"
file -L ${FILE}
echo -e "\033[31m [Commands] file --dereference ${FILE} \033[0m"
file --dereference ${FILE}
echo ""

echo -e "\033[33m [Argument] \033[0m"
echo -e "\033[32m [Describe] \033[0m"
echo -e "\033[31m [Commands] \033[0m"

echo ""

echo -e "\033[33m [Argument] \033[0m"
echo -e "\033[32m [Describe] \033[0m"
echo -e "\033[31m [Commands] \033[0m"

echo ""

echo -e "\033[33m [Argument] \033[0m"
echo -e "\033[32m [Describe] \033[0m"
echo -e "\033[31m [Commands] \033[0m"

echo ""

echo -e "\033[33m [Argument] \033[0m"
echo -e "\033[32m [Describe] \033[0m"
echo -e "\033[31m [Commands] \033[0m"

echo ""

