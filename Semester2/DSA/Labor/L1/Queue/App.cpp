#include "Queue.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() {

	//testAll();
	//testAllExtended();
	Queue q;
	for (int i = 0; i < 10; i++) {
		q.push(i);
	}
	assert(q.isEmpty() == false);
	for (int i = -10; i < 20; i++) {
		q.push(i);
	}
	assert(q.isEmpty() == false);
	for (int i = -100; i < 100; i++) {
		q.push(i);
	}
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;

	cout << "Test end" << endl;

}