#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int xCord;
    int yCord;
};

void sortIntervals(struct Interval *intervals,  int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (intervals[i].xCord > intervals[j].xCord) {
                int tempX = intervals[i].xCord;
                int tempY = intervals[i].yCord; 

                intervals[i].xCord = intervals[j].xCord;
                intervals[i].yCord = intervals[j].yCord;

                intervals[j].xCord = tempX;
                intervals[j].yCord = tempY;
            }
        }
    }
}

struct Interval* mergeIntervals(struct Interval *intervals, int n, int *m) {
    sortIntervals(intervals, n);

    int lptr = intervals[0].xCord;
    int rptr = intervals[0].yCord;
    int index = 0;

    struct Interval *ans = malloc(n * sizeof(struct Interval));
    ans[0].xCord = lptr;
    ans[0].yCord = rptr;

    for (int i = 1; i < n; i++) {
        int xCord = intervals[i].xCord;
        int yCord = intervals[i].yCord;

        if (xCord <= rptr) {
            if (yCord > rptr) {
                rptr = yCord;
            }
            ans[index].yCord = rptr;
        }
        else {
            ans[++index].xCord = xCord;
            ans[index].yCord = yCord;
            lptr = xCord;
            rptr = yCord;
        }
    }

    *m = index + 1;
    return ans;
}


int main() {

    int n;
    printf("Enter the number of intervals : ");
    scanf("%d", &n);

    struct Interval intervals[n];
    // {{1,3},{2,4},{6,8},{9,10}};

    printf("Enter the intervals : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &intervals[i].xCord);
        scanf("%d", &intervals[i].yCord);
    }

    int m = 0;
    struct Interval *ans = mergeIntervals(intervals, n, &m);

    printf("\nMerged Intervals : \n");
    for (int i = 0; i < m; i++) {
        printf("%d, %d\n", ans[i].xCord, ans[i].yCord);
    }

    return 0;
}