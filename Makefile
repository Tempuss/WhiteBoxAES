all : _aes 

_aes: aes.o
	#g++ -g -o wbc_ty wb_aes.o
	g++ -g -o wbc_tbox wbc_taes.o
	g++ -g -o tbox_gen tbox_gen.o


aes.o:
	#g++ -g -c -o wb_aes.o wbc_ty.c
	g++ -g -c -o wbc_taes.o wbc_tboxes.c
	g++ -g -c -o tbox_gen.o WBTGenerator.c



clean:

