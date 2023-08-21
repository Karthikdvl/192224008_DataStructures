#include <stdio.h>

int main() {
    int arr[100]; // Assuming array size is 100
    int size, searchElement;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0 || size > 100) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &searchElement);

    // Search for the element in the array
    int found = 0;
    int position = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchElement) {
            found = 1;
            position = i;
            break;
        }
    }

    if (found) {
        printf("Element %d found at position %d.\n", searchElement, position);
    } else {
        printf("Element %d not found in the array.\n", searchElement);
    }

    return 0;
}

