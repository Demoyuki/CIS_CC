// Victor Marrujo
// Chpt6 PA

#include <stdio.h>
#include <stdbool.h>

// Defintions  ======================================================
#define TABLE_SIZE 16
#define EMPTY_START -1
#define EMPTY_REMOVED -2

// Hash Table functions ======================================================
int hashTable[TABLE_SIZE];
void initializeHashTable();     //not needed for program

int hash(int key);
bool hashInsert(int item);
bool hashRemove(int item);
int hashSearch(int item);
void displayHashTable();

int main() {
    // Local Definitions ============================================
    initializeHashTable();
    
	// Statements ==============================================================
    printf("1) Inserting 32: %s\n", hashInsert(32) ? "Success" : "Failed");
    printf("2) Inserting 63: %s\n", hashInsert(63) ? "Success" : "Failed");
    printf("3) Inserting 16: %s\n", hashInsert(16) ? "Success" : "Failed");
    printf("4) Inserting 3: %s\n", hashInsert(3) ? "Success" : "Failed");
    printf("5) Inserting 23: %s\n", hashInsert(23) ? "Success" : "Failed");
    printf("6) Inserting 11: %s\n", hashInsert(11) ? "Success" : "Failed");
    printf("7) Inserting 64: %s\n", hashInsert(64) ? "Success" : "Failed");
    printf("8) Inserting 99: %s\n", hashInsert(99) ? "Success" : "Failed");
    printf("9) Inserting 42: %s\n", hashInsert(42) ? "Success" : "Failed");
    printf("10) Inserting 49: %s\n", hashInsert(49) ? "Success" : "Failed");
    printf("11) Inserting 48: %s\n", hashInsert(48) ? "Success" : "Failed");
    printf("12) Inserting 21: %s\n", hashInsert(21) ? "Success" : "Failed");

    printf("\n13) Displaying hash table:\n");
    displayHashTable();

    printf("\n14) Removing 32: %s\n", hashRemove(32) ? "Success" : "Failed");
    printf("15) Removing 11: %s\n", hashRemove(11) ? "Success" : "Failed");

    int result = hashSearch(64);
    printf("\n16) Searching for 64: %s", result != -9 ? "Found in " : "Not found");
    if (result != -9) {
        printf("Bucket: %d\n", result);
    }

    printf("\n17) Inserting 9: %s\n", hashInsert(9) ? "Success" : "Failed");

    result = hashSearch(48);
    printf("18) Searching for 48: %s", result != -9 ? "Found in " : "Not found");
    if (result != -9) {
        printf("Bucket: %d\n", result);
    }

    result = hashSearch(32);
    printf("19) Searching for 32: %s", result != -9 ? "Found in " : "Not found");
    if (result != -9) {
        printf("Bucket: %d\n", result);
    }

    printf("\n20) Removing 64: %s\n", hashRemove(64) ? "Success" : "Failed");
    printf("21) Removing 99: %s\n", hashRemove(99) ? "Success" : "Failed");

    printf("22) Displaying hash table after removals:\n");
    displayHashTable();

    return 0;
} // main

void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        hashTable[i] = EMPTY_START;
    } // for
} //initializeHashTable

int hash(int key) {
    return key % TABLE_SIZE;
} // hash

bool hashInsert(int item) {
    int index = hash(item);
    int count = 0;
    while (count < TABLE_SIZE) 
    {
        if (hashTable[index] == EMPTY_START || hashTable[index] == EMPTY_REMOVED) 
        {
            hashTable[index] = item;
            return true;
        } // if
        count++;
        index = (index + count * count) % TABLE_SIZE; // Quadratic probing
    } // while

    return false; //in case hashfull
} //hashInsert

bool hashRemove(int item) {
    int index = hash(item);
    int count = 0;
    while (count < TABLE_SIZE) 
    {
        if (hashTable[index] == item) 
        {
            hashTable[index] = EMPTY_REMOVED;
            return true;
        } // if
        count++;
        index = (index + count * count) % TABLE_SIZE; // Quadratic probing
    } // while

    return false; //in case not found
} //hashRemove

int hashSearch(int item) {
    int index = hash(item);
    int count = 0;
    while (count < TABLE_SIZE) 
    {
        if (hashTable[index] == item) 
        {
            return index;
        } // if
        count++;
        index = (index + count * count) % TABLE_SIZE; // Quadratic probing
    } // while

    return -9; //in case not found
} //hashSearch

void displayHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        printf("Bucket %d: %d\n", i, hashTable[i]);
    } // for
} //displayHashTable

