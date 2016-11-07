#include<iostream>
#include<cstring>
#include<algorithm>
#include"JobManager.h"
using namespace std;

JobManager* JobManager::instance = NULL;
JobManager* JobManager::getInstance() {
  if (instance != NULL) {   //  注意每次都要考虑好空和非空的情况
  return instance;
  } else {
  instance = new JobManager();
  return instance;
  }
}
bool JobManager::deleteInstance() {
  if (instance != NULL) {
    delete instance;
    instance = NULL;
    return true;
  }
  return false;
}
void JobManager::addJob(int priority) {
  Job *other = jobFrontPointer;
  if (jobFrontPointer == NULL) {  //  创建第一个
    jobFrontPointer = new Job();
    jobFrontPointer->setPriority(priority);
    return;
  }
  while (other->getNext() != NULL) {  // 创建的新job不是第一个
    other = other->getNext();
  }
  Job *temp = new Job(priority);
  other->setNext(temp);
}
void JobManager::finishOneJob() {   //  删掉第一个对象
  if (jobFrontPointer != NULL) {
    Job *t = jobFrontPointer;
    jobFrontPointer = jobFrontPointer->getNext();
    delete t;
  }
}
int JobManager::getNumOfJob() {   // 不能直接使用Job中的静态变量number,
//   所以进行计数过程
  int totalNumber = 0;
  if (jobFrontPointer != NULL) {
    Job *t = jobFrontPointer;
    totalNumber++;
    while (t->getNext() != NULL) {
      t = t->getNext();
      totalNumber++;
    }
    return totalNumber;
  } else {
    return 0;
  }
}
bool judge(Job *j1, Job *j2) {
  if (j1->getPriority() > j2->getPriority())
  return true;
  if (j1->getPriority() < j2->getPriority())
  return false;
  if (j1->getId() < j2->getId()) return true;
  else return false;
}
void JobManager::sortJob() {
  if (jobFrontPointer == NULL||jobFrontPointer->getNext() == NULL)
    return;
  Job *t = jobFrontPointer;
  int n = getNumOfJob();
  Job *total[n];
  int i = 0;
  for (int i = 0; i < n; i++) {
    total[i] = t;
    t = t->getNext();
  }
  sort(total, total + n, judge);  //  类的sort
  total[n - 1]->setNext(NULL);
  jobFrontPointer = total[0];
  t = jobFrontPointer;
  for (int i = 0; i < n; i++) {
    t->setNext(total[i]);
    t = t->getNext();
  }
}
void JobManager::printJob() {
  if (jobFrontPointer != NULL) {
  Job *t = jobFrontPointer;
  cout << t->toString();
  t = t->getNext();
  while (t != NULL) {
    cout << "->" << t->toString();
    t = t->getNext();
  }
  cout << endl;
  } else {
  cout << "empty!" << endl;
  }
}
void JobManager::clear() {
  while (jobFrontPointer != NULL)
    this->finishOneJob();
  return;
}
JobManager::JobManager() {
  jobFrontPointer = NULL;
}
JobManager::~JobManager() {
  this->clear();  // 利用已有的clear函数可以减少代码的行数，同时也比较简单
  //  类的各个函数之间常常有相似的，可直接使用，减少复杂性
}
