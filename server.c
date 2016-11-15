#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

int main()
{
 	MYSQL mysql;
 	MYSQL_RES* res;
 	MYSQL_ROW row; 
 	mysql_init(&mysql);

	char query[80], name[20],writer[20], publisher[30], amount[10];
	char a[10];
 	int i, fields; 

 	if (!mysql_real_connect(&mysql, "localhost", "root", "1234", "db", 0, (char *)NULL, 0)) 	{
 		printf("Error %d: %s\ n",
		mysql_errno(&mysql), mysql_error(&mysql));
 		exit(1);
 	}
	printf("책검색 : ");
	scanf("%s",a);
	
	sprintf(query,"select * from book where name = '%s'",a);
	if (mysql_query(&mysql, query)) {
	 	printf("MySQL Error %d: %s\ n",
		mysql_errno(&mysql), mysql_error(&mysql));
 		exit(1);
	}
 	res = mysql_use_result(&mysql);
 	fields = mysql_num_fields(res);

 	printf("Total student is as follows.\n");

 	while ((row = mysql_fetch_row(res))) {
 		for (i = 0; i < fields; ++i) {
 			printf("%12s ", row[i]);
 		} 
	printf("\n");
 }
 mysql_free_result(res); 

 mysql_close(&mysql);
 return 0;
} 	
