all:
	gcc bin_sem.c -c
	gcc File1.c -c
	gcc File2.c -c
	gcc bin_sem.o File1.o -o file1
	gcc bin_sem.o File2.o -o file2


cl_srv:
	gcc client.c -o client
	gcc server.c -o server
