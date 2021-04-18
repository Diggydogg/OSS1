#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manage.h"

int main(){
    int menu=0,count =0;
    
    #ifdef DEBUG
      printf("DEBUG MODE\n");
  #endif
    // 이렇게 넣으셔야 합니다!!
    
    product *sp[20];
    int index =0;
    index = loadProduct(sp);   
    while(1){
        menu = selectproduct();
        if(menu==0) break;
        if(menu==1||menu==3||menu==4){
            if(count==0) continue;
        }
        if(menu==1){
            if(count > 0)
                listproduct(sp,index);
            else printf("no data\n");
        }
        else if(menu == 2) {
            sp[index]=(product*)malloc(sizeof(product)); 
            count += addproduct(sp[index++]);
            printf("added\n");
        }
        else if(menu == 3) {
            int no = selectDataNo(sp,index);
            if(no ==0){
                printf("==> canceled\n");
                continue;
            }
            updateproduct(sp[no-1]);
            printf("updated!\n");
            
        }
        else if(menu == 4) {
            int no = selectDataNo(sp, index);
            if(no == 0){
            printf("=> canceled!\n");
            continue;
            }
            int deleteok;
            printf("Are you sure ?(to delete :1)");
            scanf("%d", &deleteok);
            if(deleteok == 1){
                if(sp[no-1]) free(sp[no-1]);
                sp[no-1]=NULL;
                count--;
                printf("removed\n");
            
            } 
        }
	else if(menu==5){
		saveProduct(sp,index);
	}
	else if(menu==6){
            find_Product(sp,index);
        }
    }


    /*
    int isdel = deleteScore(&s1);
    if(isdel ==1){
        printf("==> deleted");
    }*/
    for(int i =0;i<20;i++){
        if(sp[i]!=NULL){
            free(sp[i]);
        }
    }
    printf("exit");
    return 0;
}
