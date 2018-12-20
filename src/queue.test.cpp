using namespace std;

#include "queue.cpp"
#include <iostream>

int main () {
  Queue testQueue(2);
  Process p1(1, 2, 3, 3);
  Process p2(2, 2, 2, 4);

  testQueue.add(p1);
  testQueue.add(p2);

  cout << "Incoming pre move, size: " << testQueue.getIncoming().size() << endl;
  for (int i = 0; i < testQueue.getIncoming().size(); i++) {
    cout << testQueue.getIncoming().at(i).getId() << " " <<
    testQueue.getIncoming().at(i).getArrival() << " " <<
    testQueue.getIncoming().at(i).getPriority() << " " <<
    testQueue.getIncoming().at(i).getExecution() << endl;
  }
  
  cout << endl;

  cout << "Queue pre move, size: " << testQueue.getQueue().size() << endl;
  for (int i = 0; i < testQueue.getQueue().size(); i++) {
    cout << testQueue.getQueue().at(i).getId() << " " <<
    testQueue.getQueue().at(i).getArrival() << " " <<
    testQueue.getQueue().at(i).getPriority() << " " <<
    testQueue.getQueue().at(i).getExecution() << endl;
  }

  unsigned int c = testQueue.schedule(0, 0);

  cout << "Incoming post move, size: " << testQueue.getIncoming().size() << endl;
  for (int i = 0; i < testQueue.getIncoming().size(); i++) {
    cout << testQueue.getIncoming().at(i).getId() << " " <<
    testQueue.getIncoming().at(i).getArrival() << " " <<
    testQueue.getIncoming().at(i).getPriority() << " " <<
    testQueue.getIncoming().at(i).getExecution() << endl;
  }
  
  cout << endl;

  cout << "Queue post move, size: " << testQueue.getQueue().size() << endl;
  for (int i = 0; i < testQueue.getQueue().size(); i++) {
    cout << testQueue.getQueue().at(i).getId() << " " <<
    testQueue.getQueue().at(i).getStart() << " " <<
    testQueue.getQueue().at(i).getCompletion() << " " <<
    testQueue.getQueue().at(i).getTurnaround() << endl;
  }

  testQueue.schedule(0, c);

  cout << "Incoming post move, size: " << testQueue.getIncoming().size() << endl;
  for (int i = 0; i < testQueue.getIncoming().size(); i++) {
    cout << testQueue.getIncoming().at(i).getId() << " " <<
    testQueue.getIncoming().at(i).getArrival() << " " <<
    testQueue.getIncoming().at(i).getPriority() << " " <<
    testQueue.getIncoming().at(i).getExecution() << endl;
  }
  
  cout << endl;

  cout << "Queue post move, size: " << testQueue.getQueue().size() << endl;
  for (int i = 0; i < testQueue.getQueue().size(); i++) {
    cout << testQueue.getQueue().at(i).getId() << " " <<
    testQueue.getQueue().at(i).getStart() << " " <<
    testQueue.getQueue().at(i).getCompletion() << " " <<
    testQueue.getQueue().at(i).getTurnaround() << endl;
  }
}