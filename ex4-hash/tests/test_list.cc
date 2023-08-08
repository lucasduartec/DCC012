
#include "list.h"


int main()
{
    List l1;

    // testa inserção
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(3);
    if(l1.getSize() != 3)
    {
       return -1;
    }
    l1.print();
       
    l1.remove(3);
    ListNode* node = l1.search(3);
    if(node != nullptr)
       return -1;

    l1.print();
    return 0;
    
}
