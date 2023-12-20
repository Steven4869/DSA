// Remove Dups! Write code to remove duplicates from an unsorted linked list.
// FOLLOW UP
// How would you solve this problem if a temporary buffer is not allowed?

Class Node{
    public:
    int data;
    Node *next;
    Node(int d):data(d), next(nullptr){}
};

Class LinkedList{
    private:
    Node *head;
    public:
    LinkedList():head(nullptr){}

    void insert(int data){
        Node *newNode = new Node(data);
        newNode->next=head;
        head=newNode;
    }

    void removeDuplicates(){
        if(head==nullptr){
            return;
        }
        Node *curr=head;
        while(cur!=nullptr){
            Node *runner = curr;
            while(runner->next!=nullptr){
                if(runner->next->data==curr->data){
                    Node *temp = runner->next;
                    runner->next=runner->next->next;
                    delete temp;
                }
                else{
                    runner=runner->next;
                }
            }
            curr=curr->next;
        }
    }
    void print(){
        Node *curr=head;
        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
};
