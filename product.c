#include <stdio.h>
#include "product.h"
/*
typedef struct{
    char name[40];
    float weight; //in killo
    int price;
    float rating; //0<=rating<=5
    int rating_count;
}product;
*/
int newProduct(product* product){
    printf("상품명은?: ");
    //scanf("%[^\n]s",s->name);
   // fflush(stdin);
    scanf("%s",product->name);
    //getchar();
    //fgets(product->name,sizeof(product->name),stdin);
   // fflush(stdin); // \n 버퍼 방지

    printf("무게 (kg) : ");
    scanf("%f",&product->weight);
    printf("가격은? (won) ");
    scanf("%d",&product->price);
    product->rating = 0;
    product->rating_count=0;

    //printf("rating (0 ~ 5)? ");
    //scanf("%d",&product->rating);
    
    return 1;
}

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
int updateProduct(product* product){
    printf("상품명은?: ");
    //scanf("%[^\n]s",s->name);
    //fflush(stdin);
    //fgets(product->name,sizeof(product->name),stdin);
    scanf("%s",product->name);
   // fflush(stdin); // \n 버퍼 방지
    //getchar();
    printf("무게 (kg): ");
    scanf("%f",&product->weight);
    printf("가격은? (won) ");
    scanf("%d",&product->price);
    product->rating = 0;
    product->rating_count=0;

    //printf("rating (0 ~ 5)? ");
    //scanf("%d",&product->rating);
    
    return 1;
}
int selectMenu(){
    int menu;
    printf("\n*** product ***\n");
    printf("1. 메뉴조회\n");
    printf("2. 메뉴추가\n");
    printf("3. 메뉴수정\n");
    printf("4. 메뉴삭제\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int main(){
    product item;
    item.price = -1;
    while(1){
        int opt = selectMenu();
        if(opt ==0 ) return 0;
        else if(opt ==1 ){ 
            int i = readProduct(item);
        }
        else if(opt ==2 ){ 
            int i = newProduct(&item);
        }
        else if(opt ==3){ 
            int i = updateProduct(&item);
        }
        else if(opt ==4){ 
            int i = deleteProduct(&item);
        }
    }


    return 0;

}
