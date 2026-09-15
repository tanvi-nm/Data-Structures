#include <stdio.h>

int power(int x, int y) {
    int ans = 1;
    for (int i = 1; i <= y; i++) {
        ans *= x;
    }
    return ans;
}

int powerWo(int x, int y) {
    int power = 0, z = x;
    for (int i = 1; i < y; i++) {
        for (int j = 1; j <= z; j++) {
            power += x;
        }
        x = power;
        power = 0;
    }
    power = x;
    return power;
}

int main() {

    int x,y;
    printf("Enter base and exponent : ");
    scanf("%d %d", &x, &y);

    printf("Power using multiplication : %d\n", power(x,y));
    printf("Power without using multiplication : %d", powerWo(x,y));

    return 0;
}