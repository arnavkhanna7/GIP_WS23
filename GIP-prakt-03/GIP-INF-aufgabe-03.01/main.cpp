#include <iostream>
using namespace std;

int main()
{

    int tag_1;
    int tag_2;
    int monat_1;
    int monat_2;
    int jahr_1;
    int jahr_2;

    cout << "Bitte geben Sie den Tag des ersten Datums ein: " << endl;
    cin >> tag_1;
    cout << "Bitte geben Sie den Monat des ersten Datums ein: " << endl;
    cin >> monat_1;
    cout << "Bitte geben Sie das Jahr des ersten Datums ein: " << endl;
    cin >> jahr_1;
    cout << "Bitte geben Sie den Tag des zweiten Datums ein: " << endl;
    cin >> tag_2;
    cout << "Bitte geben Sie den Monat des zweiten Datums ein: " << endl;
    cin >> monat_2;
    cout << "Bitte geben Sie das Jahr des zweiten Datums ein: " << endl;
    cin >> jahr_2;

    if (jahr_1 < jahr_2)

        cout << "Das erste Datum liegt vor dem zweiten Datum." << endl;

    else if (jahr_1 > jahr_2)

        cout << "Das zweite Datum liegt vor dem ersten Datum." << endl;

    else if (jahr_1 == jahr_2)
    {
        if (monat_1 > monat_2)

            cout << "Das zweite Datum liegt vor dem ersten Datum." << endl;

        else if (monat_1 < monat_2)

            cout << "Das erste Datum liegt vor dem zweiten Datum." << endl;

        else if (monat_1 == monat_2)
        {
            if (tag_1 > tag_2)

                cout << "Das zweite Datum liegt vor dem ersten Datum." << endl;

            else if (tag_1 < tag_2)

                cout << "Das erste Datum liegt vor dem zweiten Datum." << endl;
            else if (tag_1 == tag_2)
                cout << "Beide Datumsangaben sind gleich." << endl;
        }
    }

    system("pause");
    return 0;
}