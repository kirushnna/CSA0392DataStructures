#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 100

// Structure to represent a hashtag node
struct HashTagNode {
    char tag[50];
    int frequency;
    struct HashTagNode* next;
};

// Hash table to store hashtags
struct HashTable {
    struct HashTagNode* table[HASH_TABLE_SIZE];
};

// Function to create a new hashtag node
struct HashTagNode* createHashTagNode(const char* tag) {
    struct HashTagNode* newNode = (struct HashTagNode*)malloc(sizeof(struct HashTagNode));
    strcpy(newNode->tag, tag);
    newNode->frequency = 1;
    newNode->next = NULL;
    return newNode;
}

// Function to create a hash table
struct HashTable* createHashTable() {
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

// Function to calculate the hash value
int hashFunction(const char* tag) {
    unsigned long hash = 5381;
    int c;

    while ((c = *tag++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % HASH_TABLE_SIZE;
}

// Function to add a hashtag to the hash table
void addHashTag(struct HashTable* hashTable, const char* tag) {
    int hashValue = hashFunction(tag);
    struct HashTagNode* newNode = createHashTagNode(tag);

    if (hashTable->table[hashValue] == NULL) {
        hashTable->table[hashValue] = newNode;
    } else {
        newNode->next = hashTable->table[hashValue];
        hashTable->table[hashValue] = newNode;
    }
}

// Function to retrieve the frequency of a hashtag
int getHashTagFrequency(struct HashTable* hashTable, const char* tag) {
    int hashValue = hashFunction(tag);
    struct HashTagNode* current = hashTable->table[hashValue];

    while (current != NULL) {
        if (strcmp(current->tag, tag) == 0) {
            return current->frequency;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    struct HashTable* hashTable = createHashTable();

    addHashTag(hashTable, "#programming");
    addHashTag(hashTable, "#coding");
    addHashTag(hashTable, "#programming");
    addHashTag(hashTable, "#opensource");

    printf("Frequency of #programming: %d\n", getHashTagFrequency(hashTable, "#programming"));
    printf("Frequency of #coding: %d\n", getHashTagFrequency(hashTable, "#coding"));
    printf("Frequency of #opensource: %d\n", getHashTagFrequency(hashTable, "#opensource"));
    printf("Frequency of #gaming: %d\n", getHashTagFrequency(hashTable, "#gaming"));

    return 0;
}
