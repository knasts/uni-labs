//14. Розробити набір / ієрархію структур з такою інформацією : абонент і телефон.Для
//абонента задається прізвище, адреса.Для телефону задається номер, оператор(Life,
//    Київстар тощо) і заборгованість по оплаті.Створений масив записати до бінарного
//    файлу.Передбачити можливість доповнити файл, замінити дані в файлі, видалити
//    дані з файлу.Реалізувати запити : 1) визначити прізвища абонентів, що мають
//    заборгованість по оплаті більше заданої; 2) знайти абонента за номером телефону.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

struct abonent;
struct phone;
struct abonent_info;

void generate_random_abonents(int size, const string& filename);

struct abonent
{
    string name;
    string surname;
};

struct phone
{
    string number;
    int debt = 0;
};


struct abonent_info
{
    abonent user;
    phone user_phone;

    void add_new(const string& filename)
    {
        ofstream file(filename, ios::binary | ios::app);
        if (!file)
        {
            cerr << "file opening error" << endl;
            return;
        }

        size_t name_len = user.name.size(); //отримуємо довжину рядку
                      //перетворює &name_len в const char*
        file.write(reinterpret_cast<const char*>(&name_len), sizeof(name_len)); //запис довжини рядка
        file.write(user.name.c_str(), name_len); //запис символів у рядок
                             //повертає вказівник на рядок
        size_t surname_len = user.surname.size();
        file.write(reinterpret_cast<const char*>(&surname_len), sizeof(surname_len));
        file.write(user.surname.c_str(), surname_len);

        size_t number_len = user_phone.number.size();
        file.write(reinterpret_cast<const char*>(&number_len), sizeof(number_len));
        file.write(user_phone.number.c_str(), number_len);

        file.write(reinterpret_cast<const char*>(&user_phone.debt), sizeof(user_phone.debt));
        file.close();
    }

    static void replace_user(const string& filename, const string& phone_num, const abonent_info& new_data)
    {
        fstream file(filename, ios::binary | ios::in | ios::out);
        if (!file)
        {
            cerr << "file opening error" << endl;
            return;
        }

        while (file.peek() != EOF)
        {
            streampos pos = file.tellg();
            abonent_info user;
            size_t len;

            file.read(reinterpret_cast<char*>(&len), sizeof(len));
            user.user.name.resize(len);
            file.read(&user.user.name[0], len);

            file.read(reinterpret_cast<char*>(&len), sizeof(len));
            user.user.surname.resize(len);
            file.read(&user.user.surname[0], len);

            file.read(reinterpret_cast<char*>(&len), sizeof(len));
            user.user_phone.number.resize(len);
            file.read(&user.user_phone.number[0], len);

            file.read(reinterpret_cast<char*>(&user.user_phone.debt), sizeof(user.user_phone.debt));

            if (user.user_phone.number == phone_num)
            {
                file.seekp(pos);
                size_t name_len = new_data.user.name.size();
                file.write(reinterpret_cast<const char*>(&name_len), sizeof(name_len));
                file.write(new_data.user.name.c_str(), name_len);

                size_t surname_len = new_data.user.surname.size();
                file.write(reinterpret_cast<const char*>(&surname_len), sizeof(surname_len));
                file.write(new_data.user.surname.c_str(), surname_len);

                size_t number_len = new_data.user_phone.number.size();
                file.write(reinterpret_cast<const char*>(&number_len), sizeof(number_len));
                file.write(new_data.user_phone.number.c_str(), number_len);

                file.write(reinterpret_cast<const char*>(&new_data.user_phone.debt), sizeof(new_data.user_phone.debt));
                cout << "User successfully updated.\n";
                file.close();
                return;
            }
        }

        cout << "User not found.\n";
        file.close();
    }


    void find_user(const string& filename, const string& phone_num)
    {
        
        ifstream file(filename, ios::binary);
        if (!file) {
            cerr << "file opening error" << endl;
            return;
        }
        while (file.peek() != EOF)
        {
            abonent_info user;
            size_t len;

            file.read(reinterpret_cast<char*>(&len), sizeof(len));
            user.user.name.resize(len);
            file.read(&user.user.name[0], len);

            file.read(reinterpret_cast<char*>(&len), sizeof(len));
            user.user.surname.resize(len);
            file.read(&user.user.surname[0], len);

            file.read(reinterpret_cast<char*>(&len), sizeof(len));
            user.user_phone.number.resize(len);
            file.read(&user.user_phone.number[0], len);

            file.read(reinterpret_cast<char*>(&user.user_phone.debt), sizeof(user.user_phone.debt));
        
            if (user.user_phone.number == phone_num)
            {
                cout << "Found user:" << endl;
                cout << "** Name: " << user.user.name << endl;
                cout << "** Surname: " << user.user.surname << endl;
                cout << "** Phone: " << user.user_phone.number << endl;
                cout << "** Debt: " << user.user_phone.debt << "$$" << endl;
                file.close();
                return;
            }
        }
        cout << "User with phone number " << phone_num << " NOT found in our list." << endl;
        file.close();
    }

    static void delete_user(const string& filename, const string& phone_num)
    {
        ifstream in_file(filename, ios::binary); //читаємо із основного і пишемо в тимчасовий 
        ofstream temp_file("temp.bin", ios::binary | ios::trunc); //перед записом очищається

        if (!in_file || !temp_file)
        {
            cerr << "file opening error" << endl;
            return;
        }

        bool deleted = false;

        while (in_file.peek() != EOF)//до кінця файлу
        {
            abonent_info user;
            size_t len;

            in_file.read(reinterpret_cast<char*>(&len), sizeof(len));
            user.user.name.resize(len);
            in_file.read(&user.user.name[0], len);

            in_file.read(reinterpret_cast<char*>(&len), sizeof(len));
            user.user.surname.resize(len);
            in_file.read(&user.user.surname[0], len);

            in_file.read(reinterpret_cast<char*>(&len), sizeof(len));
            user.user_phone.number.resize(len);
            in_file.read(&user.user_phone.number[0], len);

            in_file.read(reinterpret_cast<char*>(&user.user_phone.debt), sizeof(user.user_phone.debt));

            if (user.user_phone.number != phone_num) //якщо це не номер, який ми видаляємо, то переписуємо
            {
               
                size_t name_len = user.user.name.size();
                temp_file.write(reinterpret_cast<const char*>(&name_len), sizeof(name_len));
                temp_file.write(user.user.name.c_str(), name_len);

                size_t surname_len = user.user.surname.size();
                temp_file.write(reinterpret_cast<const char*>(&surname_len), sizeof(surname_len));
                temp_file.write(user.user.surname.c_str(), surname_len);

                size_t number_len = user.user_phone.number.size();
                temp_file.write(reinterpret_cast<const char*>(&number_len), sizeof(number_len));
                temp_file.write(user.user_phone.number.c_str(), number_len);

                temp_file.write(reinterpret_cast<const char*>(&user.user_phone.debt), sizeof(user.user_phone.debt));
            }
            else
            {
                deleted = true; // цей номер ми видаляємо
            }
        }

        in_file.close();
        temp_file.close();

        if (deleted)
        {
            if (remove(filename.c_str()) != 0) //видаляємо старий файл
            {
                cerr << "error deleting original file.\n";
                return;
            }

            if (rename("temp.bin", filename.c_str()) != 0) //новий файл з абонентами - копія temp 
            {
                cerr << "error renaming temp file.\n";
                return;
            }
            cout << "user deleted successfully.\n";
        }
        else
        {
            remove("temp.bin");
            cout << "user not found.\n";
        }
    }

    void user_with_debt(const string& filename, int debt_amount)
    {
        ifstream file(filename, ios::binary);
        if (!file) {
            cerr << "file opening error" << endl;
            return;
        }
        int count = 0;
        while (file.peek() != EOF)
        {
            abonent_info user;
            size_t len;

            file.read(reinterpret_cast<char*>(&len), sizeof(len));
            user.user.name.resize(len);
            file.read(&user.user.name[0], len);

            file.read(reinterpret_cast<char*>(&len), sizeof(len));
            user.user.surname.resize(len);
            file.read(&user.user.surname[0], len);

            file.read(reinterpret_cast<char*>(&len), sizeof(len));
            user.user_phone.number.resize(len);
            file.read(&user.user_phone.number[0], len);

            file.read(reinterpret_cast<char*>(&user.user_phone.debt), sizeof(user.user_phone.debt));

            if (user.user_phone.debt > debt_amount)
            {
                cout << "user's with debt more than " << debt_amount << " :" << endl;
                cout << "**name: " << user.user.name << endl;
                cout << "**surname: " << user.user.surname << endl;
                cout << "**phone number: " << user.user_phone.number << endl;
                cout << "**debt amount: " << user.user_phone.debt << "$$" << endl;
                cout << "- - - - - - - - - - - - " << endl;
                count++;
            }
        }
        cout << "total amount of users with high debts: " << count << endl;
        file.close();
    }
};

void generate_random_abonents(int size, const string &filename)
{
    srand(time(0));
    ofstream file(filename, ios::binary);
    if (!file)
    {
        cerr << "file opening error" << endl;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        abonent_info our_user;
        string num = "097";
        for (int j = 0; j < 7; j++)
        {
            num += '0' + rand() % 10;
        }

        int rand_n = rand() % 100;
        if (rand_n < 33)
        {
            our_user.user.name = "Oleg";
            our_user.user.surname = "Shugar";
            our_user.user_phone.number = num;
            our_user.user_phone.debt = rand_n + 10;
        }
        else if (rand_n < 73)
        {
            our_user.user.name = "Yeji";
            our_user.user.surname = "Kim";
            our_user.user_phone.number = num;
            our_user.user_phone.debt = 0;
        }
        else 
        {
            our_user.user.name = "Huba";
            our_user.user.surname = "Buba";
            our_user.user_phone.number = num;
            our_user.user_phone.debt = rand_n - 20;
        }
        our_user.add_new(filename);

    }
    file.close();
    cout << "adding our clients' information was successful" << endl;
    
}

static void printing_info(const string& filename)
{
    ifstream file(filename, ios::binary);
    if (!file)
    {
        cerr << "file opening error" << endl;
        return;
    }

    int index = 1;
    while (file.peek() != EOF)
    {
        abonent_info user;
        size_t len;

        file.read(reinterpret_cast<char*>(&len), sizeof(len));
        user.user.name.resize(len);
        file.read(&user.user.name[0], len);

        file.read(reinterpret_cast<char*>(&len), sizeof(len));
        user.user.surname.resize(len);
        file.read(&user.user.surname[0], len);

        file.read(reinterpret_cast<char*>(&len), sizeof(len));
        user.user_phone.number.resize(len);
        file.read(&user.user_phone.number[0], len);

        file.read(reinterpret_cast<char*>(&user.user_phone.debt), sizeof(user.user_phone.debt));

        cout << "Client #" << index++ << ":\n";
        cout << "**name: " << user.user.name << endl;
        cout << "**surname: " << user.user.surname << endl;
        cout << "**phone number: " << user.user_phone.number << endl;
        cout << "**debt amount: " << user.user_phone.debt << "$$\n";
        cout << "- - - - - - - - - - - -\n";
    }

    file.close();
}


int main()
{
    srand(time(0));    
    int sizee = 5;
    generate_random_abonents(sizee, "abonents.bin");
    int answer;
    
    cout << "Welcome! To begin choose one option and press 1 or 2:" << endl;
    cout << "**press '1' to find client's debt information" << endl;
    cout << "**press '2' to find abonent by phone number" << endl;
    cin >> answer;
    while (answer != 1 && answer != 2)
    {
        cout << "ivalid value, press again" << endl;
        cout << "**press '1' to find client's debt information" << endl;
        cout << "**press '2' to find abonent by phone number" << endl;
        cin >> answer;
    }
    if (answer == 1)
    {
        int debt_limit;
        abonent_info userr;
        cout << "enter debt limit: ";
        cin >> debt_limit;
        userr.user_with_debt("abonents.bin", debt_limit);
    }
    else if (answer == 2)
    {
        string phone_num;
        abonent_info userr;
        cout << "enter user's number: ";
        cin >> phone_num;
        userr.find_user( "abonents.bin", phone_num);
    }
    
    cout << "ALL CLIENTS" << endl;
    printing_info("abonents.bin");
    return 0;
}

