# CP3
SER334 Module 3: Create bitmap filters in c


In this assignment you will write a program that applies three different filters 
to an image. The image will be loaded from a BMP file, specified by the user, 
and then be transformed using: 1) a grayscale conversion, 2) a color shift also 
specified by the user, or 3) a scale operation. The resulting file will be saved 
back to a BMP file that can be viewed on the system.

The command line parameters should be entered in the order below.
1: the filter 2: the file you want to load 3: the filename for the output image

To compile from root directory:
gcc src/BMPHandler.c src/Image.c src/PerryImageProcessor.c

To run grayscale:
./a.out -g ./res/test2.bmp test2_output.bmp
./a.out -g ./res/ttt.bmp ttt_output.bmp
./a.out -g ./res/wb.bmp wb_output.bmp

To run color shift:
./a.out -c ./res/test2.bmp test2_output.bmp
./a.out -c ./res/ttt.bmp ttt_output.bmp
./a.out -c ./res/wb.bmp wb_output.bmp
note - prompt will appear in CLI to enter shift values


To run scale:
note - did not finish :(