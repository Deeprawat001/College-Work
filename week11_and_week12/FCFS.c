#include <stdio.h>
#include <stdlib.h>

int main()
{
    int total_head_movement = 0, initial_pos, n;
    printf("Enter the no. of cylinders in Request queue:\n");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int request_queue[n];
    printf("Enter the cylinders no. in Request queue :\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &request_queue[i]);
    printf("Enter the initial Position of RW head: ");
    if (scanf("%d", &initial_pos) != 1) return 0;
    for (int i = 0; i < n; i++)
    {
        total_head_movement += abs(initial_pos - request_queue[i]);
        initial_pos = request_queue[i];
    }
    printf("Total No. of Head Movements = %d\n", total_head_movement);
    printf("Average head movements = %.2f\n", (float)total_head_movement / n);
    return 0;
}
