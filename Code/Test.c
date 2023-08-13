/************************************************************

*************************************************************
 ____                       _      ____ _ _       _      
/ ___| _ __ ___   __ _ _ __| |_   / ___| (_)_ __ (_) ___ 
\___ \| '_ ` _ \ / _` | '__| __| | |   | | | '_ \| |/ __|
 ___) | | | | | | (_| | |  | |_  | |___| | | | | | | (__ 
|____/|_| |_| |_|\__,_|_|   \__|  \____|_|_|_| |_|_|\___|

*************************************************************

************************************************************/


/*///////////////////////////////////////////////////////////
--FileName: Smart_Clinic.c
--FileType: Visual C Source file
--Size : 26206
--Author : Khaled El-Sayed
--Created On : 8/14/2021 9:56:39 AM
--Last Modified On : 8/20/21 11:53:23 AM
--Copy Rights : t0ti20@icloud.com
--Description : clinic management system
///////////////////////////////////////////////////////////*/




/************************************************************
 _     _ _                    _           
| |   (_) |__  _ __ __ _ _ __(_) ___  ___ 
| |   | | '_ \| '__/ _` | '__| |/ _ \/ __|
| |___| | |_) | | | (_| | |  | |  __/\__ \
|_____|_|_.__/|_|  \__,_|_|  |_|\___||___/
                                          
************************************************************/

#include "Files/Const/const.h"  									  /* Constant Variables */
#include <stdio.h>			  									  /* Main Liberary */
#include <string.h>												  /* String Method Liberary */
#define password 1234		 								       /* Administrator Password */
#define number_of_patient 100										  /* Number Of Patient Will Aded On The System */
#define number_of_reservations 5									  /* Numbers Of Reservations Per Day */


/************************************************
__     __         _       _     _           
\ \   / /_ _ _ __(_) __ _| |__ | | ___  ___ 
 \ \ / / _` | '__| |/ _` | '_ \| |/ _ \/ __|
  \ V / (_| | |  | | (_| | |_) | |  __/\__ \
   \_/ \__,_|_|  |_|\__,_|_.__/|_|\___||___/
                                            
*************************************************/

typedef enum {false,true,zero=0,one,two,three,four,five,six}Constants;	  /* Constants Numbers Enum */
typedef struct {s32 id;s8 name[20];s32 age;s8 gender[10];} patient_data;	  /* Patient Data Storage */
typedef struct {s8 time[35];s8 available;s32 id;} reservations;	  		  /* Doctor Reservation Storage */
patient_data patient_num[number_of_patient];							  /* Patient Data Storage Dicleration*/
reservations av_reservations[number_of_reservations];					  /* Doctor Reservation Storage Dicleration*/
void reservation_initial();										  /* Initial State For Reservation*/
void add_patient();												  /* Function To Add Patient */
void reserve_slot();											  /* Function To Reserva A Slot*/
void delete_slot();												  /* Function To Delete A Slot */
void view_record();												  /* Function To View Record With The ID*/
void view_reservation();											  /* Function To View Reserved Reservations */
u32 edit_patient();												  /* Function To Edit Patient */
u32 admin_user();												  /* Function For Admin User*/
u32 patient_user();												  /* Function For Patient User*/
u32 access();													  /* Password Access Function */
u32 id_check(u32 id);											  /* ID Check Function */
u32 var=1;												    	  /* Global Variable To Store IN */


/*************************
 __  __       _       
|  \/  | __ _(_)_ __  
| |\/| |/ _` | | '_ \ 
| |  | | (_| | | | | |
|_|  |_|\__,_|_|_| |_|
                      
*************************/

void main(void)						/* Main Function To Select The Nature Of The User */
{
	u32 user_nature,flag=true;
	reservation_initial();				/* Initial State For Reservation */
	printf("+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+ +-+-+-+-+-+-+\n|W|e|l|c|o|m|e| |T|o| |S|m|a|r|t| |C|l|i|n|i|c|\n+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+ +-+-+-+-+-+-+\n");
	while(flag)
	{
		printf("1) Admin\n2) User\n3) Exit\nPlease Choose An Option : ");	  /* User Or Admin Option */
		scanf("%d",&user_nature);
		switch (user_nature)
		{
		case (1):flag=admin_user();break;
		case (2):flag=patient_user();break;
		case (3):flag=false;break;
		default:printf("Wrong Entery ...\n-------------------------------\n");
		}
	}
}

/***********************************************
 _____                 _   _                 
|  ___|   _ _ __   ___| |_(_) ___  _ __  ___ 
| |_ | | | | '_ \ / __| __| |/ _ \| '_ \/ __|
|  _|| |_| | | | | (__| |_| | (_) | | | \__ \
|_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|___/

***********************************************/

void reservation_initial()
{
	for(u8 i=0;i<5;i++)
	{
	av_reservations[i].available=1;
	av_reservations[i].id=0;
	}
	strcpy(av_reservations[0].time,"- (1) From (2:00)PM To (2:30)PM ");
	strcpy(av_reservations[1].time,"- (2) From (2:30)PM To (3:00)PM ");
	strcpy(av_reservations[2].time,"- (3) From (3:00)PM To (3:30)PM ");
	strcpy(av_reservations[3].time,"- (4) From (4:00)PM To (4:30)PM ");
	strcpy(av_reservations[4].time,"- (5) From (4:30)PM To (5:00)PM ");
}

u32 admin_user()
{
	u32 flag=true;
	flag=access();
	while(flag)
	{
		u32 data;
		for(int i=0;i<4;i++)
		{
			printf("ID : %d / Name : %s / Age : %d / Gender : %s\n",patient_num[i].id,patient_num[i].name,patient_num[i].age,patient_num[i].gender);
		}
		for(int i=0;i<5;i++)
		{
			printf("Avilability : %d / ID : %d / Time : %s\n",av_reservations[i].available,av_reservations[i].id,av_reservations[i].time);
		}
		printf("\n-----------------      Welcome Administrator      -----------------\n");
		printf("1) Add New Patient\n2) Edit Patient Record\n3) Reserve A Slot With The Doctor\n4) Cancel Resevation\n5) Back\n6) Exit\nPlease Choose An Option : ");
		scanf("%d",&data);
		switch (data)
		{
			case(true) :
				add_patient();break;
			case(two)   :edit_patient();break;
			case(three) :reserve_slot();break;
			case(four)  :delete_slot();break;
			case(five)  :printf("-------------------------------\n");return true;
			case(six)   :return false;
			default     :printf("Wrong Entery ...\n");
		}
	}
}

u32 patient_user()
{
	u32 flag=true;
	while(flag)
	{
		u32 data;
		printf("\n-----------------      Welcome      -----------------\n");
		printf("1) View Patient Record\n2) View Reservation For Today\n3) Back\n4) Exit\nPlease Choose An Option : ");
		scanf("%d",&data);
		switch (data)
		{
			case(true)   :view_record();break;
			case(two)    :view_reservation();break;
			case(three)  :printf("-------------------------------\n");return true;
			case(four)   :return false;
			default      :printf("Wrong Entery ...\n");
		}
	}	
}

void view_record()
{
	u32 index,data,flag=true;
	while(flag)
	{
		printf("Please Enter Patient ID : ");
		scanf("%d",&data);
		index=id_check(data);
		if(patient_num[index].id==false)
		{
			printf("Wrong Entery ...\n");
			printf("-------------------------------\n");
		}
		else flag=false;
	}
	printf("- Patient ID : %d \n- Name : %s \n- Age : %d \n- Gender : %s\n",patient_num[var].id,patient_num[var].name,patient_num[var].age,patient_num[var].gender);
}

void view_reservation()
{
	u8 flag=false;
	for (u8 i=0;i<5;i++)
	{
		if(av_reservations[i].available==0)
		{
			printf("%s For The Patient ID (%d)",av_reservations[i].time,av_reservations[i].id);
			flag=true;
		}
	}
	if(flag==false)
	{
		printf("There Is No Reservations For Today ..");
	}
}


void delete_slot()
{
	u32 id,index,flag=false;
	printf("Please Enter The ID Of The Patient's Reservation : ");
	scanf("%d",&id);
	for(index=0;index<5;index++)
	{
		if(av_reservations[index].id==id)
		{
			flag=true;break;
		}
	}
	if(flag)
	{
		av_reservations[index].available=1;
		printf("Reservation Has Been Cancelled Successfully\n");
	}
	else
	{
		printf("Invalid Input\n");
		printf("-------------------------------\n");
	}
}


void reserve_slot()
{
	u32 data,av_time,flag=true;
	for(u8 i=0,c=1;i<5;i++,c++)
	{
		if(av_reservations[i].available==1)printf("\n%s",av_reservations[i].time);
	}
	printf("\nPlease Choose From The Available Time : ");
	scanf("%d",&av_time);
	if(av_time<6)
	{
		av_reservations[(av_time-1)].available=0;
		while(flag)
		{
			printf("Please Enter The Id Of Patient : ");
			scanf("%d",&data);
			if(id_check(data)==(number_of_patient+1))
			{
				av_reservations[(av_time-1)].id=data;
				printf("Reservation Has Been Completed Successfully\n");
				flag=false;
			}
			else
			{
				printf("Invalid ID\n");
				printf("-------------------------------\n");
			}
		}
	}
}


u32 edit_patient()
{
	u32 data,counter,id;
	u32 flag=true;
	do
	{
		printf("\nPlease Enter Patient ID : ");
		scanf("%d",&id);
		counter=id_check(id);
		if(counter==(number_of_patient+1)) flag=false;
		else
		{
			printf("Invalid ID\n");
			printf("-------------------------------");
		}
	}
	while(flag);
	do
	{
		printf("1) ID\n2) Name\n3) Age\n4) Gender\n5) Back\nPLease Ender Option To Edit : ");
		scanf("%d",&data);
		switch (data)
		{
			case(true) :
				do
				{
					printf("Enter New ID : ");
					scanf("%d",&data);
					counter=id_check(data);
					if(counter==(number_of_patient+1))
					{
						printf("This ID Is Already Taken\n");
						printf("-------------------------------\n");
						flag=true;
					}
					else flag=false;
				}
				while (flag);
				patient_num[var].id=data;
				printf("ID Has Changed Succesfully ..\n");
				printf("-------------------------------\n\n");
				break;
			case(two) :
				printf("Please Enter New Name : ");
				scanf("%s",patient_num[var].name);
				break;
			case(three) :
				printf("Please Enter New Age : ");
				scanf("%d",&patient_num[var].age);
				break;
			case(four) :
				printf("Please Enter New Gender : ");
				scanf("%s",&patient_num[var].gender);
				break;
			case(five) :
				break;
			default :
				printf("This ID Is Already Taken\n");
				printf("-------------------------------\n");
		}
	} while (flag);
}

u32 id_check(u32 id)
{
	u32 counter;
	for(counter=0;counter<number_of_patient;counter++)
	{
		if(id==patient_num[counter].id) 
		{
			var=counter;
			return number_of_patient+1;
		}
		else if(patient_num[counter].id==false)
		{
			return counter;
		}
		else ;
	}
}

u32 access()
{
	u32 i=false;
	while(i<three)
	{
		printf("Please Enter Your Password : ");
		scanf("%d",&var);
		if(var==password)return true;
		else
		{
			printf("Please Enter Valid Password\n");
			i++;
		}
	}
	printf("-----------------------------------------------------\n");
	printf("You Have Entered Wrong Password For 3 Times\n");
	return false;
}

void add_patient()
{
	u32 data,counter;
	u32 flag=true;
	while(flag)
	{
		printf("\n- Enter Patient ID : ");
		scanf("%d",&data);
		counter=id_check(data);
		if(counter==(number_of_patient+1)) 
		{
			printf("This ID Is Already Taken\n");
			printf("-------------------------------");
		}
		else 
		{
			patient_num[counter].id=data;
			flag=false;
			break;
		}
	}
	printf("- Enter Patient Name : ");
	scanf("%s",&patient_num[counter].name);
	printf("- Enter Patient Age : ");
	scanf("%d",&patient_num[counter].age);
	printf("- Enter Patient Gender : ");
	scanf("%s",&patient_num[counter].gender);
	printf("- Patient Added Successfully ..\n");
}
