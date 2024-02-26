#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sandpile.h>

int main(void)
{
    int h = 0, w = 0, cell_maxval = 0;

    printf("Enter matrix height: ");
    scanf("%d", &h);
    // TODO: Handle EOF & Check height value
    printf("Enter matrix width: ");
    scanf("%d", &w);
    // TODO: Handle EOF & Check width value
    printf("Enter cell maximum value (1-8): ");
    scanf("%d", &cell_maxval);
    // TODO: Handle EOF & Check cell_maxval value

    int **mtx = malloc(sizeof(int*) * h);

    printf("\nCreate your sandpile:\n");
    for (int i = 0; i < h; i++) {
        printf("Line %2d: ", i + 1);
        char row[w + 1];
        scanf("%s", row);
        // TODO: Handle EOF
        size_t nb_bytes = strlen(row);
        if (nb_bytes < w) {
            i--;
            printf("Invalid line\n");
            continue;
        }
        row[w] = '\0';

        bool invalid_line = false;
        for (int index = 0; index < w; index++)
            if (row[index] < '0' || row[index] > '9') {
                invalid_line = true;
                break;
            }

        if (invalid_line) {
            i--;
            printf("Invalid line\n");
            continue;
        }

        mtx[i] = malloc(sizeof(int) * w);
        for (int j = 0; j < w; j++) {
            mtx[i][j] = row[j] - '0';
        }
    }

    printf("\n");
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            printf("%d", mtx[i][j]);
        printf("\n");
    }

    sandpile_t pile = create_sandpile(h, w, cell_maxval, mtx);

    printf("\n");
    dump_sandpile(&pile);

    destroy_sandpile(&pile);
}
