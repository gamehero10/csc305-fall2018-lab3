#ifndef PROCESS
#define PROCESS

class Process {

  public:
    Process(int, int, int, int);
    ~Process();

  /*
    GETTERS
  */
  int getId();
  int getArrival();
  int getPriority();
  int getExecution();

  int getStart();
  int getCompletion();
  int getTurnaround();

  /*
    SETTERS
  */
  void setId(int);
  void setArrival(int);
  void setPriority(int);
  void setExecution(int);

  void setStart(int);
  void setCompletion(int);
  void setTurnaround(int);


  private:
    int unsigned id, arrival, priority, execution;
    int unsigned start, completion, turnaround;
};

#endif

Process::Process (int id, int arrival, int priority, int execution) {
  this->setId(id);
  this->setArrival(arrival);
  this->setPriority(priority);
  this->setExecution(execution);
}

Process::~Process () {}

/*
  GETTERS
*/
int Process::getId() {
  return this->id;
}
int Process::getArrival() {
  return this->arrival;
}
int Process::getPriority() {
  return this->priority;
}
int Process::getExecution() {
  return this->execution;
}

int Process::getStart() {
  return this->start;
}
int Process::getCompletion() {
  return this->completion;
}
int Process::getTurnaround() {
  return this->turnaround;
}

/*
  SETTERS
*/
void Process::setId(int id) {
  this->id = id;
}
void Process::setArrival(int arrival) {
  this->arrival = arrival;
}
void Process::setPriority(int priority) {
  this->priority = priority;
}
void Process::setExecution(int execution) {
  this->execution = execution;
}

void Process::setStart(int start) {
  this->start = start;
}
void Process::setCompletion(int completion) {
  this->completion = completion;
}
void Process::setTurnaround(int turnaround) {
  this->turnaround = turnaround;
}