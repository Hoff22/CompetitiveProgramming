# run it like this:
# '. setup.sh'
# this takes out the current directory and changes colors
export PS1='\[\033[0;32m\]\u@\h\[\033[0;36m\]: \[\e[m\]'
alias subl='subl.exe'

if ! [ -e B.cpp ]
then
	echo 'created B.cpp'
	cp A.cpp B.cpp
fi
if ! [ -e C.cpp ]
then
	echo 'created C.cpp'
	cp A.cpp C.cpp
fi
if ! [ -e D.cpp ]
then
	echo 'created D.cpp'
	cp A.cpp D.cpp
fi
subl.exe A.cpp && subl.exe B.cpp && subl.exe C.cpp && subl.exe D.cpp
