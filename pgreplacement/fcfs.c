#include <stdio.h>

int main()
{
    int pages, frames;

    // Input: number of pages
    printf("Enter number of pages: ");
    scanf("%d", &pages);

    char ref[100]; // reference string
    printf("Enter the page reference string (no spaces): ");
    scanf("%s", ref);

    // Input: number of frames
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int frame[10];
    int i, j, k = 0;
    int faults = 0;
    int found;

    // initialize frame array with -1 (empty)
    for (i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\n");
    printf("------------------------\n");

    // FCFS Algorithm
    for (i = 0; i < pages; i++)
    {

        found = 0;

        // check if page already exists in frame
        for (j = 0; j < frames; j++)
        {
            if (frame[j] == ref[i])
            {
                found = 1;
                break;
            }
        }

        // if not found → page fault
        if (!found)
        {
            frame[k] = ref[i]; // replace oldest (k pointer)
            k = (k + 1) % frames;
            faults++;
        }

        // print the frames after each step
        printf("%c\t", ref[i]);
        for (j = 0; j < frames; j++)
        {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%c ", frame[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}
