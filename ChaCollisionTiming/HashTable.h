#pragma once
#include <iostream>
#include <vector>
using namespace std;

class LinearTable {
private:
	int data[29]{ NULL };
	double loadFactor = 0;
	int inserts = 0;
	int firstCollision = 0;

public:
	void add(int index, int numIn) {
		if (loadFactor == 1) {
			return;
		}
		inserts++;
		if (data[index % 29] == NULL) {
			data[index % 29] = numIn;
		}
		else {
			for (int i = 1; i < 29; i++) {
				if (data[((index % 29) + i) % 29] == NULL) {
					data[((index % 29) + i) % 29] = numIn;
					break;
				}
			}
			if (firstCollision == 0) {
				firstCollision = inserts;
			}
		}
		this->calcLoad();
	}

	void printTable() {
		cout << "[";
		for (int i = 0; i < 29; i++) {
			cout << data[i] << " ";
		}
		cout << "]";
	}

	void calcLoad() {
		double entries = 0;
		for (int i = 0; i < 29; i++) {
			if (data[i] != 0) {
				entries++;
			}
		}
		loadFactor = entries / 29;
	}

	double getLoad() {
		return loadFactor;
	}

	int getFirstCollsion() {
		return firstCollision;
	}
};

class QuadraticTable {
private:
	int data[29]{ NULL };
	double loadFactor = 0;
	int inserts = 0;
	int firstCollision = 0;
public:
	void add(int index, int numIn) {
		if (loadFactor == 1) {
			return;
		}
		inserts++;
		if (data[index % 29] == NULL) {
			data[index % 29] = numIn;
		}
		else {
			for (int i = 1; i < 29; i++) {
				if (data[((index % 29) + (i * i)) % 29] == NULL) {
					data[((index % 29) + (i * i)) % 29] = numIn;
					break;
				}
				if (firstCollision == 0) {
					firstCollision = inserts;
				}
			}
		}
		this->calcLoad();
	}

	void printTable() {
		cout << "[";
		for (int i = 0; i < 29; i++) {
			cout << data[i] << " ";
		}
		cout << "]";
	}

	void calcLoad() {
		double entries = 0;
		for (int i = 0; i < 29; i++) {
			if (data[i] != 0) {
				entries++;
			}
		}
		loadFactor = entries / 29;
	}

	double getLoad() {
		return loadFactor;
	}

	int getFirstCollsion() {
		return firstCollision;
	}
};

class ChainTable {
private:
	vector<int> data[29]{};
	double loadFactor = 0;
	int inserts = 0;
	int firstCollision = 0;
	int loadFactor90 = 0;
	int loadFactor100 = 0;
	int length29 = 0;

public:
	void add(int index, int numIn) {
		inserts++;
		if (data[index % 29].size() != 0 && firstCollision == 0) {
			firstCollision = inserts;
		}
		data[index % 29].push_back(numIn);
		this->calcLoad();
		if (loadFactor90 == 0 && loadFactor >= .9) {
			loadFactor90 = inserts;
		}
		if (loadFactor100 == 0 && loadFactor == 1) {
			loadFactor100 = inserts;
		}
		if (length29 == 0 && data[index % 29].size() >= 29) {
			length29 = inserts;
		}
	}

	void printTable() {
		cout << "[";
		for (int i = 0; i < 29; i++) {
			cout << data[i].size() << " ";
		}
		cout << "]";
	}

	void calcLoad() {
		double entries = 0;
		for (int i = 0; i < 29; i++) {
			if (data[i].size() != 0) {
				entries++;
			}
		}
		loadFactor = entries / 29;
	}

	double getLoad() {
		return loadFactor;
	}

	int getFirstCollsion() {
		return firstCollision;
	}

	int getLoadFactor90() {
		return loadFactor90;
	}

	int getLoadFactor100() {
		return loadFactor100;
	}

	int getLength29() {
		return length29;
	}
};