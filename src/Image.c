//
// Created by Brett Perry on 1/20/22.
//
#include <stdio.h>
#include <stdlib.h>
#include "../hdr/Image.h"



/* Creates a new image and returns it.
*
 * @param  pArr: Pixel array of this image.
 * @param  width: Width of this image.
 * @param  height: Height of this image.
 * @return A pointer to a new image.
*/
Image* image_create(struct Pixel** pArr, int width, int height) {
    pArr = (struct Pixel**) malloc(sizeof(struct Pixel*) * width);
    return (Image *) pArr;
}


/* Destroys an image. Does not deallocate internal pixel array.
*
 * @param  img: the image to destroy.
*/
void image_destroy(Image** img) {
    free(img);
}

/* Returns a double pointer to the pixel array.
*
 * @param  img: the image.
*/
struct Pixel** image_get_pixels(Image* img) {
    return img->pArr;
}

/* Returns the width of the image.
*
 * @param  img: the image.
*/
int image_get_width(Image* img) {
    return img->width;
}

/* Returns the height of the image.
*
 * @param  img: the image.
*/
int image_get_height(Image* img) {
    return img->height;
}

/* Converts the image to grayscale.
*
 * @param  img: the image.
*/
void image_apply_bw(Image* img) {

}

/**
 * Shift color of the internal Pixel array. The dimension of the array is width * height.
 * The shift value of RGB is rShift, gShift，bShift. Useful for color shift.
 *
 * @param  img: the image.
 * @param  rShift: the shift value of color r shift
 * @param  gShift: the shift value of color g shift
 * @param  bShift: the shift value of color b shift
 */
void image_apply_colorshift(Image* img, int rShift, int gShift, int bShift) {

}

/* Converts the image to grayscale. If the scaling factor is less than 1 the new image will be
 * smaller, if it is larger than 1, the new image will be larger.
 *
 * @param  img: the image.
 * @param  factor: the scaling factor
*/
void image_apply_resize(Image* img, float factor) {

}
