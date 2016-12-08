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

 
#define BUFFER_LEN 100
#define CHAT_SIZE 1024
#define BUFF_SIZE 1024
#define LISTEN_QUEUE_SIZE 5

MYSQL mysql;
MYSQL_RES* res;
MYSQL_ROW row; 
char query[80];

unsigned int i, fields; 	
int j=0;

//서버의 listen 소켓 데이터 구조 생성과정
char buffer[BUFFER_LEN];
struct sockaddr_in server_addr;
char temp[20];
int server_fd, client_fd;


int search_query(char value[30])
{	
	char select_data[1000] = "";
	char select_error[100] = "empty";
	int select_chk = 0;
	
	sprintf(query,"select * from book where name like '%%%s%%'", value);
	
	if (mysql_query(&mysql, query)) {
	 	printf("MySQL Error %d: %s\n",
		mysql_errno(&mysql), mysql_error(&mysql));
		
 		mysql_free_result(res); 
	//good!!
	}else{
		printf("1111111\n");
		res = mysql_store_result(&mysql);
		
			printf("222222\n");
			fields = mysql_num_fields(res);
 	   		printf("-------------------------\n");
			
 	   		while ((row = mysql_fetch_row(res))) {
 				for (i = 0; i < fields; i++) {	
					strcat(select_data,row[i]);
					strcat(select_data,"/");
			
				}
				select_chk = 1;
			
	   		}     
			
	  		 printf("%12s\n", select_data);
			if(select_chk == 0)
			write(client_fd, select_error, strlen(select_error));
			if(select_chk == 1)
          		write(client_fd, select_data, strlen(select_data));
 			mysql_free_result(res); 
		
     	}
}

int insert_query(char name[50],char writer[50],char publisher[50],char count[50]){
	char insert_data[1000] = "success";
	char insert_error[100] = "noInsert";
	
	sprintf(query,"insert into book values('%s','%s','%s','%s')", name,writer,publisher,count);
	
	if (mysql_query(&mysql, query)) {
	 	printf("MySQL Error %d: %s\n",
		mysql_errno(&mysql), mysql_error(&mysql));
		
		write(client_fd, insert_error, strlen(insert_error));
	//good!!
	}else{
		write(client_fd,insert_data,strlen(insert_data));
     	}

}


int delete_query(char name[300]){
	char delete_data[30] = "success";
	char delete_error[30] = "fail";
	
	sprintf(query,"delete from book where name = '%s'", name);
	
	if (mysql_query(&mysql, query)) {
	 	printf("MySQL Error %d: %s\n",
		mysql_errno(&mysql), mysql_error(&mysql));
		
		write(client_fd, delete_error, strlen(delete_error));
	//good!!
	}else{
		write(client_fd,delete_data,strlen(delete_data));
     	}
	
}




void login_query(char value[20],char value2[20]){
	char login_error[20] = "empty";
	char login_data[20] = "";
	int login_chk = 0;
	sprintf(query,"select chk from login where id = '%s' and pwd = '%s'", value, value2);
	
	//printf("result :: %d\n",mysql_query(&mysql, query));
	//res = mysql_store_result(&mysql);
	if (mysql_query(&mysql, query)) {
	 	printf("MySQL Error %d: %s\n",
		mysql_errno(&mysql), mysql_error(&mysql));
		
		
 		mysql_free_result(res); 
		
	//good!!
	}else{
		printf("1111111\n");
		res = mysql_store_result(&mysql);
		
			printf("222222\n");
			fields = mysql_num_fields(res);
 	   		printf("-------------------------\n");
			
 	   		while ((row = mysql_fetch_row(res))) {
 				for (i = 0; i < fields; ++i) {	
					strcat(login_data,row[i]);
			
				}
				login_chk = 1;
		
	   		}     
	  		 printf("%12s\n", login_data);
			if(login_chk == 0)
			write(client_fd, login_error, strlen(login_error));
			if(login_chk == 1)
          		write(client_fd, login_data, strlen(login_data));
 			mysql_free_result(res); 
			
		
     	}

}


void DB_connect()
{
	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "11111", "db", 0, (char *)NULL, 0)) 	{
 		printf("Error %d: %s\n",
		mysql_errno(&mysql), mysql_error(&mysql));
 		exit(0);
 	}
}

int main(int argc, char *argv[])
{
    
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
    memset(&server_addr, 0, sizeof(server_addr));
 
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));
 
    //bind 과정
 
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
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
    printf("=====[PORT] : %d =====\n", atoi(argv[1]));
    printf("Server: waiting connection request.\n");
    
    struct sockaddr_in client_addr;
    int sin_size=sizeof(client_addr);
    	
    if((client_fd=accept(server_fd,(struct sockaddr*)&client_addr,
             &sin_size))==-1){
  		perror("accept");
	
     }
     printf("클라이언트가 접속하였습니다.\n");
     memset(buffer, 0, sizeof(buffer));
        
     inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, temp, sizeof(temp));
     printf("Server: %s client connect.\n", temp);

 	DB_connect();
        while (1) 
    	{ 
	
        //서버에서 메세지 전송
        char buffer[BUFFER_LEN];
	char buffer2[100];
	char buffer3[100];
	char buffer4[100];
	char chk[20];
	
	int chkN = read(client_fd, chk, 20);
	chk[chkN] = '\0';
   	printf("%s\n",chk);

   	if(chk[0] == '1' && chk[1] == 'a'){
		int insertn = read(client_fd, buffer, BUFFER_LEN);
    		buffer[insertn] = '\0';
		insertn=0;
   		printf("%s\n",buffer);
		insertn = read(client_fd,buffer2,100);
		buffer2[insertn]='\0';
		insertn=0;
		printf("%s\n",buffer2);
	        insertn = read(client_fd,buffer3,100);
		buffer3[insertn]='\0';
		insertn=0;
		printf("%s\n",buffer3);
		insertn = read(client_fd,buffer4,100);
		buffer4[insertn]='\0';
		insertn=0;
		printf("%s\n",buffer4);
		if(!insert_query(buffer,buffer2,buffer3,buffer4)){
			continue;
		}else{
			continue;
		}
	}
	
	else if(chk[0] == '2' && chk[1] == 'a'){
		int searchn = read(client_fd, buffer, BUFFER_LEN);
    		buffer[searchn] = '\0';
   		printf("%s\n",buffer);
		if(!search_query(buffer)){
			continue;
		}else{
			continue;
		}
	}else if(chk[0] == '3' && chk[1] == 'a'){
		int sn = read(client_fd, buffer, BUFFER_LEN);
    		buffer[sn] = '\0';
   		printf("%s\n",buffer);

		if(!search_query(buffer)){
			continue;
		}else{

			if(!delete_query(buffer)){
				continue;
			}else{
				continue;			
			}
			continue;
		}
	}

 	if(chk[0] == '1'){
		int n = read(client_fd, buffer4, BUFFER_LEN);
    		buffer4[n] = '\0';
   		printf("%s\n",buffer4);
		if(!search_query(buffer4)){
			continue;
		}else{
			continue;
		}
	}
	else if(chk[0] == '2'){
		int n2 = read(client_fd, buffer2, 20);
    		buffer2[n2] = '\0';
   		printf("%s\n",buffer2);
		int n3 = read(client_fd, buffer3, 20);
    		buffer3[n3] = '\0';
   		printf("%s\n",buffer3);
		login_query(buffer2,buffer3);
		}

	}
 	mysql_close(&mysql);
	
	printf("Server: %s client closed.\n", temp);
	//클라이언트 접속 종료
	close(client_fd);
	//서버 listen socket 종료
	close(server_fd);
 	return 0;
} 	




