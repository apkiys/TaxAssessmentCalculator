// Tax_Assessment_Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
// Data Variables for Functions
int ansBoo;
// Data Variables for Menu
string m1, m2, m3, m4;
string menuConfirm1, menuConfirm2, menuConfirm3, menuConfirm4;
// Data Variables for Part A
int initialYA, YA, preYA, a0, a1, a2, a3, a4, a5, a6;
int grossEmploymentIncome, rentalIncome, dividendIncome, royalty, estateIncome, miscIncome, approvedDonations;
int totalAssessableIncome;
string s1;
string miscIncomeReply;
// Data Variables for Part B
int initialAge, Age, b1, b2, b3, b4;
int earnedIncomeRelief, spouseRelief, childRelief, workingMotherChildRelief, cpfRelief, nsManRelief;
string s2, s3, s4, s5, s6, s7, s8, s9;
string selfHandicapped, spouseHandicapped, spouseAnnualIncome;
string childResponse1, childResponse2, workingMother;
string nsActivity, apptHolder;
int i, noUnmarriedChildren, WMCRCount, nsCategory, cpfContribution, nsWifeParentRelief, nsManReliefGross;
int totalPersonalRelief;
// Data Variables for Part C
int chargeableIncome, taxPayable;
int j;
float tier[13][4] =
{
    {20000,0,0,0},
    {30000,0,20000,2},
    {40000,200,30000,3.5},
    {80000,550,40000,7},
    {120000,3350,80000,11.5},
    {160000,7950,120000,15},
    {200000,13950,160000,18},
    {240000,21150,200000,19},
    {280000,28750,240000,19.5},
    {320000,36550,280000,20},
    {500000,44550,320000,22},
    {1000000,84150,500000,23},
    {1000000000000,199150,500000,24},
};

// This function validates the Year of Assessment to accept only 2023 as input
int validationYA(int allAnswers0)
{
    while (true)
    {
        cout << "Do note that you're only required to enter the current Year of Assessment to proceed... " << endl;
        cout << endl;
        cout << "Please enter the Year of Assessment (YYYY): ";
        cin >> allAnswers0;
        if (allAnswers0 != 2023)
        {
            cin.clear();
            cin.ignore();
            system("cls");
        }
        else
        {
            break;
        }
    }
    return allAnswers0;
}

// This function validates Age to accept only integer input
int validationAge(int allAnswers0) {
    while (true) {
        cout << "Please enter your age: ";
        cin >> allAnswers0;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            system("cls");
        }
        else {
            break;
        }
        allAnswers0 = 0;
    }
    return allAnswers0;
}

// This function validates all numeral requests to accept only integer input
int validationNum(int allAnswers1) {
    for (;;) {
        int c;
        printf("=> S$");
        if (scanf_s("%d", &allAnswers1) == 1)
        {
            //verify that remainder of input only consists of
            //whitespace characters
            while ((c = getchar()) != EOF && c != '\n')
            {
                if (!isspace(c))
                {
                    //we cannot use "break" here, because we want
                    //to break out of the outer loop, not the inner
                    //loop
                    goto invalid_input;
                }
            }
            //input is valid
            return allAnswers1;
        }
    invalid_input:
        //print error message
        //printf("\r");
        //discard remainder of line
        do
        {
            c = getchar();
        } while (c != EOF && c != '\n');
    }
}

// This function validates all yes/no requests to convert to boolean value
string validationBoo(string allAnswers2) {
    int ansCount;
    do {
        cout << "(Yes/No) => ";
        cin >> allAnswers2;
        if (allAnswers2 == "Yes")
        {
            ansCount = 1;
            ansBoo = 1;
        }
        else if (allAnswers2 == "No")
        {
            ansCount = 1;
            ansBoo = 0;
        }
        else {
            ansCount = 0;
        }
    } while (ansCount == 0);
    return allAnswers2;
}

// This function validates child number input to accept between 1-99
int validationNumGen(int allAnswers3)
{
    for (;;) {
        int c;
        printf("=> ");
        if (scanf_s("%d", &allAnswers3) == 1) {
            //verify that remainder of input only consists of
            //whitespace characters
            while ((c = getchar()) != EOF && c != '\n')
            {
                if (!isspace(c))
                {
                    //we cannot use "break" here, because we want
                    //to break out of the outer loop, not the inner
                    //loop
                    goto invalid_input;
                }
            }
            //input is valid
            if ((allAnswers3 > -1) && (allAnswers3 < 100))
            {
                return allAnswers3;
            }
            else
            {
                continue;
            }
        }
    invalid_input:
        //print error message
        //printf("\r");
        //discard remainder of line
        do
        {
            c = getchar();
        } while (c != EOF && c != '\n');
    }
}

// This function validates NS request input to 1-3 menu number
int validationNumNS(int allAnswers4)
{
    for (;;) {
        int c;
        printf("=> ");
        if (scanf_s("%d", &allAnswers4) == 1) {
            //verify that remainder of input only consists of
            //whitespace characters
            while ((c = getchar()) != EOF && c != '\n')
            {
                if (!isspace(c))
                {
                    //We cannot use "break" here, because we want
                    //to break out of the outer loop, not the inner
                    //loop
                    goto invalid_input;
                }
            }
            //input is valid
            if ((allAnswers4 > 0) && (allAnswers4 < 4))
            {
                return allAnswers4;
            }
            else
            {
                continue;
            }
        }
    invalid_input:
        //discard remainder of line
        do
        {
            c = getchar();
        } while (c != EOF && c != '\n');
    }
}

int main()
{
    do
    {
        initialYA = validationYA(a0);
        YA = initialYA;
        preYA = YA - 1;
        printf("\nConfirm to proceed?\n");
        menuConfirm1 = validationBoo(m1);
        system("cls");
    } while (menuConfirm1 != "Yes");
    do
    {
        initialAge = validationAge(b1);
        Age = initialAge;
        printf("\nConfirm to proceed?\n");
        menuConfirm2 = validationBoo(m2);
        system("cls");
    } while (menuConfirm2 != "Yes");
    //
    // Part A Tax Assessment Calculator Menu
    //
    do
    {
        printf("--------------------------------------------------------------------------------------\n");
        printf("Year of Assessment %d\n", YA);
        printf("--------------------------------------------------------------------------------------\n");
        printf("PART A - Assessable Income\n");
        printf("\nGross Employment Income\n");
        printf("Please enter or amend your annual employment income in %d [Current: %d]:\n", preYA, grossEmploymentIncome);
        grossEmploymentIncome = validationNum(a1);
        printf("\nRental Income from Owned Property\n");
        printf("Please enter or amend your annual rental income in %d, if any [Current: %d]:\n", preYA, rentalIncome);
        rentalIncome = validationNum(a2);
        printf("\nDividend Income\n");
        printf("Please enter or amend the annual taxable dividend you received in %d, if any [Current: %d]:\n", preYA, dividendIncome);
        dividendIncome = validationNum(a3);
        printf("\nAny Other Income\n");
        printf("Current Royalty Income: %d\n", royalty);
        printf("Current Estate Income: %d\n", estateIncome);
        printf("Do you have any other income e.g. royalty, estate income to declare or amend?\n");
        miscIncomeReply = validationBoo(s1);
        switch (ansBoo)
        {
        case 0:
            break;
        case 1:
            printf("Please enter or amend the royalty you wish to declare [Current: %d]:\n", royalty);
            royalty = validationNum(a4);
            printf("Please enter or amend the estate income you wish to declare [Current: %d]:\n", estateIncome);
            estateIncome = validationNum(a5);
            miscIncome = royalty + estateIncome;
            printf("You have entered a total miscellaneous income amount of S$%d.\n", miscIncome);
            break;
        }
        printf("\nApproved Donations\n");
        printf("Please enter or amend the amount of approved donations you made in %d, if any [Current: %d]\n", preYA, approvedDonations);
        approvedDonations = validationNum(a6);
        totalAssessableIncome = grossEmploymentIncome + rentalIncome + dividendIncome + miscIncome - 2.5 * approvedDonations;
        printf("\nYour total assessable income in %d is S$%d.\n", preYA, totalAssessableIncome);
        if (totalAssessableIncome < 0)
        {
            printf("\nInvalid entries! Please enter again!\n");
            system("pause");
            system("cls");
            continue;
        }
        else
        {
            printf("\nConfirm to proceed?\n");
            menuConfirm3 = validationBoo(m3);
            system("cls");
        }
    } while (menuConfirm3 != "Yes");
    //
    // Part B Tax Assessment Calculator Menu
    //
    do
    {
        printf("--------------------------------------------------------------------------------------\n");
        printf("Year of Assessment %d\n", YA);
        printf("--------------------------------------------------------------------------------------\n");
        printf("PART B - Total Personal Reliefs\n");
        printf("\nEarned Income Relief\n");
        printf("Are you currently physically/mentally handicapped?\n");
        selfHandicapped = validationBoo(s2);
        if (Age < 55)
        {
            if (selfHandicapped == "Yes")
            {
                earnedIncomeRelief = 4000;
            }
            else if (selfHandicapped == "No")
            {
                earnedIncomeRelief = 1000;
            }
        }
        else if (Age >= 56 && Age <= 59)
        {
            if (selfHandicapped == "Yes")
            {
                earnedIncomeRelief = 10000;
            }
            else if (selfHandicapped == "No")
            {
                earnedIncomeRelief = 6000;
            }
        }
        else if (Age > 60)
        {
            if (selfHandicapped == "Yes")
            {
                earnedIncomeRelief = 12000;
            }
            else if (selfHandicapped == "No")
            {
                earnedIncomeRelief = 8000;
            }
        }
        printf("You are eligible for an earned income relief of S$%d.\n", earnedIncomeRelief);
        printf("\nSpouse/Handicapped Spouse Relief\n");
        printf("Is your spouse physically/mentally handicapped?\n");
        spouseHandicapped = validationBoo(s3);
        if (spouseHandicapped == "Yes")
        {
            spouseRelief = 5500;
        }
        else if (spouseHandicapped == "No")
        {
            printf("Is the annual income of your spouse less than or equal to S$4000?\n");
            spouseAnnualIncome = validationBoo(s4);
            if (spouseAnnualIncome == "Yes")
            {
                spouseRelief = 2000;
            }
            else if (spouseAnnualIncome == "No")
            {
                spouseRelief = 0;
            }
        }
        printf("You are eligible for a spouse relief of S$%d.\n", spouseRelief);
        printf("\nQualified Child Relief (QCR) / Handicapped Child Relief (HCR)\n");
        cout << "No. of unmarried child(ren) you're currently supporting:" << endl;
        cout << "[Current: " << noUnmarriedChildren << "]" << endl;
        noUnmarriedChildren = validationNumGen(b2);
        childRelief = 0;
        WMCRCount = 0;
        int* array = new int[noUnmarriedChildren];
        for (i = 0; i < noUnmarriedChildren; i++)
        {
            cout << "For child number " << i + 1 << " is he/she physically/mentally handicapped?" << endl;
            childResponse1 = validationBoo(s5);
            if (childResponse1 == "Yes")
            {
                childRelief = childRelief + 7500;
                if (i == 0)
                {
                    WMCRCount = WMCRCount + 15;
                }
                else if (i == 1)
                {
                    WMCRCount = WMCRCount + 20;
                }
                else if (i >= 2)
                {
                    WMCRCount = WMCRCount + 25;
                }
                continue;
            }
            else if (childResponse1 == "No")
            {
                cout << "Is he/she currently below 16 years old/studying full-time/income less than S$4000?" << endl;
                childResponse2 = validationBoo(s6);
                if (childResponse2 == "Yes")
                {
                    childRelief = childRelief + 4000;
                    if (i == 0)
                    {
                        WMCRCount = WMCRCount + 15;
                    }
                    else if (i == 1)
                    {
                        WMCRCount = WMCRCount + 20;
                    }
                    else if (i >= 2)
                    {
                        WMCRCount = WMCRCount + 25;
                    }
                }
                else if (childResponse2 == "No")
                {
                    childRelief = childRelief + 0;
                }
            }
        }
        delete[] array;
        printf("You are eligible for a QCR/HCR of S$%d.\n", childRelief);
        if (WMCRCount <= 100)
        {
            WMCRCount = WMCRCount;
        }
        else if (WMCRCount > 100)
        {
            WMCRCount = 100;
        }
        workingMotherChildRelief = grossEmploymentIncome;
        printf("\nWorking Mother Child Relief (WMCR)\n");
        printf("Are you a working mum?\n");
        workingMother = validationBoo(s7);
        if (workingMother == "Yes")
        {
            workingMotherChildRelief = workingMotherChildRelief * WMCRCount / 100;
        }
        else if (workingMother == "No")
        {
            workingMotherChildRelief = 0;
        }
        printf("You are eligible for a Working Mum Relief of S$%d.\n", workingMotherChildRelief);
        printf("\nCentral Provident Fund (CPF) Relief\n");
        printf("Enter the amount of compulsory employee CPF contributions you have made in %d\n(Ordinary Wages + Additional Wages):\n", preYA);
        printf("[Current: %d]\n", cpfContribution);
        cpfContribution = validationNum(b3);
        cpfRelief = cpfContribution;
        printf("You are eligible for a CPF Relief of S$%d.\n", cpfRelief);
        printf("\nNSman Relief (Self, Wife and Parent)\n");
        cout << "Which category of NSman relief would you be claiming?" << endl;
        cout << "1.Self" << endl;
        cout << "2.Wife of NSman" << endl;
        cout << "3.Parent of NSman" << endl;
        nsCategory = validationNumNS(b4);
        nsManRelief = 0;
        nsManReliefGross = 0;
        switch (nsCategory)
        {
        case 1:
            nsWifeParentRelief = 0;
            printf("Did you perform NS activities in %d?\n", preYA);
            nsActivity = validationBoo(s8);
            if (nsActivity == "Yes")
            {
                printf("Are you a NS key command and staff appointment holder?\n");
                apptHolder = validationBoo(s9);
                if (apptHolder == "Yes")
                {
                    nsManReliefGross = 5000;
                }
                else if (apptHolder == "No")
                {
                    nsManReliefGross = 3000;
                }
            }
            else if (nsActivity == "No")
            {
                printf("Are you a NS key command and staff appointment holder?\n");
                apptHolder = validationBoo(s9);
                if (apptHolder == "Yes")
                {
                    nsManReliefGross = 3500;
                }
                else if (apptHolder == "No")
                {
                    nsManReliefGross = 1500;
                }
            }
            break;
        case 2:
            nsWifeParentRelief = 750;
            break;
        case 3:
            nsWifeParentRelief = 750;
            break;
        }
        nsManRelief = nsManReliefGross + nsWifeParentRelief;
        printf("You are eligible for a NSman Relief of S$%d.\n", nsManRelief);
        totalPersonalRelief = earnedIncomeRelief + spouseRelief + childRelief + workingMotherChildRelief + cpfRelief + nsManRelief;
        if (totalPersonalRelief > 80000)
        {
            totalPersonalRelief = 80000;
        }
        else
        {
            totalPersonalRelief = totalPersonalRelief;
        }
        printf("\nYour total personal relief in %d is S$%d.\n", preYA, totalPersonalRelief);
        printf("\nConfirm to proceed?\n");
        menuConfirm4 = validationBoo(m4);
        system("cls");
    } while (menuConfirm4 != "Yes");
    printf("--------------------------------------------------------------------------------------\n");
    printf("PART C - Chargeable Income & Tax Payable\n");
    chargeableIncome = totalAssessableIncome - totalPersonalRelief;
    printf("\nYour total assessable income in %d is S$%d.\n", preYA, totalAssessableIncome);
    printf("\nYou are eligible for a total personal relief of S$%d.\n", totalPersonalRelief);
    printf("\nYour chargeable income is S$%d.\n", chargeableIncome);
    for (j = 0; j < 13; j++)
    {
        if ((chargeableIncome - tier[j][0]) > 0)
        {
            continue;
        }
        else
        {
            taxPayable = tier[j][1] + (chargeableIncome - tier[j][2]) * tier[j][3] / 100;
            break;
        }
        return taxPayable;
    }
    printf("\nThe tax payable on your chargeable income of S$%d in assessment year %d is S$%d.\n", chargeableIncome, YA, taxPayable);
    printf("--------------------------------------------------------------------------------------\n");
    system("pause");
}