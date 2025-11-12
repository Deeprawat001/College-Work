#include <stdio.h>

int isPresent(int x, int brr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (brr[i] == x)
            return i;
    }
    return -1;
}

int main()
{
    int frames, req;
    printf("Enter frames: ");
    scanf("%d", &frames);
    printf("Enter req: ");
    scanf("%d", &req);
    int arr[req];
    printf("Enter reference string: ");
    for (int i = 0; i < req; i++)
        scanf("%d", &arr[i]);
    int brr[frames], count[frames], hit = 0, miss = 0;
    for (int i = 0; i < frames; i++)
    {
        brr[i] = -1;
        count[i] = -1;
    }
    for (int i = 0; i < req; i++)
    {
        int pos = isPresent(arr[i], brr, frames);
        if (pos != -1)
        {
            hit++;
            count[pos] = i;
        }
        else
        {
            miss++;
            int replaceIndex = -1;
            for (int j = 0; j < frames; j++)
            {
                if (brr[j] == -1)
                {
                    replaceIndex = j;
                    break;
                }
            }
            if (replaceIndex == -1)
            {
                int mini = 100000, index = -1;
                for (int j = 0; j < frames; j++)
                {
                    if (count[j] < mini)
                    {
                        mini = count[j];
                        index = j;
                    }
                }
                replaceIndex = index;
            }
            brr[replaceIndex] = arr[i];
            count[replaceIndex] = i;
        }
    }
    printf("Hits = %d  Page Fault = %d\n", hit, miss);
    return 0;
}
