// 무게 데이터를 연산할 수 있도록 class type 구현

// - kg과 gram단위를 분리하여 연산 가능, ‘덧셈’과 ‘크기 비교 연산’ 구현

// - 다음 main( ) 함수가 동작할 수 있도록 나머지 부분 작성

int main()
{
class weight{
    public:
}

weight w1, w2, w3;  // weight라는 class object 3개 생성

    w1.set_weight(3, 400);  // w1을 3kg 400 g으로

    w2.set_weight(2, 700);  // w2을 2kg 700 g으로

    w3 = add_weight(w1, w2); // w1과 w2을 더하여 w3에 à w3는 6kg 100g

    cout << w3.get_weight( ) << “grams\n”; // w3의 값 ‘6100 grams’ 출력

    if ( less_than(w1, w2) ) // w1이 w2보다 작은 값인가 판단

        cout << “yes.\n”;

    else

        cout << “no. \n”;   // 작지 않으므로 ‘no’ 출력

}