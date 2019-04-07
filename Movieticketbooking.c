/*

*

    Author: Siddharth
    MOVIE TICKET BOOKING C PROGRAM

*

*/

//try and use ranfd function

#include<stdio.h> //header file
#include<stdlib.h>

	int movie_id[20], customer_id[20], no_seats[20], date[20], month[20], year[20], time_h[20], time_m[20], ticket_price, age[20], users, i, search_id;
	int low, high, mid, login_id, password;
	char customer_type[20], r, t, ignore, choice, p, b, c, m;
	float total_amt, total_amount[20]; //variable declaration

void new_entry()//function to take new entry
{
    	printf("\n\t\t WELCOME TO RAVANGERS MOVIE TICKET BOOKINGS");
	printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n\n\n Movie ids :\t\t\t\t\t\t DISCOUNTS:  \n\n AVENGERS - 121 \t\t\t\t\t regular customer - 10%% discount \n\n JUSTICE LEAGUE - 232 \t\t\t\t\t age < 10 - 5%% discount \n\n DEADPOOL - 313 \n\n XMEN - 424  ");//information for the customer

	//customer details
	printf("\n\n\t Enter the customer id: ");
	scanf("%d", &customer_id[i]);
	printf("\n\n\t Enter the customer type (r=regular, t=temprory): ");
	fflush(stdin); /*to remove the buffer memory*/
	scanf("%c", &customer_type[i]);
	printf("\n\n\t Enter the customer's age: ");
	scanf("%d", &age[i]);

	//movie ticket details
	printf("\n\n\t Enter the Movie id: ");
	scanf("%d", &movie_id[i]);
	printf("\n\n\t Enter the show's date in dd/mm/yyyy: ");
	scanf("%d%c%d%c%d", &date[i],&ignore, &month[i], &ignore ,&year[i]);
	printf("\n\n\t Enter the show's timing in hh:mm : ");
	scanf("%d%c%d", &time_h[i], &ignore, &time_m[i]);
	printf("\n\n\t Enter the number of seats: ");
	scanf("%d", &no_seats[i]);
	printf("\n\n  The ticket price is Rs 100 ");
	getch();
	
	printf("\n\n\t Enter\n\n\t 'p' to print ticket\\n\n\t 'c' to see customer details");
	printf("\n\n\t Enter :  ");
	fflush(stdin);
	scanf("%c", &choice);
	system("cls");

	switch(choice)
		{
			//printing ticket
			case 'p':
                       		ticket();
				getch();
				break;

			//printing customer details
			case 'c':
				printf("\n\tcustomer id: %d", customer_id[i]);
				printf("\n\tcustomer type: %c", customer_type[i]);
				printf("customer age: %d", age[i]);
				getch();
				break;

			//invalid input
			default :
				printf("\n\n\t INVALID INPUT");
				getch();
		}

void search()//searching functions
{
	printf("\nEnter the customer id to search the details:");
	scanf("%d", &search_id);

	low=0;
	high=users-1;

	while(low<=high)
	{
		mid=(high+ low)/2;

		if(customer_id[mid]=search_id)
		{
			printf("\n\nSEARCHED CUSTOMER DETAILS\n");
			printf("\n\tcustomer id: %d", customer_id[mid]);
			printf("\n\tcustomer type: %c", customer_type[mid]);
			printf("\n\tcustomer age: %d", age[mid]);

			printf("\n\nMOVIE DETAILS OF THE SEARCHED CUSTOMER");
			printf("\n\tMovie id: %d", movie_id[mid]);
			printf("\n\tMovie Date=%d/%d/%d", date[mid], month[mid], year[mid]);
			printf("\n\tMovie Time=%d:%d",time_h[mid], time_m[mid]);
			printf("\n\tNumber of seats=%d", no_seats[mid]);
			printf("\n\tTotal amount= %.2f", total_amount[mid]);
			getch();
			breal;

		}
		else if(customer_id[mid]<search_id)
		{
			low=mid+1;
		}
		else if(customer_id[mid]>search_id)
		{
			high=mid-1;
		}
	}
}


void ticket()//function of printing ticket
{
	printf("\n\n\t\t ____________________________________");
	printf("\n\t\t| Movie id: %d                       |", movie_id[i]);
	printf("\n\t\t| customer id: %d     customer type: %c |", customer_id[i], customer_type[i]);
	printf("\n\t\t| Date=%d/%d/%d   Time=%d:%d        |", date[i], month[i], year[i],time_h[i], time_m[i]);
	printf("\n\t\t| No. of seats=%d   Ticket price=100   |", no_seats[i], ticket_price);
	printf("\n\t\t| Total amount= %.2f                |", total_amount[i]);
	printf("\n\t\t|           Enjoy your show           |");
	printf("\n\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	printf("\n\n\t Enter\n\n\t 'e' to edit\n\n\t 'o' to exit");
	printf("\n\n\t Enter :  ");
	fflush(stdin);
	scanf("%c", &choice);
	switch(choice)
	{	
		case 'o':
			exit(0);
			break;
		case 'e':
			//editing function
			break;
		default :
			printf("\n\n\t INVALID INPUT");
			getch();
	}		
}		


void calculation()//function to calculate ticket price
{

	if(age<10 && customer_type=='r' )
	{
		total_amt=no_seats[i]*85;
	}
	else if(age<10 && customer_type=='t')
	{
		total_amt=95*no_seats[i];
	}
	else if(age>=10 && customer_type=='r' )
	{
		total_amt=90*no_seats[i];
	}
	else if(age>=10 && customer_type=='t')
	{
		total_amt==100;
	}

	total_amount[i]=total_amt;
}


int main()
{
    restart:
    	system("cls");
	printf("\n\t\t WELCOME TO RAVANGERS MOVIE TICKET BOOKINGS");
	printf("\n\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n\tLOGIN PAGE\n");
	printf("\n\n\tEnter login ID:");
	scanf("%d",&login_id);
	printf("\n\tEnter Password:");
	scanf("%d",&password);

	if(login_id==12345 && password==0000)
	{
	    goto ui;
	}
    	else
    	{
	    system("cls");
            printf("\n Wrong Password or Login Id try again");
            getch();
            goto restart;
	}

	ui:
	system("cls");

	printf("\n\t\t WELCOME TO RAVANGERS MOVIE TICKET BOOKINGS");
	printf("\n\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	printf("\n\nENTER \n\t '1' to take a new entry \n\t '2' search entry \n\t '3' view privious ticket \n\t '4' edit entry \n\t 'e' to exit\n\n\t--> ");
	fflush(stdin);
	scanf("%c", &choice);
 	switch(choice)
		{
			case '1'://new entry
                   		new_entry();
				getch();
				break;

			case '2'://searching
				search();
				break;

			case '3'://viewing previous ticket
				ticket();
				getch();
				break;


			case '4'://editing
				//editing function
				getch();
				break;

			case 'e'://exit
				break;

			default :
				printf("\n\n\t INVALID INPUT");
				getch();
		}


	return 0;

}
