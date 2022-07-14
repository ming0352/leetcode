/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
class MyLinkedList {
public:
    struct mylist{
        int val;
        struct mylist *next;
        mylist(int x): val(x),next(nullptr) {};
    };
    MyLinkedList() {
        _dummyhead=new mylist(0);
        _size=0;
    }
    
    int get(int index) {
        if(index>(_size-1) || index<0) return -1;
        mylist *temp=_dummyhead->next;
        while(index--){
            temp=temp->next;
        }

        return temp->val;;
    }
    
    void addAtHead(int val) {
        mylist *newNode=new mylist(val);
        newNode->next=_dummyhead->next;
        _dummyhead->next=newNode;
        _size++;
    }
    
    void addAtTail(int val) {
         mylist* newNode=new mylist(val);
          mylist* temp=_dummyhead;
         while(temp->next!=nullptr){
            temp=temp->next;
         }
         temp->next=newNode;
         _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>_size || index<0) return ;  //這裡是>，因為是要新增節點，和刪除時的判斷不一樣
         mylist *newNode=new mylist(val);
          mylist *cur=_dummyhead;
          while(index--){
            cur=cur->next;
          }
          newNode->next=cur->next;
          cur->next=newNode;
          _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=_size || index<0) return ;  //注意這裡是>=，例如現在有一個節點(index 0)，若要刪除index 1時，則操作不合法
        mylist *cur=_dummyhead;
        while(index--){
            cur=cur->next;
        }
        mylist *del=cur->next;
        cur->next=cur->next->next;
        delete del;
        _size--;
    }
    private:
        mylist* _dummyhead;
        int _size;

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

