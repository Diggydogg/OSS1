#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manage.h"
/*
typedef struct{
    char name[40];
    int price;
    float weight;
    float rating;
    int rating_count;
    

}product;*/
void listproduct(product *s[], int count);
int readProduct(product product){
    //pritnf("===== 아이템 ==========");
    if(product.price<0) return 0;
    printf(" 상품명 : %s  가격 : %.1d (won) 무게 : %.1f (kg)  리뷰 점수  : ",product.name,product.price,product.weight);
    for(int i =0;i<product.rating;i++) {
        printf("*");
    }
    printf(" 리뷰 수 : %d\n",product.rating_count);
    return 1;
}
int addproduct(product *s){
    printf("상품명은?: ");
    scanf("%s",s->name);
    printf("무게 (kg) : ");
    
    scanf("%f",&s->weight);
    printf("가격은? ");
    scanf("%d",&s->price);

    s->rating = 0;
    s->rating_count=0;
    

    return 1;
}
int updateproduct(product *s){
    printf("상품명은?: ");
    scanf("%s",s->name);
    printf("무게 (kg) : ");
    scanf("%f",&s->weight);
    printf("가격은? ");
    scanf("%d",&s->price);

    s->rating = 0;
    s->rating_count=0;
    

    return 1;
}
int selectDataNo(product* s[], int count){
    int no;
    listproduct(s, count);
    printf("no. ? (cancel : 0)? ");
    scanf("%d",&no);
    return no;
}
int deleteProduct(product* product){
    printf("are you sure? to delete this data press Y,y \n");
    char input;
    //fflush(stdin);
    getchar();
    scanf("%c",&input);
    if(input!='Y'&&input!='y') {
        printf("canceled\n");
        return 0;
    }
    else {
        product->price = -1;
        printf("data deleted\n");
        return 0;
    }
}
void listproduct(product *s[], int count){
    printf("\n     <product>   \n");
    printf("=============================\n");
    for(int i =0;i<count;i++){
        if(s[i]==NULL)continue; // not showing deleted data
        printf("%2d ",i+1);
        readProduct(*s[i]); //
    }
    printf("\n");
}

int selectproduct(){
    int product;
    printf("\n*** product_menu_Option ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("6. 찾기\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &product);
    return product;
}
void saveProduct(product *s[] , int count){
	FILE *fp;
	fp = fopen("product.txt","wt");
	for(int i =0;i<count;i++){
	if(s[i]->price == -1) continue;
	fprintf(fp,"%s %d %f %f  %d\n",s[i]->name,s[i]->price, s[i]->weight,s[i]->rating,s[i]->rating_count);
	}
	fclose(fp);
	printf("saved!\n");

}
int loadProduct(product *s[]){
	int i= 0;
	FILE *fp;
	fp = fopen("product.txt","rt");
	if(fp==NULL) {
        printf("load fail, no \"menu.txt\" in current directory\n" );
        return 0;
    }
	for(;i<20;i++){
		s[i]=(product*)malloc(sizeof(product)); 	
		fscanf(fp,"%s",s[i]->name);
		if(feof(fp)){free(s[i]); break;}
		fscanf(fp, "%d",&s[i]->price);
		fscanf(fp,"%f",&s[i]->weight);
		fscanf(fp,"%f",&s[i]->rating);
		fscanf(fp,"%d",&s[i]->rating_count);
	}
	fclose(fp);
	printf("loaded!\n");
	return i;
}
int find_Product(product *s[],int count){
    char name[20];
    printf("Enter a name of product you wish to find : ");
   
    scanf("%s",name);
    //printf("\nno   price  type   name \n");
    //printf("=============================\n");
    for(int i =0;i<count;i++){
        if(strstr(s[i]->name,name)!=NULL&&s[i]->price>0){
            printf("%2d",i+1);
            readProduct(*s[i]);
        }
    }
    return 1;
}
/*
int main(){
    int result=0,menu=0,count =0;
    
    product *sp[20];
    int index =0;
    
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
    }


    // quoted out part
    int isdel = deleteScore(&s1);
    if(isdel ==1){
        printf("==> deleted");
    }
    printf("exit");
    return 0;
}*/
