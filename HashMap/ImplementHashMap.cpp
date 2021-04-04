#include<iostream>
#include<string>
using namespace std;
template<typename T>
class Map{
		  public:
					 string key;
					 T value;
					 Map *next;
					 Map(string  key, T value){
								this->key=key;
								this->value=value;
								next=NULL;
					 }
					 ~Map(){
								delete next;
					 }
};
template<typename T>
class ourmap{
		  Map<T> ** buckets;
		  int count;
		  int numBuckets;
		  public:
		  ourmap(){
					 count=0;
					 numBuckets=5;
					 buckets=new Map<T> *[numBuckets];
					 for(int i=0;i<numBuckets;i++){
								buckets[i]=NULL;}
		  }
		  ~ourmap(){

					 for(int i=0;i<numBuckets;i++){
								delete buckets[i];}
					 delete buckets;

		  }
		  int size(){
		  return count;}

private:
int getBucketIndex(string key){
// hash code
//compression function
int hashcode=0;
// base p hash code
// abc -> a* p2 +b*p+c
int currentCoeff=1;
for(int i=key.length()-1;i>=0;i--){
hashcode+=key[i]*currentCoeff;
currentCoeff*=37; // prime number p=37
currentCoeff=currentCoeff%numBuckets ; // to make range in int;
hashcode=hashcode%numBuckets;
}

return hashcode%numBuckets;

}
public:



void insert(string key, T value){

int bucketIndex=getBucketIndex(key);
Map<T> *head=buckets[bucketIndex];

while(head!=NULL){
if(head->key==key) { // already
head->value=value;
return ;
}
head=head->next;

}
head=buckets[bucketIndex];
Map<T> * node=new Map<T>(key, value);
node->next=head;
buckets[bucketIndex]=node;
count++;
		  }
		  T getValue(string key){
		  }
		  T remove(string key){

int bucketIndex=getBucketIndex[key];

Map<T> head=buckets[bucketIndex];
Map<T> *prev=NULL;
while(head!=NULL){
if(head->key==key){
if(prev==NULL){
buckets[bucketIndex]=head->next;
}
else{
prev->next=head->next;
}
T value =head->value;
head->next=NULL;
delete head;
count--;
return value;
}
prev=head;
head=head->next;
}
return 0;
}

};
