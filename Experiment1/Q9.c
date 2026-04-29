#include <stdio.h>

struct DemoStruct {
    int i;
    float f;
    char c;
};

union DemoUnion {
    int i;
    float f;
    char c;
};

int main() {
    printf("Size of Structure = %lu bytes\n", sizeof(struct DemoStruct));
    printf("Size of Union = %lu bytes\n", sizeof(union DemoUnion));

    return 0;
}
