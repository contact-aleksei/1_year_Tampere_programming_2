#include "array_operations.hh"

using namespace std;

int greatest_v1(int* itemptr, int size)
/*
 * Returns the greatest element of the array.
 * int* itemptr: pointer to the first array element to be examined
 * int size: number of elements to be examined
 * return value: the greatest element of the array
 */{
    int the_greatest_element = *itemptr;
    int iterator=0;
    while(iterator<size){
        if (the_greatest_element<*itemptr){
            the_greatest_element = *itemptr;
        }
        iterator++;
        itemptr++;
    }
return the_greatest_element;
}

int greatest_v2(int* itemptr, int* endptr)
/*
 * Returns the greatest element of the array.
 * int* itemptr: pointer to the first array element to be examined
 * int* endptr: pointer to the memory address after the last element of the array
 * return value: the greatest element of the array
 */{
    int the_greatest_element = *itemptr;
    int iterator=0;
    while(itemptr<endptr){
        if (the_greatest_element<*itemptr){
            the_greatest_element = *itemptr;
        }
        iterator++;
        itemptr++;
    }
return the_greatest_element;
}

void copy(int* itemptr, int* endptr, int* targetptr)
/* Copies the content of the array to another array
 * int* itemptr: pointer to the first array element to be copied
 * int* endptr: pointer to the memory address after the last element of the array to be copied
 * int* targetptr: pointer to the head of the array, to which to copy
 */{
    while(itemptr<endptr){
        *targetptr = *itemptr;
        targetptr++;
        itemptr++;
    }
}

void reverse(int* leftptr, int* rightptr)
/* Reverses the elements of the array
 * int* leftptr: pointer to the first element of the reversable part
 * int* rightptr: pointer to the next memory address after the reversable part
 */{
    rightptr--;
    while (leftptr < rightptr){
        int temp = *leftptr;
        *leftptr = *rightptr;
        *rightptr = temp;
        leftptr++;
        rightptr--;
        }
}

