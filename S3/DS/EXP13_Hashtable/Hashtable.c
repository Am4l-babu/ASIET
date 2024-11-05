#include <stdio.h>
#include <stdlib.h>


#define SIZE 20

typedef struct DataItem {
   int data;   
   int key;
}DataItem;

DataItem* hashArray[SIZE]; 
DataItem* dummyItem;
DataItem* item;

int hashCode(int key) {
   return key % SIZE;
}

DataItem *search(int key) {

   int hashIndex = hashCode(key);  
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex]; 
			
     
      ++hashIndex;
      hashIndex %= SIZE;
   }        
	
   return NULL;        
}

void insert(int key,int data) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;  
   item->key = key;

   
   int hashIndex = hashCode(key);

   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      
      ++hashIndex;
		
      
      hashIndex %= SIZE;
   }
	
   hashArray[hashIndex] = item;
}

DataItem* delete(struct DataItem* item) {
   int key = item->key;

   
   int hashIndex = hashCode(key);

   
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key) {
         struct DataItem* temp = hashArray[hashIndex]; 
			
         
         hashArray[hashIndex] = dummyItem; 
         return temp;
      }
		
      
      ++hashIndex;
		
      
      hashIndex %= SIZE;
   }      
	
   return NULL;        
}

void display() {
   int i = 0;
	
   for(i = 0; i<SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->data);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}
void displayMenu() {
    printf("Menu:\n");
    printf("1. Insert Element\n");
    printf("2. Remove Element\n");
    printf("3. Search\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    
}

int main() {
   dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
   dummyItem->data = -1;  
   dummyItem->key = -1; 
   int data,key;

    while (1) {
    	int choice;
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter The key: ");
            scanf("%d", &key);
            printf("Enter The element to be inserted: ");
            scanf("%d", &data);
            insert(key, data);
            break;
        case 2:
            printf("Enter the Key to be deletd: ");
            scanf("%d",&key);
            item=search(key);
            delete(item);
            break;
        case 3:
            printf("Enter the Key to be searched: ");
            scanf("%d",&key);
            item=search(key);
            if(item != NULL) {
      	    printf("Element found: %d\n", item->data);
  	    } else {
      	    printf("Element not found\n");
   	    }
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
