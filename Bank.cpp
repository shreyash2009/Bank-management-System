#include <bits/stdc++.h>
// #include<windows.h>
using namespace std;

class Bank
{
private:
    int total;
    string id;
    struct person
    {
        string ID, name;
        int cash, contact;

    } person[100];

public:
    Bank()
    {
        total = 0;
    }
    void choice();
    void addData();
    void showData();
    void SearchAcc();
    void Update();
    void Withdraw();
    void del();
};

void Bank::choice()
{
    int res;
    while (1)
    {

        cout << "\tMAIN MENU\n"
             << endl;
        cout << "Enter your choice:- " << endl;
        cout << "1.Create Account\n2.Show Data\n3.Search Account\n4.Update\n5.Withdraw\n6.DELETEACCOUNT\n7.EXIT\n";

        cin >> res;

        switch (res)
        {

        case 1:

            Bank::addData();

            break;
        case 2:
            Bank::showData();
            break;
        case 3:
            Bank::SearchAcc();
            break;
        case 4:
            Bank::Update();
            break;
        case 5:
            Bank::Withdraw();
            break;
        case 6:
            Bank::del();
            break;
        case 7:

            exit(0);

            break;

        default:

            cout << "Invalid input" << endl;

            break;
        }
    }
}

void Bank::addData()
{
    cout << "Enter Data of person " << total + 1 << endl;
    cout << "Enter name:- ";
    cin >> person[total].name;
    cout << "Enter ID:- ";
    cin >> person[total].ID;
    cout << "Enter contact:- ";
    cin >> person[total].contact;
    cout << "Enter Balance:- ";
    cin >> person[total].cash;
    cout << "\tData added successfully :)\n";
    total++;
}

void Bank::showData()
{

    cout << "\tTotal number of acccounts:- " << total << endl;
    cout << "Account details\n"
         << endl;
    if (total == 0)
    {
        cout << "NO ACCOUNTS\n";
        return;
    }
    for (int i = 0; i < total; i++)
    {
        cout << "Account No:- " << i << endl;
        cout << "Account Holder Name:- " << person[i].name << endl;
        cout << "Account Holder ID:- " << person[i].ID << endl;
        cout << "Account Holder balance:- " << person[i].cash << endl;
        cout << "Account Holder contact:- " << person[i].contact << endl;
        cout << endl;
    }
}

void Bank::SearchAcc()
{
    cout << "Enter id you want to search:- ";
    cin >> id;
    cout << "Searching..." << endl;
    for (int i = 0; i < total; i++)
    {
        if (id == person[i].ID)
        {
            cout << "Account No:- " << i << endl;
            cout << "Account Holder Name:- " << person[i].name << endl;
            cout << "Account Holder ID:- " << person[i].ID << endl;
            cout << "Account Holder balance:- " << person[i].cash << endl;
            cout << "Account Holder contact:- " << person[i].contact << endl;
            cout << endl;
            return;
        }
    }
    cout << "Invalid ID :(" << endl;
}
void Bank::Update()
{
    cout << "Enter id you want to search:- ";
    cin >> id;
    cout << "Searching..." << endl;
    for (int i = 0; i < total; i++)
    {
        if (id == person[i].ID)
        {
            cout << "Account No:- " << i << endl;

            cout << "New Account Holder Name:- ";
            cin >> person[i].name;
            cout << "New Account Holder ID:- ";
            cin >> person[i].ID;
            cout << "New Account Holder balance:- ";
            cin >> person[i].cash;
            cout << "New Account Holder contact:- ";
            cin >> person[i].contact;
            cout << "Details Updated Successfully:)\n";
            cout << endl;
            return;
        }
    }
    cout << "No account found :(\n";
}
void Bank::Withdraw()
{
    cout << "Enter id you want to search:- ";
    cin >> id;
    cout << "Searching..." << endl;
    for (int i = 0; i < total; i++)
    {
        if (id == person[i].ID)
        {
            cout << "Account No:- " << i << endl;
            cout << " Account Holder Name:- " << person[i].name << endl;
            cout << " Account Holder ID:- " << person[i].ID << endl;
            cout << " Account Holder balance:- " << person[i].cash << endl;
            int x;
            cout << "Enter Amount to be withdraw:- ";
            cin >> x;
            if (x > person[i].cash)
            {
                cout << "Insufficient Balance\n";
                return;
            }
            else
            {
                person[i].cash -= x;

                cout << "Balance:- " << person[i].cash;
            }
            cout << endl;
            return;
        }
    }
    cout << "No account found :(\n";
}
void Bank::del()
{
    cout << "Enter id of student those data you want to remove" << endl;

    cin >> id;

    for (int i = 0; i < total; i++)
    {

        if (id == person[i].ID)
        {

            for (int j = i; j < total; j++)
            {

                person[j].name = person[j + 1].name;

                person[j].ID = person[j + 1].ID;

                person[j].contact = person[j + 1].contact;

                person[j].cash = person[j + 1].cash;

                total--;

                cout << "Your required data is deleted" << endl;
            }
            return;
        }
    }
    cout << "No data found:(\n";
}
// driver code
int main()
{
    system("CLS");
    cout << "\t\t<------WELCOME TO BANK OF PUNE------>\n";
    cout << "\t\nSign Up\n\n";
    string username, password;
    cout << "Enter username:- " << endl;
    cin >> username;
    cout << "Enter Password:- " << endl;
    cin >> password;
    cout << "Signed in successfully" << endl;

LOGIN:
    cout << "\t\nLogin\n\n";

    string username1, password1;
    cout << "Enter username1:- " << endl;
    cin >> username1;
    cout << "Enter password1:- " << endl;
    cin >> password1;

    if (username1 == username && password1 == password)
    {
        cout << "Logged in successfully" << endl;
    }
    else if (username != username1)
    {
        cout << "Username is incorrect\n";
        goto LOGIN;
    }
    else if (username != username1)
    {
        cout << "Username is incorrect\n";
        goto LOGIN;
    }
    else
    {
        cout << "Incoorect USerID and Password\n";
        goto LOGIN;
    }

    system("CLS");

    Bank b;
    b.choice();

    return 0;
}