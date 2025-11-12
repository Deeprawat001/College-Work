#include <stdio.h>
int isPresent(int x, int brr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (brr[i] == x)
            return 1;
    }
    return 0;
}
void insertInFrames(int brr[], int *rear, int val, int n)
{
    brr[*rear] = val;
    *rear = (*rear + 1) % n;
}
int main()
{
    int frames;
    printf("Enter frames: ");
    scanf("%d", &frames);

    int req;
    printf("Enter num of request: ");
    scanf("%d", &req);

    int arr[req];
    int brr[frames];
    for (int i = 0; i < frames; i++)
        brr[i] = -1;

    int front = 0, rear = 0;
    int count = 0;
    int hit = 0, miss = 0;

    printf("Enter reference string: ");
    for (int i = 0; i < req; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < req; i++)
    {
        if (isPresent(arr[i], brr, frames))
        {
            hit++;
        }
        else
        {
            miss++;
            if (count < frames)
            {
                brr[rear] = arr[i];
                rear = (rear + 1) % frames;
                count++;
            }
            else
            {
                brr[front] = arr[i];
                front = (front + 1) % frames;
                rear = (rear + 1) % frames;
            }
        }
    }
    printf("Hits = %d,Page Fault = %d\n", hit, miss);
}
