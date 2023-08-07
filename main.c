#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void countdown(int zeit);

int main()
{
    int time = 0;

    printf("Countdown in Seconds:\n");
    system("say -v Daniel Countdown in Seconds");
    scanf("%d", &time);

    if (time < 0)
    {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    countdown(time);

    return 0;
}

void countdown(int time)
{
    #define sec(time) ((time) % 60)
    #define min(time) (((time) / 60) % 60)
    #define hour(time) (((time) / 3600) % 24)
    #define day(time) (((time) / 86400) % 365)
    #define year(time) ((time) / 31536000)

    int i = time;

    while (i >= 0)
    {
        printf("\rY: %d D: %d H: %d M: %d S: %d ", year(i), day(i), hour(i), min(i), sec(i));
        fflush(stdout);
        sleep(1);
        i--;
    }

    system("say -v Daniel lets go!");

}
