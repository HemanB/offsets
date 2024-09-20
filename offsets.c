#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern int offsetsS0(int arrayIndex, int fieldIndex);
extern int offsetsS1(int arrayIndex, int fieldIndex);
extern int offsetsS2(int arrayIndex, int fieldIndex);
extern int offsetsS3(int arrayIndex, int fieldIndex);

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s [struct index] [array index] [field index]", argv[0]);
        return 0;
    }
    int arrIdx, fieldIdx, structIndex;

    int values = sscanf(argv[1], "%d", &structIndex);
    if (values != 1) {
        fprintf(stderr, "malformed struct index value");
        return 0;
    }
    if (values < 0 || values > 3) {
        fprintf(stderr, "struct index value must be within 0 and 3");
        return 0;
    }
    values = sscanf(argv[2], "%d", &arrIdx);
    if (values != 1) {
        fprintf(stderr, "malformed array index value");
        return 0;
    }
    
    values = sscanf(argv[3], "%d", &fieldIdx);
    if (values != 1) {
        fprintf(stderr, "malformed field index value");
        return 0;
    }
    int result = -1;
    switch (structIndex) {
        case 0: result = offsetsS0(arrIdx, fieldIdx); break;
        case 1: result = offsetsS1(arrIdx, fieldIdx); break;
        case 2: result = offsetsS2(arrIdx, fieldIdx); break;
        case 3: result = offsetsS3(arrIdx, fieldIdx); break;
    }
    printf("%d\n", result);
    return 0;
}