#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct BookingDetails 
{
	char name[20];
	long int roll_no;
	int status;
	int quantity[5];
	const char* item[5];
};
void MainMenu(struct BookingDetails);
void ExitProgram()
{
	printf("Thank you!");
	exit(0);
}

void ListItems(struct BookingDetails obj)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("[%d] %s\n", i + 1, obj.item[i]);
	}
	return;
}

void PostBooking(struct BookingDetails obj, int index)
{
start:
	system("cls");
	printf("Availabe Quantity of %s is: %d\n", obj.item[index], obj.quantity[index]);
	int q;
	printf("Enter no. of %s you want: ", obj.item[index]);
	scanf("%d", &q);
	if (q > obj.quantity[index])
	{
		printf("Invalid Input");
		printf("do you want to re-enter amount ?\n1.Yes\n2.No\n");
		int y;
		scanf("%d", &y);
		if (y == 1) {
			system("cls");
			goto start;
		}
		else
			ExitProgram();
	}
	else
	{
		obj.quantity[index] -= q;
		printf("Enter your roll no: ");
		scanf("%d", &obj.roll_no);
		fflush(stdin);
		printf("Enter your name: ");
		scanf("%[^\n]%*c", &obj.name); 
		obj.status = 1;

		// filing;
		FILE* fptr;
		fptr = fopen("Booking Details.txt", "a");
		//fprintf(fptr, "%s\n%d\n%d\n%d\n\n", obj.name, obj.roll_no, obj.status, obj.item[index], obj.quantity[index]);
		fprintf(fptr, "Name: %s\n", obj.name);
		fprintf(fptr, "roll no: %ld\n", obj.roll_no);
		fprintf(fptr, "status: %d\n", obj.status);
		fprintf(fptr, "item: %s\n", obj.item[index]);
		fprintf(fptr, "quantity: %d\n", obj.quantity[index]);
		fclose(fptr);
		printf("Your booking has been done!\n\n");
		printf("press 1 to go to main menu or else press 0 to exit program...");
		int x;
		scanf("%d", &x);
		if(x==1)
			MainMenu(obj);
		else
			ExitProgram();
	}

}

void BookItems(struct BookingDetails obj)
{ 
	ListItems(obj);
	printf("\nWhich item you want to select ?\n");
	int i;
	scanf("%d", &i);
	switch (i)
	{
		case 1:
		{
			PostBooking(obj, i - 1);
			break;
		}
		case 2:
		{
			PostBooking(obj, i - 1);
			break;
		}
		case 3:
		{
			PostBooking(obj, i - 1);
			break;
		}
		case 4:
		{
			PostBooking(obj, i - 1);
			break;
		}
		case 5:
		{
			PostBooking(obj, i - 1);
			break;
		}
		default:
			ExitProgram();
	}
}

void CancelBooking(struct BookingDetails obj)
{
	int r_no, var, count = 0, temp;
	char no[10] = "roll no: ";
	int temp_quantity = 0;
	printf("Enter your roll no: ");
	scanf("%d", &r_no);
	FILE* fptr;
	fptr = fopen("Booking Details.txt", "r+");
	while (fptr != NULL)
	{
		
	}
}

void MainMenu(struct BookingDetails obj)
{
	start:
	printf("SPORTS RESERVATION SYSTEM\n");
	printf("[1] List Items\n[2] Book Items\n[3] Cancel Booking\n[4] Exit\n");
	int choice = 0;
	scanf("%d", &choice);
	switch (choice)
	{
		case 1:
			ListItems(obj);
			break;
		case 2:
			BookItems(obj);
			break;
		case 3:
			CancelBooking(obj);
			break;
		case 4:
			ExitProgram();
			break;
		default:
			ExitProgram();
	}
	printf("press 1 if you want to book any item or else press 0...");
	int i;
	scanf_s("%d", &i);
	if (i == 1)
	{
		system("cls");
		goto start;
	}
	else
	{
		ExitProgram();
	}
}

void InitializeStructure(struct BookingDetails* obj)
{	
	obj->item[0] = "football";
	obj->item[1] = "bat";
	obj->item[2] = "ball";
	obj->item[3] = "badminton";
	obj->item[4] = "basketball";
	
	obj->quantity[0] = 5;
	obj->quantity[1] = 3;
	obj->quantity[2] = 10;
	obj->quantity[3] = 3;
	obj->quantity[4] = 4;
	
}

int main()
{
	struct BookingDetails obj;
	InitializeStructure(&obj);
	MainMenu(obj);
}
