/*
    ผู้ใช้กรอกข้อมูลพนักงานในบริษัท โดยจะกรอกข้อมูล ชื่อ, เงินเดือน, อายุการทำงาน ของแต่ละคน โดยเมื่อผู้ใช้กรอกตัว n จะถือเป็นการหยุดโปรแกรมและทำการแสดงข้อมูลเงินเดือนเฉลี่ยของพนักงานในบริษัท และเงินเดือนของทุกคนรวมกันที่ผู้บริหารต้องจ่าย และแสดงคนที่อายุงานเยอะที่สุดพร้อมระบุ ชื่อ เงินเดือน และอายุงาน ของคนๆ นั้น
    
    Test case:
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Yorn
        Salary (Bath/Month) : 
            15000
        Duration (Year) : 
            4
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Van
        Salary (Bath/Month) : 
            14550
        Duration (Year) : 
            2
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Thane
        Salary (Bath/Month) : 
            22500
        Duration (Year) : 
            8
        Do you want to Enter Employee Information? (y/n) : 
            n
    Output:
        Average of Salary : 17,350.00 Bath
        Payment of every month : 52,050.00 Bath
        ----------------------------------------
        ** Most duration in this business **
        Name : Thane (8 Years)
        Salary : 22,500.00 Bath

*/

//TODO: #21 output money should in decimal format (eg. 120,200,340.42).
#include <stdio.h>
#include <string.h>

struct Employee {
    char Name[20];
    float Salary;
    int Duration;
};

int main() {
    struct Employee employees[100];
    int numEmployees = 0;
    char choice;
    float totalSalary = 0;
    int maxDuration = 0;
    int maxDurationIndex;

    do {
        printf("Do you want to Enter Employee Information? (y/n) : ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            printf("----\n");
            printf("Employee Name : ");
            scanf("%s", employees[numEmployees].Name);
            printf("Salary (Bath/Month) : ");
            scanf("%f", &employees[numEmployees].Salary);
            printf("Duration (Year) : ");
            scanf("%d", &employees[numEmployees].Duration);
            totalSalary += employees[numEmployees].Salary;
            if (employees[numEmployees].Duration > maxDuration) {
                maxDuration = employees[numEmployees].Duration;
                maxDurationIndex = numEmployees;
            }
            numEmployees++;
        }
    } while (choice == 'y' || choice == 'Y');

    // คำนวณเงินเดือนเฉลี่ยและการจ่ายเงินเดือนทั้งหมด
    float averageSalary = totalSalary / numEmployees;
    float totalPayment = totalSalary * numEmployees;

    // แสดงผลลัพธ์
    printf("Average of Salary : %.2f Bath\n", averageSalary);
    printf("Payment of every month : %.2f Bath\n", totalPayment);
    printf("----------------------------------------\n");
    printf("** Most duration in this business **\n");
    printf("Name : %s (%d Years)\n", employees[maxDurationIndex].Name, employees[maxDurationIndex].Duration);
    printf("Salary : %.2f Bath\n", employees[maxDurationIndex].Salary);

    return 0;
}
