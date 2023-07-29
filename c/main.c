#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

int make_socket(uint16_t port)
{
    int sock;
    struct sockaddr_in addr;

    /* 创建字节流类型的IPV4 socket. */
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    /* 绑定到port和ip. */
    addr.sin_family = AF_INET; /* IPV4 */
    addr.sin_port = htons(port);  /* 指定端口 */
    addr.sin_addr.s_addr = htonl(INADDR_ANY); /* 通配地址 */

    /* 把IPV4地址转换成通用地址格式，同时传递长度 */
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
      perror("bind");
      exit(EXIT_FAILURE);
    }

    return sock;
}