#include <stdio.h>

#define MAX 10

int main() {
    int n, a[MAX], b[MAX], t[MAX], w[MAX], g[MAX + 1], i;
    float att = 0, awt = 0;

    // Initialize arrays
    for (i = 0; i < MAX; i++) {
        a[i] = 0;
        b[i] = 0;
        w[i] = 0;
        t[i] = 0;
    }
    g[0] = 0;

    // Input number of processes
    printf("Enter the number of process ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Number of processes exceeds the maximum limit of %d.\n", MAX);
        return 1;
    }

    // Input burst times
    printf("Enter the burst times ");
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);

    // Input arrival times
    printf("Enter the arrival times \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Calculate completion times
    for (i = 0; i < n; i++) {
        g[i + 1] = g[i] + b[i];
    }

    // Calculate waiting times and turnaround times
    for (i = 0; i < n; i++) {
        w[i] = g[i] - a[i];
        t[i] = g[i + 1] - a[i];
        if (w[i] < 0) w[i] = 0;  // Waiting time cannot be negative
        awt += w[i];
        att += t[i];
    }

    awt /= n;
    att /= n;

    // Display results
    printf("\n\tProcess\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("\tp%d\t\t%d\t\t%d\n", i + 1, w[i], t[i]);
    }

    printf("The average waiting time is %.2f\n", awt);
    printf("The average turnaround time is %.2f\n", att);

    return 0;
}
