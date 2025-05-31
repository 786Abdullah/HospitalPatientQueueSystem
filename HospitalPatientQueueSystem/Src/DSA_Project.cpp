#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<memory>

using namespace std;
template <class t>
class pQueue{
	vector<t> body;
	int getKey(t temp){
		return temp.priority;
	}
    void shiftUp(){
		int current=size()-1,parent;
		t temp;
	       while(current>0){
	       	if(!current%2) parent=((current-2)/2);
	        else parent=((current-1)/2);
			if(getKey(body[parent])<getKey(body[current])){
				temp=body[parent];
				body[parent]=body[current];
				body[current]=temp;
			  }
			 current=parent; 
		   }
	}
	void shiftDown(){
		int current=0,child;
		t temp;
		bool swap=false;
	       while(current<size()-1){
	       	if((current*2+2<size())
			    &&
				getKey(body[current*2+1])>getKey(body[current*2+2]))
				       child=(current*2+1);
	        else if((current*2+2<size())
			        &&
					getKey(body[current*2+2])>getKey(body[current*2+1]))
					    child=(current*2+2);
	        else if(size()<3) child=current+1;
			if(getKey(body[child])>getKey(body[current])){
				temp=body[current];
				body[current]=body[child];
				body[child]=temp;
				swap=true;
			  }
			  if(!swap) break;
			  swap=false;
			 current=child; 
		   }
	}
	public:
	int  size(){
		return body.size();
	}
	bool empty(){
		return size()==0;
	}
	void insert(t a){
		body.push_back(a);
		shiftUp();
	}
	t   top(){
		t *empty=new t;
		if (size()==0) return *empty;
		delete empty;
		t x=body[0];
		return x;
	}
	t pop(){
		t *empty=new t;
		if (size()==0) return *empty;
		delete empty;
		t x=body[0];
		body[0]=body[size()-1];
		body.pop_back();
		shiftDown();
		return x;
	}
	void display(){
		for(int i=0;i<size();i++){
//			cout<<getKey(body[i])
			body[i].show();
			cout<<"\n\n\n";
		}
	}
	void showList(){
		cout<<left<<setw(5)<<"num"
			    <<setw(7)<<"Id"
				<<setw(15)<<"Name"
			    <<setw(10)<<"priority"
			    <<setw(5)<<"Age"
			    <<setw(15)<<"Disease"
			    <<endl<<endl;
		for(int i=0;i<size();i++){
			cout<<left<<setw(5)<<i+1
			    <<setw(7)<<body[i].id
			    <<setw(15)<<body[i].name
				<<setw(10)<<body[i].priority
			    <<setw(5)<<body[i].age
			    <<setw(15)<<body[i].disease
			    <<endl;
		}
	}
};
template <class t>
class hTable{
	int size=35,filled=0;
//	unique_ptr<t[]> array(new t[size]);
//	t *array=new t[size];;
    t array[35];

	void start(){
//		for (int i=0;i<size;i++)
//		     array[i]= new t;
	}
	public:
		hTable(){}
//		hTable(int a){
//			size = a;
//			start();
//		}
		~hTable(){
//			delete []array;
		}
		int getKey(t temp){
			return temp.id;
		}
		int* setKey(t &temp){
			return &temp.id;
		}
		double load(){
			return (static_cast<double>(filled)/static_cast<double>(size));
		}
		int hash(int a){
			return a%size;
		}
		bool insert(t realKey){
			int key=getKey(realKey);
			for (int i=0;i<size;i++){
			if(getKey(array[hash(key)])==-1){
			    array[hash(key)]=realKey;
			    filled++;
			    return true;
			   }
			key = key+i;
			}
			return false;
		}
		t search(int realKey){
		    int key=realKey;
			for (int i=0;i<size;i++){
			if(getKey(array[hash(key)])==realKey){
			    return array[hash(key)];
			     }
			key = key+i;
			}
			t *empty =new t;
			return *empty;
		}
		bool remove(t &realKey){
		    int key=getKey(realKey);
			for (int i=0;i<size;i++){
			if(getKey(array[hash(key)])==getKey(realKey)){
				int *num=setKey(array[hash(key)]);
			    *num=-1;
			    filled--;
			    return true;
			     }
			key = key+i;
			}
			return false;
		}
		void display(){
			for (int i=0;i<size;i++){
			if(getKey(array[i])!=-1){
			    cout<<"value at index "
				    <<i<<" is "<<getKey(array[i])/*show()*/
					<<"\n";
			     }
			}
		}
};
struct pntId{
	int id;
	pntId (){
	     id = -1;
		 }
	pntId (int a){
	     id = a;
		 }
};
class patient{
	int getUniqueId(hTable <pntId> &t){
			int a=(1000+(rand()%(10000-1000)));
			if(!(t.search(a)).id==-1){	
			   a = 1000+(rand()%(10000-1000));
		    } 
		    pntId *b= new pntId(a);
		    pntId p=*b;
			t.insert(p); 
			return p.id;
			}
   public:
   	time_t chkUpTime;
	int priority,id,age;
	string name,disease;
	bool served;
		patient(){
			priority = -1;
			id=-1;
			age=-1;
			name="unknown";
			disease="unknown";
			served=false;
		}
		patient(int a,int c,string d,string e,hTable<pntId> &IDs){
			priority = a;
			id=getUniqueId(IDs);
			age=c;
			name=d;
			disease=e;
			served=false;
		}
	void setData(hTable<pntId> &IDs){
		    id=getUniqueId(IDs);
		    cout<<"\ngenerated id: "<<id;
			cout<<"\nenter name: ";
			cin>>name;
			cout<<"enter age: ";
			cin>>age;
		while(!(age>=1&&age<=149)){
      	    cout<<"\ninvalid INPUT. \n enter again";
      	    cin>>age;
	  }
			cout<<"enter disease: ";
			cin>>disease;
			cout<<"enter priority:(1 to 10) ";
			cin>>priority;
		while(!(priority>=1&&priority<=10)){
      	    cout<<"\ninvalid INPUT. \n enter again";
      	    cin>>priority;
	  }
		}		
	void getSaved(hTable<patient> &t){
			if(t.insert(*this)) cout<<"entered table";
			else cout<<"can't enter table";
		}
	void enterQueue(pQueue<patient>& q,hTable<patient> &t){
		q.insert(*this);
		t.insert(*this);
	}
	void show(){
		cout<<"\nname: "<<name;
		cout<<"\nage: "<<age;
		cout<<"\nid: "<<id;
		cout<<"\npriority: "<<priority;
		cout<<"\nserved :"<<served;
		if(served)
		cout<<"\nserved at: "<<put_time(localtime(&chkUpTime),"%Y-%m-%d-%H:%M:%S");
		cout<<"\n";
	}
	void serve(){
		chkUpTime=time(0);
		served=true;
	}
};
class doctor{
	public:
		string name;
		doctor(string n){
		   name= n;
		}
		void seeNext(pQueue<patient> &q){
			patient p=q.top();
			p.show();
		}
		void serveNext(pQueue<patient> &q,hTable<patient> &t1,vector<patient> &chkd){
			patient p=q.pop();
			t1.remove(p);
			p.serve();
			chkd.push_back(p);
		}
		void searchInQ(hTable<patient> &t){
			patient p;
			int a;
			cout<<"\nenter id to search:";
			cin>>a;
		while(!(a>=1000&&a<=9999)){
      	    cout<<"\ninvalid id. \n enter again";
      	    cin>>a;
	  }
			p=t.search(a);
			if(p.id==-1) cout <<"\nnot found\n";
			else {
			cout <<"\nfound in queue\n";
			p.show();
			}
		}
};
int qSort(vector<patient> &a,int min,int max){
	int pos=min;
	patient temp;
	for (int i=min;i<=max;i++){
		if(a[i].age<=a[max].age){
		temp=a[i];
		a[i]=a[pos];
		a[pos]=temp;
		pos++;
	}
	}
	return pos-1;
}
void quickSort(vector<patient> &a,int min,int max){
	if(min>=max) 
	     return;
	  int pivot = qSort(a,min,max);
	  quickSort(a,min,pivot-1);
	  quickSort(a,pivot+1,max);
}
void insertSort(vector<patient> &a,int max){
	patient temp;
	for (int i=0;i<max;i++){
 	   for(int j=i;j>0;j--){
 		if(a[j].chkUpTime>a[j-1].chkUpTime){
 			temp=a[j-1];
 			a[j-1]=a[j];
 			a[j]=temp;
		 }
		 else 
		     break;
	 }
   }
}
void selectSort(vector<patient> &a,int max){
	patient min,temp;
	int loc;
	for (int i=0;i<max;i++){
		
		min=a[i];
		loc=i;
		
 	   for(int j=i+1;j<max;j++){
 		if(a[j].name<min.name){
 			min=a[j];
 			loc=j;
		 }
		 }
		 temp=a[i];
		 a[i]=a[loc];
		 a[loc]=temp;
	 
   }
}
int binarySearch(vector<patient> &a,string val){
	int size=a.size(), low=0, high=size-1 ,mid;
	
	while(low<=high){
		mid=low+(high-low)/2;
		if(a[mid].name==val)
		   return mid;
		else if(a[mid].name<val)
		   low = mid+1;
		else 
		   high=mid-1;
	}
	return -1;
}
int main(){
 cout<<"Bismillah hirrehman nirraheem\n";
 srand(static_cast<int>(time(0)));
 hTable<pntId> IDs;
 hTable<patient> inQueue;
 pQueue<patient> q1;
 doctor dctr("Dr.Kamal");
 vector<patient> checked;
 int choice,choice2,b,c;
 char s;
 
 patient p1(7,15,"ali","fever",IDs);
 patient p2(10,23,"bilal","injury",IDs);
 patient p3(5,17,"saad","cough",IDs);
 patient p4(3,19,"khalid","itching",IDs);
 patient p5(1,14,"jaffer","flu",IDs);
 patient p6(7,15,"karam","fever",IDs);
 patient p7(10,28,"raza","injury",IDs);
 patient p8(5,27,"hashim","cough",IDs);
 patient p9(3,29,"khurshid","itching",IDs);
 patient p10(1,5,"zia","flu",IDs);
 patient p11(7,11,"wasee","fever",IDs);
 patient p12(10,23,"umer","injury",IDs);
 patient p13(5,7,"toqeer","cough",IDs);
 patient p14(3,9,"nadir","itching",IDs);
 patient p15(1,16,"fahad","flu",IDs);
 patient p16(1,5,"yasir","flu",IDs);
 patient p17(7,11,"wajih","fever",IDs);
 patient p18(10,23,"qarir","injury",IDs);
 patient p19(5,7,"qamar","cough",IDs);
 patient p20(3,9,"nasir","itching",IDs);
 patient p21(1,16,"javed","flu",IDs);
 
 time_t smplTime=time(0);
 
 p1.chkUpTime=smplTime-2500;
 p2.chkUpTime=smplTime-4200;
 p3.chkUpTime=smplTime-6900;
 p4.chkUpTime=smplTime-8600;
 p5.chkUpTime=smplTime-1000;
 p6.chkUpTime=smplTime-1700;
 p7.chkUpTime=smplTime-3300;
 p8.chkUpTime=smplTime-2700;
 p9.chkUpTime=smplTime-3900;
 p10.chkUpTime=smplTime-1500;
 p11.chkUpTime=smplTime-5300;
 p12.chkUpTime=smplTime-3700;
 p13.chkUpTime=smplTime-4900;
 
 checked.push_back(p1);
 checked.push_back(p2);
 checked.push_back(p3);
 checked.push_back(p4);
 checked.push_back(p5);
 checked.push_back(p6);
 checked.push_back(p7);
 checked.push_back(p8);
 checked.push_back(p9);
 checked.push_back(p10);
 checked.push_back(p11);
 checked.push_back(p12);
 checked.push_back(p13);

 p14.enterQueue(q1,inQueue);
 p15.enterQueue(q1,inQueue);
 p16.enterQueue(q1,inQueue);
 p17.enterQueue(q1,inQueue);
 p18.enterQueue(q1,inQueue);
 p19.enterQueue(q1,inQueue);
 p20.enterQueue(q1,inQueue);
 p21.enterQueue(q1,inQueue);
 
 do{
  system("cls");
  cout<<"Bismillah hirrehman nirraheem\n";
  cout<<"\n PATIENT QUEUE MANAGEMENT   \n\n";
  cout<<"\nEnter 1 to add new new patient"
      <<"\nEnter 2 to check next patient"
      <<"\nEnter 3 to find in queue"
      <<"\nEnter 4 to view patients of queue"
      <<"\nEnter 5 to view doctor name"
      <<"\nEnter 6 to view checked list"
      <<"\nEnter 7 to sort checked list"
      <<"\nEnter 8 to search by id"
      <<"\nEnter 9 to search by name"
      <<" \n your choice : ";
      cin>>choice;
      while(!(choice>=1&&choice<=9)){
      	cout<<"\ninvalid choice. \n enter again";
      	cin>>choice;
	  }
 switch(choice) {
 	case 1 :{
 		system("cls");
 		cout<<"NEW PATIENT\n";
		patient *a=new patient;
		patient p=*a;
		p.setData(IDs);
		p.enterQueue(q1,inQueue);
	 break;
	}
	case 2 :{
		system("cls");
 		cout<<"CHECKUP ROOM\n";
 		cout<<"\npatient being checked :\n";
 		dctr.seeNext(q1);
 		cout<<"\npatient got checked ?(y)";
 		cin>>s;
 		while(!(s=='y'||s=='Y')){
      	cout<<"\ninvalid input. \n enter y or Y";
      	cin>>s;
	  }
 		dctr.serveNext(q1,inQueue,checked);
	 break;
	}
	case 3 :{
		system("cls");
 		cout<<"QUEUE SEARCH\n";
 		dctr.searchInQ(inQueue);
	 break;
	}
	case 4 :{
		system("cls");
 		cout<<"QUEUE LIST\n";
 		q1.showList();
	 break;
	}
    case 5 :{
    	system("cls");
 		cout<<"THE DOCTOR\n";
 		cout<<"\n your doctoer's name is :"<<dctr.name;
	 break;
	}
	case 6 :{
		system("cls");
 		cout<<"CHECKED PATIENTS LIST\n";
		cout<<left<<setw(5)<<"num"
			    <<setw(7)<<"Id"
			    <<setw(15)<<"Name"
			    <<setw(5)<<"Age"
			    <<setw(15)<<"Disease"
			    <<setw(35)<<"Date & Time of checkup"
			    <<endl
				<<endl;
		for(int i=0;i<checked.size();i++){
			cout<<left<<setw(5)<<i+1
			    <<setw(7)<<checked[i].id
			    <<setw(15)<<checked[i].name
			    <<setw(5)<<checked[i].age
			    <<setw(15)<<checked[i].disease
			    <<setw(35)<<put_time(localtime(&checked[i].chkUpTime),"%Y-%m-%d   %H:%M:%S")
			    <<endl;
		}
	 break;
	}
	case 7 :{
		system("cls");
 		cout<<"SORTING\n";
	cout<<"\nEnter 1 to sort by age"
        <<"\nEnter 2 to sort by name"
        <<"\nEnter 3 to sort by time"
        <<" \n your choice : ";
        cin>>choice2;
        while(!(choice2>=1&&choice2<=3)){
      	cout<<"\ninvalid choice. \n enter again";
      	cin>>choice2;
	  }
    switch(choice2) {
    	case 1:{
    		quickSort(checked,0,checked.size()-1);
			break;
		}
		case 2:{
    		selectSort(checked,checked.size());
			break;
		}
		case 3:{
    		insertSort(checked,checked.size());
			break;
		}
    	default :{
			break;
		}
 	}
 		cout<<"sorted";
	 break;
	}
	case 8 :{
		system("cls");
 		cout<<"ID SEARCH\n";
		int tmpId;
		bool found=false;
		cout<<"\nenter Id :";
		cin>>tmpId;
		while(!(tmpId>=1000&&tmpId<=9999)){
      	    cout<<"\ninvalid id. \n enter again";
      	    cin>>tmpId;
	  }
		for(int i=0;i<checked.size();i++){
			if(tmpId==checked[i].id){
			
			     checked[i].show();
			     found=true;
			     }
		}
		if(!found)
		cout<<"\nnot found";
	 break;
	}
	case 9 :{
		system("cls");
 		cout<<"NAME SEARCH\n";
		string tmpname;
		int index;
		cout<<"\nenter name :";
		cin>>tmpname;
		selectSort(checked,checked.size());
		index=binarySearch(checked,tmpname);
		if(index==-1)cout<<"\nnot found";
		else checked[index].show();
	 break;
	}
	default:
		break;
}
 cout<<"\nenter 0 to quit and 1 to go back: ";
 cin>>c;
 }while (!c==0);
 return 0;
 }