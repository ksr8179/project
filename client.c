#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
 
#define PORT 10000
#define BUFFER_LEN 100
#define CHAT_SIZE 1024
#define BUFF_SIZE 1024
#define LISTEN_QUEUE_SIZE 5
 
int main(int argc, char** argv) 
{
	char a[10];
    if (argc != 2) 
    {
        printf("Usage: %s IPv4-address\n", argv[0]);
        return -1;
    }
 
    //서버에 접속할 소켓 데이터 구조 생성과정
 
       int   client_socket;
     struct sockaddr_in   server_addr;
       char   buff[BUFF_SIZE+5];
 
      client_socket = socket(PF_INET, SOCK_STREAM, 0);
      if(client_socket == -1)
      {
          printf("socket 생성 실패\n");
           exit(1);
       }
 
    //connect file descriptor 선언
 
    // memset은 모든 값을 0으로 초기화 해주기위해 클라이언트 실행 시 이용한다.
     memset( &server_addr, 0, sizeof( server_addr));
 
     server_addr.sin_family     = AF_INET;
      server_addr.sin_port       = htons(9190); // 포트번호를 4000으로 임의 지정해두었다.
     server_addr.sin_addr.s_addr= inet_addr("127.0.0.1"); // 서버 ip는 로컬 주소인 127.0.0.1로 지정해두었다.
 
    //서버에 접속하시오
 
      if(connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
       {
            printf("접속 실패\n");
            exit(1);
      }
    printf("책검색 : ");
	scanf("%s",a);
        char buffer[BUFFER_LEN] = {0};
        sprintf(buffer, a);
        write(client_socket, buffer, strlen(buffer));

    
 
    //클라이언트 접속 종료
     close( client_socket);
 
    return 0;
}
