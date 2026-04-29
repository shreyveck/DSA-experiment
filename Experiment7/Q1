#include <stdio.h>

int hashFunction(long sap_id) {
    int lastThree = sap_id % 1000;
    return lastThree % 10;
}

int main() {
    long sap;
    int family;

    printf("Enter SAP-ID: ");
    scanf("%ld", &sap);

    family = hashFunction(sap);

    printf("\nStudent with SAP-ID %ld belongs to Family %d\n", sap, family);

    return 0;
}
