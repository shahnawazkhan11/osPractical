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
    int i, j, k;
    int faults = 0;
    int found;

    // initialize frames
    for (i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\n");
    printf("------------------------\n");

    // LRU Algorithm
    for (i = 0; i < pages; i++)
    {
        found = 0;

        // Check if page already present in frame
        for (j = 0; j < frames; j++)
        {
            if (frame[j] == ref[i])
            {
                found = 1;
                break;
            }
        }

        // If page not found → Page Fault → Apply LRU
        if (!found)
        {
            // find LRU page (the one used farthest in past)
            int lru_index = 0;
            int farthest = 9999;

            for (j = 0; j < frames; j++)
            {
                if (frame[j] == -1)
                {
                    lru_index = j;
                    break;
                }

                // Check last use of frame[j]
                int last_use = -1;
                for (k = i - 1; k >= 0; k--)
                {
                    if (ref[k] == frame[j])
                    {
                        last_use = k;
                        break;
                    }
                }

                // If this page was least recently used
                if (last_use < farthest)
                {
                    farthest = last_use;
                    lru_index = j;
                }
            }

            // Replace LRU page
            frame[lru_index] = ref[i];
            faults++;
        }

        // Print frames
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
