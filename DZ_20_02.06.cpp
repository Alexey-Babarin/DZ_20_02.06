#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Структура для хранения данных о покупателе
struct Customer
{
    std::string surname;
    std::string name;
    std::string patronymic;
    char gender = 0;
    std::string nationality;
    int height = 0;
    int weight = 0;
    std::string birthdate; // в формате ГГГГ-ММ-ДД
    std::string phone;
    std::string address; // в одной строке
    std::string credit_card;
    std::string bank_account;
};

// Функция для чтения данных из файла
std::vector<Customer> readCustomersFromFile(const std::string& filename)
{
    std::vector<Customer> customers;
    std::ifstream file(filename);
    Customer customer;

    if (file.is_open())
    {
        while (file >> customer.surname >> customer.name >> customer.patronymic >> customer.gender >> customer.nationality >> customer.height >> customer.weight >> customer.birthdate >> customer.phone >> customer.address >> customer.credit_card >> customer.bank_account)
        {
            customers.push_back(customer);
        }
        file.close();
    }
    else
    {
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
    }

    return customers;
}

// Функция для записи отфильтрованных данных в новый файл
void writeCustomersToFile(const std::string& filename, const std::vector<Customer>& customers)
{
    std::ofstream file(filename);

    if (file.is_open())
    {
        for (const auto& customer : customers)
        {
            std::cout << "Обработка: " << customer.surname << " " << customer.name << " " << customer.address << std::endl; // Отладочный вывод
            if (customer.address.find("Волгоград") != std::string::npos)
            {
                std::cout << "Запись: " << customer.surname << " " << customer.name << std::endl; // Вывод для отладки
                file << customer.surname << " "
                    << customer.name << " "
                    << customer.patronymic << " "
                    << customer.gender << " "
                    << customer.nationality << " "
                    << customer.height << " "
                    << customer.weight << " "
                    << customer.birthdate << " "
                    << customer.phone << " "
                    << customer.address << " "
                    << customer.credit_card << " "
                    << customer.bank_account << std::endl;
            }
        }
        file.close();
    }
    else
    {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
    }
}


int main()
{
    setlocale(LC_ALL, "Rus");
    // Создание и запись данных в файл
    std::string inputFilename = "customers.txt";
    std::ofstream outFile(inputFilename);
    if (outFile.is_open())
    {
        // Здесь должен быть код для записи данных о покупателях
        // Пример:
        outFile << "Иванов Иван Иванович M Русский 180 80 1980-01-01 1234567890 Россия_Волгоградская область_Волгоград_ул._Пушкина_д._10_кв._5 1111222233334444_5555666677778888" << std::endl;
        // Добавьте больше данных в соответствии с вашими требованиями
        outFile.close();
    }
    else
    {
        std::cerr << "Не удалось создать файл." << std::endl;
    }

    // Чтение и обработка данных
    std::vector<Customer> customers = readCustomersFromFile(inputFilename);

    // Сохранение результатов в новый файл
    std::string outputFilename = "volgograd_customers.txt";
    writeCustomersToFile(outputFilename, customers);

    return 0;
}
