#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct HashTable {
    int data[TABLE_SIZE];
    int isOccupied[TABLE_SIZE];
};

void initialize(struct HashTable *hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->isOccupied[i] = 0;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(struct HashTable *hashTable, int value) {
    int index = hashFunction(value);

    if (hashTable->isOccupied[index]) {
        int newIndex = (index + 1) % TABLE_SIZE;
        while (hashTable->isOccupied[newIndex]) {
            newIndex = (newIndex + 1) % TABLE_SIZE;
        }
        index = newIndex;
    }

    hashTable->data[index] = value;
    hashTable->isOccupied[index] = 1;
}

void display(struct HashTable *hashTable) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable->isOccupied[i]) {
            printf("Index %d: %d\n", i, hashTable->data[i]);
        }
    }
}

int main() {
    struct HashTable hashTable;
    initialize(&hashTable);

    int n, value;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&hashTable, value);
    }

    display(&hashTable);

    return 0;
}

