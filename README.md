# 📒 Address Book in C  

## 📌 Description
This project is a Command-Line Interface (CLI) based Address Book application implemented in C.

It follows a menu-driven approach to perform operations like creating, searching, updating, and removing contacts.

All the contact details are stored in a CSV file, ensuring data is preserved even after the program is closed.


## 🖥️ Interface  

* CLI-based application  
* Menu-driven interaction  


## 🚀 Features  

* Create new contacts  
* Search contacts using name, phone number, or email  
* Update existing contact information  
* Remove contacts  
* Display all contacts (sorted alphabetically)  
* Load and save data using file handling  
* Simple and user-friendly menu navigation  


## ✅ Input Validation  

* Phone number must contain exactly 10 digits  
* Email should follow valid format (ends with '@gmail.com')  
* Duplicate phone numbers and emails are restricted  


## 🛠️ Technologies Used  

* C Programming Language  
* File Handling (CSV)  
* Structures, Arrays, and Pointers  


## Project Structure  

AddressBook/  
│── main.c  
│── addressbook.c  
│── addressbook.h  
│── database.csv  


## ▶️ How to Run  

Compile  
gcc main.c addressbook.c  

Run  
./a.out  


## 📌 Sample Output  

Address Book Menu:  

1. Add/Create contact  
2. Search contact  
3. Edit contact  
4. Delete contact  
5. List all contacts  
6. Exit  


## 🔮 Future Enhancements  

* Develop a GUI version  
* Replace arrays with linked lists  
* Enhance search functionality (partial matching)  


## 👩‍💻 Author  
# -Thirukovvalluru Pravallika  
