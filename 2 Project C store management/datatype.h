#include<stdbool.h>
//cau truc 
int *choice;//Lua chon
struct login{//cau truc dang nhap tk,mk 
	char Email[150];
	char Password[100];
};
typedef struct{
	int id;
	char Name[100];
	int isDeleted;
}Store;
typedef struct{
	int id;
	char Name[100];
	int Quality;
	int Price;
}Product;
int n;

