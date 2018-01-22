#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 10

typedef struct{
	char type; // 0 = Fried Chicken, 1 = French Fries
	int amount; // Pieces or weight
	char unit; // 0 = Pieces , 1 = Grams
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

item newItem(char a,int b, char c){
	item i;
	i.type = a;
	i.amount = b;
	i.unit = c;
	return i;
}

void produce(item *i){
	while ((first + 1) % BUFFER_SIZE == last){
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
}

item *consume(){
	item *i = malloc(sizeof(item));
	while (first == last){
	}
	memcpy(i, &buffer[last],sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	return i;
}

void print(item *i){
	if(i == NULL) return;
	printf("%s %d %s\n", i->type, i->amount, i->unit);
}
int main(){
	item item1, item2;
	item1 = newItem(0,5,0);
	item2 = newItem(1,200,1);
	produce(&item1);
	produce(&item2);
	print((consume()));
	return 0;
}
