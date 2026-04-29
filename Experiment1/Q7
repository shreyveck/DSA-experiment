#include <stdio.h>
#include <stdlib.h>

struct Record {
    int id;
    char name[50];
};

int main() {
    struct Record *rec = NULL;
    int n = 0, choice;

    while(1) {
        printf("\n1.Add\n2.Display\n3.Delete Last\n4.Exit\nChoice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            n++;
            rec = realloc(rec, n * sizeof(struct Record));
            printf("Enter ID and Name: ");
            scanf("%d %s", &rec[n-1].id, rec[n-1].name);
        }
        else if(choice == 2) {
            for(int i = 0; i < n; i++)
                printf("%d %s\n", rec[i].id, rec[i].name);
        }
        else if(choice == 3) {
            if(n > 0) n--;
        }
        else {
            free(rec);
            break;
        }
    }

    return 0;
}
