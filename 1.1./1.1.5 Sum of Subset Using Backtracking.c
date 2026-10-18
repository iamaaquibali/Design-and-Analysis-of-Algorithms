#include <stdio.h>

int arr[20];
int subset[20];
int result[1000][20];
int resultSize[1000];
int count = 0;

void findSubsets(int index, int n, int target, int sum, int size) {
    if (sum == target) {
        resultSize[count] = size;
        for (int i = 0; i < size; i++)
            result[count][i] = subset[i];
        count++;
        return;
    }

    if (index == n || sum > target)
        return;

    // Include current element
    subset[size] = arr[index];
    findSubsets(index + 1, n, target, sum + arr[index], size + 1);

    // Exclude current element
    findSubsets(index + 1, n, target, sum, size);
}

int main() {
    int n, target;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &target);

    findSubsets(0, n, target, 0, 0);

    if (count == 0) {
        printf("-1");
    } else {
        for (int i = count - 1; i >= 0; i--) {
            for (int j = 0; j < resultSize[i]; j++) {
                printf("%d ", result[i][j]);
                
            }
            if (i != 0)
                printf("\n");
        }
    }

    return 0;
}
