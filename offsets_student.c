#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "structs.h"

size_t offsetsS0(int arrayIndex, int fieldIndex) {
        size_t offsets0[] = {0, 4, 16, 24};
        return (arrayIndex * sizeof(struct S0) + offsets0[fieldIndex]);
}

size_t offsetsS1(int arrayIndex, int fieldIndex) {
        size_t offsets1[] = {0, 8, 16, 18};
        return (arrayIndex * sizeof(struct S1) + offsets1[fieldIndex]);
}

size_t offsetsS2(int arrayIndex, int fieldIndex) {
        size_t offsets2[] = {0, 4, 8, 16};
        return (arrayIndex * sizeof(struct S2) + offsets2[fieldIndex]);
}

size_t offsetsS3(int arrayIndex, int fieldIndex) {
        size_t offsets3[] = {0, 8, 12, 14};
        return (arrayIndex * sizeof(struct S3) + offsets3[fieldIndex]);
}
