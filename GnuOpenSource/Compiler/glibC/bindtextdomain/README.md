   
   char * bindtextdomain (const char *domainname, const char *dirname)
  The bindtextdomain function can be used to specify the directory which contains
the message catalogs for domain domainname for the different languages. To be
correct, this is the directory where the hierarchy of directories is expected. Details
are explained below.
  For the programmer it is important to note that the translations which come with the
program have be placed in a directory hierarchy starting at, say, ‘/foo/bar’. Then
the program should make a bindtextdomain call to bind the domain for the current
program to this directory. So it is made sure the catalogs are found. A correctly
running program does not depend on the user setting an environment variable.
The bindtextdomain function can be used several times and if the domainname
argument is different the previously bound domains will not be overwritten.
  If the program which wish to use bindtextdomain at some point of time use the chdir
function to change the current working directory it is important that the dirname
strings ought to be an absolute pathname. Otherwise the addressed directory might
vary with the time.
  If the dirname parameter is the null pointer bindtextdomain returns the currently
selected directory for the domain with the name domainname.Chapter 8: Message Translation
  The bindtextdomain function returns a pointer to a string containing the name of
the selected directory name. The string is allocated internally in the function and
must not be changed by the user. If the system went out of core during the execution
of bindtextdomain the return value is NULL and the global variable errno is set accordingly.
