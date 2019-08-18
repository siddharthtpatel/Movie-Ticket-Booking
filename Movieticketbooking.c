/*
*
    Author: Siddharth Patel
    MOVIE TICKET BOOKING PLATFORM USING C

*
*/

#include<stdio.h> //header file
#include<stdlib.h>

	struct customer_id
	{
        int movie_id, customer_id, no_seats, date, month, year, time_h, time_m, age;
        char customer_type;
        float total_amount;
	}c[10];

    int ticket_price, users, i, search_id, n;
	int low, high, mid, login_id, password, g;
	char  r, t, ignore, choice, p, b, m;
	float total_amt; //variable declaration

void new_entry()//function to take new entry
{

    for (i=n;i<=n;i++)
    {

        re:
        printf("\n\t\t WELCOME TO RAVANGERS MOVIE TICKET BOOKINGS");
        printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n\n\n Movie ids :\t\t\t\t\t\t DISCOUNTS:  \n\n AVENGERS - 121 \t\t\t\t\t regular customer - 10%% discount \n\n JUSTICE LEAGUE - 232 \t\t\t\t\t age < 10 - 5%% discount \n\n DEADPOOL - 313 \n\n XMEN - 424  ");//information for the customer

        //customer details
        printf("\n\n\t Enter the customer id: ");
        scanf("%d", &c[i].customer_id);
        printf("\n\n\t Enter the customer type (r=regular, t=temporary): ");
        fflush(stdin); /*to remove the buffer memory*/
        scanf("%c", &c[i].customer_type);
        printf("\n\n\t Enter the customer's age: ");
        scanf("%d", &c[i].age);

        //movie ticket details
        printf("\n\n\t Enter the Movie id: ");
        scanf("%d", &c[i].movie_id);
        printf("\n\n\t Enter the show's date in dd/mm/yyyy: ");
        scanf("%d%c%d%c%d", &c[i].date,&ignore, &c[i].month, &ignore ,&c[i].year);
        printf("\n\n\t Enter the show's timing in hh:mm : ");
        scanf("%d%c%d", &c[i].time_h, &ignore, &c[i].time_m);
        printf("\n\n\t Enter the number of seats: ");
        scanf("%d", &c[i].no_seats);
        printf("\n\n  The ticket price is Rs 100 ");
        getch();

        printf("\n\n\t Enter\n\n\t 'p' to print ticket\n\n\t 'r' to reset the details");
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
                case 'r':
                    goto re;
                    getch();
                    break;

                //invalid input
                default :
                    printf("\n\n\t INVALID INPUT");
                    getch();
            }
    }
}

void search()//searching functions
{
    for (i=n;i<=n;i++)
    {
        printf("\nEnter the customer id to search the details:");
        scanf("%d", &search_id);

        low=0;
        high=users-1;

        while(low<=high)
        {
            mid=(high+ low)/2;

            if(c[mid].customer_id=search_id)
            {
                printf("\n\nSEARCHED CUSTOMER DETAILS\n");
                printf("\n\tcustomer id: %d", c[mid].customer_id);
                printf("\n\tcustomer type: %c", c[mid].customer_type);
                printf("\n\tcustomer age: %d", c[mid].age);

                printf("\n\nMOVIE DETAILS OF THE SEARCHED CUSTOMER");
                printf("\n\tMovie id: %d", c[mid].movie_id);
                printf("\n\tMovie Date=%d/%d/%d", c[mid].date, c[mid].month, c[mid].year);
                printf("\n\tMovie Time=%d:%d",  c[mid].time_h, c[mid].time_m);
                printf("\n\tNumber of seats=%d", c[mid].no_seats);
                printf("\n\tTotal amount= %.2f", c[mid].total_amount);
                getch();

            }
            else if(c[mid].customer_id<search_id)
            {
                low=mid+1;
            }
            else if(c[mid].customer_id>search_id)
            {
                high=mid-1;
            }
        }
    }
}

void ticket()//function of printing ticket
{
     for (i=n;i<=n;i++)
    {
        printf("\n\n\t\t ____________________________________");
        printf("\n\t\t| Movie id: %d                       |", c[i].movie_id);
        printf("\n\t\t| customer id: %d     customer type: %c |", c[i].customer_id, c[i].customer_type);
        printf("\n\t\t| Date=%d/%d/%d   Time=%d:%d        |", c[i].date, c[i].month, c[i].year,c[i].time_h, c[i].time_m);
        printf("\n\t\t| No. of seats=%d   Ticket price=100   |", c[i].no_seats, ticket_price);
        printf("\n\t\t| Total amount= %.2f                |", c[i].total_amount);
        printf("\n\t\t|           Enjoy your show           |");
        printf("\n\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

        printf("\n\n\t Enter\n\t 'e' to edit and reenter the values\n\t 'm' to go back to the menu");
        printf("\n\n\t Enter :  ");
        fflush(stdin);
        scanf("%c", &choice);
        switch(choice)
        {
            case 'm':
                break;
            case 'e':
                new_entry();
                break;
            default :
                printf("\n\n\t INVALID INPUT");
                getch();
        }
    }
}


void calculation()//function to calculate ticket price
{
    for (i=n;i<=n;i++)
    {
        if(c[i].age<10 && c[i].customer_type=='r' )
        {
            total_amt=c[i].no_seats*85;
        }
        else if(c[i].age<10 && c[i].customer_type=='t')
        {
            total_amt=95*c[i].no_seats;
        }
        else if(c[i].age>=10 && c[i].customer_type=='r' )
        {
            total_amt=90*c[i].no_seats;
        }
        else if(c[i].age>=10 && c[i].customer_type=='t')
        {
            total_amt==100;
        }

        c[i].total_amount=total_amt;
    }
}


void main()
{

    restart:
    system("cls");
	printf("\n\t\t WELCOME TO RAVANGERS MOVIE TICKET BOOKINGS");
	printf("\n\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n\tLOGIN PAGE\n");
	printf("\n\n\tEnter login ID: ");
	scanf("%d",&login_id);
	printf("\n\tEnter Password: ");
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
    g=0;
    n=0;
    while(g!=1)
    {

        ui:
        system("cls");

        printf("\n\t\t WELCOME TO RAVANGERS MOVIE TICKET BOOKINGS");
        printf("\n\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n\tMAIN MENU\n");
        printf("\n\n\tENTER \n\t '1' to take a new entry \n\t '2' search ticket \n\t 'e' to exit\n\n\t--> ");
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

            case 'e'://exit
                g=1;
                break;

            default :
                printf("\n\n\t INVALID INPUT");
                getch();
        }
        n++;
    }

}
