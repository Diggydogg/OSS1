
//manage.h 
/*
typedef struct product{
	char name[40];
        float weight;	
	int price;
	float rating;
	int rating_count;

}product;

int newProduct( product* product);
int readProduct( product product);
int deleteProduct( product *product);
int updateProduct(product* product);
//file IO
int loadProduct( product* product[],int count); //load file
int saveProduct( product* product[],int count); // save file
//search_func
int listProduct( product* product[],int count); // read - all list product
void snameProduct( product* product[],int count); // search - by name _specific product 
void sratingProduct( product*product[], int count,int min_rating); // search by rating product, (ex: over min_rating)
void manyrProduct(product[],int count); //sort by number of rating count
*/
typedef struct{
    char name[40];
    int price;
    float weight;
    float rating;
    int rating_count;


}product;

void listproduct(product *s[], int count);
int readProduct(product product);
int addproduct(product *s);
int updateproduct(product *s);
int selectDataNo(product* s[], int count);
int deleteProduct(product* product);
void listproduct(product *s[], int count);
int selectproduct();
void saveProduct(product* s[],int count);
int loadProduct(product *s[]);
int find_Product(product *s[],int count);
