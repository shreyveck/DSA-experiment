#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int table[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

int hashFunction(int key) {
    return (key % 1000) % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);

    int start = index;
    while (table[index] != -1) {
        printf("[COLLISION] at index %d\n", index);
        index = (index + 1) % SIZE;

        if (index == start) {
            printf("Table Full!\n");
            return;
        }
    }

    table[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

void search(int key) {
    int index = hashFunction(key);
    int start = index;

    while (table[index] != -1) {
        if (table[index] == key) {
            printf("Found at index %d\n", index);
            return;
        }
        index = (index + 1) % SIZE;

        if (index == start) break;
    }

    printf("Not Found\n");
}

void deleteKey(int key) {
    int index = hashFunction(key);
    int start = index;

    while (table[index] != -1) {
        if (table[index] == key) {
            table[index] = -1;
            printf("Deleted %d\n", key);
            return;
        }
        index = (index + 1) % SIZE;

        if (index == start) break;
    }

    printf("Not Found\n");
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("[%d] -> %d\n", i, table[i]);
    }
}

int main() {
    int ch, val;
    initialize();

    while (1) {
        printf("\n1.Insert 2.Delete 3.Search 4.Display 5.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: scanf("%d", &val); insert(val); break;
            case 2: scanf("%d", &val); deleteKey(val); break;
            case 3: scanf("%d", &val); search(val); break;
            case 4: display(); break;
            case 5: return 0;
        }
    }
}
