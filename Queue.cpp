template <typename T>
class Queue{
	//Node Data Type
	class Node{
	public:
		T Data;
		Node* Link;
		Node(T data = (T)0): Link(nullptr), Data(data){}
		~Node(){}
	};
	//Pointers
	Node* FRONT;
	Node* END;

	void deleteAll(Node* ptr){
		if(ptr->Link != nullptr)
			deleteAll(ptr->Link);
		
		delete ptr;
	}
public:	//Default Constructor
	Queue(){
		FRONT = END = nullptr;
	}
	//Push
	void push(T data){
		if(FRONT == nullptr)
			FRONT = END = new Node(data);

		else
			END = END->Link = new Node(data);

	}
	//Pop
	T pop(){
		if(FRONT != nullptr){
			T data = FRONT->Data;
			Node* ptr = FRONT;
			FRONT = FRONT->Link;
			delete ptr;
			return data;
		}
	}
	//Destructor
	~Queue(){
		if(FRONT != nullptr)
			deleteAll(FRONT);
	}
};
