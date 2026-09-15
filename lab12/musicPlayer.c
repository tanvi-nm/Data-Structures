#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    struct Node *lptr;
    char *audio;
    struct Node *rptr;
};
struct Node *first = NULL;
struct Node *current = NULL;

void insertTrack(char *audioFile) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->audio = (char *)malloc(strlen(audioFile) + 1);
    strcpy(newNode->audio, audioFile);

    newNode->rptr = NULL;

    if (first == NULL) {
        newNode->lptr = NULL;
        first = newNode;
    }
    else {
        struct Node *temp = first;
        while (temp->rptr != NULL) {
            temp = temp->rptr;
        }
        temp->rptr = newNode;
        newNode->lptr = temp;
    }
    current = newNode;
    printf("Track added successfully!\n");

}

int playAudio(struct Node *current) {
    system("killall afplay > /dev/null 2>&1");
    if (first == NULL) {
        printf("Cannot play from an empty playlist!\n");
        return 0;
    }
    else if (current == NULL) {
        printf("Invalid track address chosen!\n");
        return 0;
    }
    else {
        printf("Playing : %s\n", current->audio);
        system(current->audio);
        printf("Track played successfully!\n");
        return 1;
    }
}

int main() {

    int choice = 1;

    while (choice) {
        printf("\n0 Exit\n");
        printf("1 Insert track\n");
        printf("2 Play current\n");
        printf("3 Play previous\n");
        printf("4 Play next\n");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        if (choice == 0) {
            system("killall afplay > /dev/null 2>&1");
            break;
        }

        else if (choice == 1) {
            char s[100];
            printf("Enter the valid url of the track to be played (afplay filename.mp3) : ");
            scanf(" %99[^\n]", s); 

            insertTrack(s);
        }

        else if (choice == 2) {
            playAudio(current);
        }

        else if (choice == 3) {
            if (current != NULL && current->lptr != NULL) {
                playAudio(current->lptr);
                current = current->lptr;
            }
            else {
                printf("Already at the very first track!\n");
            }
        }

        else if (choice == 4) {
            if (current != NULL && current->rptr != NULL) {
                playAudio(current->rptr);
                current = current->rptr;
            }
            else {
                printf("Already at the very last track!\n");
            }
        }
    }

    printf("\nHasta la Vista! 🌻\n");

    return 0;
}