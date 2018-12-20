#ifndef ALGORITHM
#define ALGORITHM

#include "queue.cpp"
#include <iostream>
using namespace std;

class Algorithm {
  public:
    static float fcfs(Queue&);
    static float priority(Queue&);
    static float sjn(Queue&);

  private:
};

#endif

float Algorithm::fcfs(Queue & queue) {
  // Time.
  unsigned int t = 0;
  // Size
  unsigned int n = queue.getIncoming().size();

  // Until there are no more incoming.
  while (queue.getIncoming().size() > 0) {

    // Index of best choice.
    signed int b = -1;
    
    // Iterate through whatever incoming is left.
    for (unsigned int i = 0; i < queue.getIncoming().size(); i++) { 

      // If the time is greater than or equal to the arrival && the arrival is the least.
      if (t >= queue.getIncoming().at(i).getArrival()) {

        // If there is nothing to compare with for this i round.
        if (i == 0) {
          b = i;
        }
        // Else if there is something to compare with.
        else {
          // If the current arrival time is better.
          if (queue.getIncoming().at(i).getArrival() < queue.getIncoming().at(b).getArrival())
            b = i;
        }

        
      }
    }

    // If anything was found at this t.
    if (b > -1)
      // Schedule it.
      t = queue.schedule(b, t);
    // Else if nothing was found at this t.
    else
      t += 1;
  }

  float sumT = 0;

  for (unsigned int i = 0; i < queue.getQueue().size(); i++) {
    sumT += queue.getQueue().at(i).getTurnaround();
  }

  return sumT / queue.getQueue().size();
}

float Algorithm::priority(Queue & queue) {
  // Time.
  unsigned int t = 0;
  // Size
  unsigned int n = queue.getIncoming().size();

  // Until there are no more incoming.
  while (queue.getIncoming().size() > 0) {

    // Index of best choice.
    signed int b = -1;
    
    // Iterate through whatever incoming is left.
    for (unsigned int i = 0; i < queue.getIncoming().size(); i++) { 

      // If the time is greater than or equal to the arrival && the arrival is the least.
      if (t >= queue.getIncoming().at(i).getArrival()) {

        // If there is nothing to compare with for this i round.
        if (i == 0) {
          b = i;
        }
        // Else if there is something to compare with.
        else {
          // If the current priority is better.
          if (queue.getIncoming().at(i).getPriority() < queue.getIncoming().at(b).getPriority())
            b = i;
        }

      }
    }

    // If anything was found at this t.
    if (b > -1)
      // Schedule it.
      t = queue.schedule(b, t);
    // Else if nothing was found at this t.
    else
      t += 1;
  }

  float sumT = 0;

  for (unsigned int i = 0; i < queue.getQueue().size(); i++) {
    sumT += queue.getQueue().at(i).getTurnaround();
  }

  return sumT / queue.getQueue().size();
}

float Algorithm::sjn(Queue & queue) {
  // Time.
  unsigned int t = 0;
  // Size
  unsigned int n = queue.getIncoming().size();

  // Until there are no more incoming.
  while (queue.getIncoming().size() > 0) {

    // Index of best choice.
    signed int b = -1;
    
    // Iterate through whatever incoming is left.
    for (unsigned int i = 0; i < queue.getIncoming().size(); i++) { 

      // If the time is greater than or equal to the arrival && the arrival is the least.
      if (t >= queue.getIncoming().at(i).getArrival()) {

        // If there is nothing to compare with for this i round.
        if (i == 0) {
          b = i;
        }
        // Else if there is something to compare with.
        else {
          // If the current priority is better.
          if (queue.getIncoming().at(i).getExecution() < queue.getIncoming().at(b).getExecution())
            b = i;
        }

      }
    }

    // If anything was found at this t.
    if (b > -1)
      // Schedule it.
      t = queue.schedule(b, t);
    // Else if nothing was found at this t.
    else
      t += 1;
  }

  float sumT = 0;

  for (unsigned int i = 0; i < queue.getQueue().size(); i++) {
    sumT += queue.getQueue().at(i).getTurnaround();
  }

  return sumT / queue.getQueue().size();
}