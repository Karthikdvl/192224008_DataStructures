#include <stdio.h>

int main() {
    int arr[100]; // Assuming array size is 100
    int size, position;

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

    printf("Enter the position to delete from (0-indexed): ");
    scanf("%d", &position);

    if (position < 0 || position >= size) {
        printf("Invalid position.\n");
        return 1;
    }

    // Shift elements to overwrite the element to be deleted
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--; // Decrement array size

    printf("Array after deletion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

