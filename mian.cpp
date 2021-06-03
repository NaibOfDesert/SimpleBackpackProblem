#include <iostream>

using namespace std;

// wyznaczanie wartosci wiekszej
int maximum(int _value_1, int _value_2) {
	if (_value_1 > _value_2) {
		return _value_1;
	}
	else {
		return _value_2;
	}
}

// wyszukiwanie wartosci najwiekszej
int better_solution(int _value[], int _weight[], int _pack_quantity, int _max_weight) {
	if (_pack_quantity == 0 || _max_weight == 0)
		return 0;

	if (_weight[_pack_quantity - 1] > _max_weight) {
		return better_solution(_value, _weight, _pack_quantity - 1, _max_weight);
	}
	else {
		return maximum(_value[_pack_quantity - 1] + better_solution(_value, _weight, _pack_quantity - 1, _max_weight - _weight[_pack_quantity - 1]), better_solution(_value, _weight, _pack_quantity - 1, _max_weight));
	}
}

// rozwiazanie dla poszczegolnego samochodu
int load_and_solve() {
	int pack_quantity;
	// wczytywanie ilosci obiektow
	cin >> pack_quantity;

	// tworzenie niezbednych zmiennych i tablic
	int* value = new int[pack_quantity];
	int* weight = new int[pack_quantity];

	// wczytywanie wartosci obiektow
	for (int j = 0; j < pack_quantity; j++) {
		cin >> value[j];
	}

	// wczytywanie ciezaru obiektow
	for (int j = 0; j < pack_quantity; j++) {
		cin >> weight[j];
		if (weight[j] > 100) {
			if (value[j] <= 5) {
				value[j] = 0;
			}
			else value[j] -= 5;

		}
	}

	// wczytywanie pojemnosci samochodu
	int max_weight;
	cin >> max_weight;

	// wyszukaiwanie najwyzszej wartosci
	int total_value = -20;
	total_value += better_solution(value, weight, pack_quantity, max_weight);

	// zwalnianie pamieci
	delete[] weight, value;

	// zwracanie maksymalnej wartosci
	return total_value;
}

int main() {
	int bus_quantity;

	// wczytywanie ilosci samochodow
	cin >> bus_quantity;

	int* total_value = new int[bus_quantity];

	// wykonywanie zadania
	for (int i = 0; i < bus_quantity; i++) {
		total_value[i] = load_and_solve();
	}

	// wypisywanie wynikow
	for (int i = 0; i < bus_quantity; i++) {
		if (total_value[i] <= 0) {
			cout << "0" << endl;
		}
		else cout << total_value[i] << endl;
	}

	// zwalnianie pamieci
	delete[] total_value;

	return 0;
}
