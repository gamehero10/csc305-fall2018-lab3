#ifndef QUEUE
#define QUEUE

using namespace std;

#include <vector>
#include "process.cpp"

class Queue {
  public:
    Queue(unsigned int);
    ~Queue();

    vector<Process> getIncoming();
    vector<Process> getQueue();

    int add(Process);
    int schedule(unsigned int, unsigned int);
    bool isFree(unsigned int);
    bool isDone(unsigned int);

  private:
    vector<Process> incoming;
    vector<Process> queue;
};

#endif

Queue::Queue (unsigned int n) {
  this->incoming.reserve(n);
  this->queue.reserve(n);
}

Queue::~Queue () {
  vector<Process>().swap(this->queue);
  vector<Process>().swap(this->incoming);
}

vector<Process> Queue::getIncoming() {
  return this->incoming;
}

vector<Process> Queue::getQueue() {
  return this->queue;
}

int Queue::add (Process p) {
  this->incoming.push_back(p);
}

int Queue::schedule (unsigned int i, unsigned int t) {
  // Move process from incoming to queue.
  move(this->incoming.begin() + i, this->incoming.begin() + i + 1, back_inserter(queue));

  // Remove process from incoming.
  this->incoming.erase( this->incoming.begin() + i);

  // Get arrival and execution times.
  unsigned int a = this->queue.at( this->queue.size() - 1 ).getArrival();
  unsigned int e = this->queue.at( this->queue.size() - 1 ).getExecution();

  // Set start time.
  if (t == 0)
    this->queue.at( this->queue.size() - 1 ).setStart(a);
  else
    this->queue.at( this->queue.size() - 1 ).setStart(t);
  unsigned int s = this->queue.at( this->queue.size() - 1 ).getStart();
  
  // Set set completion time.
  unsigned int c = s + e;
  this->queue.at( this->queue.size() - 1 ).setCompletion(c);

  // Set turnaround time.
  this->queue.at( this->queue.size() - 1 ).setTurnaround(c - a);

  // Return when the process ends.
  return c;
}