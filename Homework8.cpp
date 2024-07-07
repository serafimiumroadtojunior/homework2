#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Subscriber {
    string lastName;
    string phoneNumber;
};

vector<Subscriber> readSubscribersFromFile(const string& filename) {
    vector<Subscriber> subscribers;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return subscribers;
    }

    Subscriber sub;
    while (file >> sub.lastName >> sub.phoneNumber) {
        subscribers.push_back(sub);
    }

    file.close();
    return subscribers;
}

void displayAllSubscribers(const vector<Subscriber>& subscribers) {
    cout << "Подписчики и их номера:" << endl;
    for (const auto& sub : subscribers) {
        cout << sub.lastName << " " << sub.phoneNumber << endl;
    }
}

void displaySubscriber(const vector<Subscriber>& subscribers, const string& lastName) {
    for (const auto& sub : subscribers) {
        if (sub.lastName == lastName) {
            cout << "Подписчик: " << sub.lastName << " " << sub.phoneNumber << endl;
            return;
        }
    }
    cout << "Поиск подписчика по имени " << lastName << " не найден." << endl;
}

int main() {
    string filename = "subscribers.txt";
    vector<Subscriber> subscribers = readSubscribersFromFile(filename);

    if (subscribers.empty()) {
        cout << "Подписчики отсутствуют или ошибка с файлом." << endl;
        return 1;
    }

    int choice;
    string lastName;

    cout << "Выберите действие:" << endl;
    cout << "[1] Показ всех подписчиков и их номеров" << endl;
    cout << "[2] Поиск по имени" << endl;
    cout << "Выбирайте: ";
    cin >> choice;

    switch (choice) {
    case 1:
        displayAllSubscribers(subscribers);
        break;
    case 2:
        cout << "Напишите имя подписчика: ";
        cin >> lastName;
        displaySubscriber(subscribers, lastName);
        break;
    default:
        cout << "Неверный выбор." << endl;
        break;
    }

    return 0;
}

void copyLinesInSameOrder(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Ошибка открытия файла." << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "output_same_order.txt";

    copyLinesInSameOrder(inputFile, outputFile);

    cout << "Строки скопированы в том же порядке." << endl;

    return 0;
}

void copyLinesInReverseOrder(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Ошибка открытия файла." << endl;
        return;
    }

    vector<string> lines;
    string line;
    while (getline(inFile, line)) {
        lines.push_back(line);
    }

    for (auto it = lines.rbegin(); it != lines.rend(); ++it) {
        outFile << *it << endl;
    }

    inFile.close();
    outFile.close();
}

int main() {
    string inputFile = "input2.txt";
    string outputFile = "output_reverse_order.txt";

    copyLinesInReverseOrder(inputFile, outputFile);

    cout << "Строки скопированы в обратном порядке." << endl;

    return 0;
}


void addDashesAfterLastLineWithoutSpaces(const string& inputFile) {
    ifstream inFile(inputFile);
    ofstream tempFile("temp.txt");

    if (!inFile.is_open() || !tempFile.is_open()) {
        cerr << "Ошибка открытия файла." << endl;
        return;
    }

    string line;
    bool addedDashes = false;
    while (getline(inFile, line)) {
        tempFile << line << endl;
        if (!addedDashes && line.find(' ') == string::npos) {
            addedDashes = true;
        }
    }

    if (addedDashes) {
        tempFile << "------------" << endl;
    }
    else {
        tempFile << "------------" << endl;
    }

    inFile.close();
    tempFile.close();

    ifstream tempInFile("temp.txt");
    ofstream outFile(inputFile);

    if (!tempInFile.is_open() || !outFile.is_open()) {
        cerr << "Ошибка открытия временного файла." << endl;
        return;
    }

    while (getline(tempInFile, line)) {
        outFile << line << endl;
    }

    tempInFile.close();
    outFile.close();

    remove("temp.txt");
}

int main() {
    string inputFile = "input3.txt";

    addDashesAfterLastLineWithoutSpaces(inputFile);

    cout << "Строка из двенадцати черточек добавлена." << endl;

    return 0;
}