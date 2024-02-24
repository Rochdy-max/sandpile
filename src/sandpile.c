#include <stdio.h>
#include <stdlib.h>
#include <sandpile.h>

sandpile_t create_sandpile(int height, int width, int cell_maxval, int** mtx)
{
    sandpile_t new_pile = {
        height,
        width,
        cell_maxval,
        mtx
    };

    normalize_sandpile(&new_pile);
    return new_pile;
}

void destroy_sandpile(sandpile_t* pile)
{
    for (int i = 0; i < pile->height; i++) {
        free(pile->mtx[i]);
    }
    free(pile->mtx);
}

void normalize_sandpile(sandpile_t* pile)
{
    int i = 0, j = 0;

    while (i != pile->height) {
        // Normalization code here
        j++;
        if (j == pile->width) {
            i++;
            j = 0;
        }
    }
}
