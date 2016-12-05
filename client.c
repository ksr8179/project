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
#define BUFFER_LEN 100
#define CHAT_SIZE 1024
#define BUFF_SIZE 1024
#define LISTEN_QUEUE_SIZE 5
 
char* b[4][4];
int client_socket;
struct sockaddr_in client_addr;
char buff[BUFF_SIZE+5];
char buffer[BUFFER_LEN];
char a[20] = "";
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
	int j =0;
	char* token = NULL;
	token = strtok(s,"/");
	while(token != NULL){
	b[0][j] = token;	
	token = strtok(NULL,"/");
	j+=1;
	}
	gotoxy(2,10);
	printf("| %-15s | %-10s | %-10s | %-2s |",b[0][0],b[0][1],b[0][2],b[0][3]);
	}
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
	//getch();
	
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
			select_tuple();
		}
		if(check[0] == '2' && check[1] == 'a'){
		
		}
		if(check[0] == '3' && check[1] == 'a'){
		
		}
		if(check[0] == '4' && check[1] == 'a'){
		
		}
		if(check[0] == '5' && check[1] == 'a'){
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



