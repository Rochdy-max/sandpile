#include <stdbool.h>

typedef struct sandpile_t
{
    int height;
    int width;
    int cell_maxval;
    int** mtx;
}sandpile_t;

typedef struct cellpos_t
{
    int row;
    int col;
}cellpos_t;

sandpile_t create_sandpile(int height, int width, int cell_maxval, int** mtx);
void destroy_sandpile(sandpile_t* pile);
bool cell_is_unstable(sandpile_t* pile, int row, int col);
bool cell_is_in_sandpile(sandpile_t* pile, int row, int col);
void normalize_sandpile(sandpile_t* pile);
void add_sandpile(sandpile_t* pile, sandpile_t* other);
