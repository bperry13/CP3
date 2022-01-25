/**
* Implementation of several functions to manipulate Image.
*
* Completion time: 20 hours
*
* @author Brett Perry, Ruben Acuna
* @version 1.24.22
*/
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

    //allocate mem
    Image* img = malloc(sizeof(struct Image));
    //assign height
    img->height = height;
    //assign width
    img->width = width;
    //assign pixel array
    img->pArr = pArr;

    //return new image
    return img;
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

    int r, g, b, grayscale;

    for (int y = 0; y < image_get_height(img); y++) {
        for (int x = 0; x < image_get_width(img); x++) {

            b = img->pArr[y][x].pBlue;
            g = img->pArr[y][x].pGreen;
            r = img->pArr[y][x].pRed;

            //find average value of pixels
            grayscale = 0.299*r + 0.587*g + 0.114*b;

            //write average value of pixels
            img->pArr[y][x].pBlue = grayscale;
            img->pArr[y][x].pGreen = grayscale;
            img->pArr[y][x].pRed = grayscale;
        }
    }
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

    int r, g, b, b_tot, g_tot, r_tot, min=0, max=255;

    for (int y = 0; y < image_get_height(img); y++) {
        for (int x = 0; x < image_get_width(img); x++) {

            b = img->pArr[y][x].pBlue;
            g = img->pArr[y][x].pGreen;
            r = img->pArr[y][x].pRed;

            b_tot = b + bShift;
            if (b_tot > max) {
                b_tot = max;
            } else if (b_tot < min) {
                b_tot = min;
            }
            g_tot = g + gShift;
            if (g_tot > max) {
                g_tot = max;
            } else if (g_tot < min) {
                g_tot = min;
            }
            r_tot = r + rShift;
            if (r_tot > max) {
                r_tot = max;
            } else if (r_tot < min) {
                r_tot = min;
            }

            //write average value of pixels
            img->pArr[y][x].pBlue = b_tot;
            img->pArr[y][x].pGreen = g_tot;
            img->pArr[y][x].pRed = r_tot;
        }
    }

}

/* Converts the image to grayscale. If the scaling factor is less than 1 the new image will be
 * smaller, if it is larger than 1, the new image will be larger.
 *
 * @param  img: the image.
 * @param  factor: the scaling factor
*/
void image_apply_resize(Image* img, float factor) {

    int width, height, padding;

    //determine new dims
    width = img->width * factor;
    height = img->height * factor;

    //determine new padding
    padding = 4 - (3 * width) % 4;

    //determine new img size
    img->pArr = (width * sizeof(struct Pixel) + padding) * abs(height);

    for (int y = 0; y < image_get_height(img); y++) {
        for (int i = 0; i < factor; i++) {
            for (int x = 0; x < image_get_width(img); x++) {
                for (int j = 0; j < factor; j++) {
                    image_get_pixels(img);
                }
            }
        }
    }
}
