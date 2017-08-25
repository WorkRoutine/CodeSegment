======================= Preview ==========================
1. How to connect git with github.
   -> Creat your project and git,use cmd:
        git init
   -> create filter file of git and add the type name what you want ignore in 
      current dirent.
        vi .gitignore
          -> add line:
                tags
                xx/
   -> Add your modify into git and commit it.
        git add --all
        git commit -m "xxxx"
   -> Sign in your github and select your Organizations.Select "New repository",
      then add your repository name,and finish created.
   -> Add your SSH key,chang your dirent into topdir for current user.
      Create SSH Key:
        cd ~/
        Check if "id_rsa" and "id_rsa.pub" existed,if not use cmd:
        ssh-keygen -t rsa -C "your email"
        And we will get "id_rsa" and "id_rsa.pub" on "~/.ssh/".
      Sign in your github and open "Account settings" and select 
      "SSH and GPG Keys".Then click "New SSH Key",past the "id_rsa.pub" into
      "Key".
   -> Connect the local git to github,we can use cmd:
        git remote add Free_V4L2 git@github.com:LozziStation/Free_V4L2.git
      "Free_V4L2" is name of github repository.
      "git@github.com:LozziStation/Free_V4L2.git" is from github.
      Now you can push your code into gitbub,we can use cmd
        git push Free_V4L2 master
      "Free_V4l2" is github repository and "master" is local repository
   -> Now we can push code when we commit in local.In order to simply push 
      your code,you can add the cmd into your Makefile,like:
        vi Makefile
           -> add line:
              # Update data into github/LozziStation/Free_V4L2
              	  @git push Free_V4L2 master
   -> We can also pull code from gitbub,use cmd:
        git push
      In order to speed your operation,you can add the command into Makefile:
        vi Makefile
           -> add line:
              # Download the data from github/LozziStation/Free_V4L2
                  @git pull Free_V4L2 master
