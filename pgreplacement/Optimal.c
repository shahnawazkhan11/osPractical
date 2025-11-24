#include <stdio.h>

int main() {
    int pages, frames;
    printf("Enter number of pages: ");
    scanf("%d", &pages);

    char ref[100];
    printf("Enter the page reference string (no spaces): ");
    scanf("%s", ref);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int frame[10], faults = 0;
    for (int i = 0; i < frames; i++) frame[i] = -1;

    printf("\nPage\tFrames\n-------------------------\n");

    for (int i = 0; i < pages; i++) {
        int found = 0;

        // Check if page exists
        for (int j = 0; j < frames; j++)
            if (frame[j] == ref[i]) { found = 1; break; }

        if (!found) {
            int pos = -1, far = -1;

            // Check for empty frame first
            for (int j = 0; j < frames; j++)
                if (frame[j] == -1) { pos = j; break; }

            // No empty frame → find optimal
            if (pos == -1) {
                for (int j = 0; j < frames; j++) {
                    int k;
                    for (k = i + 1; k < pages; k++)
                        if (ref[k] == frame[j]) break;

                    if (k == pages) { pos = j; break; }      // never used again
                    if (k > far) { far = k; pos = j; }        // farthest future use
                }
            }

            frame[pos] = ref[i];
            faults++;
        }

        // Print frames
        printf("%c\t", ref[i]);
        for (int j = 0; j < frames; j++)
            printf("%c ", frame[j] == -1 ? '-' : frame[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
