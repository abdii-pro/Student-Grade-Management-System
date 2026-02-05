#include<iostream>
#include<fstream>
using namespace std;
int* intgrow(int* arr, int size);
char* chargrow(char* arr, int size);
int* shrink(int* arr, int size);
char* shrink_char(char* arr, int size);
void grade_calculator(char* grade, int* percentage, int ind);
void displaydata(int* roll, int* comp, int* math, int* percentage, char* grade, int size);
bool rollno_chkr(int* rollno, int size, int oldrollnumber);
void updaterollno(int* rollno, int size);
void update_Particular_CSmarks(int* rollno, int* comp, int* mathmarks, int* percentage, char* grade, int size);
void update_all_CSmarks(int* rollno, int* comp, int* mathmarks, int* percentage, char* grade, int size);
void update_Particular_Mathmarks(int* rollno, int* comp, int* mathmarks, int* percentage, char* grade, int size);
void update_all_Mathmarks(int* rollno, int* comp, int* mathmarks, int* percentage, char* grade, int size);
void sort_data(int* rollno, int* comp, int* mathmarks, int* percentage, char* grade, int size);
void sorting(int* arr, int i, int j);
void sorting_char(char* arr, int i, int j);
void delete_Particular_record(int* rollno, int* comp, int* mathmarks, int* percentage, char* grade, int size);
void add_Particular_record(int* rollno, int* comp, int* mathmarks, int* percentage, char* grade, int size);

int main() {
	int size = 1;
	int* rollno = new int[size];
	int* compmarks = new int[size];
	int* mathmarks = new int[size];
	int* percentage = new int[size];
	char* grade = new char[size];
	int ind = 0;
	char opt;
	do {    //adding data
		cout << "==================================\n";
		cout << "| Welcome to Student Admin Panel |\n";
		cout << "==================================\n";
		cout << "Enter the Roll Number of Student " << size << ": ";
		cin >> rollno[ind];
		do {
			cout << "Enter the Marks of Computer Science of Student within (100) " << size << ": ";
			cin >> compmarks[ind];
			if (compmarks[ind] > 100)
			{
				cout << "Invalid Input!\n";
			}
		} while (compmarks[ind] > 100);
		do {
			cout << "Enter the Marks of Math of Student within (100) " << size << ": ";
			cin >> mathmarks[ind];
			if (mathmarks[ind] > 100)
			{
				cout << "Invalid Input!\n";
			}
		} while (mathmarks[ind] > 100);

		//calculating average

		percentage[ind] = (compmarks[ind] + mathmarks[ind]) / 2;

		//calculating Grade
		if (ind == 0) {
			if (percentage[ind] < 50) {
				grade[ind] = { 'F' };
			}
			else if (percentage[ind] >= 50 && percentage[ind] < 60) {
				grade[ind] = { 'D' };
			}
			else if (percentage[ind] >= 60 && percentage[ind] < 75) {
				grade[ind] = { 'C' };
			}
			else if (percentage[ind] >= 75 && percentage[ind] <= 90) {
				grade[ind] = { 'B' };
			}
			else if (percentage[ind] >= 91 && percentage[ind] <= 100) {
				grade[ind] = { 'A' };
			}
		}
		else {
			grade_calculator(grade, percentage, ind);
		}

		//adding data of more students using regrow function


		do {
			cout << "Enter (Y) to continue adding Students and their Data or Press (N) to Stop:  ";
			cin >> opt;
			if (opt != 'Y' && opt != 'y' && opt != 'N' && opt != 'n') {
				cout << "Invalid Input!\n";
			}
		} while (opt != 'Y' && opt != 'y' && opt != 'N' && opt != 'n');
		if (opt == 'Y' || opt == 'y')
		{
			rollno = intgrow(rollno, size);
			compmarks = intgrow(compmarks, size);
			mathmarks = intgrow(mathmarks, size);
			percentage = intgrow(percentage, size);
			grade = chargrow(grade, size);
			ind++;
			size++;
			system("cls");
		}
		else
		{
			system("cls");

			//Displaying Data

			displaydata(rollno, compmarks, mathmarks, percentage, grade, size);
		}
	} while (opt != 'N' && opt != 'n');

	// ********************
	// *Advance Operations*
	// ********************

	char opt1;
	int opt2;
	do {
		do {
			cout << "If you want to perform other advance operations press (Y) or press (N) for Exit\n";
			cin >> opt1;
			if (opt1 != 'Y' && opt1 != 'y' && opt1 != 'N' && opt1 != 'n') {
				cout << "Invalid input!\n";
			}
			else if (size == 0) {
				int opt3;
				do {
					cout << "\nThere is No Record!\n\n";
					cout << "Please Enter the Data First by pressing (1)\n";
					cin >> opt3;
					if (opt3 == 1) {
						rollno = intgrow(rollno, size);
						compmarks = intgrow(compmarks, size);
						mathmarks = intgrow(mathmarks, size);
						percentage = intgrow(percentage, size);
						grade = chargrow(grade, size);
						size++;
						add_Particular_record(rollno, compmarks, mathmarks, percentage, grade, size);
						system("cls");
						displaydata(rollno, compmarks, mathmarks, percentage, grade, size);
					}
				} while (opt3 != 1 && opt3 != 2);

			}
		} while (opt1 != 'Y' && opt1 != 'y' && opt1 != 'N' && opt1 != 'n');

		if (opt1 == 'Y' || opt1 == 'y') {
			cout << "1) Press 1 to update Roll Number of a particular Student\n";
			cout << "2) Press 2 to update marks of a particular student for Computer Science\n";
			cout << "3) Press 3 to update marks of Computer Science for all students who are already enrolled\n";
			cout << "4) Press 4 to update marks of a particular student for Mathematics\n";
			cout << "5) Press 5 to update marks of Mathematics for all students who are already enrolled\n";
			cout << "6) Press 6 to sort the data on the basis of generated percentages\n";
			cout << "7) Press 7 to delete the record of a particular student\n";
			cout << "8) Press 8 to Add the record of a particular student\n";
			do {
				cin >> opt2;
				if (opt2 < 1 || opt2 >8) {
					cout << "Please Enter a valid input\n";
				}
			} while (opt2 < 1 || opt2 >8);
			if (opt2 == 1) {
				updaterollno(rollno, size);
			}
			else if (opt2 == 2) {
				update_Particular_CSmarks(rollno, compmarks, mathmarks, percentage, grade, size);
			}
			else if (opt2 == 3) {
				update_all_CSmarks(rollno, compmarks, mathmarks, percentage, grade, size);
			}
			else if (opt2 == 4) {
				update_Particular_Mathmarks(rollno, compmarks, mathmarks, percentage, grade, size);
			}
			else if (opt2 == 5) {
				update_all_Mathmarks(rollno, compmarks, mathmarks, percentage, grade, size);
			}
			else if (opt2 == 6) {
				sort_data(rollno, compmarks, mathmarks, percentage, grade, size);
			}
			else if (opt2 == 7) {
				delete_Particular_record(rollno, compmarks, mathmarks, percentage, grade, size);
				rollno = shrink(rollno, size);
				compmarks = shrink(compmarks, size);
				mathmarks = shrink(mathmarks, size);
				percentage = shrink(percentage, size);
				grade = shrink_char(grade, size);
				size--;
			}
			else {
				rollno = intgrow(rollno, size);
				compmarks = intgrow(compmarks, size);
				mathmarks = intgrow(mathmarks, size);
				percentage = intgrow(percentage, size);
				grade = chargrow(grade, size);
				size++;
				add_Particular_record(rollno, compmarks, mathmarks, percentage, grade, size);
			}
			system("cls");
			displaydata(rollno, compmarks, mathmarks, percentage, grade, size);
		}
		else {
			cout << "\n\t\t\t\t\t(Data has been Stored in File)\n\n";
			cout << "*********************************************************************************************************\n";
			cout << "                                                 FINISH                                                  \n";
			cout << "*********************************************************************************************************\n";
		}
	} while (opt1 != 'n' && opt1 != 'N');
	ofstream fout("output.txt");
	fout << "                                           STUDENT GRADE REPORT                                               \n";
	fout << "=========================================================================================================\n";
	fout << "|Student#|\t|Roll Number|\t   |Computer Marks|\t   |Math Marks|\t      |Percentage|\t  |Grade|\n";
	for (int i = 0; i < size; i++) {
		fout << "     " << i + 1 << "\t\t     " << rollno[i] << "\t\t          " << compmarks[i] << "\t\t\t" << mathmarks[i] << "\t\t   " << percentage[i] << "\t\t     " << grade[i] << endl;
	}
	fout << "=========================================================================================================\n";
	fout.close();

	delete[]rollno;
	delete[]compmarks;
	delete[]mathmarks;
	delete[]percentage;
	delete[]grade;
	cout << endl;
	system("pause");
	return 0;
}

//***************************************************
//Different Functions that are used in this Programme
//***************************************************


//Data display fnction

void displaydata(int* roll, int* comp, int* math, int* percentage, char* grade, int size) {
	cout << "                                           STUDENT GRADE REPORT                                               \n";
	cout << "=========================================================================================================\n";
	cout << "|Student#|\t|Roll Number|\t   |Computer Marks|\t   |Math Marks|\t      |Percentage|\t  |Grade|\n";
	for (int i = 0; i < size; i++) {
		cout << "     " << i + 1 << "\t\t     " << roll[i] << "\t\t          " << comp[i] << "\t\t\t" << math[i] << "\t\t   " << percentage[i] << "\t\t     " << grade[i] << endl;
	}
	cout << "=========================================================================================================\n";
}

//Integer array regrow function 

int* intgrow(int* arr, int size) {
	size++;
	int* newarr = new int[size];
	for (int i = 0; i < size - 1; i++) {
		newarr[i] = arr[i];
	}
	delete[]arr;
	return newarr;
}

//Character array regrow function 

char* chargrow(char* arr, int size) {
	size++;
	char* newarr = new char[size];
	for (int i = 0; i < size - 1; i++) {
		newarr[i] = arr[i];
	}
	delete[]arr;
	return newarr;
}

//Integer array Shrink function 

int* shrink(int* arr, int size) {
	size--;
	int* newarr = new int[size];
	for (int i = 0; i < size; i++) {
		newarr[i] = arr[i];
	}
	delete[]arr;
	return newarr;
}

//Character array Shrink function 

char* shrink_char(char* arr, int size) {
	size--;
	char* newarr = new char[size];
	for (int i = 0; i < size; i++) {
		newarr[i] = arr[i];
	}
	delete[]arr;
	return newarr;
}

//Grade Calculator

void grade_calculator(char* grade, int* percentage, int ind) {
	if (percentage[ind] < 50) {
		grade[ind] = { 'F' };
	}
	else if (percentage[ind] >= 50 && percentage[ind] < 60) {
		grade[ind] = { 'D' };
	}
	else if (percentage[ind] >= 60 && percentage[ind] < 75) {
		grade[ind] = { 'C' };
	}
	else if (percentage[ind] >= 75 && percentage[ind] <= 90) {
		grade[ind] = { 'B' };
	}
	else if (percentage[ind] >= 91 && percentage[ind] <= 100) {
		grade[ind] = { 'A' };
	}
}
//Roll Number Checker

bool rollno_chkr(int* rollno, int size, int oldrollnumber) {
	bool found = false;
	for (int i = 0; i < size; i++) {
		if (rollno[i] == oldrollnumber) {
			found = true;
			break;
		}
	}
	return found;
}

// Sorting int array Function

void sorting(int* arr, int i, int j) {
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

// Sorting Character array Function

void sorting_char(char* arr, int i, int j) {
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

// 1: Updating a particular Studentroll number

void updaterollno(int* rollno, int size) {
	int oldrollnumber, newrollnumber;
	bool found;
	do {
		cout << "Enter the old roll number: \n";
		cin >> oldrollnumber;

		//Checking that entered roll no exists or not in Data 

		found = rollno_chkr(rollno, size, oldrollnumber);
		if (found == true) {
			cout << "Enter the new roll number: \n";
			cin >> newrollnumber;
			for (int i = 0; i < size; i++) {
				if (rollno[i] == oldrollnumber) {
					rollno[i] = newrollnumber;
				}
			}
		}
		else {
			cout << "Roll Number not Found!\n\n";
		}
	} while (found != true);
}

// 2: Updating a particular Student CS Marks

void update_Particular_CSmarks(int* rollno, int* comp, int* mathmarks, int* percentage, char* grade, int size) {
	int rollnumber, newmarks;
	bool found;
	do {
		cout << "Enter the Roll number of Student: \n";
		cin >> rollnumber;

		//Checking that entered roll no exists or not in Data 

		found = rollno_chkr(rollno, size, rollnumber);
		if (found == true) {
			cout << "Enter the Updated Marks of CS: \n";
			cin >> newmarks;
			for (int i = 0; i < size; i++) {
				if (rollno[i] == rollnumber) {
					comp[i] = newmarks;
					percentage[i] = (comp[i] + mathmarks[i]) / 2;
					grade_calculator(grade, percentage, i);
				}
			}
		}
		else {
			cout << "Roll Number not Found!\n\n";
		}
	} while (found != true);
}

// 3: Updating a CS Marks of all Students

void update_all_CSmarks(int* rollno, int* comp, int* mathmarks, int* percentage, char* grade, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter the Updated Marks of CS Student With Roll Number " << rollno[i] << ": \n";
		cin >> comp[i];
		percentage[i] = (comp[i] + mathmarks[i]) / 2;
		grade_calculator(grade, percentage, i);
	}
}

// 4: Updating a particular Student Math Marks

void update_Particular_Mathmarks(int* rollno, int* comp, int* mathmarks, int* percentage, char* grade, int size) {
	int rollnumber, newmarks;
	bool found;
	do {
		cout << "Enter the Roll number of Student: \n";
		cin >> rollnumber;

		//Checking that entered roll no exists or not in Data 

		found = rollno_chkr(rollno, size, rollnumber);
		if (found == true) {
			cout << "Enter the Updated Marks of Math: \n";
			cin >> newmarks;
			for (int i = 0; i < size; i++) {
				if (rollno[i] == rollnumber) {
					mathmarks[i] = newmarks;
					percentage[i] = (comp[i] + mathmarks[i]) / 2;
					grade_calculator(grade, percentage, i);
				}
			}
		}
		else {
			cout << "Roll Number not Found!\n\n";
		}
	} while (found != true);
}

// 5: Updating a Math Marks of all Students

void update_all_Mathmarks(int* rollno, int* comp, int* mathmarks, int* percentage, char* grade, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter the Updated Marks of Math Student With Roll Number " << rollno[i] << ": \n";
		cin >> mathmarks[i];
		percentage[i] = (comp[i] + mathmarks[i]) / 2;
		grade_calculator(grade, percentage, i);
	}
}

// 6: Sorting data on the Bases of Percentage

void sort_data(int* rollno, int* comp, int* mathmarks, int* percentage, char* grade, int size) {

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (percentage[i] < percentage[j]) {
				sorting(rollno, i, j);
				sorting(comp, i, j);
				sorting(mathmarks, i, j);
				sorting(percentage, i, j);
				sorting_char(grade, i, j);
			}
		}
	}
}

// 7: deleting a particular Student Record

void delete_Particular_record(int* rollno, int* comp, int* mathmarks, int* percentage, char* grade, int size) {
	int rollnumber, indx = -1;
	bool found;
	do {
		cout << "Enter the Roll number of Student: \n";
		cin >> rollnumber;

		//Checking that entered roll no exists or not in Data 

		found = rollno_chkr(rollno, size, rollnumber);
		if (found == true) {
			for (int i = 0; i < size; i++) {
				if (rollno[i] == rollnumber) {
					indx = i;
					break;
				}
			}
			for (int i = indx; i < size; i++) {
				rollno[i] = rollno[i + 1];
				comp[i] = comp[i + 1];
				mathmarks[i] = mathmarks[i + 1];
				percentage[i] = percentage[i + 1];
				grade[i] = grade[i + 1];
			}
		}
		else {
			cout << "Roll Number not Found!\n\n";
		}
	} while (found != true);
}

// 8: Record adding Function

void add_Particular_record(int* rollno, int* comp, int* mathmarks, int* percentage, char* grade, int size) {
	cout << "Enter the Roll number of Student: \n";
	cin >> rollno[size - 1];
	do {
		cout << "Enter the Marks of Computer Science of Student within (100) " << size << ": ";
		cin >> comp[size - 1];
		if (comp[size - 1] > 100)
		{
			cout << "Invalid Input!\n";
		}
	} while (comp[size - 1] > 100);
	do {
		cout << "Enter the Marks of Math of Student within (100) " << size << ": ";
		cin >> mathmarks[size - 1];
		if (mathmarks[size - 1] > 100)
		{
			cout << "Invalid Input!\n";
		}
	} while (mathmarks[size - 1] > 100);

	//calculating average

	percentage[size - 1] = (comp[size - 1] + mathmarks[size - 1]) / 2;
	grade_calculator(grade, percentage, size - 1);

}
