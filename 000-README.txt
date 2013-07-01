
git config --global credential.helper osxkeychain

[ bueller @ PRISM1 :: 000-CRACKING-CODING-INTERVIEW ]$ which git
/opt/local/bin/git
[ bueller @ PRISM1 :: 000-CRACKING-CODING-INTERVIEW ]$ git --version
git version 1.8.2.3
[ bueller @ PRISM1 :: 000-CRACKING-CODING-INTERVIEW ]$ /usr/bin/git
git                 git-cvsserver       git-receive-pack    git-shell           git-upload-archive  git-upload-pack     gitk
[ bueller @ PRISM1 :: 000-CRACKING-CODING-INTERVIEW ]$ /usr/bin/git --version
git version 1.7.12.4 (Apple Git-37)
[ bueller @ PRISM1 :: 000-CRACKING-CODING-INTERVIEW ]$ git credential-osxkeychain
usage: git credential-osxkeychain <get|store|erase>

[..]$ git config --global --list
 user.name=FARIS, BUELLER
 user.email=dfarisphd@gmail.com
 credential.helper=osxkeychain


