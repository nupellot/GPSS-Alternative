#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// Исходные данные.
double const MODEL_TIME = 3600;
int R[] = {2, 8, 11, 9};
int G[] = {1, 5, 8, 6};
int B[] = {2, 7, 11, 8};
int RGB[] = {5, 20, 30, 23};


class Client {  // Класс клиента.
private:
	int number = -1;
public:
	int getNumber() {
		return number;
	}
};

class CashRegister {  // Класс кассы.
private:
	// Очередь клиентов. Обсулживаемый в данный момент клиент тоже входит в очередь.
	queue<Client> clientsQueue;
	int number = -1;
public:
	CashRegister(int n) {  // Конструктор кассы.
		number = n;
	}
	void addClient(Client client) {  // Добавить клиента в очередь.
		clientsQueue.push(client);
	}
	int getQueueLength() {  // Получить длину очереди.
		return clientsQueue.size();
	}
	void serveClient() {  // Обслужить клиента.
		if (!clientsQueue.empty()) {
			cout << "Касса " << number << " обработала клиента " << clientsQueue.front().getNumber() << endl;
			// Удаляем клиента из очереди.
			clientsQueue.pop();
		}
	}
};


int main() {
	// Создаём 2 кассы.
	CashRegister cashRegister1(1);
	CashRegister cashRegister2(2);
  double currentTime = 0;  // Глобальный счётчик времени.
	// Есть 2 вида события - приход клиента и его уход.
	// В любой момент времени ближайшим событием будет являться либо окончание обслуживания клиента на одной из касс, либо приход нового клиента.

	// Находим время до событий.
	double nextEntranceTime = currentTime + double(rand() % (RGB[1] * 100)) / 100;
	double nextExitTimeFor1 = currentTime + R[1] + double(rand() % ((RGB[1] - R[1]) * 100)) / 100;
	double nextExitTimeFor2 = currentTime + G[1] + double(rand() % ((RGB[1] - G[1]) * 100)) / 100;

	while (currentTime < 50) {
		// Обрабатываем ближайшее событие.
		if (nextEntranceTime < nextExitTimeFor1 && nextEntranceTime < nextExitTimeFor2) {
			// Ближайшим событием оказался приход клиента.
			
			currentTime = nextEntranceTime;
			nextEntranceTime = currentTime + double(rand() % (RGB[1] * 100)) / 100;
		} else
		if (nextExitTimeFor1 < nextEntranceTime && nextExitTimeFor1 < nextExitTimeFor2) {
			// Ближайшим событием оказалось обслуживание клиента на первой кассе.
			cashRegister1.serveClient();
			currentTime = nextExitTimeFor1;
			nextExitTimeFor1 = currentTime + R[1] + double(rand() % ((RGB[1] - R[1]) * 100)) / 100;
		} else
		if (nextExitTimeFor2 < nextEntranceTime && nextExitTimeFor2 < nextExitTimeFor1) {
			// Ближайшим событием оказалось обслуживание клиента на второй кассе.
			cashRegister2.serveClient();
			currentTime = nextExitTimeFor2;
			nextExitTimeFor2 = currentTime + G[1] + double(rand() % ((RGB[1] - G[1]) * 100)) / 100;
		}

	}

}