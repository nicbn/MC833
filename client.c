#include <arpa/inet.h>  // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>  // bzero()
#include <sys/socket.h>
#include <unistd.h>  // read(), write(), close()
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
void manageChoice(char choice) {
    /*
    "\nMENU\n"
    "Write a number accordingly to what you want:\n"
    "1 - Insert a new profile in the system\n"
    "2 - List all people graduated in a specific course\n"
    "3 - List all people graduated in a specific year\n"
    "4 - Liss all informations of all profiles\n"
    "5 - Given an email, list all information of it\n"
    "6 - Given an email, remove a profile\n"
    */
    if (choice == "1") {
        char message[50] = "Insert email";
        strcpy(message, "Insert name");
        strcpy(message, "Insert lastname");
        strcpy(message, "Insert city");
        strcpy(message, "Insert graduation field");
        strcpy(message, "Insert graduation year");
        strcpy(message, "Insert skills");
    }
    if (choice == "2") {
        printf("28483748274873");
    }
    if (choice == "3") {
    }
    if (choice == "4") {
    }
    if (choice == "5") {
    }
    if (choice == "6") {
    }
}
void func(int sockfd) {
    char buff[MAX];
    int n;
    for (;;) {
        bzero(buff, sizeof(buff));
        char menu[500] =
            "\nMENU\n"
            "Write a number accordingly to what you want:\n"
            "1 - Insert a new profile in the system\n"
            "2 - List all people graduated in a specific course\n"
            "3 - List all people graduated in a specific year\n"
            "4 - Liss all informations of all profiles\n"
            "5 - Given an email, list all information of it\n"
            "6 - Given an email, remove a profile\n";
        printf("%s", menu);
        manageChoice(menu[0]);
        n = 0;
        while ((buff[n++] = getchar()) != '\n') {
        }
        write(sockfd, buff, sizeof(buff));
        printf("buff");
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("From Server : %s", buff);
        if ((strncmp(buff, "exit", 4)) == 0) {
            printf("Client Exit...\n");
            break;
        }
    }
}

int main() {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    } else {
        printf("Socket successfully created..\n");
    }
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // connect the client socket to server socket
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    } else {
        printf("connected to the server..\n");
    }

    // function for chat
    func(sockfd);

    // close the socket
    close(sockfd);
}
