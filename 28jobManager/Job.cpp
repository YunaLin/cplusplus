#include<iostream>
#include<cstring>
#include<sstream>
#include"Job.h"
using namespace std;

int Job::number = 0;  //  静态变量外部独立定义
Job::Job(int priority) {
  nextJob = NULL;
  this->priority = priority;
  id = number;
  number++;
}
void Job::setId(int id) {
  this->id = id;
}
int Job::getId() const {
  return id;
}
void Job::setPriority(int priority) {
  this->priority = priority;
}
int Job::getPriority() const {
  return priority;
}
void Job::setNext(Job *job) {
  nextJob = job;   //  job 是已经创建好的一个类对象
}
Job* Job::getNext() const {
  return nextJob;
}
string Job::toString() {
  ostringstream strCat;  //  stringstream 的用法与ostringstream相似
  strCat << "[" << id << ":" << priority << "]";
  return strCat.str();
}
