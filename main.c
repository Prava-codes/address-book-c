/*
PROJECT NAME 	:	ADDRESS  BOOK 
NAME			:	PRAVALLIKA THIRUKKOVALLURU
REG NO. 		:	25048_038
SUBMISSION DATE :	02-04-2026

----------------------------------------DESCRIPTION-----------------------------------------

*Address Book project is a menu-driven program written in C to manage contact details.
*It stores information like name, phone number, and email using structures and an array of structures is used to store multiple contacts.
*The project is divided into three files: header file, source file, and main file.
*The "header file" contains structure definitions and function declarations.
*The "source file" contains all logic such as add, search, edit, delete, and display.
*The "main file" controls program execution using a menu and switch-case.
*At the start of the program, contacts are loaded from a database.CSV file.
*File handling is used to store and retrieve data permanently.
*The "add_contact" function takes input from the user and stores it in the structure. 
*It validates phone number and email before saving and it also checks for duplicate phone numbers and emails.
*The "search function" allows searching contacts by name, phone number, or email and matching records are stored using an index array.
*The "edit function" allows updating name, phone, or email of a selected contact.
*The "delete function" removes a contact by shifting remaining contacts in the array.
*The "list function" displays all contacts in sorted order and Sorting is done alphabetically using a sorting function.
*We are using Validation functions to ensure correct input format for phone and email and Unique functions to prevent duplicate entries.
*Before exiting, all contacts are saved back to the file.
* The program demonstrates concepts like structures, arrays, functions, file handling, and string operations.
*Finally, done an ADDRESS BOOK project using this concepts according to the basic requirements.......
*/


#include "addressbook.h"
int main() 
{
    int choice;
	FILE *fp;
	char ch;
    struct AddressBook addressBook;
    addressBook.contactCount = 0;
    addressBook.ir_size = 0;

	load_contact(&addressBook);
    printf("%zu\n", sizeof(addressBook));
    
    do 
    {
	printf("\nAddress Book Menu:\n");
	printf("1. Add/Create contact\n");
	printf("2. Search contact\n");
	printf("3. Edit contact\n");
	printf("4. Delete contact\n");
	printf("5. List all contacts\n");
	printf("6. Exit\n\n");
	printf("Enter your choice: ");

	scanf("%d", &choice);

	switch (choice) 
	{
	    case 1:
		add_contact(&addressBook);
		break;
	    case 2:
		search_contact(&addressBook);
		break;
	    case 3:
		edit_contact(&addressBook);
		break;
	    case 4:
		delete_contact(&addressBook);
		break;
	    case 5:
		list_contacts(&addressBook);
		break;
	    case 6:
		save_contact(&addressBook);
		printf("Saving and Exiting...\n");
		break;
	    default:
		printf("Invalid choice. Please try again.\n");
	}
    } while (choice != 6);
	printf("\v");
	printf("--********--\n");
	printf("\v");
    return 0;
}
