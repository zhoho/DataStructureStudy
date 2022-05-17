#include <iostream>
using namespace std;
#define Q_SIZE 10
class element
{
    public:
        string s_title;
        int npages;
        int price;
        void set_data(string s1, int s2, int s3);

};

void element::set_data(string s1, int s2, int s3)
{
    s_title = s1;
    npages = s2;
    price = s3;
}

class my_queue
{
    element q[Q_SIZE];
    int front, rear;
    public:
        my_queue();
        void insert_q(element x);
        element delete_q();
        bool queue_full();
        bool queue_empty();
};

my_queue::my_queue()
{
    front = 0;
    rear = 0;
}

void my_queue::insert_q(element x)
{
    if(!queue_full())
    {
        q[rear] = x;
        rear = (rear + 1) % Q_SIZE;
    }
    else 
        cout << "q가 꽉 찼습니다. ";
}

element my_queue::delete_q()
{
    element tmp;
    if(!queue_empty()) //비어있지않으면 즉 데이터가 있으면 값 return 비어있으면?
    {
        tmp = q[front];
        front = (front + 1) % Q_SIZE;
        return tmp;
    }
}

bool my_queue::queue_full()
{
    if((rear + 1) % Q_SIZE == front) 
        return true;
    else
        return false;
}

bool my_queue::queue_empty()
{
    if(rear == front)
        return true;
    else
        return false;
}

int main()
{
    my_queue a;
    element tmp;
    
    tmp.set_data("C++ Programming", 534, 35000);
    a.insert_q(tmp);
    tmp.set_data("Data Structure", 621, 42000);
    a.insert_q(tmp);
    tmp.set_data("JAVA Programming", 485, 38000);
    a.insert_q(tmp);
    tmp.set_data("Logic Design", 532, 44000);
    a.insert_q(tmp);
    
    while (!a.queue_empty())
    {
        tmp = a.delete_q();
        cout << tmp.s_title << " : " << tmp.npages  << " : " << tmp.price << "\n";
    }
        return 0;
}

// Array를 사용한 Circular queue의 구현 예제:

 

// - 도서정보 = {도서명, 페이지수, 가격} 로 이루어진 원소를 저장하는 circular queue를 구현하고,

// 다음 main function 이 수행되도록 프로그램을 완성하시오.

// int main()

// {

//         my_queue  a;

//         element  tmp;

 

//         tmp.set_data("C++ Programming", 534, 35000);

//         a.insert_q(tmp);

//         tmp.set_data("Data Structure", 621, 42000);

//         a.insert_q(tmp);

//         tmp.set_data("JAVA Programming", 485, 38000);

//         a.insert_q(tmp);

//         tmp.set_data("Logic Design", 532, 44000);

//         a.insert_q(tmp);

        

//         while (!a.empty() ) {

//                 tmp = a.delete_q();

//                 cout << tmp.s_title << " : " << tmp.npages  << " : " << tmp.price << "\n";

//         }

//         return 0;

// }

 

// < 예상 출력 >

//         C++ Programming :  534 : 35000

//         Data Structure :  621 : 42000

//         JAVA Programming :  485 : 38000

//         Logic Design : 532 : 44000

