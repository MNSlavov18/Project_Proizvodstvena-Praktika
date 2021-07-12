#include <iostream>
#include <string>
using namespace std;
bool option1Check = false;

struct CUSTOMER
{
	int Id;
	string Username;
	string Password;
	string First_Name;
	string Last_Name;
	string Address;
	string Student_Name;
	int Year_of_student;
};
bool isAdmin(string UsernName, string pass)
{
	string admin = "admin";
	string adminPass = "adminpass";
	if (UsernName == admin and adminPass == pass)
	{
		cout << "Correct Password and Username!\nAccess Granted!" << endl;
		return true;
	}
	else
	{
		cout << "Wrong Password or Username! " << endl;
		return false;
	}
}
void createCustomer(CUSTOMER* customers, int& customerCount, CUSTOMER newOrder, int& maxId) {
	newOrder.Id = maxId;
	customers[customerCount] = newOrder;
	customerCount++;
	maxId++;
}
int getCustomerById(CUSTOMER* customers, int& customerCount, int Id )
{
	for (int i = 0; i < customerCount; i++)
	{
		if (customers[i].Id == Id)
		{
			return i;
		}
	}

	return -1;
}
void updateCustomer(CUSTOMER* customers, int& customerCount, CUSTOMER newCustomer, int& maxId)
{
	int index = getCustomerById(customers, customerCount, maxId);
	customers[index] = newCustomer;
}

void deleteCustomer(CUSTOMER* customer, int& customerCount, int Id) {

	int index = getCustomerById(customer, customerCount, Id);
	for (int i = index; i < customerCount - 1; i++)
	{
		customer[i] = customer[i + 1];
	}
	customerCount--;

}
CUSTOMER getOrder(CUSTOMER* customer, int& customerCount, int Id)
{
	int index = getCustomerById(customer, customerCount, Id);
	if (index != Id)
	{
		cout << "Enter valid ID";
		cin >> index;
	}
	return customer[index];
}

void showCustomerMenu(CUSTOMER* customers, int& customerCount, int& maxId)
{

	cout << "\n List of the Customer: " << endl;

	for (int i = 0; i < customerCount; i++)
	{
		cout << "Customer's id:" << customers[i].Id << endl;;
		cout << "Customer's Username: " << customers[i].Username << endl;
		cout << "Customer's Password: " << customers[i].Password << endl;
		cout << "Customer's First name: " << customers[i].First_Name << endl;
		cout << "Customer's Last Name: " << customers[i].Last_Name << endl;
		cout << "Customer's Address: " << customers[i].Address << endl;
		cout << "Customer's Student Name: " << customers[i].Student_Name << endl;
		cout << "Customer's Year of student: " << customers[i].Year_of_student << endl;
	}
}
void search(CUSTOMER* customers, int& customerCount )
{
	CUSTOMER customer;
	string familyParents;
	getline(cin, familyParents);
	if (familyParents == customer.Last_Name) 
	{
		for (int i = 0; i < customerCount; i++)
		{
			cout << "Customer's id:" << customers[i].Id << endl;;
			cout << "Customer's Username: " << customers[i].Username << endl;
			cout << "Customer's Password: " << customers[i].Password << endl;
			cout << "Customer's First name: " << customers[i].First_Name << endl;
			cout << "Customer's Last Name: " << customers[i].Last_Name << endl;
			cout << "Customer's Address: " << customers[i].Address << endl;
			cout << "Customer's Student Name: " << customers[i].Student_Name << endl;
			cout << "Customer's Year of student: " << customers[i].Year_of_student << endl;
		}
	}
		else
		{
			cout << "There aren't people with that name!";
		}
	}
void CustomerMenu(CUSTOMER* customers, int& customerCount, int& maxId) {
	CUSTOMER customer;

	cout << "Username: ";
	cin >> customer.Username;

	cout << "Password: ";
	cin >> customer.Password;

	cout << "First Name: ";
	cin >> customer.First_Name;

	cout << "Last Name: ";
	cin >> customer.Last_Name;

	cout << "Address: ";
	cin >> customer.Address;

	cout << "Student's name: ";
	cin >> customer.Student_Name;

	cout << "Year of Student: ";
	while (!(cin >> customer.Year_of_student) or customer.Year_of_student < 12 or customer.Year_of_student > 16)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\nEnter correct Year: ";
	}

	createCustomer(customers, customerCount, customer, maxId);
}

void editOrderMenu(CUSTOMER* customers, int& customerCount) {
	int customerId;
	cin >> customerId;
	CUSTOMER customer = getOrder(customers, customerCount, customerId);

	cout << "1. Username: " << endl;
	cout << "2. Password: " << endl;
	cout << "3. First Name: " << endl;
	cout << "4. LastName: " << endl;
	cout << "5 Address: " << endl;
	cout << "6 Student Name: " << endl;
	cout << "7 Year of student: " << endl;
	cout << "Which field you want to edit: ";

	int edit;
	cin >> edit;

	switch (edit) {
	case 1: {
		cout << "Username: ";
		cin >> customer.Username;
		updateCustomer(customers, customerCount, customer, customerId);
		break;
	}
	case 2: {
		cout << "Password: ";
		cin >> customer.Password;
		updateCustomer(customers, customerCount, customer, customerId);
		break;
	}
	case 3: {
		cout << "First Name: ";
		cin >> customer.First_Name;
		updateCustomer(customers, customerCount, customer, customerId);
		break;
	}
	case 4: {
		cout << "Last Name: ";
		cin >> customer.Last_Name;
		updateCustomer(customers, customerCount, customer, customerId);
		break;
	}
	case 5: {
		cout << "Address: ";
		cin >> customer.Address;
		updateCustomer(customers, customerCount, customer, customerId);
		break;
	}
	case 6: {
		cout << "Student Name: ";
		cin >> customer.Student_Name;
		updateCustomer(customers, customerCount, customer, customerId);
		break;
	}
	case 7: {
		cout << "Year of student: ";
		cin >> customer.Year_of_student;
		updateCustomer(customers, customerCount, customer, customerId);
		break;
	}
	default: {
		cout << "Invalid field!" << endl;
		break;
	}


	}
}
void deleteCustomerMenu(CUSTOMER* customers, int& customerCount, int& maxId) {
	int customerId;

	cout << "Enter User Id: ";
	cin >> customerId;

	deleteCustomer(customers, customerCount, customerId);
}

bool showMainMenu(CUSTOMER* customers, int& customerCount, int& maxId) {

	int choice;

	cout << "\n===MAIN MENU===" << endl;
	cout << "1. Customer Menu" << endl;
	cout << "2. Show Customer" << endl;
	cout << "3. Edit Customer Order" << endl;
	cout << "4. Delete Customer Order" << endl;
	cout << "5. Seatch" << endl;
	cout << "9. Exit" << endl;
	cout << "Your choice: ";

	cin >> choice;

	switch (choice) {
	case 1: {
		CustomerMenu(customers, customerCount, maxId);
		break;
	}
	case 2: {
		showCustomerMenu(customers, customerCount, maxId);
		break;
	}
	case 3: {
		editOrderMenu(customers, customerCount);
		break;
	}
	case 4: {
		deleteCustomerMenu(customers, customerCount, maxId);
		break;
	}
	case 5:
	{
		search(customers, customerCount);
		break;
	}
	case 9: {
		return false;
	}
	default:
		break;

	}
}

int main()
{
	cout << "Obshtaka Programe\n";
	int customerCount = 0;
	int maxId = 1;
	CUSTOMER customers[500];

	bool mainMenu = true;
	string admin;
	string adminpass;
	cout << "Insert Username: ";
	getline(cin, admin);
	cout << "Insert Password: ";
	getline(cin, adminpass);
	bool isAdmina = isAdmin(admin, adminpass);
	if (isAdmina == true)
	{
		do {
			mainMenu = showMainMenu(customers, customerCount, maxId);
		} while (mainMenu);
	}
}

