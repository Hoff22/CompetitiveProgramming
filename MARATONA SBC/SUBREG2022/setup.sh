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
if ! [ -e G.cpp ]
then
	echo 'created G.cpp'
	cp A.cpp G.cpp
fi
if ! [ -e K.cpp ]
then
	echo 'created K.cpp'
	cp A.cpp K.cpp
fi
if ! [ -e L.cpp ]
then
	echo 'created G.cpp'
	cp A.cpp L.cpp
fi
if ! [ -e M.cpp ]
then
	echo 'created G.cpp'
	cp A.cpp M.cpp
fi
if ! [ -e N.cpp ]
then
	echo 'created G.cpp'
	cp A.cpp N.cpp
fi