#include <stdio.h>

int main() {
    int arr[100]; // Assuming array size is 100
    int size, element, position;

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

    printf("Enter the element to insert: ");
    scanf("%d", &element);

    printf("Enter the position to insert at (0-indexed): ");
    scanf("%d", &position);

    if (position < 0 || position > size) {
        printf("Invalid position.\n");
        return 1;
    }

    // Shift elements to make space for the new element
    for (int i = size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert the element at the specified position
    arr[position] = element;
    size++; // Increment array size

    printf("Array after insertion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

