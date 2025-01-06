#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
 
int main(int argc, char *argv[]) {
	int choice;
	int n=3;
	Store stores[100]={
	{1,"Do an"},
	{2,"Do uong"},
	{3,"Quan ao"},
};
	int deletedIds[100];
    int deletedCount =0;
    loadStoresFromFile(stores, &n);//luufile
do{	
	//Hien thi Menu dang nhap tai khoan , mat khau
	system("cls");
	BeginStore();
	choicee(&choice);
switch(choice){

	case 0://Thoat khoi chuong trinh
	printf("\n\tBan da thoat khoi login\n");
	break;
	
	case 1://login admin
		system("cls");
//		loginAdmin();
		do{
			MenuStore();
		    choicee(&choice);
		    switch(choice){
			case 1://Hienthi
				system("cls");
			    HienThiStore(stores, &n);
			    Back(&choice);
			    if(choice==1){
			    	system("cls");
			    	continue;
				}else{
					saveStoresToFile(stores, &n);//Luu khi thoat
					return 0;
				}
				break;
				
			case 2://Them
				system("cls");
				HienThiStore(stores, &n);
				ThemStore(stores, &n, deletedIds, &deletedCount);
				saveStoresToFile(stores, &n);//Luu khi thay doi
				Back(&choice);
			    if(choice==1){
			    	system("cls");
			    	continue;
				}else{
					saveStoresToFile(stores, &n);//Luu khi thoat
					return 0;
				}
				break;
				
			case 3://Sua
				system("cls");
				HienThiStore(stores, &n);
				updateStore(stores, n);
				saveStoresToFile(stores, &n);//Luu khi thay doi
				Back(&choice);
			    if(choice==1){
			    	system("cls");
			    	continue;
				}else{
					saveStoresToFile(stores, &n);//Luu khi thoat
					return 0;
				}
				break;
				
			case 4://Xoa
				system("cls");
				HienThiStore(stores, &n);
				deleteStore(stores, &n, deletedIds, &deletedCount);
				saveStoresToFile(stores, &n);//Luu khi thay doi
				Back(&choice);
			    if(choice==1){
			    	system("cls");
			    	continue;
				}else{
					saveStoresToFile(stores, &n);//Luu khi thoat
					return 0;
				}
				break;
				
			case 5://Tim kiem theo ten
			system("cls");
				FindByName(stores,&n);
				Back(&choice);
			    if(choice==1){
			    	system("cls");
			    	continue;
				}else{
					return 0;
				}
				break;
			
			case 6://Sap xep
				system("cls");
				HienThiStore(stores, &n);
				ChonThuTu(&choice);
				if(choice==1){
					SoftStoreByName1(stores, &n);
				}else{
					SoftStoreByName2(stores, &n);
				}
				Back(&choice);
			    if(choice==1){
			    	system("cls");
			    	continue;
				}else{
					return 0;
				}
				break;	
			
			case 7:
				do{
					system("cls");
					MenuProduct();
					choicee(&choice);
		            switch(choice){
		            	case 1:
		            		break;
					}
				}while(choice!=0);
		    }

		}while(choice!=0);
		break;
	
	case 2://Client
		break;	
}//switch
	
		
}while(choice!=0);			
	return 0;
}
