//product
typedef struct{
    char name[40];
    float weight; //in killo
    int price;
    float rating; //0<=rating<=5
    int rating_count;
}product;
//crud
int newProduct( product* product); //creat- new product
int readProduct( product product); // read- product
int deleteProduct( product* product); //delete product 
int updateProduct( product* product); // update product
//file IO
int loadProduct( product* product[],int count); //load file
int saveProduct( product* product[],int count); // save file
//search_func
int listProduct( product* product[],int count); // read - all list product
void snameProduct( product* product[],int count); // search - by name _specific product 
void sratingProduct( product*product[], int count,int min_rating); // search by rating product, (ex: over min_rating)
void manyrProduct(product[],int count); //sort by number of rating count
