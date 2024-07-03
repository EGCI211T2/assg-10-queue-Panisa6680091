#ifndef queue_h
#define queue_h
#include "Node.h"
class Queue {
	NodePtr headPtr,tailPtr;
	int size;
public:
    void enqueue(int);
    int dequeue();
    Queue();
    ~Queue();
};

void Queue::enqueue(int x)
{
  NodePtr new_node= new NODE(x);
  if(new_node)
  { 
      //Add head and tail for me please 
    if(headPtr==NULL)
    {
      tailPtr=new_node;
      headPtr=tailPtr;
    }
    else
    {
      tailPtr->set_next(new_node);
      tailPtr=tailPtr->get_next();
    }
    
    size++;
  }
}

int Queue::dequeue()
{
  if(headPtr!=NULL)
  {
    NodePtr t=headPtr;
    int value=t->get_value();
    
    headPtr = headPtr->get_next();
    
    if(headPtr==NULL) tailPtr=headPtr;
    
    --size;
    delete t;
    return value;
  }
  cout<<"Empty queue";
  return -1;
}

Queue::Queue()
{
    //initialize 
    size=0;
    headPtr=NULL;
    tailPtr=NULL;
}

Queue::~Queue()
{
    //delete all remaning Queue (i.e. DQ all)
    int value, i;
    NodePtr t;

    cout<<"Clearing queue"<<endl;

    for(i=0; i<size; i++)
    {
      t=headPtr;
      value=t->get_value();
      headPtr=headPtr->get_next();

      cout<<"Dequeing "<<value<<endl;
      delete t;
    }
    
}
#endif
