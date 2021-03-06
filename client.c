#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <termio.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
 
#define PORT 10000
#define BUFFER_LEN 1000
#define CHAT_SIZE 1024
#define BUFF_SIZE 1024
#define LISTEN_QUEUE_SIZE 5
 
char* b[4][4];
int client_socket;
struct sockaddr_in client_addr;
char buff[BUFF_SIZE+5];
char buffer[BUFFER_LEN];
char a[100] = "";
char id[] = "";
char pwd[10] = "";
char admin_chk[] = "";
char check[] = "";
int i =0;
char s[BUFFER_LEN] = "";


int getch(void)
{
    int ch;

    struct termios old;
    struct termios new;

    tcgetattr(0, &old);

    new = old;
    new.c_lflag &= ~(ICANON|ECHO);
    new.c_cc[VMIN] = 1;
    new.c_cc[VTIME] = 0;

    tcsetattr(0, TCSAFLUSH, &new);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &old);

    return ch;
}

void print_screen(char fname[])
{
	FILE *fp;
	char line[100];

	if ( (fp = fopen(fname,"r"))  == NULL ){
		printf("file open error\n");
		//getch();
		exit(-1);
	}
	while(1)
	{
		if( fgets(line, 99, fp) == NULL){
		     break;
		}
		printf("%s", line);
	}

	fclose(fp);
}

void gotoxy(int x, int y) {
    printf("\033[%d;%df", y, x);
    fflush(stdout);
}

void select_tuple()
{
		for(i=0; i<25; i++){
		printf("                                                                          \n");
		}
		gotoxy(0,0);
		print_screen("select_view.txt");
	
		gotoxy(25,4);
	scanf("%s",a);
		fflush(stdin);
	getch();
        
        write(client_socket, a, strlen(a));
	
	char s[BUFFER_LEN] = "";
	int n = read(client_socket, s, BUFFER_LEN);
    	buffer[n] = '\0';
        
	if(strcmp(s,"empty") == 0){
		gotoxy(6,14);
		printf("검색하신 책이 없습니다.");
	}
	else{
		int c =0;
		int to =0;
		char* token = NULL;
		token = strtok(s,"/");
		char *name[100][100] = {0,};
  	
             while(token != NULL){
		
		name[c][to] = token;
		token = strtok(NULL,"/");
		to++;

		if(to>3){
			c++;
			to=0;
		}
	     }
		
		gotoxy(1,10);
		int d = 0;

		for(d;d<c;d++){
			printf("| %-18s | %-10s | %-15s | %-2s |\n",name[d][0],name[d][1],name[d][2],name[d][3]);
		}
	}
	buffer[0]='\0';
	getch();
}


int insert_tuple(){
		char name[100];
		char writer[50];
		char publisher[50];
		char count[100];

		for(i=0; i<25; i++){
			printf("                                                                          \n");
		}
		gotoxy(0,0);
		print_screen("insert_view.txt");

		
		gotoxy(25,4);
		scanf("%s",name);
		fflush(stdin);
		write(client_socket,name, strlen(name));
		gotoxy(25,6);	
		scanf("%s",writer);
		fflush(stdin);
		write(client_socket,writer,strlen(writer));
		gotoxy(25,8);
		scanf("%s",publisher);
		fflush(stdin);
		write(client_socket,publisher,strlen(publisher));
		gotoxy(25,10);
		scanf("%s",count);
		fflush(stdin);
		write(client_socket,count,strlen(count));
		getch();
        
        
	

	char insert[BUFFER_LEN] = "";
	int n = read(client_socket, insert, BUFFER_LEN);
    	buffer[n] = '\0';

	if(strcmp(insert,"noInsert") == 0){
		gotoxy(10,14);
		printf("도서 추가에 실패하였습니다.");
		getch();
	}else if(strcmp(insert,"success")==0){
		gotoxy(10,14);
		printf("도서 추가에 성공하였습니다.");
		getch();
	}
	

}


void delete_tuple(){
	char dele[100];
	for(i=0; i<25; i++){
			printf("                                                                          \n");
		}
		gotoxy(0,0);
		print_screen("delete_view.txt");
	
		gotoxy(25,4);
		scanf("%s",dele);
		fflush(stdin);
		getch();
        
        write(client_socket, dele, strlen(dele));
	
	char deles[BUFFER_LEN] = "";
	int delen = read(client_socket, deles, BUFFER_LEN);
    	buffer[delen] = '\0';
        
	if(strcmp(deles,"empty") == 0){
		gotoxy(6,14);
		printf("검색하신 책이 없습니다.");
	}
	else{
	int c =0;
	int to =0;
	char* token = NULL;
	token = strtok(deles,"/");
	char *name[100][100] = {0,};
  	
             while(token != NULL){
		
		name[c][to] = token;
		token = strtok(NULL,"/");
		to++;

		if(to>3){
			c++;
			to=0;
		}
	     }
		
		gotoxy(1,10);
		int d = 0;

		for(d;d<c;d++){
			printf("| %-18s | %-10s | %-15s | %-2s |\n",name[d][0],name[d][1],name[d][2],name[d][3]);
		}
		
	buffer[0]='\0';
	getch();

	
	if(c==1){
		write(client_socket,name[0][0],strlen(name[0][0]));

		char delete[1000] = "";
		int deleten = read(client_socket, delete, BUFFER_LEN);
    		buffer[deleten] = '\0';

		if(strcmp(delete,"fail") == 0){
			gotoxy(10,14);
			printf("도서 삭제에 실패하였습니다.");
			getch();
		}else if(strcmp(delete,"success")==0){
			gotoxy(10,14);
			printf("도서 삭제에 성공하였습니다.");
			getch();
		}
	}else{
		for(i=10; i<25; i++){
			printf("                                                                          \n");
		}
		gotoxy(1,10);
		printf("삭제할 책을 한가지만 선택해주세요.\n");
	}

	}
	buffer[0]='\0';
	getch();

	

}


void login()
{
		for(i=0; i<25; i++){
		printf("                                                                          \n");
		}
		gotoxy(0,0);
		print_screen("login_view.txt");
		gotoxy(16,4);
		scanf("%s",id);
		fflush(stdin);
		write(client_socket, id, strlen(id));

		gotoxy(16,5);
		scanf("%s",pwd);
		fflush(stdin);
		getch();
		write(client_socket, pwd, strlen(pwd));

		
		int n = read(client_socket, s, BUFFER_LEN);
    		buffer[n] = '\0';
}


int main(int argc, char** argv) 
{
	
    if (argc != 2) 
    {
        printf("Usage: %s IPv4-address\n", argv[0]);
        return -1;
    }
 
    //서버에 접속할 소켓 데이터 구조 생성과정
 
       
      
 
      client_socket = socket(PF_INET, SOCK_STREAM, 0);
      if(client_socket == -1)
      {
          printf("socket 생성 실패\n");
           exit(1);
       }
 
    //connect file descriptor 선언	
 
    // memset은 모든 값을 0으로 초기화 해주기위해 클라이언트 실행 시 이용한다.
     memset(&client_addr, 0, sizeof(client_addr));
 
     client_addr.sin_family = AF_INET;
     client_addr.sin_port = htons(9190); // 포트번호를 9190으로 임의 지정해두었다.
     client_addr.sin_addr.s_addr= inet_addr("127.0.0.1"); // 서버 ip는 로컬 주소인 127.0.0.1로 지정해두었다.
 
    //서버에 접속하시오
 
        if(connect(client_socket, (struct sockaddr*)&client_addr, sizeof(client_addr)) == -1)
        {
            printf("접속 실패\n");
            exit(1);
        }
   	printf("접속에 성공했습니다.\n");

	while(1){
	for(i=0; i<25; i++){
	printf("                                                                          \n");
	}
	gotoxy(0,0);
	print_screen("menu2_view.txt");
	gotoxy(36,10);
	
	scanf("%s",admin_chk);
	fflush(stdin);
	write(client_socket, admin_chk, strlen(admin_chk));

	if(admin_chk[0] == '1'){
		select_tuple();
	
	}
	else if(admin_chk[0] == '2'){
		login();
		
	    while(1){
	     if(strcmp(s,"1")==0){
		gotoxy(26,5);
		printf("로그인성공");
		getch();
		gotoxy(0,0);
		
		while(1){
			for(i=0; i<25; i++){
				printf("                                                                          \n");
			}
			gotoxy(0,0);
			print_screen("menu_view.txt");
			gotoxy(36,10);
	
			scanf("%s",check);
			fflush(stdin);
			strcat(check,"a");
			write(client_socket, check, strlen(check));

			if(check[0] == '1' && check[1] == 'a'){
				insert_tuple();
			}
			if(check[0] == '2' && check[1] == 'a'){
				select_tuple();
			}
			if(check[0] == '3' && check[1] == 'a'){
				delete_tuple();
			}
			if(check[0] == '4' && check[1] == 'a'){
				for(i=0; i<25; i++){
				printf("                                                                          \n");
			}
			gotoxy(0,0);
			exit(1);
			}
			else{
				gotoxy(38,12);
				printf("값을 잘못 입력하였습니다.");
				continue;
			}
		    }
		}	
		else if(strcmp(s,"empty")==0){
			gotoxy(26,5);
			printf("아이디 혹은 비밀번호가 틀렸습니다.");
			getch();
			continue;
		}
	    }
		
	}
	else{
		gotoxy(38,12);
		printf("값을 잘못 입력하였습니다.");
		continue;
		}
	}
	
    	
	
	
 
    //클라이언트 접속 종료
     close(client_socket);
 
    return 0;
}



