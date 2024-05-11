#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string Fine_user[500], borrow_title[500], borrow_name[500], borrow_email[500], Pickup_date[500],username[500],Reserve_book[500],admin_email[500],admin_pass[500],user_email[500],user_pass[500],admin_fname[500],admin_lname[500],user_fname[500],user_lname[500],userprivatekey[500];
int borrow_date[500], borrow_due[500];
int budget = 0;
int total = 0;
int tot = 0;
int count = total;
int countt = tot;
bool fine=true;
   //Other Functions...
   void useable();
   void mainfunc();
   
   //Admin Features...
   void admin_signup();
   void admin_login();
   void User_Management();
   void adminmain();
   void budgte_Management();
   
   //User Features...
   void user_registration();
   void user_Authentication();
   void user_lib_rules();
   void user_Profile_management();
   
   
   void useable(){
    while(true){

cout<<"\t\t\t----------->>   Welcome on user's library Management Portal   <<-----------"<<endl<<endl<<endl;
cout<<"Press 1 for Registration" <<endl<<endl;
cout<<"Press 2 for Authentication (Login) " <<endl<<endl;
cout<<"Press 3 for Welcome Page"<<endl<<endl;    
int user_select;
cin>>user_select;
cout<<endl;
if(user_select == 3){
mainfunc();
}

else if(user_select == 2){
user_Authentication();
}


        switch(user_select){
           
            case 1:
            user_registration();
            break;
           
        }
}
   }
struct Book {
    string title;
    string author;
    string ISBN;
    bool available;
};
Book books[500];
int numBooks = 0;
void initializeBooks() {
    Book book1 = {"The Alchemist", "Paulo Coelho", "500", true};
    Book book2 = {"To Kill a Mockingbird", "Harper Lee", "499", true};
    Book book3 = {"1984", "George Orwell", "498", true};
    Book book4 = {"he Catcher in the Rye", "J.D. Salinger", "497", true};
    Book book5 = {"The Great Gatsby", "F. Scott Fitzgerald", "496", true};
    Book book6 = {"The Lord of the Rings", "J.R.R. Tolkien", "495", true};
    Book book7 = {"Harry Potter and the Philosopher's Stone", "J.K. Rowling", "494", true};
    Book book8 = {"My Brother M.A. Jinnah", "Fatima Jinnah", "493", true};
    Book book9 = {"Quaid-e-Azam The Great Leader", "A.I. Rahim", "494", true};
    Book book10 = {"The Life of the Prophet Muhammad", "Ibn Kathir", "493", true};
    Book book11 = {"Pakistan A Personal History", "Imran Khan", "492", true};
    books[0] = book1;
    books[1] = book2;
    books[2] = book3;
    books[3] = book4;
    books[4] = book5;
    books[5] = book6;
    books[6] = book7;
    books[7] = book8;
    books[8] = book9;
    books[9] = book10;
    books[10] = book11;
    numBooks = 11;
}
void search_books_by_title() {
initializeBooks();
    string query;
    cout<<"\n\n\t\t\t---> Search Book By Title <---\t\t\t"<<endl<<endl;
    cout << "Enter title to search: ";
    getline(cin, query);
    cout<<endl;

    bool found = false;

    for (int i = 0; i < numBooks; i++) {
        if (books[i].title == query) {
        cout<<"\t\t---> Book Found <---\t\t"<<endl;
        cout << "Title   : " << books[i].title << endl;
        cout << "Author  : " << books[i].author << endl;
        cout << "ISBN    : " << books[i].ISBN << endl;
        if (books[i].available) {
        cout << "Status  : Available\n"<<endl<<endl;
        } else {
        cout << "Status  : Not Available\n"<<endl<<endl;
        }
        cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "\t\t---> No matching books found <---\t\t" <<endl<<endl;
    }
}
void browse_books_by_author() {
initializeBooks();
    string query;
    cout<<"\n\n\t\t\t---> Browse Book By Author <---\t\t\t"<<endl<<endl;
    cout << "Enter author to browse: ";
    getline(cin, query);
    cout <<endl;

    bool found = false;

    for (int i = 0; i < numBooks; i++) {
        if (books[i].author == query) {
        cout<<"\t\t---> Book Found <---\t\t"<<endl;
        cout << "Title    : " << books[i].title << endl;
        cout << "Author   : " << books[i].author << endl;
        cout << "ISBN     : " << books[i].ISBN << endl;
        if (books[i].available) {
        cout << "Status   : Available\n"<<endl<<endl;
        } else {
    	cout << "Status   : Not Available\n"<<endl<<endl;
        }
        cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "\t\t---> No books by this author found <---\t\t" <<endl<<endl;
    }
}
const int MAX_RESERVATIONS = 100;

struct Reservation {
    string bookTitle;
    string userName;
    string pickupDate;
    bool isReserved;
};

Reservation reservations[MAX_RESERVATIONS];
int numReservations = 0;

void reserveBook() {
	initializeBooks();
    if (numReservations >= MAX_RESERVATIONS) {
        cout << "Maximum number of reservations reached.\n";
        return;
    }
    int j=0;
    string userName;
    string bookTitle;
    string pickupDate;

    cout << "Enter your name: ";
    getline(cin, userName);
		
    cout << "Enter the book title you want to reserve: ";
    getline(cin, bookTitle);

	int z=0;
    Reservation reservation;
    reservation.bookTitle = bookTitle;
    reservation.userName = userName;
    reservation.pickupDate = pickupDate;
    reservation.isReserved = true;
    reservations[numReservations] = reservation;
    
    for(int i=0; i<numBooks; i++){
    	if(books[i].title==bookTitle){
    		cout << "Enter the pickup date (YYYY-MM-DD): ";
    		getline(cin, pickupDate);
    		Reserve_book[z]=reservation.bookTitle;
    		username[z]=reservation.userName;
    		Pickup_date[z]=reservation.pickupDate;
    		cout << "Book reserved successfully.\n";
    		z++;
    		numReservations++;	
    		return;
		}
		
	}
		cout<<"This book is not available: "<<endl;
}
void displayReservations() {
    if (numReservations == 0) {
        cout << "No reservations found.\n";
        return;
    }

    cout << "\t\t\t----> All Reservations: <----\t\t\t\n\n\n";
    for (int i = 0; i < numReservations; i++) {
        cout << "Book Title: " << Reserve_book[i] << "\n";
        cout << "User Name: " << username[i] << "\n";
        cout << "Pickup Date: " << Pickup_date [i]<< "\n";
        cout << "Reservation Status: " << (reservations[i].isReserved ? "Reserved" : "Not Reserved") << "\n";
        cout << "---------------------------------\n";
    }
}

void User_Book_Reservation_Management() {
    int choice;

    cout << "\t\t----> Book Reservation Management <----\n";
    cout << "Select an option:\n";
    cout << "1. Reserve a book\n";
    cout << "2. Display all reservations\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); 

    switch (choice) {
        case 1:
        	initializeBooks();
            reserveBook();
            break;
        case 2:
            displayReservations();
            break;
        case 3:
            cout << "Exiting Book Reservation Management.\n";
            adminmain();
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
    }
}
int borrow=0;
void Book_Borrow(){
	initializeBooks();
	string name;
	string email;
	string title;
	int date;
	cout<<"\n\t\t\t\t---> Book Borrow <---\t\t\t\t\n"<<endl;
	cout<<"Enter Your Name: "<<endl;
	getline(cin, name);
	
	cout<<"\nEnter Your Email : "<<endl;
	getline(cin, email);
	
	for(int i=0; i<numBooks; i++){
		if(email==user_email[i]){
			cout<<"\nEnter Book Title : "<<endl;
			getline(cin, title);
			for(int j=0; j<numBooks; j++){
				if(title==books[j].title){
					cout<<"\nEnter Today's Date : "<<endl;
					cout<<"2023-June-";
					cin>>date;
					borrow_title[borrow]=title;
					borrow_name[borrow]=name;
					borrow_email[borrow]=email;
					borrow_date[borrow]=date;
					cout<<"\t\t---> Book Borrow Successfully :) <---\t\t"<<endl<<endl;
					cout<<"You have to return book at: ";
					cout<<"2023-June-"<<date+5<<endl;
					borrow_due[borrow]=date+5;
					borrow++;
					return;
				}
				
			}
			cout<<"\t\t---> This book is not available:( <---\t\t ";
			return;
			
		}
	}
	cout<<"\t\t---> This Email is not Register in our library: <---\t\t"<<endl;
	cout<<"\t\t---> You have to Register yourself first: <---\t\t"<<endl;
	return;
}
void Book_Renew(){
	cout<<"\n\n\t\t\t\t---> Book Renew <---\t\t\t\t\n\n\n";
	string a;
	int b, c;
	cout<<"Enter the Title of the Book: "<<endl;
	getline(cin, a);

	for(int i=0; i<borrow; i++){
		if(a==borrow_title[i]){
			cout<<"Enter the Date when you borrow the book: "<<endl;
			cin>>b;
			if(b==borrow_date[i]){
				cout<<"Enter Today's Date: "<<endl;
				cin>>c;
				if(c<=borrow_due[i]){
					cout<<"\t\t\t---> Book Renew Succesfully: <---\t\t\t"<<endl<<endl;
					cout<<"\t\t\t---> Now You can return book at: ";
					borrow_due[i]=borrow_due[i]+5;
					cout<<borrow_due[i]<<"-June-2023 <---\t\t\t"<<endl<<endl;
					return;
				}else if(c>borrow_due[i]){
					cout<<"\t\t---> We can't renew your book :( <----\t\t"<<endl;
					cout<<"\t\t---> you are out of due, you have to pay fine "<<endl;
					Fine_user[i]="Fine";
					return;
				}
			}else{
				cout<<"\t\t--> You didn't borrow this book at your given date: <--\t\t"<<endl;
				return; }
			
			}
			
	}
	cout<<"\t\t\t---> This book is not borrow yet: <---\t\t\t"<<endl;
	}
void Book_Return(){
	cout<<"\t\t\t\t---> Book Return <---\t\t\t\t\n\n\n";
	string hello;
	int h;
	cout<<"Enter the Title of the Book: "<<endl;
	getline(cin, hello);
	for(int i=0; i<=borrow; i++){
		if(hello==borrow_title[i]){
			cout<<"Enter Today's Date: "<<endl;
			cin>>h;
				if(h<=borrow_due[i]){
					for (int j = i; j < borrow - 1; j++) {
                borrow_title[j] = borrow_title[j + 1];
                borrow_name[j]= borrow_name[j+1];
                borrow_email[j]= borrow_email[j+1];
                borrow_date[j]=borrow_date[j+1];
                borrow_due[j]=borrow_due[j+1];
            	borrow--;
				cout<<"You Return your book successfully: "<<endl;
				return;
				}
				}else {
				cout<<"you have to pay fine: "<<endl;
				cout<<"You can check your fine in fine management system: ";
				Fine_user[i]="Fine";
				fine=false;
				return;
			}
		}
			
	}
	cout<<"This boook is not borrow yet: "<<endl;
	
}
void User_Fine(){
	string name, email;
	int q;
	cout<<"\n\t\t\t\t----> Welcome to Fine and Fee Management <----\t\t\t\t\n\n";
	cout<<"If you get notification then press 1"<<endl;
	cout<<"If you wanna check fine by yourself then press 2"<<endl;
	cout<<"Press: ";
	cin>>q;
	cin.ignore();
	if(q==1){
		cout<<"Enter Your Name: ";
	getline (cin, name);
	for(int i=0; i<borrow; i++){
		if(name==borrow_name[i]){
			cout<<"Enter Your Email: ";
			getline (cin, email);
			if(email==borrow_email[i]){
				if(Fine_user[i]=="Fine"){
					cout<<"You have to pay 500 before "<<borrow_due[i]+5<<"-June-2023"<<endl;
					cout<<"at your book: "<<borrow_title[i]<<endl;
					cout<<"Thank You :) "<<endl;
					return;
				}else{
					cout<<"No Fine :)"<<endl;
					return;
				}
			}			
		}
		cout<<"Incorrect Email: "<<endl;
		return;	
	}
	cout<<"Correct Your Name; "<<endl;
	return;
	}else if(q==2){
		cout<<"Enter Your Name: ";
	getline (cin, name);
	for(int i=0; i<borrow; i++){
		if(name==borrow_name[i]){
			cout<<"Enter Your Email: ";
			getline (cin, email);
			if(email==borrow_email[i]){
				cout<<"Enter today's date ";
				int date;
				cin>>date;
				if(date>=borrow_due[i]){
					cout<<"You have to pay 500 before "<<borrow_due[i]+5<<"-June-2023"<<endl;
					cout<<"at your book: "<<borrow_title[i]<<endl;
					cout<<"Thank You :) "<<endl;
					return;
				}else{
					cout<<"No Fine :)"<<endl;
					return;
				}
			}			
		}
		cout<<"Incorrect Email: "<<endl;
		return;	
	}
}
}
void fine_list(){
	int s;
	cout<<"\n\t\t\t---> List of borrowed books <---\t\t\t";
	if(borrow==0){
		cout<<"No one borrow book yet: "<<endl;
		return;
	}else{
	for(int i=0; i<=borrow; i++){
		cout<<"\n\n\t\t\t---> Number "<<i<<" <---\t\t\t"<<endl<<endl;
		cout<<"Name           : "<<borrow_name[i]<<endl;
		cout<<"Email          : "<<borrow_email[i]<<endl;
		cout<<"Book Title     : "<<borrow_title[i]<<endl;
		cout<<"Borrow date    : "<<borrow_date[i]<<endl;
		cout<<"Due date       : "<<borrow_due[i]<<endl;
		cout<<"----------------------------------------";
	}
	cout<<"\n\nEnter Today's date : "<<endl;
	cin>>s;
	for(int i=0; i<=borrow; i++){
		if(s<=borrow_due[i]){
		cout<<"\n\t\t\t---> This user have to pay fine: <---\t\t\t"<<endl<<endl;
		cout<<"Name           : "<<borrow_name[i]<<endl;
		cout<<"Email          : "<<borrow_email[i]<<endl;
		cout<<"Book Title     : "<<borrow_title[i]<<endl;
		cout<<"Borrow date    : "<<borrow_date[i]<<endl;
		cout<<"Due date       : "<<borrow_due[i]<<endl<<endl;
		cout<<"\t\t\t---> Send Email to this user: <---\t\t\t"<<endl;
		return;
		}
	}
}
	cout<<"No one has to pay fine: "<<endl<<endl;
	
}
void Remove_fine(){
	
}
void fine_management(){
	while(true){
	
	int x;
	cout<<"\n\n\t\t\t\t----> Welcome to Fine Management <----\t\t\t\t"<<endl<<endl<<endl;
	cout<<"--->  Fine                    --->  (Press-1) "<<endl;
	cout<<"--->  Remove Fine             --->  (Press-2) "<<endl;
	cout<<"--->  Exit                    --->  (Press-3) "<<endl;
	cout<<"Enter your choice :"<<endl;
	cin>>x;
	switch (x){
		case 1:
			fine_list();
			break;
		case 2:
			cout<<"No fine yet \n\n";
			break;
		case 3:
			adminmain();
			cout<<"Existing...."<<endl;
			break;
		
		default:
			cout<<"Invalid number: "<<endl;
			
		break;
			
	}
}
	
}
void Book_Borrow_Renew_Return(){
	int l;
	cout<<"\n\n\t\t\t\t----> Book Borrow, Renew & Return <----\t\t\t\t\n\n\n";
	cout<<"--->  Book Borrow            --->  (Press-1) "<<endl;
	cout<<"--->  Book Renew             --->  (Press-2) "<<endl;
	cout<<"--->  Book Return            --->  (Press-3) "<<endl;
	cout<<"4-->  Exit                   --->  (Press-4) "<<endl;
	cout<<"Enter your choice: ";
	cin>>l;
	cin.ignore();
	switch(l){
		case 1:
		Book_Borrow();
		break;
		case 2:
		Book_Renew();
		break;
		case 3:
		Book_Return();
		break;
		case 4:
		cout<<"existing...."<<endl;
		break;
		default:
		cout<<"Invalid number: ";
		break;	
	}
}

void urooj(){
initializeBooks();
int choice;
    while (true) {
        cout << "\n\t\t\t\t----> Book Searching and Browsing <----\t\t\t\t" <<endl;
        cout << "--->  Search for a Book by Title     ---> (Press-1) " <<endl;
        cout << "--->  Browse Books by Author         ---> (Press-2) " <<endl;
        cout << "--->  Display all the books          ---> (Press-3) " <<endl;
        cout << "--->  Exit                           ---> (Press-4) " <<endl;
        cout <<endl;
        cout << "Press: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                search_books_by_title();
                break;
            case 2:
            	browse_books_by_author();
                break;
			case 3:
			initializeBooks();
			void displayBooks();
			break;
            case 4:
                cout << "\t\t---> Existing Book searching and browsing <---\t\t\n";
                cout<<"\n\nPress 3 for Profile Management" <<endl<<endl;
                cout<<"Press 4 for Rules and Regulations of the Library" <<endl<<endl;
                cout<<"Press 5 for Book Borrow, Renewal and Return" <<endl<<endl;
                cout<<"Press 6 for Fine and Fee Management" <<endl<<endl;
                cout<<"Press 7 for Book Searching and Browsing" <<endl<<endl;
           		cout<<"Press 8 if you want to go back"<<endl<<endl;  

int user_select;
cin>>user_select;
cout<<endl;

if(user_select == 8){
cout<<"\t\t\t----------->>   Welcome on library Management Portal   <<-----------"<<endl<<endl<<endl;
cout<<"Press 1 for Registration" <<endl<<endl;
cout<<"Press 2 for Authentication (Login) " <<endl<<endl;
cout<<"Press 3 for Welcome Page"<<endl<<endl;  
int user_select;
cin>>user_select;
cout<<endl;
if(user_select == 3){
mainfunc();
}
else if(user_select == 2){
user_Authentication();


}
        switch(user_select){
           
            case 1:
            user_registration();
            break;          
        }
}else if(user_select==7){
urooj();
}


else if(user_select == 4){
user_lib_rules();
}
else if(user_select == 3){
user_Profile_management();
}
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
void addBook() {
    if (numBooks >= 500) {
        cout << "\t----> Maximum number of books reached. <----\t\n";
        return;
    }
    cout<<"\t\t\t\t----> Add a Nw Book in the Library <----\t\t\t\t"<<endl<<endl;
    Book newBook;
    cout << "Enter the title of the book: ";
    getline(cin, newBook.title);
    cout << "\nEnter the author of the book: ";
    getline(cin, newBook.author);
    cout << "\nEnter the ISBN of the book: ";
    getline(cin, newBook.ISBN);
    newBook.available = true;
    books[numBooks] = newBook;
    numBooks++;
    cout << "\t\t---> Book added successfully :) <---\t\t\n"<<endl;
}
void removeBook() {
	cout<<"\t\t\t\t----> Remove Book from the Library <----\t\t\t\t"<<endl<<endl;
    if (numBooks == 0) {
        cout << "\t\t---> No books in the library <---\t\t\n"<<endl;
        return;
    }
    cout << "Enter the ISBN of the book to remove: ";
    string ISBN;
    getline(cin, ISBN);
    for (int i = 0; i < numBooks; i++) {
        if (books[i].ISBN == ISBN) {
            for (int j = i; j < numBooks - 1; j++) {
                books[j] = books[j + 1];
            }
            numBooks--;
            cout << "\t\t---> Book removed successfully. <---\t\t\n"<<endl;
            return;
        }
    }
    cout << "\t\t---> Book not found. <---\t\t\n"<<endl;
}
void editBook() {
	cout<<"\t\t\t\t----> Edit the Book in the Library <----\t\t\t\t"<<endl<<endl;
    if (numBooks == 0) {
        cout << "\t\t---> No books in the library <---\t\t\n"<<endl ;
        return;
    }
    cout << "\nEnter the ISBN of the book to edit: ";
    string ISBN;
    getline(cin, ISBN);
    for (int i = 0; i < numBooks; i++) {
        if (books[i].ISBN == ISBN) {
            cout << "\nEnter the new title of the book: ";
            getline(cin, books[i].title);
            cout << "\nEnter the new author of the book: ";
            getline(cin, books[i].author);
            cout << "\n\t\t---> Book edited successfully :) <---\t\t\n";
            return;
        }
    }
    cout << "\t\t---> Book not found :( <---\t\t\n"<<endl;
}
void displayBooks() {

    if (numBooks == 0) {
        cout << "\n\t----> No books in the library. <----\t\n"<<endl;
        return;
    }
    cout << "\n\t-----> Books in the library : <-----\t\n"<<endl;
    for (int i = 0; i < numBooks; i++) {
    	cout<<"\t\t\t---> Book "<<i<<endl<<endl;
        cout << "Title  : " << books[i].title << endl;
        cout << "Author : " << books[i].author << endl;
        cout << "ISBN   : " << books[i].ISBN << endl;
        if (books[i].available) {
        cout << "Status : Available\n"<<endl;
        } else {
        cout << "Status : Not Available\n"<<endl;
        }
        cout << endl;
    }
   
}
void choice(){
initializeBooks();
int choice;
    do {
        cout << "\t\t\t----> Welcome to the Book Management System. <----\t\t\t\n"<<endl;
        cout << "---> Add a book          --->(Press-1) \n";
        cout << "---> Remove a book       --->(Press-2) \n";
        cout << "---> Edit a book         --->(Press-3) \n";
        cout << "---> Display books       --->(Press-4) \n";
        cout << "---> Exit                --->(Press-5) \n";
        cout << "\nEnter number: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                removeBook();
                break;
            case 3:
                editBook();
                break;
            case 4:
            displayBooks();
            adminmain();
            break;
            void choice();
            continue;
            case 5:
                cout << "\t\t\t---> Exiting Book Management :) <---\t\t\t\n"<<endl;
                adminmain();
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);
}
   
   void admin_signup(){
    if(total == 0){
   
       for(int i = 1; i <= 1; i++){
              cout<<"\n\n\t\t======> Welcome on Admin Signup Page"<<endl<<endl;
          cout<<"Enter your first name : ";
          cin>>admin_fname[i];
          cout<<endl;
          cout<<"Enter your last name : ";
          cin>>admin_lname[i];
          cout<<endl;
        cout<<"Enter Email Like; xyz@xyz.com : ";
        cin>>admin_email[i];
        cout<<endl;
        cout<<"Enter Password : ";
        cin>>admin_pass[i];
        cout<<endl;
       }
        cout<<"Press 1 for signup ";
        int ent;
        cin>>ent;
        cout<<endl;
       
       if(ent == 1){
             
                       cout<<"\t\t\t---> Signup Successfully :) <---\t\t\t"<<endl<<endl;
                         total = total + ent;
                         cout<<endl;
}

else{
cout<<"\t======>  You haven't press 1 so you have to register again :( "<<endl<<endl<<endl;
admin_signup();
}
cout<<endl;
}
else{
       for(int i = total+1; i <= total+1; i++){
                    cout<<"\n\n\t\t======> Welcome on Admin Signup Page"<<endl<<endl;
        cout<<"Enter your first name : ";
        cin>>admin_fname[i];
        cout<<endl;
        cout<<"Enter your last name : ";
        cin>>admin_lname[i];
        cout<<endl;
        cout<<"Enter Email Like; xyz@xyz.com : ";
        cin>>admin_email[i];
        cout<<endl;
        cout<<"Enter Password : ";
        cin>>admin_pass[i];
        cout<<endl;
       }
       
        cout<<"Press 1 for signup ";
        int ent;
        cin>>ent;
        cout<<endl;
      if(ent == 1){
             
            cout<<"\t\t\t---> Signup Successfully :) <---\t\t\t"<<endl<<endl;
                         total = total + ent;
//                          cout<<endl;
}

else{
cout<<"\t======>  You haven't press 1 so you have to register again "<<endl<<endl<<endl;
admin_signup();
}
// cout<<endl;
}
}


void adminmain(){
cout<<"\t\t\t----------->>   Welcome on library Management Portal   <<-----------"<<endl<<endl<<endl;
                cout<<"Press 1 for User Management "<<endl<<endl;
                cout<<"Press 2 for Book Management "<<endl<<endl;
                cout<<"Press 3 for Fine Management "<<endl<<endl;
				cout<<"Press 4 for Budget Management "<<endl<<endl;
                cout<<"Press 5 for Reservation Management "<<endl<<endl;
                cout<<"Press 6 for Logout "<<endl<<endl;
               
                int user_select;
cin>>user_select;
cout<<endl;

if(user_select == 4){
	budgte_Management();
}

else if(user_select == 6){
mainfunc();
}

else if(user_select == 1){
User_Management();
}else if(user_select==2){
choice();
}else if(user_select==5){
	User_Book_Reservation_Management();
}else if(user_select==3){
	fine_management();
}

}


    void admin_login(){
        string email,pass;
                      cout<<"\n\n\t\t======> Welcome on Admin Login Page"<<endl<<endl;
        cout<<"Enter your email : ";
        cin>>email;
        cout<<endl;
        cout<<"Enter your password : ";
        cin>>pass;
        cout<<endl;
       
        if(total == 0){
        cout<<"\t\t\t---> No Acccount found :( <---\t\t\t"<<endl<<endl;
//         break;
}
       
        for(int i = 1; i <= total; i++){
       
       
           
            if(email == admin_email[i] && pass == admin_pass[i]){
            cout<<"\t\t\t---> Logged In Successfully! :) <---\t\t\t"<<endl<<endl<<endl;
            while(true){
                adminmain();
            }
        }
           
            else if(email != admin_email[i] && pass == admin_pass[i]){
                cout<<"Your Email Adress is Incorrect, Please Recorrect Your Email Adress"<<endl<<endl;
                break;
            }
           
            else if(email == admin_email[i] && pass != admin_pass[i]){
                cout<<"Your Password is Incorrect, Please Recorrect Your Password "<<endl<<endl;
                break;
            }
           
            else if(email != admin_email[i] && pass != admin_pass[i]){
 count++;
            }
        }

       
        for(int j = 1; j <=count; j++){
  if(email != admin_email[j] && pass != admin_pass[j])
  cout<<"Your email and password both are inccorect .....:( Try Again!"<<endl<<endl;
  break;
 }


       
    }
   

void user_registration(){
    if(tot == 0){
   
       for(int i = 1; i <= 1; i++){
              cout<<"\n\n\t\t======> Welcome on User Registeration Page"<<endl<<endl;
          cout<<"Enter your first name : ";
          cin>>user_fname[i];
          cout<<endl;
          cout<<"Enter your last name : ";
          cin>>user_lname[i];
          cout<<endl;
        cout<<"Enter Email Like; xyz@xyz.com : ";
        cin>>user_email[i];
        cout<<endl;
        cout<<"Enter Password : ";
        cin>>user_pass[i];
        cout<<endl;
        cout<<"Enter Private key : ";
        cout<<"\n\n\t\t\tNote : This Key will help You if you forgot your password :\t\t\t "<<endl;
        cout<<"\t\t\tIf you forget this key you have to contact with admin :)\t\t\t "<<endl;
        cout<<"\t\t\t\t\t Thank You :) \t\t\t\t\t"<<endl<<endl;
        cin>>userprivatekey[i];
//        cout<<endl<<endl;
       }
        cout<<"Press 1 for signup :";
        int ent;
        cin>>ent;
        cout<<endl;
       
       if(ent == 1){
             
                       cout<<"\t\t\t---> Signup Successfully :) <---\t\t\t"<<endl<<endl;
                         tot = tot + ent;
                         cout<<endl;
}

else{
cout<<"\t======>  You haven't press 1 so you have to register again :( "<<endl<<endl<<endl;
user_registration();
cout<<endl;
}
}
else{
       for(int i = tot+1; i <= tot+1; i++){
                    cout<<"\n\n\t\t======> Welcome on User Registeration Page"<<endl<<endl;
        cout<<"Enter your first name : ";
        cin>>user_fname[i];
        cout<<endl;
        cout<<"Enter your last name : ";
        cin>>user_lname[i];
        cout<<endl;
        cout<<"Enter Email Like; xyz@xyz.com : ";
        cin>>user_email[i];
        cout<<endl;
        cout<<"Enter Password : ";
        cin>>user_pass[i];
        cout<<endl;
        cout<<"Enter Private key : ";
        cout<<"\n\n\t\t\tNote : This Key will help You if you forgot your password :\t\t\t "<<endl;
        cout<<"\t\t\tIf you forget this key you have to contact with admin :)\t\t\t "<<endl;
        cout<<"\t\t\t\t\t Thank You :) \t\t\t\t\t"<<endl<<endl;
        cin>>userprivatekey[i];

       }
       
        cout<<"\nPress 1 for signup "<<endl;
        int ent;
        cin>>ent;
        cout<<endl;
      if(ent == 1){
             
                       cout<<"\t\t\t---> Signup Successfully :) <---\t\t\t"<<endl<<endl;
                         tot = tot + ent;
//                          cout<<endl;
}

else{
cout<<"\t======>  You haven't press 1 so you have to register again :( "<<endl<<endl<<endl;
user_registration();
}
// cout<<endl;
}
}



void mainfunc(){
cout<<endl<<endl<<"\t\t\t--------------------Welcome on Library Management Portal------------------"<<endl<<endl;
   cout<<"\t\t\t------------------>    Press 3 if you are an admin     <------------------"<<endl;
   cout<<"\t\t\t------------------>     Press 4 if you are a user      <------------------"<<endl<<endl;
   int enter;
   cin>>enter;
   cout<<endl;
   if(enter == 3){
    while(true){
        int press;
                        cout<<"\t\t\t----------->>   Welcome on Admin's library Management Portal   <<-----------"<<endl<<endl<<endl;
        cout<<"\t==============> Press 1 for login"<<endl<<endl;
        cout<<"\t==============> Press 2 for signup"<<endl<<endl;
        cout<<"\t==============> Press 3 if you want to go back on welcome page"<<endl<<endl;
        cin>>press;
       cout<<endl;
       
        switch(press){
           
            case 1:
            admin_login();
            break;
           
            case 2:
            admin_signup();
            break;
           
           case 3:
            mainfunc();
            break;
           
            default:
            cout<<"Invalid number type 1 or 2"<<endl<<endl;
           
        }
    }
   }
   else if(enter == 4){
     while(true){
                cout<<"\t\t\t----------->>   Welcome on user's library Management Portal   <<-----------"<<endl<<endl<<endl;
cout<<"Press 1 for Registration" <<endl<<endl;
cout<<"Press 2 for Authentication (Login) " <<endl<<endl;
cout<<"Press 3 for Welcome Page"<<endl<<endl;  
int user_select;
cin>>user_select;
cout<<endl;
if(user_select == 3){
mainfunc();
}

else if(user_select == 2){
user_Authentication();


}
        switch(user_select){
           
            case 1:
            user_registration();
            break;          
        }
        }
   }
   
   else{
   
    while(true){
 
       cout<<"Invalid number type 3 or 4 "<<endl<<endl;
       cout<<"\t\t\t------------------>    Press 3 if you are an admin     <------------------"<<endl;
   cout<<"\t\t\t------------------>     Press 4 if you are a user      <------------------"<<endl<<endl;
   int enter;
   cin>>enter;
   cout<<endl;
   
    if(enter == 3){
    while(true){
        int press;
        cout<<"\t==============> Press 1 for login"<<endl<<endl;
        cout<<"\t==============> Press 2 for signup"<<endl<<endl;
        cout<<"\t==============> Press 3 if you want to go back on welcome page"<<endl<<endl;
        cin>>press;
       cout<<endl;
       
        switch(press){
           
            case 1:
            admin_login();
            break;
           
            case 2:
            admin_signup();
            break;
           
            case 3:
            mainfunc();
            break;
           
            default:
            cout<<"Invalid number type 1 or 2"<<endl<<endl;
           
        }
    }
   }
   
   else if(enter == 4){
     while(true){
cout<<"\t\t\t----------->>   Welcome on user's library Management Portal   <<-----------"<<endl<<endl<<endl;
cout<<"Press 1 for Registration" <<endl<<endl;
cout<<"Press 2 for Authentication (Login) " <<endl<<endl;
cout<<"Press 3 for Welcome Page"<<endl<<endl;    
int user_select;
cin>>user_select;
cout<<endl;
if(user_select == 3){
mainfunc();
}

else if(user_select == 2){
user_Authentication();
}


        switch(user_select){
           
            case 1:
            user_registration();
            break;

           
        }    
    }
   }  
   }
}
}


void user_Authentication(){

string email,pass;
                      cout<<"\n\n\t\t======> Welcome on User Authentication Page"<<endl<<endl;
        cout<<"Enter Your Email : ";
        cin>>email;
        cout<<endl;
        cout<<"Enter Your Password : ";
        cin>>pass;
        cout<<endl;
        for(int j = 1; j <= tot; j++){
           
            if(email == user_email[j] && pass == user_pass[j]){
            cout<<"\t\t\t---> Logged In Successfully! :) <---\t\t\t"<<endl<<endl;
//             while(true){

                cout<<"\n\nPress 3 for Profile Management" <<endl<<endl;
                cout<<"Press 4 for Rules and Regulations of the Library" <<endl<<endl;
                cout<<"Press 5 for Book Borrow, Renewal and Return" <<endl<<endl;
                cout<<"Press 6 for Fine and Fee Management" <<endl<<endl;
                cout<<"Press 7 for Book Searching and Browsing" <<endl<<endl;
           		cout<<"Press 8 if you want to go back"<<endl<<endl;  

int user_select;
cin>>user_select;
cout<<endl;

if(user_select == 8){
cout<<"\t\t\t----------->>   Welcome on library Management Portal   <<-----------"<<endl<<endl<<endl;
cout<<"Press 1 for Registration" <<endl<<endl;
cout<<"Press 2 for Authentication (Login) " <<endl<<endl;
cout<<"Press 3 for Welcome Page"<<endl<<endl;  
int user_select;
cin>>user_select;
cout<<endl;
if(user_select == 3){
mainfunc();
}
else if(user_select == 2){
user_Authentication();


}
        switch(user_select){
           
            case 1:
            user_registration();
            break;          
        }
}else if(user_select==7){
urooj();
}else if(user_select==5){
	Book_Borrow_Renew_Return();
}else if(user_select==6){
	User_Fine();
}


else if(user_select == 4){
user_lib_rules();
}
else if(user_select == 3){
user_Profile_management();
}
// }

            }
       
           
            else if(email != user_email[j] && pass == user_pass[j]){
                cout<<"Your Email Adress is Incorrect, Please Type Correct Email Adress"<<endl<<endl;
            }
           
            else if(email == user_email[j] && pass != user_pass[j]){
                cout<<"Your Password is Incorrect, Please Type Correct Password "<<endl<<endl;
            }
           
            else if(email != user_email[j] && pass != user_pass[j]){
 countt++;
            }
        }

       
        for(int j = 1; j <= countt; j++){
  if(email != user_email[j] && pass != user_pass[j])
  cout<<"Your email and password both are inccorect ..... Try Again!"<<endl<<endl;
  break;
 }
                     
//          else if(email != user_email[j] && pass != user_pass[j]){
//                cout<<"Your email and password both are incorrect "<<endl<<endl;
//            }
           
       
}



void budgte_Management(){
		cout<<"\n\n\t\t\t\t----> Welcome to Budget Management <----\t\t\t\t"<<endl<<endl<<endl;
		int tota;
		while(true){
		cout<<endl;
cout<<"--->     Current Budget                                     --->(Press-1) "<<endl<<endl;
cout<<"--->     Budget Adjustment                                  --->(Press-2) "<<endl<<endl;
cout<<"--->     Reports of all expenses                            --->(Press-3) "<<endl<<endl;
cout<<"--->     Exit from this function                            --->(Press-4) "<<endl<<endl;
int press;
cin>>press;
cout<<endl;
string date1,date,reason;
int bud,budg;


if(press == 1){
		cout<<"\t\t\t\t---> Current Budget <---\t\t\t\t\n\n\n";
		if(tota == 0){
			cout<<"\t\t\t\t--------- Still no budget ----------"<<endl<<endl;
		} 
		else {
			cout<<"Current budget of your library is " <<budget <<endl<<endl;
		}
	
}

else if(press == 3){
				cout<<"\t\t\t\t---> Reports of all expenses <---\t\t\t\t\n\n\n";

	if(tota == 0){
		cout<<"There is no report "<<endl<<endl;
	}
	else{
		cout<<"\t\t\t----->> Record of total balance <<-----"<<endl<<endl;
		cout<<"Current Budget : " <<budget<<endl<<endl;
		cout<<"\t\t\t----->> Record of adding balance <<-----"<<endl<<endl;
		cout<<"Date : " <<date1<<endl<<endl;
		cout<<"Amount : " <<bud<<endl<<endl;
		
		cout<<"\t\t\t----->> Record of taken balance <<-----"<<endl<<endl;
		cout<<"Date : " <<date<<endl<<endl;
		cout<<"Amount : " <<budg<<endl<<endl;
		cout<<"Reason : " <<reason<<endl<<endl;
	}
	
}

else if(press == 2){
			cout<<"\t\t\t\t---> Budget Adjustment <---\t\t\t\t\n\n\n";
			int enter;
			cout<<"Press 1 if you want to add budget " <<endl<<endl;
			cout<<"Press 2 if you want to take budget for anything "<<endl<<endl;
			cin>>enter;
			
			if(enter == 1){
				cout<<"\t\t============>>>  Add Budget"<<endl<<endl;							
				cout<<"Enter how much budget do you want to add"<<endl<<endl;
				cin>>bud;
				cout<<"Enter date like; (DD/MM/YY)"<<endl<<endl;
				cin>>date1;
				tota ++;
				budget+= bud;	
				cout<<"Budget added successfully"<<endl<<endl;			
			}
			
			else if(enter == 2){
				cout<<"\t\t============>>>  Take Budget"<<endl<<endl;
			
				cout<<"Enter for which purpose do you want to take budget"<<endl<<endl;
				cin>>reason;
				cout<<"Enter date like; (DD/MM/YY)"<<endl<<endl;
				cin>>date;
				cout<<"Enter how much budget do you want to take"<<endl<<endl;
				cin>>budg;
//				while(true){
				
				if(budg > bud){
					cout<<"\n\nThis amount is not available in the system"<<endl<<endl;
					cout<<"Total amount in the system is : "<<budget<<endl<<endl;
				}
				else{				
				budget-= budg;
				cout<<"\nBudget taken successfully"<<endl<<endl;
		}
//	}
			}

}



else if(press == 4){
	adminmain();
}

else{
	cout<<"Invalid number ------ Enter number from 1 - 4"<<endl<<endl;
}
}
}


void user_lib_rules(){

while(true){
cout<<"\n\n\t\t\t----------->>   Rules and Regulations of the Library are mentioned below   <<-----------"<<endl<<endl;
cout<<"--->  Rules about Borrowing Library Materials            --->(Press-1) "<<endl<<endl;
cout<<"--->  Rules about Damage & Loss of Library Materials     --->(Press-2) "<<endl<<endl;
cout<<"--->  General Rules & Regulations                        --->(Press-3) "<<endl<<endl;
cout<<"--->  Exit from this function                            --->(Press-4) "<<endl<<endl;
int press;
cin>>press;

switch(press){

    case 1:
cout<<"\t\t\t--->   Rules about Borrowing Library Materials   <---\t\t\t"<<endl<<endl;
cout<<"1- :  Only registered users in the library will be allowed to borrow library material"<<endl<<endl;
cout<<"2- :  Late returns of borrowed books shall attract a penalty at a rate to be determined from time to time"<<endl<<endl;
cout<<"3- :  The Librarian in charge shall reserve the right to recall a book on loan "<<endl<<endl;
cout<<"4- :  These books shall be returned within the shortest time possible and a fine shall be charged for any inexplicable delay"<<endl<<endl;
cout<<"5- :  No user shall take a book out of the Library unless it is properly issued from online System"<<endl<<endl<<endl;
break;

case 2:
cout<<"\t\t\t--->   Rules about Damage & Loss of Library Materials   <---\t\t\t"<<endl<<endl;
    cout<<"1- :  Any user who causes damage to library materials or other property will foot the cost of repair"<<endl<<endl;
    cout<<"2- :  Users will be held responsible for any material lost while in their custody and will be required to foot the cost of replacement"<<endl<<endl;
    cout<<"3- :  Lost books once recovered will remain the property of the Library; monies charged for replacement will not be refunded "<<endl<<endl<<endl;
    break;
   
    case 3:
cout<<"\t\t\t--->   General Rules & Regulations   <---\t\t\t"<<endl<<endl;
cout<<"1- :  The Librarian shall reserve the right to withdraw or refuse Library services to any user who disregards the above-listed rules and regulations"<<endl<<endl;
cout<<"2- :  Anyone who will return after the given time will be charged"<<endl<<endl;
cout<<"3- :  If there is any issue in the account of library portal should resest their password immediately"<<endl<<endl<<endl;
    break;
   
    case 4:
    useable();
   
    default:
    cout<<"Invalid Number :( "<<endl<<endl;
}
}
}

void user_Profile_management(){

while(true){
cout<<"\t\t\t----> Profile Management <----\t\t\t"<<endl<<endl<<endl;
cout<<"--->  Update Your Information    ---> (Press-1) "<<endl<<endl;
cout<<"--->  Forget Password            ---> (Press-2) "<<endl<<endl;
cout<<"--->  Wanna Go Back              ---> (Press-3) "<<endl<<endl;

int press;
cin>>press;

if(press == 1){
string eml,pas;
cout<<"\t\t--->  Update Information <---\t\t"<<endl<<endl;
cout<<"Enter Your Old Email : ";
cin>>eml;
cout<<"\nEnter Your Old password : ";
cin>>pas;

for(int i = 1; i <= tot; i++){

if(eml == user_email[i] && pas == user_pass[i]){

cout<<"\n\t\t---> Your old information : <---\t\t"<<endl<<endl;
cout<<"First Name  : " <<user_fname[i]<<endl<<endl;
cout<<"Last Name   : " <<user_lname[i]<<endl<<endl;
cout<<"Email       : "  <<user_email[i]<<endl<<endl;
cout<<"Password    : " <<user_pass[i]<<endl<<endl;
cout<<"Private key : " <<userprivatekey[i]<<endl<<endl;

cout<<"\n\t\t---> Update Information <---\t\t "<<endl<<endl;
cout<<"First Name : ";
cin>>user_fname[i];
cout<<"\nLast Name : ";
cin>>user_lname[i];
cout<<"\nEmail : ";
cin>>user_email[i];
cout<<"\nPassword : ";
cin>>user_pass[i];
cout<<"\n Private key : ";
cout<<"\n\n\t\t\tNote : This Key will help You if you forgot your password :\t\t\t "<<endl;
cout<<"\t\t\tIf you forget this key you have to contact with admin :)\t\t\t "<<endl;
cout<<"\t\t\t\t\t Thank You :) \t\t\t\t\t"<<endl<<endl;
cin>>userprivatekey[i];
cout<<"\t\t\t---> Your information has been updated :) <---\t\t\t\n\n\n";
        return;
}
}
cout<<"\t\t\t----> Didn't found any account\t\t\t\n\n";
return;	
}

else if(press == 2){

cout<<"\t\t\t\t---->  Forget Password? <----\t\t\t\t"<<endl<<endl;
cout<<"Enter your private key to check your password: "<<endl<<endl;
string keyy;
cin>>keyy;
for(int i = 1; i<=tot; i++){
	
if(keyy == userprivatekey[i]){
cout<<"Your old password : ";
cout<<user_pass[i];
cout<<endl<<endl;
return;
}

}
cout<<"\t\t\t----> Enter Correct Private key :(  <----\n";
cout<<"\t\t\t----> Or Contact with your admin    <-----\n\n";
return;	

}

else if(press == 3){

useable();
}

else{
cout<<"\nYou have choosed invalid number :( "<<endl<<endl;
}

}
}


void User_Management(){

while(true){

cout<<"\n\n\t\t======> Welcome on User Management Page"<<endl<<endl;
cout<<"--->  Information of all the user's account               --->  (Press-1) : "<<endl<<endl;
cout<<"--->  Update the info of any user's account               --->  (Press-2) : "<<endl<<endl;
cout<<"--->  Create user's new account                           --->  (Press-3) : "<<endl<<endl;
cout<<"--->  Delete user's account                               --->  (Press-4) : "<<endl<<endl;
cout<<"--->  Reset password of user's account                    --->  (Press-5) : "<<endl<<endl;
cout<<"--->  Check Any Specific user's account information       --->  (Press-6) : "<<endl<<endl;
cout<<"--->  Go Back                                             --->  (Press-7) : "<<endl<<endl;  
int press;
cin>>press;

if(press == 4){

cout<<"\t\t\t\t----> Delete Account <----\n\n";
string dummy_email;

cout<<"Enter Email for Delete Account : "<<endl<<endl;

cin>>dummy_email;

for(int i=0;i<tot;i++)

{

if(dummy_email==user_email[i])

{

for(int j=i;j<tot;j++)

{

user_fname[j] = user_fname [j+1];

user_lname[j] = user_lname [j+1];

user_email[j] = user_email [j+1];

user_pass[j]=user_pass [j+1];

userprivatekey[j] = userprivatekey [j+1];

    }

tot--;

cout<<"\t\t\t---> Your required account is deleted <---\t\t\t\n"<<endl;
return;
}
}
cout<<"\t\\t\tAcount didn't find "<<endl<<endl;
return ;
}


if(press == 6)
{
cout<<"\t\t\t\t----> User Information Page : <----\t\t\t\t" <<endl<<endl;
cout<<"\t\t---> Check Info of Specific User: <---\t\t"<<endl<<endl;
string email;
cout<<"Email : ";
cin>>email;
cout<<endl<<endl;
for(int i = 1; i <=tot; i++){
if(email == user_email[i]){

cout<<"First Name   : " <<user_fname[i]<<endl;
cout<<"Last Name    : " <<user_lname[i]<<endl;
cout<<"Email        : "  <<user_email[i]<<endl;
cout<<"Password     : " <<user_pass[i]<<endl;
cout<<"Private Key  : " <<userprivatekey[i]<<endl;
}
cout<<"-------------------------------------------"<<endl<<endl;
return;
}
cout<<"\t\t\t-----> No Email Found <--------\t\t\t\n\n";
return;
}

else if(press == 5){
cout<<"\t\t\t\t----> Reset User's Password <----\t\t\t\t"<<endl<<endl;

string email;
    cout<<"Enter User's Email : "<<endl;
cin>>email;
cout<<endl<<endl;
for(int i = 1; i <= tot; i++){

if(email == user_email[i]){
cout<<"---> Enter new password of user"<<endl<<endl;
cout<<"New Password : ";
cin>>user_pass[i];
cout<<"\n\n\t\t\t---> Password has been reset :) <---\t\t\t"<<endl<<endl;
return;
}
}
cout<<"Wrong email\n\n";
return;
}

else if(press == 3 ){

user_registration();
}

else if(press == 2){

cout<<"\t\t\t\t----> Update Usr's Information <----\t\t\t\t" <<endl<<endl;

string email;

cout<<"Enter Email of User : ";
cin>>email;

for(int i = 1; i <=tot; i++){

if(email == user_email[i]){

cout<<"\n\t\t\t---> Old information of this User <---\t\t\t"<<endl<<endl;
cout<<"First name : " <<user_fname[i]<<endl<<endl;
cout<<"Last name : " <<user_lname[i]<<endl<<endl;
cout<<"Email : "  <<user_email[i]<<endl<<endl;
cout<<"Password : " <<user_pass[i]<<endl<<endl;
cout<<"Private key : " <<userprivatekey[i]<<endl<<endl;

cout<<"\n\t\t\t---> Update Account's info <---\t\t\t"<<endl<<endl;
cout<<"Enter First name : ";
cin>>user_fname[i];
cout<<"\nEnter Last name : ";
cin>>user_lname[i];
cout<<"\nEnter Email : ";
cin>>user_email[i];
cout<<"\nEnter Password : ";
cin>>user_pass[i];
cout<<"Enter Private key : ";
cout<<"\n\n\t\t\tNote : This Key will help You if you forgot your password :\t\t\t "<<endl;
cout<<"\t\t\tIf you forget this key you have to contact with admin :)\t\t\t "<<endl;
cout<<"\t\t\t\t\t Thank You :) \t\t\t\t\t"<<endl<<endl;
cin>>userprivatekey[i];
               
cout<<"\t\t\t---> Your information has been Updated :) <---\t\t\t\n\n";
return;
}

}
  cout<<"\n\n\t\t\t---> No Record of this Email Address...! <---\t\t\t"<<endl<<endl;
  return;
                    

}
else if(press == 1){

for(int i = 1; i <= tot; i++){

cout<<"\t\t\t\t----> User Information Page " <<i <<" <----\t\t\t\t"<<endl<<endl<<endl;
cout<<"\t\t---> Information of user " <<i <<" <---\t\t"<<endl<<endl;
cout<<"First Name  : " <<user_fname[i]<<endl;
cout<<"Last Name   : " <<user_lname[i]<<endl;
cout<<"Email       : "  <<user_email[i]<<endl;
cout<<"Password    : " <<user_pass[i]<<endl;
cout<<"Private Key : " <<userprivatekey[i]<<endl;
}
          if(tot == 0){
cout<<"\n\t\t\t---> No Records :( <---\t\t\t"<<endl<<endl;
}
}

if(press == 7){
adminmain();
}
}
}

int main(){
mainfunc();
    return 0;
}



