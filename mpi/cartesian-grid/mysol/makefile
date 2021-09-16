# Makefile

MPICC = mpicc
MPIF90 = mpiifort

MPICFLAGS 	= -O3 
MPIFFLAGS 	= -O3

mysol:
	$(MPICC) $(MPICFLAGS) mysol.c -o mysol $(MPILIBS) -lm

clean:
	rm -f *.o