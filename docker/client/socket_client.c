#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_ADDRESS "PLEASE ASSIGN"
#define SERVER_PORT PLEASE ASSIGN

int main() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from <your student ID>";
    char buffer[1024] = {0};

    // 建立 socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error \n");
        return -1;
    }

    // 設置 socket 資訊
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);

    // 將 IP 位址轉換為網路位元組序
    if (inet_pton(AF_INET, SERVER_ADDRESS, &serv_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported \n");
        return -1;
    }

    // 連接到伺服器
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection Failed \n");
        return -1;
    }

    // 發送消息給伺服器
    send(sock, hello, strlen(hello), 0);
    printf("Hello message sent.\n");

    // 接收伺服器回應
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);

    // 關閉 socket
    close(sock);
    return 0;
}
