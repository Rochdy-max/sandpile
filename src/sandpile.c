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
        if (pile->mtx[i][j] > pile->cell_maxval) {
            cellpos_t neighbors[4] = {
                {i - 1, j}, // Up
                {i, j + 1}, // Right
                {i + 1, j}, // Down
                {i, j - 1}  // Left
            };
            int to_draw = pile->cell_maxval + 1;
            pile->mtx[i][j] -= to_draw;
            for (int k = 0; k < to_draw; k++) {
                int row = neighbors[k].row, col = neighbors[k].col;
                if (row >= 0 && row < pile->height && col >= 0 && col < pile->width) {
                    pile->mtx[row][col]++;
                }
            }
            // Stay on cell if it's still unstable
            if (pile->mtx[i][j] > pile->cell_maxval)
                continue;
            // Go back to upper cell if it becomes unstable 
            int up_index = 0;
            int row = neighbors[up_index].row, col = neighbors[up_index].col;
            if (row >= 0 && row < pile->height && col >= 0 && col < pile->width && pile->mtx[row][col] > pile->cell_maxval) {
                i--;
                continue;
            }
            // Go back to left cell if it becomes unstable 
            int left_index = 0;
            row = neighbors[left_index].row, col = neighbors[left_index].col;
            if (row >= 0 && row < pile->height && col >= 0 && col < pile->width && pile->mtx[row][col] > pile->cell_maxval) {
                j--;
                continue;
            }
        }
        // Go to next cell
        j++;
        if (j == pile->width) {
            i++;
            j = 0;
        }
    }
}
