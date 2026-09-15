#include <stdio.h>
#include <math.h>

int count(int n) {
    int ans = 0;
    while (n > 0) {
        ans++;
        n /= 10;
    }
    return ans;
}

int isArmStrong(int n) {
    int digits = count(n);
    int temp = n;
    int sum = 0;

    while (temp > 0) {
        sum += (int)pow(temp % 10, digits);
        temp /= 10;
    }

    if (sum == n) {
        return 1;
    }
    else {
        return 0;
    }

}

int main() {

    for (int i = 1; i <= 1000; i++) {
        if (isArmStrong(i)) {
            printf("%d, ", i);
        }
    }
    
    return 0;
}