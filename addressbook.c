#include "addressbook.h"

// validations
int validate_phone(char *,struct AddressBook *addressBook);
int validate_email(char *,struct AddressBook *addressBook);

// unique
int unique_number(char *,struct AddressBook *addressBook);
int unique_email(char *,struct AddressBook *addressBook);

// searching
int search_by_name(struct AddressBook *addressBook);
int search_by_phone(struct AddressBook *addressBook);
int search_by_email(struct AddressBook *addressBook);

// edit
void edit_name(int,struct AddressBook *addressBook);
void edit_phone(int,struct AddressBook *addressBook);
void edit_email(int,struct AddressBook *addressBook);

void deletion_contact(int,struct AddressBook *addressBook);
void sortContacts(struct AddressBook *addressBook);


// *************CREATE CONTACTS******************

void add_contact(struct AddressBook *addressBook)
{

    char NAME[50];
    char PHONE[15];
    char EMAIL[50];
    int i = addressBook->contactCount;
    int valid_ret;
    char ch;

    do{
        // ********* NAME *************
        printf("Name: ");
        scanf(" %[^\n]",NAME);

        // ********* PHONE ************
        do{

        printf("Phone No.: ");
        scanf(" %[^\n]",PHONE);

        valid_ret = validate_phone(PHONE,addressBook);

        if(valid_ret == 0)
            printf("Phone Number is Invalid!!\n");

            // Checking Number is Unique or not
        if(unique_number(PHONE,addressBook) == 1)
            valid_ret = 0;

        }while(valid_ret == 0 );
        
        // ************ Email ***************

        do
        {
            printf("Email ID: ");
            scanf("%s",EMAIL);
            valid_ret = validate_email(EMAIL,addressBook);
            if(valid_ret == 1)
                printf("Email Id is Invalid\n");

            if(unique_email(EMAIL,addressBook))
                valid_ret == 1 ;
        } while (valid_ret == 1);

        printf("Do you want to Save the Contact ( Y / N ): \n");
        scanf(" %c",&ch);
    }while(ch != 'Y');

    // saving to the structure

    strcpy(addressBook->contacts[addressBook->contactCount].name,NAME);
    strcpy(addressBook->contacts[addressBook->contactCount].phone,PHONE);
    strcpy(addressBook->contacts[addressBook->contactCount].email,EMAIL);
    addressBook->contactCount++;
  
}

// *************SEARCH CONTACTS******************

void search_contact(struct AddressBook *addressBook)
{
    int choice;

    printf("Choose Search Type:\n");
    printf("1.Name\n");
    printf("2.Phone Number\n");
    printf("3.Email Id\n");

    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        search_by_name(addressBook);
        break;
    case 2:
        search_by_phone(addressBook);
        break;
    case 3:
        search_by_email(addressBook);
        break;
    default:
        printf("Invalid Input !!!\n");
        break;
    }


}

// *************EDIT CONTACTS******************

void edit_contact(struct AddressBook *addressBook)
{

    int choice;
    int contact_edit_op;
    int return_value;
    
    printf("Choose Search Type to Edit Contact:\n");
    printf("1.Name\n");
    printf("2.Phone Number\n");
    printf("3.Email Id\n");

    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        return_value = search_by_name(addressBook);
        if(return_value == 0)
            break;
        choice = 1;
        if(addressBook->ir_size > 0)
        {
            printf("Choose the Contact to Edit:\n");
            scanf("%d",&choice);
        }

        choice = addressBook->index_record[choice-1]; // acessing the index value

        printf("Enter choice to edit: \n");
        printf("1.Name \n2.Phone Number \n3.Email\n");
        scanf("%d",&contact_edit_op);

        switch(contact_edit_op)
        {
            //Editing Name
            case 1: 
                edit_name(choice,addressBook);
                break;
            // Editing Phone Number
            case 2:
                edit_phone(choice,addressBook);
                break;
                // Email update
            case 3: 
                edit_email(choice,addressBook);
                break;
        }

        break;
    case 2:
        return_value = search_by_phone(addressBook);
        if(return_value == 0)
            break;
        choice = 1;
        if(addressBook->ir_size > 0)
        {
            printf("Choose the Contact to Edit:\n");
            scanf("%d",&choice);
        }

        choice = addressBook->index_record[choice-1]; // acessing the index value

        printf("Enter choice to edit: \n");
        printf("1.Name \n2.Phone Number \n3.Email\n");
        scanf("%d",&contact_edit_op);

        switch(contact_edit_op)
        {
            //Editing Name
            case 1: 
                edit_name(choice,addressBook);
                break;
            // Editing Phone Number
            case 2:
                edit_phone(choice,addressBook);
                break;
                // Email update
            case 3: 
                edit_email(choice,addressBook);
                break;
        }
        break;
    case 3:
        return_value = search_by_email(addressBook);
        if(return_value == 0)
            break;
        choice = 1;
        if(addressBook->ir_size > 0)
        {
            printf("Choose the Contact to Edit:\n");
            scanf("%d",&choice);
        }

        choice = addressBook->index_record[choice-1]; // acessing the index value

        printf("Enter choice to edit: \n");
        printf("1.Name \n2.Phone Number \n3.Email\n");
        scanf("%d",&contact_edit_op);

        switch(contact_edit_op)
        {
            //Editing Name
            case 1: 
                edit_name(choice,addressBook);
                break;
            // Editing Phone Number
            case 2:
                edit_phone(choice,addressBook);
                break;
                // Email update
            case 3: 
                edit_email(choice,addressBook);
                break;
            default:
            printf("Invalid Input !!!\n");
            break;
        }
        break;
    default:
        printf("Invalid Input !!!\n");
        break;
    }
}

// *************DELETE CONTACTS******************

void delete_contact(struct AddressBook *addressBook)
{
    int choice;
    int return_value;

    printf("Choose Search Criteria to Delete Contact: \n");
    printf("1.Name\n");
    printf("2.Phone Number\n");
    printf("3.Email\n");

    scanf("%d",&choice);

    switch (choice)
    {
        // using name
    case 1:
        return_value = search_by_name(addressBook);
        if(return_value == 0)
            break;

        choice = 1;
        
        
            printf("Choose the Contact to Delete:\n");
            scanf("%d",&choice);


        choice = addressBook->index_record[choice-1]; // acessing the index value

        deletion_contact(choice,addressBook);
        break;
        //using phone
    case 2:
        return_value = search_by_phone(addressBook);
        if(return_value == 0)
            break;

        choice = 1;
       
        
            printf("Choose the Contact to Delete:\n");
            scanf("%d",&choice);
        

        choice = addressBook->index_record[choice-1]; // acessing the index value

        deletion_contact(choice,addressBook);

        break;
        // search by email
    case 3:
        return_value = search_by_email(addressBook);
        if(return_value == 0)
            break;

        choice = 1;
        
        
            printf("Choose the Contact to Delete:\n");
            scanf("%d",&choice);
        

        choice = addressBook->index_record[choice-1]; // acessing the index value

        deletion_contact(choice,addressBook);
        
    default:
        break;
    }

}

// *************LIST CONTACTS******************

void list_contacts(struct AddressBook *addressBook)
{

    sortContacts(addressBook);
    printf("-------------------------------------------------------------------------------\n");
    printf("%-5s  %-20s %-20s %-30s\n", "Sl", "NAME", "Phone number", "Email");
    printf("-------------------------------------------------------------------------------\n");
    for(int i = 0 ; i < addressBook->contactCount ; i++)
    {
        printf("%-5d %-20s %-20s %-30s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        printf("-------------------------------------------------------------------------------\n");
    }
}

// *************LOAD CONTACTS******************

void load_contact(struct AddressBook *addressBook)
{
    FILE *fp;
    fp = fopen("database.csv","r");
	if(fp == NULL)
	{
		perror("Database not Found unable to Load");
		return ;
	}
	while((fscanf(fp,"%[^,],%[^,],%[^\n]",addressBook->contacts[addressBook->contactCount].name,
								addressBook->contacts[addressBook->contactCount].phone,
								addressBook->contacts[addressBook->contactCount].email)) == 3)
	{
		
		addressBook->contactCount++;
        fgetc(fp);
	}
	fclose(fp);
}

// *************SAVE CONTACTS******************

void save_contact(struct AddressBook *addressBook)
{
    FILE *fp;
    fp = fopen("database.csv","w");

		if(fp == NULL)
		{
			perror("Error");
				return ;
		}
		for(int i = 0 ; i < addressBook->contactCount ; i++)
		{
			fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
		}

		fclose(fp);
}


// ***************************VALIDATIONS***************************

// Number validate
int validate_phone(char PHONE[],struct AddressBook *addressBook)
{
    // length  is 10 or not
    if(strlen(PHONE) != 10)  
        return 0;

    // is all char is digit
    for(int i = 0 ; i < strlen(PHONE) ; i++ ) 
    {
        if(!(isdigit(PHONE[i])))
            return 0;
    }
    
    return 1;
}


//  Email validate 
int validate_email(char EMAIL[],struct AddressBook *addressBook)
{
    char gmail[]={"@gmail.com"};

    // checking does email id ends with @gmail.com
    char * str = strstr(EMAIL,"@");

    if(str == NULL)
        return 1 ;
    if(strcmp(str,gmail))
        return 1;

    int atleast_one_char = 0;
    // Checking Whether the email is in lower case or numbers only till @gmail.com  
    for(int i = 0 ; EMAIL[i] != '@' ; i++)
    {
        if(islower(EMAIL[i]))
            atleast_one_char = 1;
        if(!(islower(EMAIL[i]) || isdigit(EMAIL[i]) || EMAIL[i] == '.'))
            return 1;
        
    }
    
    if(atleast_one_char != 1)
        return 1;

    return 0;
}

// Unique Number
int unique_number(char PHONE[],struct AddressBook *addressBook)
{
    // does already exist or unique
        for(int i = 0 ; i < addressBook->contactCount ; i++)
        {
            if( !(strcmp(PHONE,addressBook->contacts[i].phone)) )
            {
                printf("Phone Number Already Exist!!\n");
                return 1;
            }
        }
        return 0;
}

// unique Email

int unique_email(char EMAIL[],struct AddressBook *addressBook)
{
    // does already exist or unique
        for(int i = 0 ; i < addressBook->contactCount ; i++)
        {
            if( !(strcmp(EMAIL,addressBook->contacts[i].email)) )
            {
                printf("Email Already Exist!!\n");
                return 1;
            }
        }
        return 0;
}

//search by name

int search_by_name(struct AddressBook *addressBook )
{
    char NAME[50];
    int i = 0 , j = 0 ;
    char check = 0; // checkes atleast 1 contact found
    printf("Enter the Name: \n");
    scanf(" %[^\n]",NAME);

    addressBook->ir_size = 0 ;
    // print out the matching contact and saving index into index record
    printf("-------------------------------------------------------------------------------\n");
    printf("%-5s  %-20s %-20s %-30s\n", "Sl", "NAME", "Phone number", "Email");
    printf("-------------------------------------------------------------------------------\n");
    for(i = 0 ; i < addressBook->contactCount ; i++)
    {   
        if(strcmp(addressBook->contacts[i].name , NAME) == 0)
        {
            printf("%-5d %-20s %-20s %-30s\n",j+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            printf("-------------------------------------------------------------------------------\n");
            addressBook->index_record[j] = i;
            check = 1 ;
            j++;
            addressBook->ir_size++;
        }
    }
    if(check == 0)
    {    
        printf("\n    !!!!...No Contact Found based on search...!!!!\n");
        return 0;
    }

    return 1;
}

//search_by phone

int search_by_phone(struct AddressBook *addressBook)
{
    char PHONE[15];
    int valid_ret;
    char check = 0; // checkes atleast 1 contact found
    addressBook->ir_size = 0 ;
    int i, j = 0;

    // do-while loop runs until entered phone number is valid
    do{

    printf("Phone No.: ");
    scanf(" %[^\n]",PHONE);

    valid_ret = validate_phone(PHONE,addressBook);

    if(valid_ret == 0)
        printf("Phone Number is Invalid!!\n");

    }while(valid_ret == 0 );

    // print out the matching contact and saving index into index record
    printf("%-2s  %-20s %-15s %-40s\n", "Sl", "NAME", "Phone number", "Email");
    for(i = 0 ; i < addressBook->contactCount ; i++)
    {
        if(strcmp(addressBook->contacts[i].phone , PHONE) == 0)
        {
            printf("%2d) %-20s %-15s %-40s\n",j+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            addressBook->index_record[j] = i;
            check = 1 ;
            j++;
            addressBook->ir_size++;
        }
    }  
    if(check == 0)
    {    
        printf("\n    !!!!...No Contact Found based on search...!!!!\n");
        return 0;
    }

    return 1;

    
}

//search by email
int search_by_email(struct AddressBook *addressBook)
{
    char EMAIL[50];
    int valid_ret;
    char check = 0; // checkes atleast 1 contact found
    addressBook->ir_size = 0 ;
    int i, j = 0;

    // do-while loop runs until entered EMAIL id is valid
    do
    {
        printf("Email ID: ");
        scanf(" %s",EMAIL);
        valid_ret = validate_email(EMAIL,addressBook);
        if(valid_ret == 1)
            printf("Email Id is Invalid\n");

    } while (valid_ret == 1);

    // print out the matching contact and saving index into index record
    printf("%-2s  %-20s %-15s %-40s\n", "Sl", "NAME", "Phone number", "Email");
    for(i = 0 ; i < addressBook->contactCount ; i++)
    {
        if(strcmp(addressBook->contacts[i].email , EMAIL) == 0)
        {
            printf("%2d) %-20s %-15s %-40s\n",j+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            addressBook->index_record[j] = i;
            check = 1 ;
            j++;
            addressBook->ir_size++;
        }
    } 
    if(check == 0)
    {    
        printf("\n    !!!!...No Contact Found based on search...!!!!\n");
        return 0;
    }

    return 1;
}

// name_edit
void edit_name(int choice,struct AddressBook *addressBook)
{

    char NAME[50];
    char ch;
    do{
        printf("Enter the Name: \n");
        scanf(" %[^\n]",NAME);

        printf("You Entered: \n\n");
        printf("%-20s %-15s %-40s\n", "NAME", "Phone number", "Email");            
        printf("%-20s %-15s %-40s\n",NAME,addressBook->contacts[choice].phone,addressBook->contacts[choice].email);

                    
        printf("Do You Want to Save the Contact \" ( Y / N ) \": \n");
        scanf(" %c",&ch);
    }while(ch == 'N');
    
    // saving to be done
    strcpy(addressBook->contacts[choice].name,NAME);
    
}
 
// edit_phone
void edit_phone(int choice,struct AddressBook *addressBook)
{
    char PHONE[15];
    char ch;
    int valid_ret;
    do{
        do{

            printf("Phone No.: ");
            scanf(" %[^\n]",PHONE);

            valid_ret = validate_phone(PHONE,addressBook);

            if(valid_ret == 0)
                printf("Phone Number is Invalid!!\n");

                // Checking Number is Unique or not
            if(unique_number(PHONE,addressBook) == 1)
                valid_ret = 0;

        }while(valid_ret == 0 );

        printf("You Entered: \n\n");
        printf("%-20s %-15s %-40s\n",  "NAME", "Phone number", "Email");
        printf("%-20s %-15s %-40s\n",addressBook->contacts[choice].name,PHONE,addressBook->contacts[choice].email);

        printf("Do you Want to save the Contact \" ( Y / N ) \": \n ");
        scanf(" %c",&ch);
    }while(ch == 'N');
    
    // Saving to be done

    strcpy(addressBook->contacts[choice].phone,PHONE);

}

//edit email
void edit_email(int choice,struct AddressBook *addressBook)
{

    char EMAIL[50];
    char ch;
    int valid_ret;   
    do{
        do
        {
            printf("Email ID: \n");
            scanf(" %s",EMAIL);
            valid_ret = validate_email(EMAIL,addressBook);
            if(valid_ret == 1)
                printf("Email Id is Invalid\n");

            if(unique_email(EMAIL,addressBook))
                valid_ret == 1 ;
        } while (valid_ret == 1);   
        
        printf("You Entered: \n\n");
        printf("%-20s %-15s %-40s\n",  "NAME", "Phone number", "Email");
        printf("%-20s %-15s %-40s\n",addressBook->contacts[choice].name,addressBook->contacts[choice].phone,EMAIL);

        printf("Do you Want to save the Contact \" ( Y / N ) \": \n ");
        scanf(" %c",&ch);
        
    }while(ch == 'N');

    // saving to be done

    strcpy(addressBook->contacts[choice].email,EMAIL);

}

// deletion of contact
void deletion_contact(int choice,struct AddressBook *addressBook)
{

    // shifts the contacts
    for(int i = choice ; i < addressBook->ir_size ; i++)
    {
        strcpy(addressBook->contacts[choice].name,addressBook->contacts[choice + 1].name);
        strcpy(addressBook->contacts[choice].phone,addressBook->contacts[choice + 1].phone);
        strcpy(addressBook->contacts[choice].email,addressBook->contacts[choice + 1].email);
    }

    // delete the contact count
    addressBook->contactCount--;
    printf("Contact Deleted!!");
    printf("\v");
}

//sorting the list

void sortContacts(struct AddressBook *addressBook) 
{
    int i, j;
    struct Contact temp;

    for (i = 0; i < addressBook->contactCount - 1; i++) {
        for (j = 0; j < addressBook->contactCount - i - 1; j++) {

            if (strcasecmp(addressBook->contacts[j].name,
                           addressBook->contacts[j + 1].name) > 0) {

                temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = temp;
            }
        }
    }
}
