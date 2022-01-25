/**
* Implementation of several functions to manipulate BMP files.
*
* Completion time: ?
*
* @author Brett Perry, Ruben Acuna
* @version 1.24.22
*/

#include <stdio.h>
#include <stdlib.h>
#include "../hdr/BMPHandler.h"

/**
 * Read BMP header of a BMP file.
 *
 * @param  file: A pointer to the file being read
 * @param  header: Pointer to the destination BMP header
 */
void readBMPHeader(FILE* file, struct BMP_Header* header) {
    fread(&header->signature, sizeof(char) * 2, 1, file);
    fread(&header->size, sizeof(int), 1, file);
    fread(&header->reserved1, sizeof(short), 1, file);
    fread(&header->reserved2, sizeof(short), 1, file);
    fread(&header->offset_pixel_array, sizeof(int), 1, file);

    //display contents
}

/**
 * Write BMP header of a header. Useful for creating a BMP header.
 *
 * @param  header: A pointer to the header being written
 * @param  header: The header to write to the header
 */
void writeBMPHeader(FILE* file, struct BMP_Header* header) {
    fwrite(&header->signature, sizeof(char) * 2, 1, file);
    fwrite(&header->size, sizeof(int), 1, file);
    fwrite(&header->reserved1, sizeof(short), 1, file);
    fwrite(&header->reserved2, sizeof(short), 1, file);
    fwrite(&header->offset_pixel_array, sizeof(int), 1, file);
}

/**
 * Read DIB header from a BMP file.
 *
 * @param  file: A pointer to the file being read
 * @param  header: Pointer to the destination DIB header
 */
void readDIBHeader(FILE* file, struct DIB_Header* header) {
    fread(&header->dib_size, sizeof(int), 1, file);
    fread(&header->image_width, sizeof(int), 1, file);
    fread(&header->image_height, sizeof(int), 1, file);
    fread(&header->planes, sizeof(char) * 2, 1, file);
    fread(&header->bits_per_pxl, sizeof(char) * 2, 1, file);
    fread(&header->compression, sizeof(int), 1, file);
    fread(&header->image_size, sizeof(int), 1, file);
    fread(&header->x_pxl_per_m, sizeof(int), 1, file);
    fread(&header->y_pxl_per_m, sizeof(int), 1, file);
    fread(&header->color_table, sizeof(int), 1, file);
    fread(&header->imp_color_count, sizeof(int), 1, file);
}

/**
 * Write DIB header of a file. Useful for creating a BMP file.
 *
 * @param  file: A pointer to the file being written
 * @param  header: The header to write to the file
 */
void writeDIBHeader(FILE* file, struct DIB_Header* header) {
    fwrite(&header->dib_size, sizeof(int), 1, file);
    fwrite(&header->image_width, sizeof(int), 1, file);
    fwrite(&header->image_height, sizeof(int), 1, file);
    fwrite(&header->planes, sizeof(char) * 2, 1, file);
    fwrite(&header->bits_per_pxl, sizeof(char) * 2, 1, file);
    fwrite(&header->compression, sizeof(int), 1, file);
    fwrite(&header->image_size, sizeof(int), 1, file);
    fwrite(&header->x_pxl_per_m, sizeof(int), 1, file);
    fwrite(&header->y_pxl_per_m, sizeof(int), 1, file);
    fwrite(&header->color_table, sizeof(int), 1, file);
    fwrite(&header->imp_color_count, sizeof(int), 1, file);
}

/**
 * Make BMP header based on width and height. Useful for creating a BMP file.
 *
 * @param  header: Pointer to the destination DIB header
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void makeBMPHeader(struct BMP_Header* header, int width, int height) {

}

/**
* Make new DIB header based on width and height.Useful for creating a BMP file.
*
* @param  header: Pointer to the destination DIB header
* @param  width: Width of the image that this header is for
* @param  height: Height of the image that this header is for
*/
void makeDIBHeader(struct DIB_Header* header, int width, int height) {

}

/**
 * Read Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read
 * @param  pArr: Pixel array to store the pixels being read
 * @param  width: Width of the pixel array of this image
 * @param  height: Height of the pixel array of this image
 */
void readPixelsBMP(FILE* file, struct Pixel** pArr, int width, int height) {
    int padding;
    int x, y;
    padding = 4 - (3*width) % 4;

    //iterate scanlines
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            fread(&pArr[y][x].pBlue, sizeof(unsigned char), 1, file);
            fread(&pArr[y][x].pGreen, sizeof(unsigned char), 1, file);
            fread(&pArr[y][x].pRed, sizeof(unsigned char), 1, file);
        }

        // skip padding
        fseek(file, padding, SEEK_CUR);
    }
}

/**
 * Write Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image to write to the file
 * @param  width: Width of the pixel array of this image
 * @param  height: Height of the pixel array of this image
 */
void writePixelsBMP(FILE* file, struct Pixel** pArr, int width, int height) {
    int padding;
    int x, y, p;

    padding = 4 - (3 * width) % 4;
    printf("%d", padding);

    //iterate scanlines
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            fwrite(&pArr[y][x].pBlue, sizeof(unsigned char), 1, file);
            fwrite(&pArr[y][x].pGreen, sizeof(unsigned char), 1, file);
            fwrite(&pArr[y][x].pRed, sizeof(unsigned char), 1, file);
        }

        // skip padding write for loop to add chars

        for (p = 0; p < padding; p++) {
            fwrite(" ", sizeof(unsigned char), 1, file);
        }
    }
}

