#include <iostream>
#include <vector>
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
	double entranceTime = -1;

};

class CashRegister {  // Класс кассы.
private:
	// Очередь клиентов. Обсулживаемый в данный момент клиент тоже входит в очередь.
	queue<Client> clientsQueue;
public:
	void addClient(Client client) {  // Добавить клиента в очередь.
		clientsQueue.push(client);
	}
	int getQueueLength() {  // Получить длину очереди.
		return clientsQueue.size();
	}
};


int main() {
	// Создаём 2 кассы.
	vector<CashRegister> CashRegisters(2);
  double currentTime = 0;  // Глобальный счётчик времени.
	// Есть 2 вида события - приход клиента и его уход.
	// В любой момент времени ближайшим событием будет являться либо окончание обслуживания клиента, либо приход нового клиента.

	double nextEntranceTime = currentTime + double(rand() % (RGB[1] * 100)) / 100;
	while (currentTime < 50) {
		currentTime++;
		printf("%lf\n", double(rand() % (RGB[1] * 100)) / 100);
	}
}