

#define NUMOFITEMS	2
#define FILENAME	"lab14_data.bin"

#include <stdio.h>
#include <string.h>






void flushInputBuffer();
typedef struct {
	int id;
	char name[50];
	double price;
} item_t;

typedef union {
	int phone;
	char mail[25];
}contactInfo_t;

typedef struct {
	item_t item;
	contactInfo_t	contInfo;
}itemWithCont_t;


item_t *getItems(item_t items[], int size);
void printItem(item_t item);
int writeItems(char filename[],item_t items[], int size);
item_t readAnItem(FILE *file);
void contactInfoAdder(item_t items[], int size, itemWithCont_t contacts[]);


void
printItem(item_t item)
{
	printf("Id:     %d\n", item.id);
	printf("Name:   %s\n", item.name);
	printf("Price:  %.2f\n", item.price);
}
void flushInputBuffer();
void
flushInputBuffer()
{
	char tmp;
	do
		scanf("%c",&tmp);
	while(tmp!='\n');
}

int
writeItems(char filename[],item_t items[], int size) {
	int result;
	FILE *file;

	file = fopen(filename,"ab");
	
	result = fwrite(items, sizeof(item_t), size, file);

	fclose(file);
	
	return result;
}

item_t
readAnItem(FILE *file)
{
	item_t item;
	if(file == NULL) {
		/* file not found */
		item.id = -1;
		return item;
	}
	
	if(1 == fread(&item,sizeof(item_t),1,file))
		return item;
	/* cannot read an item, return an item with negative id */
	item.id = -1;
	return item;
}

item_t
*getItems(item_t items[], int size) {
	int i;
	for(i=0;i<size;++i) {
		printf("Id =>");
		scanf("%d",&items[i].id);
		flushInputBuffer();
		
		printf("Name => ");
		gets(items[i].name);

		printf("Price =>");
		scanf("%lf", &items[i].price);
	}
	return items;
}

void
contactInfoAdder(item_t items[], int size, itemWithCont_t contacts[])
{
	int i,
	userInput;
	
	for(i=0;i<size;++i) {
		contacts[i].item = items[i];
		/*
		printf("Contacts: %s\n", items[i].name);
		printf("[1] - Add Phone\n");
		printf("[2] - Add Mail\n");		
		
		
		scanf("%d", &userInput);*/
		if(items[i].id % 2) {
			printf("Enter the phone for %s => ", items[i].name);
			scanf("%d",&contacts[i].contInfo.phone);
			printf("\n");			
		}
		else {
			printf("Enter a mail for %s => ", items[i].name);
			flushInputBuffer();
			gets(contacts[i].contInfo.mail);
			printf("\n");
		}
	}
}

void
printItemWithContactInfo(itemWithCont_t itemsWithCont)
{
	printItem(itemsWithCont.item);
	if(itemsWithCont.item.id % 2)
		printf("Phone number: %d\n", itemsWithCont.contInfo.phone);
	else
		printf("Mail: %s\n", itemsWithCont.contInfo.mail);
	
}
int
main(void)
{
	item_t	items[NUMOFITEMS],
		testItem;
	int i,j;
	FILE *file;
	itemWithCont_t	itemWithContacts[NUMOFITEMS];
	

	for(j=0;j<3; ++j) {
		getItems(items, NUMOFITEMS);
	
		for(i=0;i<NUMOFITEMS;++i)
			printItem(items[i]);

		if(NUMOFITEMS == writeItems(FILENAME, items, NUMOFITEMS))
			printf("Succesfully wrote data to file\n");
		else
			printf("Could not write data to file\n");	
	}
	
	printf("\nReading from file:\n");
	file = fopen(FILENAME, "rb");

	for(i=0;i<3*NUMOFITEMS; ++i) {
		testItem = readAnItem(file);

		if(testItem.id < 0)
			printf("Could not read an item from file\n");
		else
			printItem(testItem);
	}
	/* bonus */
	contactInfoAdder(items, NUMOFITEMS, itemWithContacts);
	for(i=0;i<NUMOFITEMS;++i)
		printItemWithContactInfo(itemWithContacts[i]);
	return 0;
}




