#include <iostream>
#include <array>

template <typename T, size_t N>
void print(const std::array<T, N>& arr) {
    /*
    함수에 std::array 객체를 전달할 경우, 기본적으로 새로운 배열에 모든 원소가 복사됨. (깊은 복사)
    이러한 동작을 피하고 싶다면 참조 또는 const 참조를 사용할 수 있음.
    */
    for (typename std::array<T, N>::const_iterator iter = arr.begin(); iter != arr.end(); iter++) {
        const T& ele = *iter;
        std::cout << ele << " ";
    }
    std::cout << std::endl;
}

int main() {
    /*
    std:array는 c와 달리 메모리를 자동으로 할당하고 해제함.
    std:array는 원소의 타입과 배열 크기를 매개변수로 사용하는 클래스 템플릿.
    */
    std::array<short, 10> arr1;
    std::array<short, 4> arr2 = {1, 2, 3, 4};
    std::array<short, 4> arr3 = {1, 2, 3, 4};
    std::array<short, 5> arr4 = {1, 2, 3, 4, 5};
    
    arr1[0] = 1;
    
    std::cout << "arr1 배열의 첫 원소: " << arr1[0] << std::endl;
    
    std::cout << "arr2 배열의 모든 원소: ";
    for (short i = 0; i < arr2.size(); i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    // std::array의 [] 연산자는 전달된 인덱스 값이 배열의 크기보다 큰지를 검사하지 않음.
    std::cout << arr3[4] << std::endl;      // 1
    try {
        /*
        at 함수를 사용하면 std::out_of_range 예외를 발생시킴.
        */
        std::cout << arr3.at(4) << std::endl;
    } catch (const std::out_of_range& ex) {
        std::cerr << ex.what() << std::endl;
    }

    print(arr4);

    std::cout << arr4.front() << std::endl;         // 배열의 첫 번째 원소에 대한 참조 반환
    std::cout << arr4.back() << std::endl;          // 배열의 마지막 원소에 대한 참조 반환
    std::cout << *(arr4.data() + 1) << std::endl;   // 배열 객체 내부에서 실제 데이터 메모리 버퍼를 가리키는 포인터를 반환. 포인터를 함수의 인자로 받는 함수를 사용할 때 유용.

    return 0;
}

/*
arr1 배열의 첫 원소: 1
arr2 배열의 모든 원소: 1 2 3 4 
1
array::at
1 2 3 4 5
1
5
2
*/
