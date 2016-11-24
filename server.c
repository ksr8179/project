#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

MYSQL mysql;
MYSQL_RES* res;
MYSQL_ROW row; 
char query[80];

int i, fields; 	
int j=0;

#define PORT 10000
#define BUFFER_LEN 100
#define CHAT_SIZE 1024
#define BUFF_SIZE 1024
#define LISTEN_QUEUE_SIZE 5

void search_query(char value[20])
{
	sprintf(query,"select * from book where name like '%%%s%%'", value);
	//sprintf(query,"select * from %s", value);
	
	if (mysql_query(&mysql, query)) {
	 	printf("MySQL Error %d: %s\n",
		mysql_errno(&mysql), mysql_error(&mysql));
 		exit(1);
	}
}

void print()
{
	res = mysql_use_result(&mysql);
 	fields = mysql_num_fields(res);

 	printf("Total student is as follows.\n");

 	while ((row = mysql_fetch_row(res))) {
 		for (i = 0; i < fields; ++i) {
 			printf("%12s ", row[i]);
 		} 
	printf("\n");
 }
}

void DB_connect()
{
	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "1234", "db", 0, (char *)NULL, 0)) 	{
 		printf("Error %d: %s\n",
		mysql_errno(&mysql), mysql_error(&mysql));
 		exit(1);
 	}
}

int main(int argc, char *argv[])
{
	//서버의 listen 소켓 데이터 구조 생성과정
    char buffer[BUFFER_LEN];
    struct sockaddr_in server_addr, client_addr;
    char temp[20];
    char chat_data[CHAT_SIZE];
    int server_fd, client_fd;
    int len, msg_size;
    char test[20];
    char a[10];
    char Quit[5] = "quit";
 
    if (argc != 2)
    {
        printf("사용법 : ./filename 포트번호 \n");
        exit(0);
    }
 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("Server: can not Open Socket\n");
        exit(0);
    }
 
    //listen file descriptor 선언
 
    // memset은 모든 값을 0으로 초기화 해주기위해 서버 실행 시 이용한다.
    memset(&server_addr, 0x00, sizeof(server_addr));
 
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));
 
    //bind 과정
 
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Server: can not bind local address\n");
        exit(0);
    }
    printf("Waiting for clients...\n");
 
    //listen 과정
    if (listen(server_fd, 5) < 0) 
    {
        printf("Server: can not listen connect. \n");
        exit(0);
    }
 
    memset(buffer, 0x00, sizeof(buffer));
    len = sizeof(client_addr);
 
    printf("=====[PORT] : %d =====\n", atoi(argv[1]));
    printf("Server: waiting connection request.\n");
 
 
 
    // accept 기다리는 과정
    
        //클라이언트를 accept하는 과정
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&len);
 
        if (client_fd < 0)
        {
            printf("Server: accept failed\n");
            exit(0);
        }
 
        
        inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, temp, sizeof(temp));
        printf("Server: %s client connect,\n", temp);
	
        
        while (1) 
    	{
        //서버에서 메세지 전송
        char buffer[BUFFER_LEN];
   	 int n = read(client_fd, buffer, BUFFER_LEN);
    	buffer[n] = '\0';
   	 printf("클라이언트로 부터 넘어온 값 : %s\n",buffer);

 	DB_connect();
	search_query(buffer);
	res = mysql_use_result(&mysql);
 	fields = mysql_num_fields(res);
	char s[] = "";
 	printf("Total student is as follows.\n");
	
 	while ((row = mysql_fetch_row(res))) {
	
 		for (i = 0; i < fields; ++i) {	
			strcat(s,row[i]);
			strcat(s,"/");
			
		}
		
	}     
		printf("%12s\n", s);
	
        //sprintf(buffer, s);
	
        write(client_fd, s, strlen(s));
    }
 
 	
 	mysql_free_result(res); 
 	mysql_close(&mysql);
	
	printf("Server: %s client closed.\n", temp);
	//클라이언트 접속 종료
	close(client_fd);
	//서버 listen socket 종료
	close(server_fd);
 	return 0;
} 	


