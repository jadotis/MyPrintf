myprint: clean
	gcc -ggdb -m32 -c itoa.c -o itoa.o
	gcc -ggdb -m32 -c my_printf.c -o my_printf.o
	ar rcs PrintLib.a itoa.o my_printf.o
	gcc -ggdb -m32  run.c PrintLib.a -o run

clean:
	rm itoa.o || true
	rm my_printf.o || true
	rm PrintLib.a || true
	rm run || true
