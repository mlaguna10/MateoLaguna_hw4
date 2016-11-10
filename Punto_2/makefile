animacion.py : datos.dat
	python animacion.py

datos.dat : a.out
	./a.out > datos.dat

a.out : cuerda.c
	gcc cuerda.c -lm 

clean:
	rm -f a.out datos.dat *.png cuerda.gif
