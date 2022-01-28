#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int randNum(){
    int file = open("/dev/random", O_RDONLY);
    unsigned int rand;
    int randNum = read(file, &rand, sizeof(rand));
    return rand;
}

int main(){
    int a[10];
    int i;
    for (i = 0; i < 10; i++) {
        a[i] = randNum();
    }
    int j;
    for (j = 0; j < 10; j++) {
        printf("%u\n", a[j]);
    }

    int file = open("file.txt", O_CREAT | O_RDWR, 0644);

    write(file, a, sizeof(a));

    file = open("file.txt", O_RDONLY);

    int arr[10];
    read(file, arr, sizeof(arr));

    printf("\n");

    for (i = 0; i < 10; i++) {
        printf("%u\n", arr[i]);
    }

    return 0;
}
