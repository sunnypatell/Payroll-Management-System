/**
 * Copyright (C) December 2022 {Sunny Patel} <{sunnypatel124555@gmail.com}>

    This file is part of the {Payroll Management System} project.

The {Payroll Management System} project can not be copied, distributed, and/or modified without the express
permission of {Sunny Patel} <{sunnypatel124555@gmail.com}>.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Define a struct to represent an employee record
struct Employee
{
    int code;
    string name;
    string address;
    string phone;
    string joining_date;
    string designation;
    string grade;
    int loan;
    float basic_salary;
    float house_allowance;
    // Add other relevant fields here, such as deductions, net salary, etc.
    float deductions;
};

// Define a class to manage the payroll system
class Payroll
{
private:
    // Use a vector to store the employee records
    vector<Employee> employees;

public:
    // Add a new employee to the system
    void addEmployee(int code, string name, string address, string phone, string joining_date, string designation, string grade, int loan, float basic_salary, float house_allowance)
    {
        Employee employee = {code, name, address, phone, joining_date, designation, grade, loan, basic_salary, house_allowance};
        employees.push_back(employee);
    }

    // Modify an existing employee record
    void modifyEmployee(int code, string name, string address, string phone, string joining_date, string designation, string grade, int loan, float basic_salary, float house_allowance)
    {
        // Find the employee with the given code
        for (int i = 0; i < employees.size(); i++)
        {
            if (employees[i].code == code)
            {
                // Update the fields of the employee record
                employees[i].name = name;
                employees[i].address = address;
                employees[i].phone = phone;
                employees[i].joining_date = joining_date;
                employees[i].designation = designation;
                employees[i].grade = grade;
                employees[i].loan = loan;
                employees[i].basic_salary = basic_salary;
                employees[i].house_allowance = house_allowance;
                break;
            }
        }
    }

    // Delete an employee record
    void deleteEmployee(int code)
    {
        // Find the employee with the given code
        for (int i = 0; i < employees.size(); i++)
        {
            if (employees[i].code == code)
            {
                // Remove the employee from the vector
                employees.erase(employees.begin() + i);
                break;
            }
        }
    }

    // Print the salary slip of an employee
    void printSalarySlip(int code)
    {
        // Find the employee with the given code
        for (int i = 0; i < employees.size(); i++)
        {
            if (employees[i].code == code)
            {
                Employee employee = employees[i];
                // Print the salary slip for the employee
                cout << "Salary Slip for " << employee.name << " (" << employee.designation << ", " << employee.grade << ")" << endl;
                cout << "Basic salary: " << employee.basic_salary << endl;
                // Add other relevant fields here, such as deductions, net salary, etc.
                cout << "Allowances: " << employee.house_allowance << endl;
                cout << "Deductions: " << employee.deductions << endl;
                cout << "Total salary: " << employee.basic_salary + employee.house_allowance - employee.deductions << endl;
            }
        }
    }
    // Display the record of a single employee
    void displayEmployee(int code)
    {
        // Find the employee with the given code
        for (int i = 0; i < employees.size(); i++)
        {
            if (employees[i].code == code)
            {
                Employee employee = employees[i];
                // Print the employee record
                cout << "Employee Code: " << employee.code << endl;
                cout << "Name: " << employee.name << endl;
                cout << "Address: " << employee.address << endl;
                cout << "Phone: " << employee.phone << endl;
                cout << "Joining Date: " << employee.joining_date << endl;
                cout << "Designation: " << employee.designation << endl;
                cout << "Grade: " << employee.grade << endl;
                cout << "Loan: " << employee.loan << endl;
                cout << "Basic Salary: " << employee.basic_salary << endl;
                cout << "House Allowance: " << employee.house_allowance << endl;
                // Add other relevant fields here, such as deductions, net salary, etc.
            }
        }
    }

    // Display the records of all employees
    void displayEmployees()
    {
        // Print the table header
        cout << "Code\tName\tPhone\tJoining Date\tDesignation\tGrade\tSalary" << endl;
        // Print the employee records
        for (int i = 0; i < employees.size(); i++)
        {
            Employee employee = employees[i];
            cout << employee.code << "\t" << employee.name << "\t" << employee.phone << "\t" << employee.joining_date << "\t" << employee.designation << "\t" << employee.grade << "\t" << employee.basic_salary << endl;
        }
    }
};

int main()
{
    Payroll payroll;

    /** TEST CODE FOR PROGRAM USAGE BELOW*/

    // Add some employees to the system
    payroll.addEmployee(1, "John Smith", "123 Main Street", "555-555-1212", "01/01/2022", "Manager", "A", 0, 50000, 1000);
    payroll.addEmployee(2, "Jane Doe", "456 Market Street", "555-555-1213", "01/02/2022", "Assistant Manager", "B", 500, 40000, 500);
    payroll.addEmployee(3, "Bob Johnson", "789 Market Street", "555-555-1214", "01/03/2022", "Employee", "C", 1000, 30000, 0);

    // Modify the record of employee 2
    payroll.modifyEmployee(2, "Jane Smith", "456 Market Street", "555-555-1213", "01/02/2022", "Manager", "A", 500, 50000, 1000);

    // Delete the record of employee 3
    payroll.deleteEmployee(3);

    // Display the record of employee 2
    payroll.displayEmployee(2);

    // Display the records of all employees
    payroll.displayEmployees();

    return 0;
}
