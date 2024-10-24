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
if ! [ -e E.cpp ]
then
	echo 'created E.cpp'
	cp A.cpp E.cpp
fi
if ! [ -e F.cpp ]
then
	echo 'created F.cpp'
	cp A.cpp F.cpp
fi
if ! [ -e G.cpp ]
then
	echo 'created G.cpp'
	cp A.cpp G.cpp
fi
subl.exe A.cpp && subl.exe B.cpp && subl.exe C.cpp && subl.exe D.cpp && subl.exe E.cpp && subl.exe F.cpp && subl.exe G.cpp
