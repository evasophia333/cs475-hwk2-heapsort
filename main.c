#include <stdio.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEE 6

int main()
{
	struct Employee person[MAX_EMPLOYEE];
	int numEmployee = 0;
	int cont = 0;
	char nextRound;
	int inputinvalid = 0; 
	while(cont==0){
	printf("Name: ");
	scanf("%s", person[numEmployee].name);
	printf("Salary: ");
	scanf("%d", &person[numEmployee].salary);
	numEmployee++;
		if(numEmployee<MAX_EMPLOYEE){ //-1 because i starts at 0
		//Keep asking for input otherwise finish
		printf("Enter another user (y/n)? ");
		scanf(" %c", &nextRound);
				if(nextRound == 'y') {
					cont = 0;
				}else if(nextRound == 'n') {
					cont = 1;
					inputinvalid = 1; //get out of the loop
					break;
				}else {
					printf("Invalid input...try again!\n");
				}
		}else{
			printf("MAX NUMBER OF EMPLOYEE'S REACHED");
			break;
		}
	
	if(inputinvalid==1){
		break; //get out of the other loop
	}
	}
	printList(person,numEmployee);
	heapify(person,2,numEmployee);
	printList(person,numEmployee);

	return 0;
}
