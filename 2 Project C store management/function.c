#include <stdio.h>
#include <string.h> 
#include "function.h"

//logic ham
void choicee(int *choice){//lua chon
	printf("\tMoi ban lua chon : ");
	scanf("%d",choice);
}
void Back(int *choice){//lua chon
	printf("\n\tQuay lai(1)? or Exit(0)?: ");
	scanf("%d",choice);
}

void ChonThuTu(int *choice){//lua chon
	printf("\n\tTu lon den be(1)? or Tu be den lon(2)?: ");
	scanf("%d",choice);
}

void YesOrNo(int *choice){//lua chon
	printf("\n\tBan co muon xoa ko?\n");
	printf("\n\tYES(1) or NO(0): ");
	scanf("%d",choice);
}

void BeginStore(){//hien thi dau tien
	system("cls");
	printf("\n\t***Store Management System Using C***\n");
	printf("\n\tCHOOSE YOUR ROLE\n");
	printf("\t===============\n");
	printf("\t[1].Admin\n");
	printf("\t[2].Client\n");
	printf("\t[0].Thoat.\n");
	printf("\t===============\n");
}

void loginAdmin(){//ADMIN
	system("cls");
	struct login logAdmin;
	char checkEmail[] =  "admin@email.com";//tai khoan admin
	char checkPass[] = "12345";//Mat khau admin
	char testPass;
	do{//Neu nguoi dung dang nhap sai se duoc dang nhap lai
	printf("\n\t\t***LOGIN ADMIN***\n"); 
	fflush(stdin);	 
	printf("\t====================================\n");
	printf("\tEmail(admin@email.com): ");//Yeu cau nguoi dung nhap tai khoan
	fgets(logAdmin.Email,sizeof(logAdmin.Email),stdin);
	logAdmin.Email[strcspn(logAdmin.Email, "\n")] = '\0';
	printf("\tPassword(12345): ");;//yeu cau nguoi dung nhap mat khau
	fgets(logAdmin.Password,sizeof(logAdmin.Password),stdin);
	logAdmin.Password[strcspn(logAdmin.Password, "\n")] = '\0';
	printf("\t====================================\n");
	//Kiem tra tai khoan va mat khau da dung chua?

	if(strcmp(logAdmin.Email,checkEmail) ==0 && strcmp(logAdmin.Password,checkPass) == 0){
		printf("\tBan da dang nhap thanh cong\n");
	}else{
		printf("\tDang nhap khong thanh cong\n");
	}
		
}while(strcmp(logAdmin.Email,checkEmail) !=0 && strcmp(logAdmin.Password,checkPass) != 0);//while

}
void MenuStore(){//Menu store
	printf("\n\t***Store Management System Using C***\n");
	printf("\n\t\tStore Management\n");
	printf("\t=====================================\n");
	printf("\t[1].Hien thi danh sach danh muc\n");
	printf("\t[2].Them danh muc\n");
	printf("\t[3].Sua danh muc\n");
	printf("\t[4].Xoa danh muc\n");
	printf("\t[5].Tim kiem danh muc theo ten\n");
	printf("\t[6].Sap xep danh muc theo ten\n");
	printf("\t[7].San pham\n");
	printf("\t[0].Thoat\n");
	printf("\t=====================================\n");
}

void MenuProduct(){//Menu san pham
	printf("\n\t***Product Management System Using C***\n");
	printf("\n\t\tProduct Management\n");
	printf("\t=====================================\n");
	printf("\t[1].Hien thi danh sach san pham\n");
	printf("\t[2].Them san pham\n");
	printf("\t[3].Sua san pham\n");
	printf("\t[4].Xoa san pham\n");
	printf("\t[5].Tim kiem san pham theo ten\n");
	printf("\t[6].Sap xep san pham theo gia\n");
	printf("\t[7].Loc san pham\n");
	printf("\t[8].Quay lai Store\n");
	printf("\t[0].Thoat\n");
	printf("\t=====================================\n");
}

void HienThiStore(Store stores[], int *n){	
    printf("\n\t\t***ALL CATEGORY LISH***\n");
    printf("|==========|===============================================|\n");
    printf("|    ID    |              Category Name                    |\n");
    printf("|==========|===============================================|\n");
	int i;
    for (i = 0; i < *n; i++) {
        printf("| %4d     | %-45s |\n", 
               stores[i].id, stores[i].Name);
        printf("|----------|-----------------------------------------------|\n");
    }
}

void HienThiProduct(Product products[], int *p){
    printf("\n\t***ALL PRODUCT***\n");
    printf("|==========|===============================================|==========|==================|\n");
    printf("|    ID    |                      Name                     | Quality  |      Price       |\n");
    printf("|==========|===============================================|==========|==================|\n");
    int i;
    for (i = 0; i <*p; i++) {
        printf("| %4d     | %-45s | %4d     |%12d VND  |\n", 
               products[i].id, products[i].Name, products[i].Quality, products[i].Price);
        printf("|----------|-----------------------------------------------|----------|------------------|\n");
    }
}
void ThemStore(Store stores[], int *n, int deletedIds[], int *deletedCount) {
    printf("\n\t\t***ADD CATEGORY***\n");
    int SoLuong;
    printf("\tNhap so luong danh muc muon them: ");
    scanf("%d", &SoLuong);
    getchar();

    int maxNameLength = 45; // Ðo dai toi da cua ten danh muc
    int i;
    for (i = 0; i < SoLuong; i++) {
        int id;
        if (*deletedCount > 0) {
            id = deletedIds[--(*deletedCount)];
        } else {
            id = *n + 1;
        }

        char tempName[45]; // Du dinh kiem tra chuoi dài
        while (1) {
            printf("\tMoi ban them danh muc moi (%d/%d): ", i + 1, SoLuong);
            fgets(tempName, sizeof(tempName), stdin);

            // Kiem tra do dai nhap vào
            if (strcspn(tempName, "\n") == sizeof(tempName) - 1) {
                printf("\tLoi: Ten danh muc qua dai (toi da %d ky tu). Vui long nhap lai.\n", maxNameLength);
                while (getchar() != '\n'); // Xóa phan con lai trong bo dem
                continue;
            }

            tempName[strcspn(tempName, "\n")] = '\0';
            

            if (strlen(tempName) == 0) {
                printf("\tLoi: Ten danh muc khong duoc de trong. Vui long nhap lai.\n");
                continue;
            }

            if (strlen(tempName) > maxNameLength) {
                printf("\tLoi: Ten danh muc qua dai (toi da %d ky tu). Vui long nhap lai.\n", maxNameLength);
                continue;
            }

            // Kiem tra trung ten
            int isDuplicate = 0;
            int j;
            for ( j = 0; j < *n; j++) {
                if (stores[j].isDeleted == 0 && strcmp(stores[j].Name,tempName) == 0) {
                    isDuplicate = 1;
                    break;
                }
            }

            if (isDuplicate) {
                printf("\tLoi: Danh muc '%s' da ton tai. Vui long nhap lai.\n",tempName);
                continue;
            }

            strcpy(stores[*n].Name,tempName);
            break;
        }

        stores[*n].id = id;
        stores[*n].isDeleted = 0;
        (*n)++;
    }
    printf("\tThem thanh cong!\n");
}


void updateStore(Store stores[], int n){//Sua 
	printf("\n\t\t***UPDATE CATEGORY***\n");
	int position;
	printf("\tMoi ban nhap vao vi tri muon sua:");
	scanf("%d", &position);
	int findIndex=-1;
	int i;
	for( i=0;i<n;i++){
		if(stores[i].id==position){
			findIndex =i;
			break;
		}
	} 
	if(findIndex==-1){
		printf("\tKhong tim thay danh muc de sua\n ");
	}else{
		getchar();
        int maxNameLength = 45; // Do dai toi da cua ten danh muc
        char tempName[100]; // Dung du nhap ten moi

        while (1) {
            printf("\tMoi ban nhap vao ten danh muc moi: ");
            fgets(tempName, sizeof(tempName), stdin);

            // Lo?i b? ký t? newline n?u có
            tempName[strcspn(tempName, "\n")] = '\0';

            // Ki?m tra n?u tên nh?p vào là r?ng
            if (strlen(tempName) == 0) {
                printf("\tLoi: Ten danh muc khong duoc de trong. Vui long nhap lai.\n");
                continue;
            }

            // Kiem tra tên quá dài
            if (strlen(tempName) > maxNameLength) {
                printf("\tLoi: Ten danh muc qua dai (toi da %d ky tu). Vui long nhap lai.\n", maxNameLength);
                continue;
            }

            // Ki?m tra trùng tên v?i các danh m?c khác
            int isDuplicate = 0;
            int j;
            for ( j = 0; j < n; j++) {
                if (j != findIndex && stores[j].isDeleted == 0 && strcmp(stores[j].Name, tempName) == 0) {
                    isDuplicate = 1;
                    break;
                }
            }

            if (isDuplicate) {
                printf("\tLoi: Danh muc '%s' da ton tai. Vui long nhap lai.\n", tempName);
                continue;
            }

            // N?u tên h?p l?, c?p nh?t tên danh m?c
            strcpy(stores[findIndex].Name, tempName);
            break;
        }

        printf("\tSua thanh cong!\n");
    }
}

void deleteStore(Store stores[],  int *n,int deletedIds[], int *deletedCount){
	printf("\n\t\t***DELETE CATEGORY***\n");
	int position;
	printf("\tMoi ban nhap vao vi tri muon xoa:");
	scanf("%d", &position);
	int findIndex=-1;
	int i;
	for(i=0;i<*n;i++){
		if(stores[i].id==position){
			findIndex =i;
			break;
		}
	} 
	if(findIndex==-1){
		printf("\tKhong tim thay danh muc de xoa");
	}else{
		int choice;
		YesOrNo(&choice);
		if(choice==1){
			stores[findIndex].isDeleted = 1;
			deletedIds[(*deletedCount)++] = stores[findIndex].id;
			int i;
			for(i=findIndex;i<*n;i++){
				stores[i]=stores[i+1];
			}
			(*n)--;
		}else{
			return;
		}
		printf("\n\tXoa thanh cong!\n");
	}
}

// Chuyen chuoi sang chu thuong
void toLowerCase(char str[]) {
	int i;
    for ( i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Ham tim kiem danh mc theo tên
void FindByName(Store stores[], int n) {
    char search[100], tempName[100];
    int found = 0;

    getchar(); // Xoa ky tu xuong dong trong bo dem
    printf("\n\t\t***ALL CATEGORY LISH***\n");
    printf("\n\tNhap ten danh muc muon tim: ");
    fgets(search, 100, stdin);
    search[strcspn(search, "\n")] = '\0'; // Loai bo ky tu xuong dong
    toLowerCase(search); // Chuyen chuoi tim kiem sang chu thuong

    printf("\n\tKet qua tim kiem:\n");
    printf("|==========|===============================================|\n");
    printf("|    ID    |              Category Name                    |\n");
    printf("|==========|===============================================|\n");
	int i;
    for (i = 0; i < n; i++) {
        strcpy(tempName, stores[i].Name); // Sao chep ten danh muc
        toLowerCase(tempName);           // Chuyen ten danh muc sang chu thuong

        if (strstr(tempName, search) != NULL) { // Tim kiem chuoi con
            printf("| %4d     | %-45s |\n", stores[i].id, stores[i].Name);
            found = 1;
        }
    }

    if (!found) {
        printf("| Khong tim thay danh muc nao                              | \n");
    }

    printf("|----------|-----------------------------------------------|\n");
}


void SoftStoreByName1(Store stores[], int *n){
	printf("\n\t\t***SOFT CATEGORY BY NAME***\n");
	int i;
	for(i=0;i<*n-1;i++){
		int j;
		for(j=i+1;j<*n;j++){
			if(strcmp(stores[i].Name,stores[j].Name)<0){
				Store temp=stores[i];
				stores[i]=stores[j];
				stores[j]=temp;
			}
		}
	}
	printf("\tSap xep thanh cong!");
}

void SoftStoreByName2(Store stores[], int *n){
	printf("\n\t\t***SOFT CATEGORY BY NAME***\n");
	int i;
	for(i=0;i<*n-1;i++){
		int j;
		for(j=i+1;j<*n;j++){
			if(strcmp(stores[i].Name,stores[j].Name)>0){
				Store temp=stores[i];
				stores[i]=stores[j];
				stores[j]=temp;
			}
		}
	}
	printf("\tSap xep thanh cong!");
}

void loadStoresFromFile(Store stores[], int *n) {
    FILE *file = fopen("stores.dat","rb"); // M? file d? d?c
    if (file == NULL) {
        printf("\tLoi: Khong the mo file de doc.\n");
    } 
	Store ReadStore[100];
	*n = fread(ReadStore, sizeof(Store),100,file);
	int i;
	for(i=0 ;i < *n;i++){
		stores[i] = ReadStore[i];
	}
	printf("\tDu lieu da duoc tai ve thanh cong!\n");
    fclose(file); // Ðóng file
}

void saveStoresToFile(Store stores[], int *n) {
			
			//Mo FILE
			FILE *file;
			file = fopen("stores.dat","wb");//LUU FILE
			
			//Thao tac voi FILE
			if(file == NULL){//Kiem tra FIle
				printf("Khong mo  duoc FILE\n");
			}
			fwrite(stores, sizeof(Store), *n, file);
			printf("Luu FILE thanh cong\n");
			//Dong FILE
			fclose(file);	
}
