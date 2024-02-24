typedef struct sandpile_t
{
    int height;
    int width;
    int cell_maxval;
    int** mtx;
}sandpile_t;

sandpile_t create_sandpile(int height, int width, int cell_maxval, int** mtx);
void destroy_sandpile(sandpile_t* pile);
void normalize_sandpile(sandpile_t* pile);
