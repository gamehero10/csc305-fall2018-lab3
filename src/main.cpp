using namespace std;

#include "algorithm.cpp"
#include <iostream>
#include <iomanip>

static unsigned int columnSize = 13;
static unsigned int algorithm = 0;

int main () {
  Queue queue(4);
  Process p1(1, 2, 3, 3);
  Process p2(2, 2, 2, 4);
  Process p3(3, 3, 1, 1);
  Process p4(4, 5, 3, 2);

  queue.add(p1);
  queue.add(p2);
  queue.add(p3);
  queue.add(p4);

  float avgT = 0;

  switch (algorithm) {
    case 0:
      avgT = Algorithm::fcfs(queue);
      cout << "FCFS" << endl;
      break;
    case 1:
      avgT = Algorithm::priority(queue);
      cout << "PRIORITY" << endl;
      break;
    case 2:
      avgT = Algorithm::sjn(queue);
      cout << "SJN" << endl;
      break;
    default:
      avgT = Algorithm::fcfs(queue);
      cout << "FCFS" << endl;
  }

  cout << setw(columnSize) << left << "PID";
  cout << setw(columnSize) << left << "Start";
  cout << setw(columnSize) << left << "Completion";
  cout << setw(columnSize) << left << "Turnaround";
  cout << endl;
  
  for (int i = 0; i < 4; i++) {
    cout << setw(columnSize) << left << queue.getQueue().at(i).getId();
    cout << setw(columnSize) << left << queue.getQueue().at(i).getStart();
    cout << setw(columnSize) << left << queue.getQueue().at(i).getCompletion();
    cout << setw(columnSize) << left << queue.getQueue().at(i).getTurnaround();
    cout << endl;
  }

  cout << "Order of execution: ";

  for (unsigned int i = 0; i < 4; i++)
    cout << "PID " << queue.getQueue().at(i).getId() << " ";
  cout << endl;

  cout << "Average turnaround time: " << avgT << endl;
}