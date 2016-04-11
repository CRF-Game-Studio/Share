#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct SaleItem{
	int size;
	void (*print)(SaleItem *);
	unsigned char data[1];
};

struct Book
{
	int size;
	void (*print)(SaleItem *);
	char title[80];
	char author[30];
	char publisher[30];
	char year[5];
	double price;
};
  
struct Magazine
{
	int size;
	void (*print)(SaleItem *);
	char title[80];
	char issue[10];
	char year[5];
	char month[3];
	char publisher[30];
	double price;
};
  
struct VCD
{
	int size;
	void (*print)(SaleItem *);
	char title[80];
	char seriesTitle[80];
	char casts[60];
	char year[5];
	char producer[30];
	double price;
};

void printBook(struct SaleItem *book);
void printMagazine(struct SaleItem *magazine);
void printVCD(struct SaleItem *vcd);
void initialize(int *nItems, struct SaleItem *items[]);

void main(){
	int nItems;
	struct SaleItem *items[100];
	int i;
    
	initialize(&nItems, items);
 
	for(i=0;i<nItems;i++){
		(*items[i]->print)(items[i]);
	}
	// 請在此處撰寫一個迴圈來列印所有 nItems 個商品
	// 的內容，這個迴圈的內容應該只有一個簡單的函式
	// 呼叫，通通透過欄位 print 這個函式指標變數來呼叫，
	// 因為此時已經將所有商品抽象化看成是一致的 SaleItem 
	// 的東西了

	for (i=0; i<nItems; i++)
		free(items[i]); // 請注意此處也不需要區分資料的種類

	printf("Press enter to continue...");
	getchar();
	return;
	}

	void printBook(struct SaleItem *book)
	{
	struct Book *bPtr = (struct Book *)book;
  
	printf("Book name is %s\n", bPtr->title);
	printf("     author is %s\n", bPtr->author);
	printf("     publisher is %s\n", bPtr->publisher);
	printf("     price is %f\n\n", bPtr->price);
}

void printMagazine(struct SaleItem *magazine)
{
	struct Magazine *mPtr = (struct Magazine *)magazine;

	printf("Magazine name is %s\n", mPtr->title);
	printf("         issue is %s\n", mPtr->issue);
	printf("         month/year is %s/%s\n", mPtr->month, mPtr->year);
	printf("         publisher is %s\n", mPtr->publisher);
	printf("         price is %f\n\n", mPtr->price);
}

void printVCD(struct SaleItem *vcd){
	struct VCD *vprt=(struct VCD *)vcd;

	printf("VCD title is %s\n",vprt->title);
	printf("    seriesTitle is %s\n",vprt->seriesTitle);
	printf("    casts is %s\n",vprt->casts);
	printf("    year is %s\n",vprt->year);
	printf("    priducer is %s\n",vprt->producer);
	printf("    price is %f\n",vprt->price);
}

void initialize(int *nItems, struct SaleItem *items[])
{
	struct Book *bPtr;
	struct Magazine*mPtr;
	struct VCD *vPtr;
  
	bPtr = (struct Book*) malloc(sizeof(struct Book)); // 配置
	items[0] = (struct SaleItem *) bPtr; // 強制型態轉換
	bPtr->size = sizeof(struct Book);  // 結構佔記憶體大小
	bPtr->print = printBook;  // 指向列印本結構之函式
	strcpy(bPtr->title, "Harry Potter and the Prisoner of Azkaban ");
	strcpy(bPtr->author, "J.K. Rowling ");
	strcpy(bPtr->publisher, "Bloomsbury");
	strcpy(bPtr->year, "2000");
	bPtr->price = 7.99;

	mPtr = (struct Magazine*) 
		malloc(sizeof(struct Magazine));
	items[1] = (struct SaleItem *) mPtr;
	mPtr->size = sizeof(struct Magazine);
	mPtr->print = printMagazine;
	strcpy(mPtr->title, "Reader's Digest");
	strcpy(mPtr->issue, "---");
	strcpy(mPtr->year, "2005");
	strcpy(mPtr->month, "03");
	strcpy(mPtr->publisher, "The Reader's Digest Association, Inc.");
	mPtr->price = 13.5;

	vPtr = (struct VCD*) malloc(sizeof(struct VCD));
	items[2] = (struct SaleItem *) vPtr;
	vPtr->print = printVCD;
	strcpy(vPtr->title, "The Two Towers");
	strcpy(vPtr->seriesTitle, "Lord of the Rings");
	strcpy(vPtr->casts, "Elijah Wood, Ian Mackellen");
	strcpy(vPtr->year, "2003");
	strcpy(vPtr->producer, "Entertainment in Video");
	vPtr->price = 70;

	*nItems = 3;
}