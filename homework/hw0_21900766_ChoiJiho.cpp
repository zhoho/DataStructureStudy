#include <iostream>
using namespace std;

int main()
{
    my_list a;
    node tmp;
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp)
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);
    cout << a.num_nodes() << ":" << a.score_sum() << "\n"; //1 check
    tmp.set_data("Park",91.3);
    a.add_to_tail(tmp);
    cout << a.num_nodes() << " : " << a.score_sum; //2 check 
    tmp = a.delete_from_head();
    cout << tmp.name << "is deleted\n"; //3 check
    tmp.set_data("Choi", 85.1);
    a.add_to_tail(tmp);
    tmp.set_data("Ryu", 94.3);
    a.add_to_head(tmp);
    cout << a.num_nodes()<< " : " << a.score_sum() << "\n";
    cout << "Park’s score : " << a.get_score("Park") << "\n"; //4 check 
    if(a.remove_a_node("Kim") == 1)
        cout << "Kim is deleted from the list. \n"; //5 check 
    cout << a.num_nodes() << " : " << a.score_sum() << "\n"; // last check
    return 0;
}