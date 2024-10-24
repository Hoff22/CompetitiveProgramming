make f=Kbrute	|| exit 1
make f=K 	|| exit 1
make f=gen	|| exit 1
for ((i = 1; ; i++)) do
	./gen $i > tour.in
	./K > out
	./Kbrute > out2
	if (! cmp -s out out2) then
		echo "--> entrada:"
		cat tour.in
		echo "--> saida1:"
		cat out
		echo "--> saida2:"
		cat out2
		break;
	fi
	echo $i
done