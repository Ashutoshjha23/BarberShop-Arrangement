#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int n,nc,br = 1,customer,a[100],count = 0,busy = 0,newc,nofc = 0,start = 0,upto = 0,flag = 0,index,st,c;

	printf("\n Enter how many chairs are in waiting room of barbershop :");
	scanf("%d",&n);
again:
	printf("\n Enter number of customers :");
	scanf("%d",&customer);

	if( (flag == 1) && (customer != 0) )
	{
		printf("\n customer wakes up the barber \n");
	}
	if(customer == 0)
	{
		printf("\n Barber went to sleep");
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			a[i] = 0;
		}

		printf("\n Barber is busy because,");
		printf("\n Customer %d inside the barber shop\n ",br);
		busy = 1;


		for(int i=0;i<customer-1;i++)
		{
			if(a[i] == 0)
			{
				a[i] = 1;
				printf("\n Customer %d is inside the waiting room \n chair %d is occupied by customer %d\n",i+2,i+1,i+2);
				nofc = i;
			}
		}


		if( (busy == 1) && (customer > 0) )
		{
			sleep(3);
			printf("\n customer %d is leaving the shop \n",br);
			busy = 0;
			customer--;
		}

		if( (busy == 0) && (customer > 0) )
		{
			for(int i=0;( (customer != 0) && (i != n) );i++)
			{
				if(busy == 1)
				{
					sleep(3);
					printf("\n customer %d is done and leaving the shop \n",i+1);
					busy = 0;
				}

				if(busy == 0)
				{
					printf("\n customer %d leaving the waiting room\n",i+2);
					printf("\n barber is busy because, ");
					printf("\n customer %d inside the barber shop \n",i+2);
					customer--;
					a[i] = 0;
					busy = 1;
				}

				printf("\n enter how many new customers are coming ");
				scanf("%d",&newc);
				customer = customer + newc;
				//start = nofc+1;
				start = customer - newc;
				st = newc;
				upto = newc + (nofc + 1);
				/*for(int i = start;i<upto;i++)
				{
					if(a[i] == 0)
					{
						a[i] = 1;
						printf("\n customer %d is inside the waitig room \n chair %d is occupied by customer %d\n",i+2,i+1,i+2);
						nofc = i;
					}
				}*/
				index =0;
				c = 0;
				for(int j=0;j<n;j++)
				{
					if(a[i] == 0)
					{
						a[i] = 1;
						printf("\n customer %d is inside the waiting room\n");
						index++;
						start++;
						printf(" chair %d is occupied by customer %d \n",i+1,start);
						/*if(start == customer)
						{
							break;
						}*/
						newc--;
					}
					else
					{
						c++;
					}
				}

				if(c == n)
				{
					printf("\n all chairs are occupied so customer leaves the shop\n",);
				}
				else
				{
					printf("\n %d customer leaves the shop",newc);
				}

				
			}
			if(customer == 0)
			{
				printf("\n There is no any customer is left so barber went to sleep\n\n");
			}
		}


		printf("\n is there any new customer is coming (Enter 1 for yes / 0 for no)");
		scanf("%d",&nc);

		if(nc == 0)
		{
			return 0;
		}
		else
		{
			flag = 1;
			goto again;
		}
		/*while(nc == 1)
		{

			printf("\n Enter number of new coming customer :");
			scanf("%d",&customer);

			for(int i=0;(customer != 0 && i != n);i++)
			{
				if(a[i] == 0)
				{
					a[i] = 1;
					printf("\n chair %d is occupied by customer %d",i+1,i+1);
					customer--;
				}
				else
				{
					count++;
				}
			}

			if(count == n)
			{
				printf("\n Customer leave the shop because all the chairs are occupied by other customers");
			}
		}*/
	}

}
